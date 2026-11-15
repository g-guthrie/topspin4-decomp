/* CW4 part b. Built with /Oc. */
typedef unsigned int u32;
typedef unsigned char u8;
#ifdef _MSC_VER
extern void *memcpy(void *, const void *, unsigned int);
#else
#include <string.h>
#endif
#ifdef _MSC_VER
#define CW4_INL static __forceinline
#else
#define CW4_INL static inline
#endif

extern void *lbl_880D620C[];
extern void *lbl_880F31D8[];

/* Typed reads from a buffered stream: if the span [pos,pos+0x14) is not mapped, read through slot 14 into a local, else map and load. */
struct Cw4Stream;
typedef struct Cw4StreamVt {
    void *s[9];
    void *(*map)(struct Cw4Stream *, void *, u32, u32);
    void *s2[2];
    u32 (*can_map)(struct Cw4Stream *, u32, u32);
    void *s3;
    void (*read)(struct Cw4Stream *, void *, u32, void *, u32, void *);
} Cw4StreamVt;
typedef struct Cw4Stream { const Cw4StreamVt *vt; } Cw4Stream;
typedef struct Cw4Reader { Cw4Stream *stream; u32 pos; } Cw4Reader;

/* 0x88177AC0: read one byte */
u8 ts4_reader_read_u8_88177AC0(Cw4Reader *r)
{
    u8 value;
    void *tag;
    u8 ok = (u8)r->stream->vt->can_map(r->stream, r->pos, 0x14);
    if (ok == 0) {
        tag = lbl_880D620C;
        r->stream->vt->read(r->stream, r, r->pos, &value, 1, &tag);
        return value;
    }
    return *(u8 *)r->stream->vt->map(r->stream, r, r->pos, 1);
}

/* 0x88177B78: read one 16-bit value */
typedef unsigned short u16;
u16 ts4_reader_read_u16_88177B78(Cw4Reader *r)
{
    u16 value;
    void *tag;
    u8 ok = (u8)r->stream->vt->can_map(r->stream, r->pos, 0x14);
    if (ok == 0) {
        tag = lbl_880F31D8;
        r->stream->vt->read(r->stream, r, r->pos, &value, 2, &tag);
        return value;
    }
    return *(u16 *)r->stream->vt->map(r->stream, r, r->pos, 2);
}


/* 0x8818B650 / 0x8818BB88: allocate a 0x14-byte object through fn_88199068 (size 1000 request record), clear its fields, set vtable */
extern void *fn_88199068(void *a, u32 size, void *req);
extern void *lbl_880DD0A0[];
extern void *lbl_880DD110[];
typedef struct Cw4Obj14 { void **vtbl; u32 f4; u32 f8; u8 fc; u8 pad[3]; u32 f10; } Cw4Obj14;
Cw4Obj14 *ts4_create_obj14_8818B650(void)
{
    Cw4Obj14 *r = 0;
    u32 req[2];
    volatile Cw4Obj14 *p;
    req[0] = 1000;
    req[1] = 0;
    p = (volatile Cw4Obj14 *)fn_88199068(0, 0x14, req);
    if (p != 0) {
        p->f4 = 0;
        p->f8 = 0;
        p->fc = 0;
        p->vtbl = lbl_880DD0A0;
        p->f10 = 0;
        r = (Cw4Obj14 *)p;
    }
    return r;
}
Cw4Obj14 *ts4_create_obj14_8818BB88(void)
{
    Cw4Obj14 *r = 0;
    u32 req[2];
    Cw4Obj14 *p;
    req[0] = 1000;
    req[1] = 0;
    p = (Cw4Obj14 *)fn_88199068(0, 0x14, req);
    if (p != 0) {
        p->f4 = 0;
        p->f8 = 0;
        p->fc = 0;
        p->f10 = 0;
        p->vtbl = lbl_880DD110;
        r = p;
    }
    return r;
}

/* 0x8818C0C0: like ts4_lookup_8818BEE8 but returns a bool and sets the failed flag when work is pending */
typedef struct Cw4Lookup2 { u8 pad[0xc]; u8 failed; u8 pad2[3]; void *target; } Cw4Lookup2;
extern void *fn_88566220(void *a, void *b, void *c);
extern int ts4_if_call_seq_u32_offc_88565B10(void *p);
extern void ts4_tailcall_fn_88565BA8_88565CD8(void *p);
u32 ts4_lookup_ok_8818C0C0(Cw4Lookup2 *self, void *a, void *b)
{
    void *r = fn_88566220(a, b, self->target);
    if (r == 0 && ts4_if_call_seq_u32_offc_88565B10(self->target) == 0) {
        ts4_tailcall_fn_88565BA8_88565CD8(self->target);
        return 0;
    }
    if (ts4_if_call_seq_u32_offc_88565B10(self->target) != 0) self->failed = 1;
    return r != 0;
}

