/*
 * Swing_DLL.xex, executable version 0.0.0.3.
 * Shared declarations for the exact-match units in this directory; types, names
 * and field roles are reconstructions from the disassembly of the retail module.
 */
#ifndef TS4_DRAFT_TYPED_HANDLE_H
#define TS4_DRAFT_TYPED_HANDLE_H

typedef struct ts4_typed_owner ts4_typed_owner;

typedef struct ts4_typed_handle {
    ts4_typed_owner *owner;      /* +0 */
    unsigned int index;          /* +4: 0xFFFFF = none */
    unsigned char *container;    /* +8 */
} ts4_typed_handle;

#define TS4_TYPED_HANDLE_NO_INDEX 0xFFFFFu

/* Build a handle from a path string; return `out`. */
ts4_typed_handle *fn_8862BE08(ts4_typed_handle *out, const char *path);
ts4_typed_handle *fn_8862C0E8(ts4_typed_handle *out, const char *path);

unsigned char *fn_88923530(unsigned char *container, ts4_typed_handle handle, unsigned int type);

#endif
