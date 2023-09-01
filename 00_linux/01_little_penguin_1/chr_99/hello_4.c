#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Sergey Seliverstov <sopka13@mail.ru>");
MODULE_DESCRIPTION("Tested module");

static int	hello_4_data __initdata = 4;

static int	__init hello_init(void){
	pr_info("Hello module_4, data = %d!\n", hello_4_data);
	return (0);
}

static void	__exit hello_exit(void){
	pr_info("Goodbye module_4!\n");
}

module_init(hello_init);
module_exit(hello_exit);