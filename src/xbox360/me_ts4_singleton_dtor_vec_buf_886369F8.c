/* Swing_DLL.xex 0x886369F8: singleton destructor; sets the vtable, clears the instance pointer, destroys the item range [+0x28, +0x2c),
 * frees the buffers at +0x28 and +0x1c when non-null, then the base destructor. agO: plain route only (LTCG folds the static, as 889561F8). */
extern char lbl_880F7F90[];
typedef struct Item Item;
extern void ts4_loop_call_seq_u32_off4_88282DF0(Item *first, Item *last);
extern void ts4_destroy_owned_object(void *obj);
extern void ts4_if_call_seq_lbl_880F7EE4_88617D28(void *self);
/* File-static singleton instance pointer of the original translation unit. */
static void *lbl_88D45B28;

typedef struct Vec { Item *first; Item *last; Item *cap; } Vec;
typedef struct Obj { void *vtbl; char pad[0x18]; void *buf1c; char pad2[8]; Vec items; } Obj;

static __inline void vec_dtor(Vec *v)
{
    ts4_loop_call_seq_u32_off4_88282DF0(v->first, v->last);
    if (v->first)
        ts4_destroy_owned_object(v->first);
}

void fn_886369F8(Obj *self)
{
    self->vtbl = lbl_880F7F90;
    lbl_88D45B28 = 0;
    vec_dtor(&self->items);
    if (self->buf1c)
        ts4_destroy_owned_object(self->buf1c);
    ts4_if_call_seq_lbl_880F7EE4_88617D28(self);
}
