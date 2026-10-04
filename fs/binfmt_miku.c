#include <linux/types.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/binfmts.h>
#include <linux/fs.h>
#include <linux/slab.h>
#include <linux/uaccess.h>

#define MIKU_MAGIC "MIKU00"

#define MIKU_MAGIC_SIZE 6

#define MIKU_DATA_OFFSET 0x10

#define MIKU_DATA_END    0x110

#define MIKU_DATA_SIZE   0x100

#define MIKU_FLAGS_OFFSET 0x110

#define MIKU_FLAGS_END    0x130

#define MIKU_FLAGS_SIZE   0x20

struct miku_header {

    char magic[6];

    __u16 version;

    __u32 entry;

    __u32 code_offset;

    __u32 code_size;

    __u32 data_offset;

    __u32 data_size;

};

static int load_miku_binary(struct linux_binprm *bprm)
{
    struct miku_header header;

    if (bprm->buf_size < MIKU_MAGIC_SIZE)
        return -ENOEXEC;

    if (memcmp(bprm->buf, MIKU_MAGIC, MIKU_MAGIC_SIZE) != 0)
        return -ENOEXEC;

    if (bprm->buf_size < sizeof(header))
        return -ENOEXEC;

    memcpy(&header, bprm->buf, sizeof(header));

    pr_info("MiniMiku: Miku binary detected: %s\n",
            bprm->filename);

    pr_info("MiniMiku: version: %u\n",
            header.version);

    pr_info("MiniMiku: entry: 0x%08x\n",
            header.entry);

    pr_info("MiniMiku: code offset: 0x%08x\n",
            header.code_offset);

    pr_info("MiniMiku: code size: 0x%08x\n",
            header.code_size);

    pr_info("MiniMiku: data offset: 0x%08x\n",
            header.data_offset);

    pr_info("MiniMiku: data size: 0x%08x\n",
            header.data_size);

    return -ENOEXEC;
}

static struct linux_binfmt miku_format = {
    .module = THIS_MODULE,
    .load_binary = load_miku_binary,
};

static int __init miku_binfmt_init(void)
{
    int ret;

    ret = register_binfmt(&miku_format);

    if (ret)
        pr_err("MiniMiku: failed to register Miku binary format\n");
    else
        pr_info("MiniMiku: Miku binary format registered\n");

    return ret;
}

static void __exit miku_binfmt_exit(void)
{
    unregister_binfmt(&miku_format);

    pr_info("MiniMiku: Miku binary format unregistered\n");
}

module_init(miku_binfmt_init);
module_exit(miku_binfmt_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("GDDASH45");
MODULE_DESCRIPTION("MiniMiku Miku binary format");