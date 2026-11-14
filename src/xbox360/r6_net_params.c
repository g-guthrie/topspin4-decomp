/* R6: net parameter-block parsing (Swing_DLL.xex 0x889xxxxx). */
typedef unsigned int u32;
typedef unsigned long long u64;

typedef struct Ts4NetParamEntry {
    u32 key;
    u32 pad4[3];
    u32 value;
    u32 value_ptr;
} Ts4NetParamEntry; /* 0x18 bytes */

typedef struct Ts4NetParamSource {
    u32 pad0[15];
    u32 base_a;       /* 0x3c */
    u32 base_b;       /* 0x40 */
    u32 size_a;       /* 0x44 */
    u32 size_b;       /* 0x48 */
    u32 entry_count;  /* 0x4c */
    u32 pad50;
    Ts4NetParamEntry *entries; /* 0x54 */
} Ts4NetParamSource;

typedef struct Ts4NetParamDest {
    u32 pad0[2];
    u32 pad8[16];
    u32 sum_a;        /* 0x48 */
    u32 sum_b;        /* 0x4c */
    u32 pad50[0x84 / 4 - 0x50 / 4];
    u32 sum_c;        /* 0x84 */
    u32 copy_a;       /* 0x88 */
} Ts4NetParamDest;

typedef struct Ts4NetParamOut {
    u32 pad[16];
    u64 value;        /* 0x40 */
} Ts4NetParamOut;

struct Ts4NetParamHandler;
typedef struct Ts4NetParamHandlerVtbl {
    u32 pad[0x1D4 / 4];
    void (*on_param)(struct Ts4NetParamHandler *self, Ts4NetParamDest *dest, u32 key, u32 value);
} Ts4NetParamHandlerVtbl;

typedef struct Ts4NetParamHandler {
    Ts4NetParamHandlerVtbl *vtbl;
} Ts4NetParamHandler;

#ifdef _MSC_VER
extern void *memcpy(void *dst, const void *src, unsigned int size);
#else
#include <string.h>
#endif
void fn_88606108(u32 value_ptr, void *dest_field);

/* Swing_DLL.xex 0x889954E8: derive layout sums into dest and dispatch each keyed entry. */
void ts4_net_parse_param_block_889954E8(
    Ts4NetParamHandler *handler,
    Ts4NetParamSource *source,
    Ts4NetParamDest *dest,
    Ts4NetParamOut *out)
{
    u32 index;

    dest->sum_a = source->base_a + source->size_a;
    dest->sum_b = source->base_b + source->size_b;
    dest->sum_c = source->size_b + source->size_a;
    dest->copy_a = source->base_a;
    if (out != 0) {
        memcpy(out, source, 0x3C);
    }
    for (index = 0; index < source->entry_count; index++) {
        Ts4NetParamEntry *entry = (Ts4NetParamEntry *)((char *)source->entries + index * 0x18);

        switch (entry->key) {
        case 0x20008107:
            if (out != 0) {
                out->value = *(u64 *)&entry->value;
            }
            break;
        case 0x40008109:
            fn_88606108(entry->value_ptr, (char *)dest + 8);
            break;
        default:
            handler->vtbl->on_param(handler, dest, entry->key, entry->value);
            break;
        }
    }
}
