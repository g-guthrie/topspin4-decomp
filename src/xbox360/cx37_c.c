/* CX37: offset-array finds, text accessors and loops, Swing_DLL.xex 0x8894xxxx-0x8895xxxx. */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
#ifdef _MSC_VER
#define CX37_INL static __forceinline
#else
#define CX37_INL static inline
#endif

typedef struct Cx37Hdr { int off; int cnt; } Cx37Hdr;
typedef struct Cx37E44 { u8 pad[0x24]; int k; u32 k2; } Cx37E44;
extern void *ts4_offset_array_end44_88160B30(Cx37Hdr *h);
extern void fn_889578D0(void *p, int a);

/* 0x889579D0: act on the entry whose (key, key2) pair equals the arguments */
void ts4_array44_act_889579D0(Cx37Hdr *h, u32 a, u32 b)
{
    Cx37E44 *p = 0;
    Cx37E44 *end;
    if (h->off != -1)
        p = (Cx37E44 *)((char *)h + h->off);
    end = (Cx37E44 *)ts4_offset_array_end44_88160B30(h);
    for (; p != end; p++) {
        if ((u32)p->k == a && p->k2 == b) {
            fn_889578D0(p, 1);
            return;
        }
    }
}

#if 0 /* near miss, not byte-identical */
typedef struct Cx37E60 { u8 pad[0x48]; int k; u8 pad2[0x14]; } Cx37E60;
extern char *lbl_88D458C0;
CX37_INL Cx37E60 *e60_begin(Cx37Hdr *h)
{
    Cx37E60 *r = 0;
    if (h->off != -1)
        r = (Cx37E60 *)((char *)h + h->off);
    return r;
}
CX37_INL Cx37E60 *e60_end(Cx37Hdr *h)
{
    Cx37E60 *r = 0;
    if (h->off != -1)
        r = (Cx37E60 *)((char *)h + (h->cnt * 0x60 + h->off));
    return r;
}
/* 0x889422F8: find the 0x60-byte entry with key at +0x48 in the self-relative table at +0x18 of the global */
Cx37E60 *ts4_find_e60_889422F8(int key)
{
    Cx37Hdr *h = (Cx37Hdr *)(lbl_88D458C0 + 0x18);
    Cx37E60 *p = e60_begin(h);
    Cx37E60 *e = e60_end(h);
    for (; p != e; p++)
        if (p->k == key)
            return p;
    return 0;
}
#endif
