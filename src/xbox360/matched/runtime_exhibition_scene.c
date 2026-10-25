/*
 * Swing_DLL.xex, executable version 0.0.0.3.
 * Functions in this file compile to exact objdiff matches with the Xbox 360
 * compiler (see docs/matching-build.md). They were written from the disassembly
 * of the retail module with AI assistance; names, types and field roles are
 * reconstructions, and each function states its address range.
 */
#include "typed_handle.h"

typedef unsigned char ts4_u8;
typedef unsigned int ts4_u32;
typedef int ts4_s32;

extern void *lbl_88D45B1C;
extern void *lbl_88D45A60;
extern void *lbl_88D41FC4;
extern ts4_u32 lbl_88C6C014;
extern ts4_u32 lbl_88C6C05C;
extern float g_ts4_event_value;          /* 0x8814B440 */
extern double g_ts4_script_constants[];  /* 0x880D0F70; read here as a float at +0 */
extern const char lbl_880EE76C[];
extern const char lbl_880E4EA0[];
extern const void *const lbl_880E4880[];
extern const void *const lbl_880F8188[];
extern const void *const lbl_880F814C[];

void ts4_memset(void *destination, int value, ts4_u32 size);
void ts4_format_text(char *buffer, ts4_u32 size, const char *format, const char *text, ts4_u32 value);
void *fn_88617D88(void *object);
void fn_88617D28(void *object);
void fn_8862B028(void *object, const char *path, ts4_u32 key, ts4_u32 player);
ts4_u8 *fn_88626AE8(void *object, const char *path, ts4_u32 key, ts4_u32 type, ts4_u32 a, ts4_u32 b, ts4_u32 c,
    ts4_u32 d, ts4_u8 e, ts4_u32 player, ts4_u8 f);
ts4_u8 *fn_887F4BA0(ts4_u8 *self);
ts4_u32 fn_887CEF00(ts4_u8 *self, ts4_u8 *entry);
void fn_887E24B8(ts4_u8 *entry);
void fn_886A6860(void *item);
void fn_887D97C8(ts4_u8 *self);
void fn_887E3420(ts4_u8 *self);
void fn_887E72E0(ts4_u8 *self, ts4_u32 zero);
void fn_887E9018(ts4_u8 *self);
void fn_887E5538(ts4_u8 *self);
void fn_887CEB60(ts4_u8 *self, ts4_u8 *entry);
void fn_887CEDD0(ts4_u8 *self);
void fn_887DAA58(ts4_u8 *self);
void fn_887DD428(ts4_u8 *self);
void fn_887E7CD0(ts4_u8 *self);
ts4_u32 fn_887E8FB0(ts4_u8 *self);
void fn_887BD000(ts4_u8 *self);
void fn_882125E0(ts4_u8 *member, ts4_u8 *view);
void fn_8816CAA0(ts4_u8 *member, const char *name);
void fn_887BE998(ts4_u8 *self, const char *name, const ts4_u32 *key, ts4_u32 a, ts4_u32 b, ts4_u32 c, ts4_u32 d,
    float weight);
void fn_887E41E8(ts4_u8 *self);
void fn_888E7498(ts4_s32 slot);
void fn_887DBFD0(void *result, ts4_typed_handle handle, ts4_s32 index, ts4_u32 one);

typedef ts4_u32 (*ts4_slot_self)(void *self);

/*
 * 0x8888A658-0x8888A70C (5 direct callers): with `key` spilled to the frame,
 * calls slots +0x34(self, &key), +0x28(self, &key, arg, 0, 0, 0),
 * +0x2C(self, &key) and +0x3C(self, &key, value in f1). At the first call
 * r5 and f1 still hold `arg` and `value`; whether slot +0x34 reads them is
 * UNRESOLVED (virtual target).
 */
