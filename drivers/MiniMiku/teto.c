/*
    Teto driver

    Written on Oct 4, 2026

    Contributers to this file:

    GDDASH45 - Oct 4, 2026
*/

#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <MiniMiku/metadata.h>


static int __init teto_init(void)
{
    pr_info("MiniMiku: Teto has entered the kernel\n");
    return 0;
}

module_init(teto_init);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("GDDASH45");
MODULE_DESCRIPTION("MiniMiku Teto driver");
EXPORT_METADATA(MODULE_NAME, "TETO_EASTER_EGG_DRIVER");