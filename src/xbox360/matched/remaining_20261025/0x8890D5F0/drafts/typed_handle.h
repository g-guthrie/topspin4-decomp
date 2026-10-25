/*
 * Provisional guest declarations for independently checked exact-code units.
 * Type roles, layouts and signatures remain inferred, not original ABI proof.
 * This header carries no separate function or behavior credit; each unit
 * manifest pins its complete source/header dependency closure.
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

/* Address of the element of `type` the handle designates inside its container, or 0
 * (drafted as fn_88923530 in runtime_registry_queries.c). */
unsigned char *fn_88923530(unsigned char *container, ts4_typed_handle handle, unsigned int type);

#endif
