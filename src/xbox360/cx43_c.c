/* CX43 part c: net/lobby helpers, Swing_DLL.xex 0x889Axxxx-0x889Bxxxx. */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
#ifdef _MSC_VER
#define CX43_INL static __forceinline
#else
#define CX43_INL static inline
#endif
typedef struct Cx43Sess { u8 pad[0x68]; u8 *p68; } Cx43Sess;
extern Cx43Sess *g_ts4_session_context;
typedef struct Cx43Cfg { u8 pad[0x275]; u8 b275; u8 pad1[2]; u32 w278; u32 w27c; } Cx43Cfg;
extern Cx43Cfg *lbl_88D45B1C;

/* 0x889A0CA8 */
extern void *fn_88617D88(void *o);
extern char lbl_880D24B8[];
typedef struct Cx43O0c { void *vt; u8 pad[0x18]; u32 w1c, w20, w24, w28; } Cx43O0c;
#if 0 /* near miss, not byte-identical */
void *ts4_ctor_889A0CA8(Cx43O0c *o)
{
    fn_88617D88(o);
    o->w1c = 0;
    o->w20 = 0;
    o->w24 = 0;
    o->vt = lbl_880D24B8;
    o->w28 = lbl_88D45B1C->w27c;
    return o;
}
#endif

/* 0x889B12C0 */
extern void *fn_889395D8(void *src, u32 *dst);
extern void fn_889AFE48(void *e, void *a);
typedef struct Cx43L50c { u8 pad[0x42c]; u8 e[0x38]; } Cx43L50c;
void ts4_load_entries_889B12C0(u8 *self, void *a)
{
    u32 i;
    u8 *e;
    fn_889395D8(a, (u32 *)(self + 0x50c));
    i = 0;
    if (*(u32 *)(self + 0x50c) > 0) {
        e = self + 0x42c;
        do {
            fn_889AFE48(e, a);
            i++;
            e += 0x38;
        } while (i < *(u32 *)(self + 0x50c));
    }
}

/* 0x889BD8B0 */
typedef struct Cx43Row { u16 id; u16 flag; u32 pad; void *(*fn)(void *); } Cx43Row;
extern Cx43Row lbl_880C6C00[];
#if 0 /* near miss, not byte-identical */
void *ts4_dispatch_889BD8B0(u8 *self)
{
    u32 i;
    u32 id = (u32)((self[10] << 8) | self[11]);
    u32 fl = *(u16 *)(self + 8);
    Cx43Row *r = lbl_880C6C00;
    for (i = 0; i < 0x54; i++) {
        if ((u16)id == r->id && r->flag == (fl & 1))
            return r->fn(self);
        r++;
    }
    return self;
}
#endif

/* 0x889BCB10 */
typedef struct Cx43Wait { u8 pad[0xc]; void **obj; u8 pad1[0x270 - 0x10]; u32 w270; u8 pad2[4]; int w278; } Cx43Wait;
void ts4_wait_889BCB10(u8 *self)
{
    Cx43Wait *w;
    if (lbl_88D45B1C->b275 == 0) {
        w = (Cx43Wait *)(self + 4);
        while (lbl_88D45B1C->b275 == 0) {
            if (w->w278 != 4)
                w->w278 = 2;
            w->w270 = w->w270 + 1;
            ((void (*)(void *))(*(void ***)w->obj)[2])(w->obj);
        }
    }
}

/* 0x889A0478 */
typedef struct Cx43Grid { int *tab; int pad; int n; } Cx43Grid;
u32 ts4_grid_valid_889A0478(Cx43Grid *g)
{
    int i, j;
    int n = g->n;
    if ((u32)n != 0) {
        for (i = 0; i < n; i++) {
            for (j = i + 1; j < n; j++) {
                if (g->tab[i * 8 + j - 1] == (int)0x80000000)
                    return 0;
            }
        }
        return 1;
    }
    return 0;
}

/* 0x889A0BE8 */
extern void *ts4_find_entry_by_alt_id_88866C30(u32 id, u8 *tab);
#if 0 /* near miss, not byte-identical */
u32 ts4_find_alt_value_889A0BE8(u8 *self)
{
    u8 *p = *(u8 **)(self + 0x24) + 0x214;
    u8 *h = p + *(int *)p;
    u32 r = 0;
    u8 *e = (u8 *)ts4_find_entry_by_alt_id_88866C30(*(u32 *)(h + 0x30), g_ts4_session_context->p68 + 0x13c0);
    if (e)
        r = *(u32 *)(e + 0xa8);
    return r;
}
#endif
