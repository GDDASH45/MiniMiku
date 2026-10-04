#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIKU_MAGIC "MIKU00"

#define MIKU_DATA_OFFSET 0x10
#define MIKU_DATA_END    0x110
#define MIKU_DATA_SIZE   0x100

struct miku_header {
    char magic[6];

    uint16_t version;

    uint32_t entry;

    uint32_t code_offset;
    uint32_t code_size;

    uint32_t data_offset;
    uint32_t data_size;
};

static void usage(const char *program)
{
    fprintf(stderr, "usage: %s <output>\n", program);
}

int main(int argc, char **argv)
{
    struct miku_header header;
    FILE *file;

    if (argc != 2) {
        usage(argv[0]);
        return 1;
    }

    memset(&header, 0, sizeof(header));

    memcpy(header.magic, MIKU_MAGIC, 6);

    header.version = 0;
    header.entry = 0;

    header.code_offset = sizeof(header);
    header.code_size = 0;

    header.data_offset = MIKU_DATA_OFFSET;
    header.data_size = MIKU_DATA_SIZE;

    file = fopen(argv[1], "wb");

    if (!file) {
        perror(argv[1]);
        return 1;
    }

    if (fwrite(&header, sizeof(header), 1, file) != 1) {
        perror("write");
        fclose(file);
        return 1;
    }

    fclose(file);

    return 0;
}