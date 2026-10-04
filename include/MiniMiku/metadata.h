#ifndef _MINIMIKU_METADATA_H
#define _MINIMIKU_METADATA_H

#define EXPORT_METADATA(name, value) \
    static const char *name __attribute__((used)) = value

#endif