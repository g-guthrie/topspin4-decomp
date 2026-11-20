/* Twin of 0x88943978 (ts4_find_by_name_88943978 in src/xbox360/cx37_g.c). Element stride 0x30. */
#ifdef _MSC_VER
#define CX37_INL static __forceinline
#else
#define CX37_INL static inline
#endif
typedef unsigned char u8;
typedef unsigned int u32;
#ifdef _MSC_VER
extern int strcmp(const char *, const char *);
#pragma intrinsic(strcmp)
#else
int strcmp(const char *, const char *);
#endif
typedef struct Cx37Hdr { int off; int cnt; } Cx37Hdr;
typedef struct Cx37Nm48 { u8 pad[0x10]; int noff; u8 pad2[0x30 - 0x14]; } Cx37Nm48;
typedef struct Cx37Own1c { u8 pad[0x1c]; char *p1c; } Cx37Own1c;
extern u8 lbl_880C1320[];
extern void *ts4_offset_array_end48_88160B88(Cx37Hdr *h);
CX37_INL Cx37Nm48 *nm48_begin(Cx37Hdr *h)
{
    Cx37Nm48 *r = 0;
    if (h->off != -1)
        r = (Cx37Nm48 *)((char *)h + h->off);
    return r;
}
Cx37Nm48 *ts4_find_by_name_88943B70(Cx37Own1c *o, const char **name)
{
    Cx37Nm48 *p;
    Cx37Nm48 *end;
    Cx37Hdr *h;
    if (o->p1c == 0)
        return 0;
    h = (Cx37Hdr *)(o->p1c + 0x3c);
    p = nm48_begin(h);
    end = (Cx37Nm48 *)ts4_offset_array_end48_88160B88(h);
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
