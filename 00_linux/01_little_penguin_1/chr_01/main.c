#include <linux/kernel.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("eyohn");
MODULE_DESCRIPTION("chr_01");


int		init_module(void){
	pr_info("] Hello world !\n"); 
	return 0; 
}

void	cleanup_module(void){
	pr_info("Cleaning up module.\n");
}
