/* CX42: net/lobby, scheduler, front end helpers (part 5), Swing_DLL.xex 0x8898xxxx-0x8899xxxx. */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wint-to-pointer-cast"
#pragma clang diagnostic ignored "-Wint-to-void-pointer-cast"
#pragma clang diagnostic ignored "-Wunused-parameter"
#pragma clang diagnostic ignored "-Wunused-macros"
#pragma clang diagnostic ignored "-Wpointer-to-int-cast"
#endif
#define W(o, off) (*(u32 *)((u8 *)(o) + (off)))
#define B(o, off) (*(u8 *)((u8 *)(o) + (off)))
extern u8 *g_ts4_session_context;
extern u8 *lbl_88D45B1C;
extern u8 *ts4_pad_record_find_88614938(u32 a, u32 b);

/* 0x88994CA0: zero n bytes */
void ts4_cx42_zero_bytes_88994CA0(u8 *p, u32 n)
{
    if (n != 0) {
        u32 i = n;
        do { *p++ = 0; } while (--i != 0);
    }
}

/* 0x889975D0: query ten (key, mask) pairs and or together the masks of the ones that are set */
extern u32 fn_8857A410(u32 a, u32 b, u32 *c);
typedef struct Pair { u32 key; u32 mask; } Pair;
extern Pair lbl_880D0E78[];
u32 ts4_cx42_query_mask_889975D0(u32 id)
{
    u32 acc = 0;
    u8 *s = ts4_pad_record_find_88614938(W(lbl_88D45B1C, 0x234), id);
    u32 h;
    u32 i;
    if (s != 0) h = W(s, 0x10); else h = (u32)-1;
    for (i = 0; i < 10; i++) {
        u32 t = 0;
        u32 rc = fn_8857A410(h, lbl_880D0E78[i].key, &t);
        if (rc != 0) {
            if (rc == 0x4dd) return 0;
        } else if ((int)t != 0) acc |= lbl_880D0E78[i].mask;
    }
    return acc;
}

extern void *ts4_memset(void *, int, u32);
extern int fn_884F17D8(u32 a, u32 b, void *c, void *d);
int ts4_cx42_overlapped_88996908(u8 *o, u32 unused, int *out)
{
    u8 *g;
    u8 *s;
    u32 h;
    int r;
    if (W(o, 0x4c) == 0) return 1;
    g = (u8 *)W(g_ts4_session_context, 0x1c);
    if (g == 0) return 1;
    s = ts4_pad_record_find_88614938(W(lbl_88D45B1C, 0x234), 0);
    if (s != 0) h = W(s, 0x10); else h = (u32)-1;
    if (B((u8 *)W(g, 0x14), 0x2c) != 0) ts4_memset(o + 0x54, 0, 0x3c);
    else h = 0xfe;
    r = fn_884F17D8(W(o, 0x4c), h, o + 0x54, o + 0x30);
    *out = r;
    return r != 0x3e5 ? -1 : 0;
}
