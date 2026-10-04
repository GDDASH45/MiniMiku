/*
    MiniMiku version driver

    MiniMiku 10.04.2026 (MM.DD.YYYY)

    Written on Oct 4, 2026

    Contributers to this file:

    GDDASH45 - Oct 4, 2026
    GDDASH45 - Oct 4, 2026 (#2)

*/

#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>
#include <generated/utsrelease.h>

#define MIKU_VERSION "10.04.2026"

static int mikuver_show(struct seq_file *m, void *v)
{
    seq_printf(m, "%s\n", MIKU_VERSION); // MiniMiku version
    seq_printf(m, "Linux %s\n", UTS_RELEASE); // UTS_Release

    return 0;
}

static int mikuver_open(struct inode *inode, struct file *file)
{
    return single_open(file, mikuver_show, NULL);
}

static const struct proc_ops mikuver_ops = {
    .proc_open = mikuver_open,
    .proc_read = seq_read,
    .proc_lseek = seq_lseek,
    .proc_release = single_release,
};

static int __init mikuver_init(void)
{
    struct proc_dir_entry *dir;

    dir = proc_mkdir("MiniMiku", NULL);
    if (!dir)
        return -ENOMEM;

    if (!proc_create("version", 0444, dir, &mikuver_ops))
        return -ENOMEM;

    pr_info("MiniMiku: version %s\n", MIKU_VERSION);
    return 0;
}

static void __exit mikuver_exit(void)
{
    pr_info("MiniMiku: version driver unloaded\n");
}

module_init(mikuver_init);
module_exit(mikuver_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("GDDASH45");
MODULE_DESCRIPTION("MiniMiku version driver");