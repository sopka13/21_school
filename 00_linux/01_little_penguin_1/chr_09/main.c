#include <linux/module.h>
#include <linux/init.h>
#include <linux/slab.h>
#include <linux/kernel.h>
#include <linux/proc_fs.h>
#include <linux/fs.h>
#include <linux/fs_struct.h>
#include <linux/dcache.h>

static char		*proc_file_name = "mounted";

static struct	proc_dir_entry *proc_file;
static char		buffer[PATH_MAX];

static char *strjoin(char *dst, const char *src)
{
	char *tmp;

	if (!dst) {															// If first allocate
		tmp = kmalloc(strlen(src) + 1, GFP_NOWAIT);
		strcpy(tmp, src);
		return tmp;
	}
	if (!(tmp = kmalloc(strlen(dst) + strlen(src) + 1, GFP_NOWAIT)))	// If one more allocate
		return NULL;
	memset(tmp, 0, strlen(dst) + strlen(src) + 1);
	strcat(tmp, dst);
	strcat(tmp, src);

	kfree(dst);
	return tmp;
}

ssize_t		proc_read(struct file *fp, char __user *user,
						size_t size, loff_t *offs)
{
	int				ret = 0;
	char			*str = NULL;
	struct dentry	*curdentry;

	list_for_each_entry(curdentry, &current->fs->root.mnt->mnt_root->d_subdirs, d_child) {
		if (curdentry->d_flags & DCACHE_MOUNTED) {
			str = strjoin(str, curdentry->d_name.name);
			str = strjoin(str, "\t");
			str = strjoin(str, dentry_path_raw(curdentry, buffer, sizeof(buffer)));
			str = strjoin(str, "\n");
		}
	}
	ret = simple_read_from_buffer(user, size, offs, str, strlen(str));
	kfree(str);
	return ret;
}

static const struct file_operations fops = {
	.owner = THIS_MODULE,
	.read = proc_read,
};

static int __init fs_init(void)
{
	proc_file = proc_create(proc_file_name, 0, NULL, (const struct proc_ops *)&fops);
	if (proc_file == NULL) {
		pr_err("Error: proc_create faill /proc/%s\n", proc_file_name);
		return -ENOMEM;
	}

	pr_info("proc_create ok. /proc/%s created\n", proc_file_name);

	return 0;
}

static void __exit fs_exit(void)
{
	proc_remove(proc_file);
	pr_info("/proc/%s removed\n", proc_file_name);
}


module_init(fs_init);
module_exit(fs_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Sergey Seliverstov eyohn <sopka13@mail.ru>");
MODULE_DESCRIPTION("chr_07 Debugfs");