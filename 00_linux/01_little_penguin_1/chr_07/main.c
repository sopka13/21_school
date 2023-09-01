#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/moduleparam.h>						// For module_param
#include <linux/fs.h>								// For dev_t
#include <linux/cdev.h>								// For cdev
#include <linux/debugfs.h>							// For debugfs
#include <linux/jiffies.h>							// For jiffies
#include <linux/slab.h>

#define SUCCESS 0
#define INVALID_VALUE "invalid value"
#define CORRECT_VALUE "correct write"

static int		hello_major = 0;					// Major number
module_param_named(major, hello_major, int, 0);
MODULE_PARM_DESC(major, " Major device number");

static int		hello_minor = 0;					// Minor number
module_param_named(minor, hello_minor, int, 0);
MODULE_PARM_DESC(minor, " Minor device number");

static char		*driver_name = "fortytwo";			// Device name
module_param(driver_name, charp, 0);
MODULE_PARM_DESC(driver_name, " Device name");

# define		LOGIN_SIZE 6
static char		login[LOGIN_SIZE] = "Eyohn";
module_param_string(login, login, LOGIN_SIZE, 0);
MODULE_PARM_DESC(login, " My login");

#define			LOCAL_BUFF_SIZE PAGE_SIZE
static char		local_buff[LOCAL_BUFF_SIZE];

// static dev_t		dev;							// dev_t
static int			hello_num_dev = 1;				// Count of device
static struct cdev	test_ioctl_cdev;				// cdev struct

static ssize_t	hello_read(struct file *filp,
							char __user *buffer,
							size_t length,
							loff_t *offset)
{
	int len = sizeof(login);
	int ret = len;

	if (!*(login + *offset)) {		/* This is end of message */
		*offset = 0;				/* Reset offset */
		return 0;					/* End of file */
	}

	pr_info("Hello read start: sizeof = %ld; login_size = %d; offset = %lld\n",
			sizeof(login), LOGIN_SIZE, *offset);
	
	if(*offset >= len || copy_to_user(buffer, login, len)) {
		pr_info("Hello copy_to_user failed\n");
		ret = -EINVAL;
	} else {
		pr_info("Hello copy_to_user success\n");
		*offset += len;
	}

	// pr_info("ret after send login = %d\n", ret);

	// len = print_dev_t(local_buff, MKDEV(hello_major, hello_minor));
	// pr_info("ret after print_dev_t = %d\n", len);

	// ret = copy_to_user(buffer + *offset, local_buff, len);
	// *offset += len;
	// pr_info("ret after copy_to_user = %d, len = %d\n", ret, len);

	pr_info("hello_read end: ret = %d; offset = %lld\n", ret, *offset);

	return ret;
}

static ssize_t	ji_read(struct file *filp,
							char __user *buffer,
							size_t length,
							loff_t *offset)
{
	int len = sizeof(local_buff);
	int ret = len;

	sprintf(local_buff, "%lu\n", jiffies);

	if (!*(local_buff + *offset)) {		/* This is end of message */
		*offset = 0;				/* Reset offset */
		return 0;					/* End of file */
	}

	pr_info("ji read start: offset = %lld\n",
			*offset);
	
	if(*offset >= len || copy_to_user(buffer, local_buff, len)) {
		pr_info("Hello copy_to_user failed\n");
		ret = -EINVAL;
	} else {
		pr_info("Hello copy_to_user success\n");
		*offset += len;
	}

	pr_info("ji_read end: ret = %d; offset = %lld\n", ret, *offset);

	return ret;
}

static char		*foo_buff = NULL;
static ssize_t	foo_len;

static ssize_t	foo_read(struct file *filp,
							char __user *buffer,
							size_t length,
							loff_t *offset)
{
	return simple_read_from_buffer(buffer, length, offset, foo_buff, foo_len);
}

static ssize_t	foo_write(struct file *filp,
							const char __user *buffer,
							size_t length,
							loff_t *offset)
{
	// if (length > LOCAL_BUFF_SIZE)
	// 	return -EMSGSIZE;
	// memcpy(foo_buff, buffer, length);
	// foo_len = length;
	// return length;
	int		ret;

	if (!foo_buff) {
		foo_buff = kmalloc(PAGE_SIZE + 1, GFP_KERNEL);
		memset(foo_buff, 0, PAGE_SIZE);
	}

	if (!foo_buff) {
		ret = -ENOMEM;
		goto error;
	} else
		memset(foo_buff, 0, PAGE_SIZE);

	foo_len = (length < PAGE_SIZE) ? length : PAGE_SIZE;
	if (copy_from_user(foo_buff, buffer, foo_len))
		ret = -EFAULT;
	else
		ret = strlen(foo_buff);

	return ret;
error:
	return ret;
}

