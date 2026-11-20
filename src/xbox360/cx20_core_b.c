/* CX20 part b: game core (0x881655A0-0x881732E0): small helpers. */
typedef unsigned int u32;
typedef unsigned char u8;
#ifdef _MSC_VER
extern int strcmp(const char *, const char *);
#pragma intrinsic(strcmp)
#else
#include <string.h>
#endif

extern void ts4_destroy_owned_object(void *obj);
extern const char lbl_880C1320[];

/* 0x8816C440: compare a string with the object's self-relative name (default name when the offset is -1) */
typedef struct Cx20RelName { int off; } Cx20RelName;
int ts4_relname_equals_8816C440(Cx20RelName *self, const char *s)
{
    const char *name;
    if (self->off != -1) name = self->off + (char *)self;
    else name = lbl_880C1320;
    return strcmp(s, name) == 0;
}

/* 0x8816C208: destroy the owned object of both slots, last first */
typedef struct Cx20Slot { u8 pad0[8]; void *obj; u8 pad[0x14 - 0xc]; } Cx20Slot;
typedef struct Cx20Slots2 { Cx20Slot s[2]; } Cx20Slots2;
void ts4_destroy_slots2_8816C208(Cx20Slots2 *self)
{
    Cx20Slot *p = &self->s[2];
    int i;
    for (i = 1; i >= 0; i--) {
        --p;
        if (p->obj) ts4_destroy_owned_object(p->obj);
    }
}

/* 0x88165E80: map a byte range through a function (char in, char out) into an output; return the output end */
char *ts4_transform_chars_88165E80(const char *begin, const char *end, char *out, char (*fn)(int))
{
    for (; begin != end; begin++) {
        *out = fn(*begin);
        out++;
    }
    return out;
}


/* 0x8816C198: destroy the owned objects of the two slots at +0x3C, the object at +0x30, then the two slots at +0 */
typedef struct Cx20Own3 { Cx20Slot b[2]; void *x28[2]; void *x30; u32 pad34[2]; Cx20Slot a[2]; } Cx20Own3;
void ts4_destroy_owned_3_8816C198(Cx20Own3 *self)
{
    Cx20Slot *p = &self->a[2];
    int i;
    for (i = 1; i >= 0; i--) {
        --p;
        if (p->obj) ts4_destroy_owned_object(p->obj);
    }
    if (self->x30) ts4_destroy_owned_object(self->x30);
    p = &self->b[2];
    for (i = 1; i >= 0; i--) {
        --p;
        if (p->obj) ts4_destroy_owned_object(p->obj);
    }
}

/* 0x88166178: destroy a range of 0x30-byte records: three owned objects, a sub-range, then the owned object at +0 */
typedef struct Cx20Rec30 { void *a0; u32 a4; u32 pad8; void *oc; u32 pad10, pad14; void *o18; u32 pad1c, pad20; void *o24; u32 pad28, pad2c; } Cx20Rec30;
extern void ts4_loop_call_seq_u32_off18_88165F68(void *begin, u32 end);
void ts4_destroy_rec30_range_88166178(Cx20Rec30 *first, Cx20Rec30 *last)
{
    Cx20Rec30 *e = last;
    Cx20Rec30 *p = first;
    for (; p != e; p++) {
        ts4_destroy_owned_object(p->o24);
        ts4_destroy_owned_object(p->o18);
        ts4_destroy_owned_object(p->oc);
        ts4_loop_call_seq_u32_off18_88165F68(p->a0, p->a4);
        if (p->a0) ts4_destroy_owned_object(p->a0);
    }
}
