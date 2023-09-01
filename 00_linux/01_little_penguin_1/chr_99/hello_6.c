#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/moduleparam.h>					// For module_param
#include <linux/fs.h>							// For dev_t

#define SUCCESS 0

static int		hello_major = 0;				// Major number
module_param_named(major, hello_major, int, 0);
MODULE_PARM_DESC(major, "Major device number");

static int		hello_minor = 0;				// Minor number
module_param_named(minor, hello_minor, int, 0);
MODULE_PARM_DESC(minor, "Minor device number");

static char		*driver_name = "Test_driver";	// Device name
module_param(driver_name, charp, 0);
MODULE_PARM_DESC(driver_name, "Device name");

static int		second[] = { 0, 0 };
static int		arr_argc = sizeof(second) / sizeof(second[0]);
module_param_array(second, int, &arr_argc, 0);
MODULE_PARM_DESC(second, "Test int array arguments");

static char		str[FIXLEN] = "";
module_param_string(some_str, str, sizeof(str), 0);
MODULE_PARM_DESC(some_str, "Test string argument");

static dev_t	dev;							// dev_t
static int		hello_num_dev = 1;				// Count of device

static int __init hello_init(void)
{
	int result = 0;

	pr_info("%s start\n", driver_name);
	pr_info("args: hello_major = %d, size arr = %d,", hello_major, arr_argc);
	for (int i = 0; i < arr_argc; i++)
		pr_info(" second[%d] = %d,", i, second[i]);
	

	/* Register major number for device */
	if(hello_major) {
		dev = MKDEV(hello_major, hello_minor);
		result = register_chrdev_region(dev, hello_num_dev, driver_name);
	} else {
		result = alloc_chrdev_region(&dev, hello_minor, hello_num_dev, driver_name);
		hello_major = MAJOR(dev);
	}

	if (result < 0) {
		pr_warn("%s can't get major %d\n", driver_name, hello_major);
		return result;
	} else {
		pr_info("%s get major success: %d\n", driver_name, hello_major);
	}

	return SUCCESS;
}

static void __exit hello_exit(void)
{
	pr_info("%s exit\n", driver_name);

	/* Unregister major number for divice */
	unregister_chrdev_region(dev, hello_num_dev);
	pr_info("%s unregister device success\n", driver_name);
}

module_init(hello_init);
module_exit(hello_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Sergey Seliverstov eyohn <sopka13@mail.ru>");
MODULE_DESCRIPTION("Test driver");