static ssize_t	hello_write(struct file *filp,
							const char __user *buffer,
							size_t length,
							loff_t *offset)
{
	int len = length;
	int k;
	pr_info("Hello write start length = %d\n", len);
	if (length > LOCAL_BUFF_SIZE)
		len = LOCAL_BUFF_SIZE;

	if (copy_from_user(local_buff, buffer, len))
		return -EFAULT;

	for(k = 0; k < len; k++) {
		// pr_info("i = %d, message[k] = %c, msg[k] = %c\n", k, message[k], msg[k]);
		if (login[k] != local_buff[k]){
			pr_info("%s\n", INVALID_VALUE);
			len = -EINVAL;
			goto err;
		}
	}
	pr_info("%s\b", CORRECT_VALUE);

	return len;
err:
	return len;
}

static struct file_operations fops =
{
	.read = hello_read,			// get data from device
	.write = hello_write,		// for write data to device
	.owner = THIS_MODULE		// module pointer
};

static const struct file_operations id_fops =
{
	.read = hello_read,			// get data from device
	.write = hello_write,		// for write data to device
	.owner = THIS_MODULE		// module pointer
};

static const struct file_operations ji_fops =
{
	.read = ji_read,			// get data from device
	// .write = hello_write,		// for write data to device
	.owner = THIS_MODULE		// module pointer
};

static const struct file_operations foo_fops =
{
	.read = foo_read,			// get data from device
	.write = foo_write,			// for write data to device
	.owner = THIS_MODULE		// module pointer
};

static struct dentry *		debug_struct;

static int __init hello_init(void)
{
	dev_t				dev;
	int					ret_alloc_chr = -1;
	int					ret_cdev_add = -1;

	pr_info("%s start\n", driver_name);
	pr_info("args: hello_major = %d", hello_major);

	/* Register major number for device */
	if(hello_major) {
		dev = MKDEV(hello_major, hello_minor);
		ret_alloc_chr = register_chrdev_region(dev, hello_num_dev, driver_name);
	} else {
		ret_alloc_chr = alloc_chrdev_region(&dev, hello_minor, hello_num_dev, driver_name);
		hello_major = MAJOR(dev);
	}

	if (ret_alloc_chr)
		goto error;

	/* Register functions */
	cdev_init(&test_ioctl_cdev, &fops);
	ret_cdev_add = cdev_add(&test_ioctl_cdev, dev, hello_num_dev);

	if (ret_cdev_add)
		goto error;

	if(printk_ratelimit())							// Limit print message
		pr_info("Hello alloc_chr success: %d\n"
				"cdev_add success\n",
				hello_major);

	/* Get device number */
	// int print_dev_t(char *buffer, dev_t dev);		// Print device number
	// char *format_dev_t(char *buffer, dev_t dev);	// Print device number
	
	/* Create dubugfs files */
	debug_struct = debugfs_create_dir("fortytwo", NULL);

	if (!debug_struct ||
		!debugfs_create_file("id", 0666, debug_struct, NULL, &id_fops) ||
		!debugfs_create_file("jiffies", 0444, debug_struct, NULL, &ji_fops) ||
		!debugfs_create_file("foo", 0655, debug_struct, NULL, &foo_fops))
		goto error;

	pr_info("Hello debugfs create success\n");

	return SUCCESS;

error:
	if (ret_cdev_add == 0)
		cdev_del(&test_ioctl_cdev);
	if (ret_alloc_chr == 0)
		unregister_chrdev_region(dev, hello_num_dev);
	return -1;
}

static void __exit hello_exit(void)
{
	// pr_info("%s start exit\n", driver_name);
	dev_t	dev = MKDEV(hello_major, hello_minor);

	/* Unregister functions */
	cdev_del(&test_ioctl_cdev);
	
	/* Unregister major number for divice */
	unregister_chrdev_region(dev, hello_num_dev);

	debugfs_remove_recursive(debug_struct);
	
	pr_info("%s unregister device success\n", driver_name);
}

module_init(hello_init);
module_exit(hello_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Sergey Seliverstov eyohn <sopka13@mail.ru>");
MODULE_DESCRIPTION("chr_07 Debugfs");