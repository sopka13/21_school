#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Sergey Seliverstov <sopka13@mail.ru>");

static int	hello_3_data __initdata = 3;

static int	__init hello_init(void){
	pr_info("Hello module_3, data = %d!\n", hello_3_data);
	return (0);
}

static void	__exit hello_exit(void){
	pr_info("Goodbye module_3!\n");
}

module_init(hello_init);
module_exit(hello_exit);