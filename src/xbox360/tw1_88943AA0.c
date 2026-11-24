/* Swing_DLL.xex 0x88943AA0: find entry by name in the 0x30-stride table at p1c+0x30 (twin ts4_find_by_name_88943978 with stride 0x60) */
typedef unsigned char u8;
extern int strcmp(const char *, const char *);
#ifdef _MSC_VER
#pragma intrinsic(strcmp)
#endif
#ifdef _MSC_VER
#define CX37_INL static __forceinline
#else
#define CX37_INL static inline
#endif

typedef struct Cx37Hdr { int off; int cnt; } Cx37Hdr;
typedef struct Cx37Nm30 { u8 pad[0x28]; int noff; u8 pad2[4]; } Cx37Nm30;
typedef struct Cx37Own1c { u8 pad[0x1c]; char *p1c; } Cx37Own1c;
extern u8 lbl_880C1320[];
extern void *ts4_offset_array_end48_88160B88(Cx37Hdr *h);

CX37_INL Cx37Nm30 *nm30_begin(Cx37Hdr *h)
{
    Cx37Nm30 *r = 0;
    if (h->off != -1)
        r = (Cx37Nm30 *)((char *)h + h->off);
    return r;
}

Cx37Nm30 *ts4_find_by_name_88943AA0(Cx37Own1c *o, const char **name)
{
    Cx37Nm30 *p;
    Cx37Nm30 *end;
    Cx37Hdr *h;
    if (o->p1c == 0)
        return 0;
    h = (Cx37Hdr *)(o->p1c + 0x30);
    p = nm30_begin(h);
    end = (Cx37Nm30 *)ts4_offset_array_end48_88160B88(h);
    for (; p != end; p++) {
        const char *s;
        if (p->noff != -1)
            s = (const char *)&p->noff + p->noff;
        else
            s = (const char *)lbl_880C1320;
        if (strcmp(*name, s) == 0)
            return p;
    }
    return 0;
}
