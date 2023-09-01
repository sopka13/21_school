#include <linux/module.h>
#include <linux/moduleparam.h>
// #include <linux/kernel.h>

#define SUCCESS 0

static int first;
static char *program_name;
module_param(first, int, S_IRUGO);
module_param(program_name, charp, S_IRUGO);

static int __init hello_init(void)
{
	pr_info("%s init start, first arg = %d\n", program_name, first);
	return SUCCESS;
}

static void __exit hello_exit(void)
{
	pr_info("Hello exit start");
}

module_init(hello_init);
module_exit(hello_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Sergey Seliverstov eyohn <sopka13@mail.ru>");
MODULE_DESCRIPTION("Test module");