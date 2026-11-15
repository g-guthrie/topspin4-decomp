/* CW10 part a: game core 0x8820F390-0x88220C18, small functions. Built with /Oc. */
typedef unsigned int u32;
typedef unsigned char u8;
#ifdef _MSC_VER
extern void *memcpy(void *, const void *, unsigned int);
#else
#include <string.h>
#endif

/* 0x882200D8: vector of 0x10c-byte strings, trim: assign [end..end) over begin (nothing to move), set end */
extern void ts4_byte_string_assign_8816D090(void *dst, void *src);
typedef struct Cw10Ent10c { u8 b[0x10c]; } Cw10Ent10c;
typedef struct Cw10Vec10c { Cw10Ent10c *begin; Cw10Ent10c *end; } Cw10Vec10c;
void ts4_vec10c_trim_882200D8(Cw10Vec10c *v)
{
    Cw10Ent10c *dest = v->begin;
    Cw10Ent10c *src = v->end;
    int n = v->end - src;
    for (; n > 0; --n) {
        ts4_byte_string_assign_8816D090(dest, src);
        src++;
        dest++;
    }
    v->end = dest;
}

/* 0x88216268: find the 0x18-byte record whose id (+0xc) matches, in a self-relative array */
typedef struct Cw10Rec18 { u8 pad[0xc]; int id; u8 pad2[8]; } Cw10Rec18;
typedef struct Cw10RelArr { int off; int count; } Cw10RelArr;
Cw10Rec18 *ts4_find_rec_by_id_88216268(Cw10RelArr *a, const int *id)
{
    Cw10Rec18 *res = 0;
    int i;
    for (i = 0; i < a->count; i++) {
        Cw10Rec18 *r = (Cw10Rec18 *)((char *)a + (i * 0x18 + a->off));
        if (r->id == *id) { res = r; break; }
    }
    return res;
}

/* 0x8820F828 / 0x8820FE68: assignment operators: base assign, counted pointer assign, then a 9-word block copy */
extern void ts4_call_seq_fn_881CE548_881CCE80(void *dst, void *src);
extern void ts4_call_seq_fn_8819B0C8_881CE548(void *dst, void *src);
extern void ts4_counted_ptr_assign_881C38D0(void *dst, void *src);
typedef struct Cw10Blk9 { u32 w[9]; } Cw10Blk9;
typedef struct Cw10AssignA { u8 base[0x34]; u32 ptr; u32 pad; Cw10Blk9 blk; } Cw10AssignA;
void ts4_assign_8820F828(Cw10AssignA *self, Cw10AssignA *src)
{
    ts4_call_seq_fn_881CE548_881CCE80(self, src);
    ts4_counted_ptr_assign_881C38D0(&self->ptr, &src->ptr);
    self->blk = src->blk;
}
typedef struct Cw10AssignB { u8 base[0x20]; Cw10Blk9 blk; u32 ptr; } Cw10AssignB;
void ts4_assign_8820FE68(Cw10AssignB *self, Cw10AssignB *src)
{
    ts4_call_seq_fn_8819B0C8_881CE548(self, src);
    ts4_counted_ptr_assign_881C38D0(&self->ptr, &src->ptr);
    self->blk = src->blk;
}

#ifdef _MSC_VER
#define CW10_INL static __forceinline
#else
#define CW10_INL static inline
#endif
extern void *fn_88562DC0(void *dst, void *src, u32 n);
extern void ts4_destroy_owned_object(void *obj);
typedef struct Cw10Vec { char *first; char *last; } Cw10Vec;
CW10_INL char *cw10_copy(char *first, char *last, char *dest)
{
    if (first == last) {
        return dest;
    } else {
        u32 n = (u32)(last - first);
        dest = (char *)fn_88562DC0(dest, first, n);
        return dest + n;
    }
}

/* 0x88216460: destroy 0x270-byte entries [begin,end): collapse the vector at +0, free its storage */
typedef struct Cw10Ent270 { Cw10Vec vec; u8 pad[0x270 - 8]; } Cw10Ent270;
void ts4_destroy_ent270_range_88216460(Cw10Ent270 *begin, Cw10Ent270 *end)
{
    Cw10Ent270 *p;
    for (p = begin; p != end; p++) {
        Cw10Vec *v = &p->vec;
        v->last = cw10_copy(v->last, v->last, v->first);
        if (p->vec.first) ts4_destroy_owned_object(p->vec.first);
    }
}

/* 0x882164C8: uninitialised copy of 0x214-byte records (class copy plus two trailing words) */
extern void fn_881B2AC8(void *dst, void *src);
typedef struct Cw10Rec214 { u8 b[0x20c]; u32 w20c; u32 w210; } Cw10Rec214;
Cw10Rec214 *ts4_uninit_copy_rec214_882164C8(Cw10Rec214 *first, Cw10Rec214 *last, Cw10Rec214 *dest)
{
    for (; first != last; first++, dest++) {
        if (dest) {
            fn_881B2AC8(dest, first);
            dest->w20c = first->w20c;
            dest->w210 = first->w210;
        }
    }
    return dest;
}

