/* Swing_DLL.xex 0x886ED0E0-0x886F1770, executable version 0.0.0.3. */
#ifndef _MSC_VER
#define __forceinline inline
#endif
typedef unsigned int u32;
typedef struct { u32 x, y, z; } V3;
extern char *lbl_88D45AD4;



typedef struct { char pad[0xb8]; V3 pos; } Inner_886ED0E0;
static __forceinline V3 ts4_getpos_886ED0E0(Inner_886ED0E0 *s) { return s->pos; }
void ts4_copy_global_vec3_886ED0E0(V3 *out)
{
    *out = ts4_getpos_886ED0E0((Inner_886ED0E0 *)(lbl_88D45AD4 + 0x10));
}

typedef struct { char pad[0xb8]; V3 pos; } Inner_886ED588;
static __forceinline V3 ts4_getpos_886ED588(Inner_886ED588 *s) { return s->pos; }
void ts4_copy_global_vec3_886ED588(V3 *out)
{
    *out = ts4_getpos_886ED588((Inner_886ED588 *)(lbl_88D45AD4 + 0x10));
}

typedef struct { char pad[0xac]; V3 pos; } Inner_886F0578;
static __forceinline V3 ts4_getpos_886F0578(Inner_886F0578 *s) { return s->pos; }
void ts4_copy_global_vec3_886F0578(V3 *out)
{
    *out = ts4_getpos_886F0578((Inner_886F0578 *)(lbl_88D45AD4 + 0x10));
}

typedef struct { char pad[0xac]; V3 pos; } Inner_886F1770;
static __forceinline V3 ts4_getpos_886F1770(Inner_886F1770 *s) { return s->pos; }
void ts4_copy_global_vec3_886F1770(V3 *out)
{
    *out = ts4_getpos_886F1770((Inner_886F1770 *)(lbl_88D45AD4 + 0x10));
}
