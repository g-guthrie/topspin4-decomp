/* Swing_DLL.xex 0x88478258-0x88483320, executable version 0.0.0.3. */
#ifndef _MSC_VER
#define __forceinline inline
#endif
extern void *lbl_88CACF08;
extern void *KeTlsGetValue(void *idx);
extern void fn_8841A590(void *a, void *p, unsigned n, int tag);
extern void fn_88477610(void *o);
extern void ts4_tailcall_fn_88477610_88479BF8(void *o);
typedef struct Ts4Block88478258 { void *data; int size; unsigned word; } Ts4Block88478258;
typedef struct Ts4Owner88478258 { char pad[0xc0]; Ts4Block88478258 blk; } Ts4Owner88478258;
static __forceinline void ts4_block_release_x88478258(Ts4Block88478258 *b)
{
    int w = b->word;
    if ((w & (int)0x80000000) == 0) {
        void *t = KeTlsGetValue(lbl_88CACF08);
        fn_8841A590(t, b->data, w << 2, 0x17);
    }
    b->data = 0;
    b->size = 0;
    b->word = (b->word & 0x40000000) | 0x80000000;
}
void ts4_free_block_88478258(Ts4Owner88478258 *o)
{
    if (o->blk.size == 0) {
        ts4_block_release_x88478258(&o->blk);
    }
    fn_88477610(o);
}
typedef struct Ts4Block8847A740 { void *data; int size; unsigned word; } Ts4Block8847A740;
typedef struct Ts4Owner8847A740 { char pad[0x150]; Ts4Block8847A740 blk; } Ts4Owner8847A740;
static __forceinline void ts4_block_release_x8847A740(Ts4Block8847A740 *b)
{
    int w = b->word;
    if ((w & (int)0x80000000) == 0) {
        void *t = KeTlsGetValue(lbl_88CACF08);
        fn_8841A590(t, b->data, w << 3, 0x17);
    }
    b->data = 0;
    b->size = 0;
    b->word = (b->word & 0x40000000) | 0x80000000;
}
void ts4_free_block_8847A740(Ts4Owner8847A740 *o)
{
    if (o->blk.size == 0) {
        ts4_block_release_x8847A740(&o->blk);
    }
    ts4_tailcall_fn_88477610_88479BF8(o);
}
typedef struct Ts4Block884832A8 { void *data; int size; unsigned word; } Ts4Block884832A8;
typedef struct Ts4Owner884832A8 { char pad[0x150]; Ts4Block884832A8 blk; } Ts4Owner884832A8;
static __forceinline void ts4_block_release_x884832A8(Ts4Block884832A8 *b)
{
    int w = b->word;
    if ((w & (int)0x80000000) == 0) {
        void *t = KeTlsGetValue(lbl_88CACF08);
        fn_8841A590(t, b->data, w << 2, 0x17);
    }
    b->data = 0;
    b->size = 0;
    b->word = (b->word & 0x40000000) | 0x80000000;
}
void ts4_free_block_884832A8(Ts4Owner884832A8 *o)
{
    if (o->blk.size == 0) {
        ts4_block_release_x884832A8(&o->blk);
    }
    ts4_tailcall_fn_88477610_88479BF8(o);
}