/* 0x88219F18: uninitialised copy of 0x1c-byte records (two text fields and a flag byte) */
extern void ts4_assign_formatted_text(void *dst, void *src);
typedef struct Cw10Str { void *p; u32 pad[2]; } Cw10Str;
typedef struct Cw10Rec1c { Cw10Str t0; Cw10Str t1; u8 flag; u8 pad[3]; } Cw10Rec1c;
Cw10Rec1c *ts4_uninit_copy_rec1c_88219F18(Cw10Rec1c *first, Cw10Rec1c *last, Cw10Rec1c *dest)
{
    for (; first != last; first++, dest++) {
        if (dest) {
            ts4_assign_formatted_text(&dest->t0, first->t0.p);
            ts4_assign_formatted_text(&dest->t1, first->t1.p);
            dest->flag = first->flag;
        }
    }
    return dest;
}

/* 0x882209F0: trim for 0x130-byte entries: copy first word, assign +0x10 sub-object; then destroy [dest,end) */
extern void fn_88258CD8(void *dst, void *src);
extern void fn_88261CA8(void *begin, void *end);
typedef struct Cw10Ent130 { u32 w0; u32 pad[3]; u8 sub[0x120]; } Cw10Ent130;
typedef struct Cw10Vec130 { Cw10Ent130 *begin; Cw10Ent130 *end; } Cw10Vec130;
void ts4_vec130_trim_882209F0(Cw10Vec130 *v)
{
    Cw10Ent130 *dest = v->begin;
    Cw10Ent130 *src = v->end;
    int n = v->end - src;
    for (; n > 0; --n) {
        dest->w0 = src->w0;
        fn_88258CD8(dest->sub, src->sub);
        src++;
        dest++;
    }
    fn_88261CA8(dest, v->end);
    v->end = dest;
}

/* 0x8821FA90: search the byte range for a 7-byte pattern; index or -1 */
extern char lbl_880F0234[];
extern char *fn_88168F08(char *b, char *e, char *p, char *pe);
typedef struct Cw10Range { char *begin; char *end; } Cw10Range;
int ts4_find_pattern_8821FA90(Cw10Range *r)
{
    char *end = r->end;
    char *begin = r->begin;
    if ((u32)(end - begin) >= 7) {
        char *hit = fn_88168F08(begin, end, lbl_880F0234, lbl_880F0234 + 7);
        if (hit != end) return (int)(hit - begin);
    }
    return -1;
}

/* 0x88213CC8: erase one 0x10-byte element: shift the tail down (word + fn_88150600 on the +0xc part), drop the last, destroy its owned object */
extern void fn_88150600(void *dst, void *src);
typedef struct Cw10E10 { u32 w0; void *w4; u32 w8; u32 wc; } Cw10E10;
typedef struct Cw10V10 { u32 pad; Cw10E10 *end; } Cw10V10;
Cw10E10 *ts4_vec10_erase_88213CC8(Cw10V10 *v, Cw10E10 *pos)
{
    Cw10E10 *dest = pos;
    Cw10E10 *src = pos + 1;
    if (src != v->end) {
        int n = v->end - src;
        for (; n > 0; --n) {
            dest->w0 = src->w0;
            fn_88150600(&dest->w4, &src->w4);
            src++;
            dest++;
        }
    }
    v->end--;
    ts4_destroy_owned_object(v->end->w4);
    return pos;
}

/* 0x88220B00: append a zeroed 0x20-byte element (last word = 1), growing through fn_88227B38 when full; returns the new element */
extern void fn_88227B38(void *v, void *end);
typedef struct Cw10Elem20 { u32 w[7]; u32 flag; } Cw10Elem20;
typedef struct Cw10Vec20 { u32 pad; Cw10Elem20 *end; u32 pad2; Cw10Elem20 *cap; } Cw10Vec20;
Cw10Elem20 *ts4_vec20_emplace_88220B00(Cw10Vec20 *v)
{
    if (v->end == v->cap) fn_88227B38(v, v->end);
    if (v->end) {
        Cw10Elem20 *e = v->end;
        e->w[0] = 0;
        e->w[1] = 0;
        e->w[2] = 0;
        e->w[3] = 0;
        e->w[4] = 0;
        e->w[5] = 0;
        e->w[6] = 0;
        e->flag = 1;
    }
    v->end = v->end + 1;
    return v->end - 1;
}

/* 0x88211418: notify the global manager, let the owner's sub-object (+0x14) handle us, then call the manager again */
typedef struct Cw10Mgr { const struct Cw10MgrVt *vt; } Cw10Mgr;
typedef struct Cw10Sub { const struct Cw10SubVt *vt; } Cw10Sub;
typedef struct Cw10Owner { u8 pad[0xc]; u32 wc; u8 pad2[4]; Cw10Sub sub; } Cw10Owner;
typedef struct Cw10Client { u8 pad[0x24]; Cw10Owner *owner; } Cw10Client;
struct Cw10MgrVt { void *s0[9]; void (*f9)(Cw10Mgr *); void *s1[7]; void (*f17)(Cw10Mgr *, u32, Cw10Owner *); };
struct Cw10SubVt { void *s0[11]; void (*f11)(Cw10Sub *, Cw10Client *); };
extern Cw10Mgr *lbl_88D41F80;
void ts4_client_register_88211418(Cw10Client *self)
{
    lbl_88D41F80->vt->f9(lbl_88D41F80);
    self->owner->sub.vt->f11(&self->owner->sub, self);
    lbl_88D41F80->vt->f17(lbl_88D41F80, self->owner->wc, self->owner);
}