/* 0x88177110: vector erase at the end of 0x28-byte entries (nothing to move), destroys [dest,end) */
extern void fn_88150600(void *dst, void *src);
extern void fn_881BD170(void *dst, void *src);
extern void ts4_destroy_ent28_range_88177288(void *begin, void *end);
typedef struct Cw4VEnt28 { u32 w0; u32 w4; u8 text[0xc]; u32 w14; u8 body[0xc]; u8 b24; u8 pad[3]; } Cw4VEnt28;
typedef struct Cw4VVec28 { Cw4VEnt28 *begin; Cw4VEnt28 *end; } Cw4VVec28;
void ts4_vec28_trim_88177110(Cw4VVec28 *v)
{
    Cw4VEnt28 *dest = v->begin;
    Cw4VEnt28 *src = v->end;
    int n = v->end - src;
    for (; n > 0; --n) {
        dest->w0 = src->w0;
        dest->w4 = src->w4;
        fn_88150600(dest->text, src->text);
        dest->w14 = src->w14;
        fn_881BD170(dest->body, src->body);
        dest->b24 = src->b24;
        src++;
        dest++;
    }
    ts4_destroy_ent28_range_88177288(dest, v->end);
    v->end = dest;
}

/* 0x8818B2F0: grow a heap buffer in steps of +0x10 until it holds at least `want` bytes, copying old contents */
extern void fn_881992A8(void *a, void *p);
typedef struct Cw4GrowBuf { u8 pad[0x10]; u32 step; u32 pad1; u32 size; u32 pad2; void *data; } Cw4GrowBuf;
void ts4_growbuf_reserve_8818B2F0(Cw4GrowBuf *b, u32 want)
{
    u32 n = b->size;
    if (n < want) {
        void *p;
        u32 req[2];
        u32 req2[2];
        do {
            n += b->step;
        } while (n < want);
        if (b->data == 0) {
            req[0] = 1000;
            req[1] = 0;
            p = fn_88199068(0, n, req);
        } else {
            req2[0] = 1000;
            req2[1] = 0;
            p = fn_88199068(0, n, req2);
            memcpy(p, b->data, b->size);
            if (b->data != 0) fn_881992A8(0, b->data);
        }
        b->data = p;
        b->size = n;
    }
}

/* 0x88173D98: std::find over a char range (four-way unrolled main loop, remainder by switch) */
char *ts4_find_char_88173D98(char *first, char *last, char value)
{
    int n = (last - first) >> 2;
    for (; n > 0; --n, ++first) {
        if (*first == value) return first;
        ++first;
        if (*first == value) return first;
        ++first;
        if (*first == value) return first;
        ++first;
        if (*first == value) return first;
    }
    switch (last - first) {
    case 3:
        if (*first == value) return first;
        ++first;
    case 2:
        if (*first == value) return first;
        ++first;
    case 1:
        if (*first == value) return first;
    case 0:
    default:
        break;
    }
    return last;
}



/* 0x8817ED58: vector<word>::insert(pos, &value); grows through fn_8817F4E8 when full; returns an iterator to the new element */
extern void ts4_destroy_owned_object(void *obj);
extern void *fn_88562DC0(void *dst, void *src, u32 n);
extern void fn_8817F4E8(void *v, u32 *pos, u32 *val, u32 n);
typedef struct Cw4WVec { u32 *begin; u32 *end; u32 *cap; } Cw4WVec;
u32 *ts4_wvec_insert_8817ED58(Cw4WVec *v, u32 *pos, u32 *val)
{
    int idx = pos - v->begin;
    if (v->end != v->cap) {
        if (pos == v->end) {
            if (v->end != 0) *v->end = *val;
            ++v->end;
        } else {
            u32 *end = v->end;
            u32 copy;
            int n;
            if (end != 0) *end = end[-1];
            ++v->end;
            copy = *val;
            n = ((char *)v->end - (char *)pos) - 8;
            if (n > 0) fn_88562DC0((char *)v->end - n - 4, pos, n);
            *pos = copy;
        }
    } else {
        fn_8817F4E8(v, pos, val, 0);
    }
    return v->begin + idx;
}
