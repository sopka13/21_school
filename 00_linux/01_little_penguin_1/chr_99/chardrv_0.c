#include <linux/module.h>
#include <linux/kernel.h>

#define SUCCESS 0



static int __init chardrv_init(void)
{
	pr_info("chardrv_init start\n");
	return SUCCESS;
}

static void __exit chardrv_exit(void)
{
	pr_info("chardrv_exit");
}

module_init(chardrv_init);
module_exit(chardrv_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Sergey Seliverstov eyohn <sopka13@mail.ru>");
MODULE_DESCRIPTION("Test char module");