/*
    MiniMiku intentional panic driver

    Creates /dev/panic.

    Writing anything to /dev/panic causes a kernel panic.

    Written on Oct 4, 2026
*/

#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/miscdevice.h>
#include <linux/module.h>
#include <linux/uaccess.h>

static ssize_t intpanic_write(
    struct file *file,
    const char __user *buf,
    size_t count,
    loff_t *ppos)
{
    panic("MiniMiku: intentional panic triggered through /dev/panic");

    return count;
}

static const struct file_operations intpanic_fops = {
    .owner = THIS_MODULE,
    .write = intpanic_write,
};

static struct miscdevice intpanic_device = {
    .minor = MISC_DYNAMIC_MINOR,
    .name = "panic",
    .fops = &intpanic_fops,
    .mode = 0200,
};

static int __init intpanic_init(void)
{
    int ret;

    ret = misc_register(&intpanic_device);
    if (ret)
        return ret;

    pr_info("MiniMiku: /dev/panic registered\n");

    return 0;
}

static void __exit intpanic_exit(void)
{
    misc_deregister(&intpanic_device);
}

module_init(intpanic_init);
module_exit(intpanic_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("GDDASH45");
MODULE_DESCRIPTION("MiniMiku intentional kernel panic device");