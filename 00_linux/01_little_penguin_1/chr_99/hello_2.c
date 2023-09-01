#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Sergey Seliverstov <sopka13@mail.ru>");

static int	__init hello_init(void){
	pr_info("Hello module_2!\n");
	return (0);
}

static void	__exit hello_exit(void){
	pr_info("Goodbye module_2!\n");
}

module_init(hello_init);
module_exit(hello_exit);