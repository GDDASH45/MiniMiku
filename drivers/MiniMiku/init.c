/*
    MiniMiku initialization driver

    Written on Oct 4, 2026
*/

#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>

static int __init minimiku_init(void)
{
    pr_info("MiniMiku: kernel initialization complete\n");

    return 0;
}

late_initcall(minimiku_init);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("GDDASH45");
MODULE_DESCRIPTION("MiniMiku kernel initialization driver");