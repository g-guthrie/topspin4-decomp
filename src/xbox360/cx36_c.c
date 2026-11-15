/* CX36: net/lobby object helpers, Swing_DLL.xex 0x8892xxxx-0x8893xxxx. */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
#ifdef _MSC_VER
#define CX36_INL static __forceinline
#else
#define CX36_INL static inline
#endif

extern void *fn_889395D8(void *s, u32 *v);
extern void *fn_88939840(void *s, u8 *v);
extern void *fn_88938F38(void *s, u8 *buf, int n);
extern void fn_88933C58(void *p);
extern void ts4_if_call_seq_fn_88933EF8_889397D8(void *p, u16 v);
extern void *ts4_find_entry24_88924430(void *tab, u32 key);

typedef struct Cx36Msg {
    u8 pad[0x42c];
    u32 w42c;
    u8 b430;
    u8 b431;
} Cx36Msg;
typedef struct Cx36Msg2 {
    u8 pad[0x42c];
    u32 w42c, w430, w434;
    u8 b438;
} Cx36Msg2;

/* 0x8893DE50: read one u32 from the stream into the message field at +0x42c */
#if 0
CX36_INL u32 cx36_rd_u32(void *stream)
{
    u32 v = 0;
    fn_889395D8(stream, &v);
    return v;
}
#endif
#if 0 /* near miss, not byte-identical */
void ts4_msg_read_u32_8893DE50(Cx36Msg *m, void *stream)
{
    m->w42c = cx36_rd_u32(stream);
}
#endif

#if 0 /* near miss, not byte-identical */
/* 0x8893C908: read one u32 from the stream into *out and return the stream */
void *ts4_stream_read_u32_to_8893C908(void *stream, u32 *out)
{
    *out = cx36_rd_u32(stream);
    return stream;
}
#endif

#if 0 /* near miss, not byte-identical */
/* 0x8893BBD8: read the u32, byte and 256-byte string fields of a message */
void ts4_msg_read_fields_a_8893BBD8(Cx36Msg *m, void *stream)
{
    u8 *name = &m->b431;
    void *s = fn_889395D8(stream, &m->w42c);
    s = fn_88939840(s, &m->b430);
    fn_88938F38(s, name, 0x100);
}
#endif

#if 0 /* near miss, not byte-identical */
/* 0x8893BCB0: read three u32 fields then a 256-byte string */
void ts4_msg_read_fields_b_8893BCB0(Cx36Msg2 *m, void *stream)
{
    void *s = fn_889395D8(stream, &m->w42c);
    u32 *p434 = &m->w434;
    u8 *name = &m->b438;
    s = fn_889395D8(s, &m->w430);
    s = fn_889395D8(s, p434);
    fn_88938F38(s, name, 0x100);
}
#endif

/* 0x88934C88: run the owner's pending action when enabled */
typedef struct Cx36Pend { u8 pad[0x1c]; void *w1c; } Cx36Pend;
u32 ts4_run_pending_88934C88(Cx36Pend *o, u32 enable)
{
    if (enable && o->w1c) {
        fn_88933C58(o->w1c);
        return 1;
    }
    return 0;
}

/* 0x8893B528: copy a u16 into the object, append it to the sequence and round the length up to 8 */
typedef struct Cx36Seq { u8 pad[4]; u32 w4; u32 len; u8 pad2[0x4c4 - 0xc]; u16 h4c4; } Cx36Seq;
#if 0 /* near miss, not byte-identical */
void ts4_seq_append_u16_8893B528(Cx36Seq *o, u16 *v)
{
    u16 x = *v;
    o->h4c4 = x;
    ts4_if_call_seq_fn_88933EF8_889397D8(&o->w4, x);
    o->len = (o->len + 7) & ~7u;
}
#endif

/* 0x88934380: copy a record (name block, three words and a byte) */
#ifdef _MSC_VER
extern void *memcpy(void *, const void *, unsigned);
#pragma function(memcpy)
#else
#include <string.h>
#endif
typedef struct Cx36Rec { u8 pad0[4]; u32 w4; u32 w8; u8 pad[0x21 - 0xc]; u8 name[0x40]; u8 pad2[0x64 - 0x61]; u32 w64; u8 pad3[5]; u8 b6d; } Cx36Rec;
Cx36Rec *ts4_record_copy_88934380(Cx36Rec *dst, Cx36Rec *src)
{
    memcpy(dst->name, src->name, 0x40);
    dst->w4 = src->w4;
    dst->w8 = src->w8;
    dst->w64 = src->w64;
    dst->b6d = src->b6d;
    return dst;
}

/* 0x889227E8: resend the object's pending state through slots 5 and 15 */
typedef struct Cx36Obj { void **vt; u8 pad[0x30]; u32 w34; } Cx36Obj;
typedef void (*Cx36Fn0)(Cx36Obj *o);
typedef void (*Cx36Fn5)(Cx36Obj *o, u32 a, u32 b, u32 c, u32 d, u32 e);
void ts4_resend_state_889227E8(Cx36Obj *o, u32 a)
{
    u32 x = o->w34;
    ((Cx36Fn0)o->vt[5])(o);
    ((Cx36Fn5)o->vt[15])(o, a, x, 0, 0, 0);
}

/* 0x88931008: create via slot 11 with a zero flag, then release through slot 2 and return it */
typedef struct Cx36Made { void **vt; } Cx36Made;
typedef Cx36Made *(*Cx36MakeFn)(Cx36Obj *o, u32 a, u32 b, u8 *flag);
typedef void (*Cx36RelFn)(Cx36Made *m);
Cx36Made *ts4_make_and_touch_88931008(Cx36Obj *o, u32 a, u32 b)
{
    u8 flag = 0;
    Cx36Made *m = ((Cx36MakeFn)o->vt[11])(o, a, b, &flag);
    if (m)
        ((Cx36RelFn)m->vt[2])(m);
    return m;
}

/* 0x88936A90: read one bit at the stream's bit cursor */
typedef struct Cx36Bits { void **vt; u8 pad[4]; u32 pos; } Cx36Bits;
typedef u8 *(*Cx36DataFn)(Cx36Bits *b);
#if 0 /* near miss, not byte-identical */
Cx36Bits *ts4_bits_read_bit_88936A90(Cx36Bits *b, u8 *out)
{
    u32 pos = b->pos;
    u8 *data = ((Cx36DataFn)b->vt[3])(b);
    int n;
    *out = (data[pos >> 3] >> (b->pos & 7)) & 1;
    n = b->pos + 1;
    if (n >= 0)
        b->pos = n;
    return b;
}
#endif
