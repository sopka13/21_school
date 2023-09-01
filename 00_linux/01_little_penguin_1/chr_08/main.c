#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/miscdevice.h>
#include <linux/fs.h>
#include <linux/slab.h>

static ssize_t myfd_read(struct file *fp, char __user *user,
							size_t size, loff_t *offs);

static ssize_t myfd_write(struct file *fp, const char __user *user,
							size_t size, loff_t *offs);

static struct file_operations myfd_fops = {
	.owner = THIS_MODULE,
	.read = myfd_read,
	.write = myfd_write
};

static struct miscdevice myfd_device = {
	.minor = MISC_DYNAMIC_MINOR,
	.name = "reverse",
	.fops = &myfd_fops
};

char str[PAGE_SIZE];
char *tmp;

static ssize_t	myfd_read(struct file *fp, char __user *user, size_t size,
							loff_t *offs)
{
	ssize_t i = 0;
	ssize_t t = (strlen(str) > 0) ? strlen(str) - 1 : 0;

	pr_info("myfd_read start\n");
	/*
	* Malloc like a boss
	*/
	if(tmp)
		kfree(tmp);
	pr_info("myfd_read 1: page_size = %ld, gfp = %d, t = %ld, str = |%s|, strlen = %ld\n",
			PAGE_SIZE, GFP_KERNEL, t, str, strlen(str));
	tmp = kmalloc(sizeof(char) * PAGE_SIZE * 2, GFP_KERNEL);

	pr_info("myfd_read  1 ok\n");
	if (!tmp)
		return -ENOMEM;

	pr_info("myfd_read  2 ok\n");
	for (i = 0; t >= 0; t--, i++) {
		pr_info("myfd_read 3: i = %ld, t = %ld, char = %d\n", i, t, (int)str[i]);
		tmp[i] = str[t];
	}

	pr_info("myfd_read  3 ok\n");
	tmp[i] = '\0';

	pr_info("myfd_read  4 ok\n");

	return simple_read_from_buffer(user, size, offs, tmp, i);
}

static ssize_t	myfd_write(struct file *fp, const char __user *user,
							size_t size, loff_t *offs)
{
	ssize_t res = 0;

	pr_info("myfd_write start\n");
	res = simple_write_to_buffer(str, size, offs, user, size);
	if (res)
		str[res] = '\0';

	pr_info("myfd_write end\n");

	return res;
}

static int __init myfd_init(void)
{
	int retval;
	
	pr_info("myfd_init start\n");
	retval = misc_register(&myfd_device);
	if (retval) {
		pr_err("can't misc_register :(\n");
		return retval;
	}

	pr_info("myfd_init end\n");
	
	return 0;
}

static void __exit myfd_cleanup(void)
{
	pr_info("myfd_cleanup start\n");
	if(tmp)
		kfree(tmp);
	misc_deregister(&myfd_device);
	pr_info("myfd_cleanup end\n");
}

module_init(myfd_init);
module_exit(myfd_cleanup)

/* Dont have a license, LOL */
MODULE_LICENSE("LICENSE");
MODULE_AUTHOR("Louis Solofrizzo <louis@ne02ptzero.me>");
MODULE_DESCRIPTION("Useless module");