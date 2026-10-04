/*
    A hidden easter egg,,,, hehehehehe

    Written on Oct 4, 2026
*/

#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>

static int __init egg_init(void)
{
    pr_info("MiniMiku: egg driver initialized\n");
    return 0;
}

static void __exit egg_exit(void)
{
    pr_info("MiniMiku: egg driver unloaded\n");
}

module_init(egg_init);
module_exit(egg_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("GDDASH45");
MODULE_DESCRIPTION("MiniMiku egg driver");