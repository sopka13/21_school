#include <linux/kernel.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Sergey Seliverstov <sopka13@mail.ru>");

int		init_module(void){
	pr_info("Hello module_1\n"); 
	/* A non 0 return means init_module failed; module can't be loaded. */
	return 0; 
}

void	cleanup_module(void){
	pr_info("Goodbye module_1\n");
}