typedef void (*ts4_key_slot)(void *self, ts4_u32 *key);
typedef void (*ts4_key_slot_args)(void *self, ts4_u32 *key, ts4_u32 arg, ts4_u32 a, ts4_u32 b, ts4_u32 c);
typedef void (*ts4_key_slot_value)(void *self, ts4_u32 *key, double value);

void ts4_runtime_keyed_update_8888a658(void *self, ts4_u32 key, ts4_u32 arg, double value)
{
    ((ts4_key_slot)(*(void ***)self)[0x34 / 4])(self, &key);
    ((ts4_key_slot_args)(*(void ***)self)[0x28 / 4])(self, &key, arg, 0, 0, 0);
    ((ts4_key_slot)(*(void ***)self)[0x2C / 4])(self, &key);
    ((ts4_key_slot_value)(*(void ***)self)[0x3C / 4])(self, &key, value);
}

/* The self-relative array of 180-byte scene entries at +0x1C0 of the +0xA8 object. */
static void ts4_scene_entries(ts4_u8 *self, ts4_u8 **begin, ts4_u8 **end)
{
    ts4_u8 *header = *(ts4_u8 **)(self + 0xA8) + 0x1C0;
    ts4_s32 offset = *(ts4_s32 *)header;
    *begin = offset != -1 ? header + offset : 0;
    *end = offset != -1 ? header + offset + *(ts4_u32 *)(header + 4) * 180 : 0;
}

/*
 * 0x887E5538-0x887E5700 (1 direct caller): when byte +0x1CC of the +0xA8
 * state is set: scans the 36-byte entries of the self-relative array at
 * +0x44 of the +0x104 object, noting whether any has byte +4 clear and
 * clearing self byte +0x44 + i for the others; state byte +0x1CD = that
 * note; byte +0x1CC = (+0x1CD or +0x1CE set). When +0x1CC ends clear: a
 * temporary object (0x88617D88; first word lbl_880F814C) receives
 * 0x88626AE8(object, lbl_880E4EA0, 0x5F1D4916, 0x6A44C9C9, 0, 1, 1, 1,
 * 1, player word +0x27C of lbl_88D45B1C, 1), stored at +0x370; when it is
 * not null, its slot +0x64 gets a descriptor {1, 0xBC959F53, 0x20000, 1,
 * 0xF020B8C2, 0, 0} (bytes at +0 and +0xC) and 0; then 0x887E41E8(self),
 * 0x888E7498(-1), and the object is destroyed (0x88617D28) with its first
 * word set to lbl_880F814C again. The 9th and 11th arguments are bytes in
 * the stack parameter area.
 */
typedef struct ts4_scene_request {
    ts4_u8 enabled;     /* +0x00 */
    ts4_u8 pad0[3];
    ts4_u32 type;       /* +0x04 */
    ts4_u32 size;       /* +0x08 */
    ts4_u8 visible;     /* +0x0C */
    ts4_u8 pad1[3];
    ts4_u32 key;        /* +0x10 */
    ts4_u32 zero_a;     /* +0x14 */
    ts4_u32 zero_b;     /* +0x18 */
} ts4_scene_request;

typedef void (*ts4_request_slot)(void *self, ts4_scene_request *request, ts4_u32 zero);

/*
 * 0x887DC2D0-0x887DC334 (2 direct callers): 0x887DBFD0(result, handle,
 * -1, 1) for the four 12-byte handles at +0x28C, then 0x887DBFD0(result2,
 * handle at +0x250, 0, 1). Each handle is passed by value (r4 and the upper
 * half of r5).
 */
void ts4_runtime_refresh_handles_887dc2d0(ts4_u8 *self)
{
    ts4_u32 result[4], result2[4];
    int i;
    for (i = 0; i < 4; i++) {
        fn_887DBFD0(result, *(ts4_typed_handle *)(self + 0x28C + 12 * i), -1, 1);
    }
    fn_887DBFD0(result2, *(ts4_typed_handle *)(self + 0x250), 0, 1);
}
