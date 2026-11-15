/* CX45 part b: Pam Display renderer helpers (0x88700000-0x88720000), plain route, no flags. */
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned short u16;
#ifdef _MSC_VER
#define CX45_INL static __forceinline
#else
#define CX45_INL static inline
#endif
#define W(p, o) (*(u32 *)((char *)(p) + (o)))
#define B(p, o) (*(u8 *)((char *)(p) + (o)))
extern void fn_8870FE00(char *self, char *ev);
extern void fn_886FAD58(char *self);
/* 0x887084A8 */
void ts4_setup_pages_887084A8(char *self)
{
    u32 q;
    u32 r;
    u32 cnt;
    char *base;
    u32 zero;
    fn_886FAD58(self);
    zero = 0;
    cnt = zero;
    if (*(int *)(self + 0x48) != -1) {
        if ((u8)((u32 (*)(char *))(*(void ***)self)[10])(self)) cnt = *(u16 *)(self + 0x92);
    }
    base = *(char **)(self + 0x80);
    W(self, 0x50) = cnt;
    W(self, 0x70) = zero;
    W(self, 0x74) = zero;
    W(self, 0x78) = zero;
    *(char **)(self + 0x54) = base;
    if (cnt != 0) {
        u32 i;
        q = cnt >> 5;
        r = cnt & 31;
        for (i = 0; i < q; i++) W(base + i * 0x1000, 0x70) = 0x20;
        if (r != 0) W(base + (q << 12), 0x70) = r;
        W(self, 0x70) = q;
        W(self, 0x78) = r;
        W(self, 0x74) = 0x20;
    }
}

extern u32 fn_8870E5E0(char *self);
extern u32 fn_8870E730(char *self, char *rec);
typedef struct Cx45Hdr { int rel; int cnt; } Cx45Hdr;
CX45_INL char *cx45_hb(Cx45Hdr *h)
{
    char *p = 0;
    if (h->rel != -1) p = (char *)h + h->rel;
    return p;
}
CX45_INL char *cx45_he34(Cx45Hdr *h)
{
    char *p = 0;
    if (h->rel != -1) p = (char *)h + (h->cnt * 0x34 + h->rel);
    return p;
}
CX45_INL u32 cx45_and(u8 acc, u8 v)
{
    if (v != 0) {
        if (acc != 0) return 1;
    }
    return 0;
}
/* 0x88717580: all 0x34-byte records of the table at +0xc pass fn_8870E730 (given slot 6 and fn_8870E5E0) */
u8 ts4_all_records_ok_88717580(char *self)
{
    u8 r = 1;
    if ((u8)((u32 (*)(char *))(*(void ***)self)[6])(self) != 0) {
        if ((u8)fn_8870E5E0(self) != 0) {
            char *p = cx45_hb(*(Cx45Hdr **)(self + 0xc));
            while (p != cx45_he34(*(Cx45Hdr **)(self + 0xc))) {
                r = (u8)cx45_and(r, (u8)fn_8870E730(self, p));
                p += 0x34;
            }
        }
    }
    return r;
}

extern char *lbl_88D45ABC;
extern void ts4_if_call_seq_u32_lbl_88D45A70_8870D9F8(char *g, char *rec, char *q);
CX45_INL char *cx45_hb0(Cx45Hdr *h)
{
    char *p = 0;
    if (h->rel != -1) p = (char *)h + h->rel;
    return p;
}
CX45_INL char *cx45_he30(Cx45Hdr *h)
{
    char *p = 0;
    if (h->rel != -1) p = (char *)h + (h->cnt * 0x30 + h->rel);
    return p;
}
/* 0x8870DD10: for every record of the two tables at +0xc (0x34-byte, then 0x30-byte) with +0x2d set, call the notifier */
void ts4_notify_tables_8870DD10(char *self)
{
    char *p = cx45_hb(*(Cx45Hdr **)(self + 0xc));
    for (; p != cx45_he34(*(Cx45Hdr **)(self + 0xc)); p += 0x34) {
        if (B(p, 0x2d) != 0) ts4_if_call_seq_u32_lbl_88D45A70_8870D9F8(lbl_88D45ABC, p, p + 0x18);
    }
    p = cx45_hb0((Cx45Hdr *)(*(char **)(self + 0xc) + 0xc));
    for (; p != cx45_he30((Cx45Hdr *)(*(char **)(self + 0xc) + 0xc)); p += 0x30) {
        if (B(p, 0x2d) != 0) ts4_if_call_seq_u32_lbl_88D45A70_8870D9F8(lbl_88D45ABC, p, p + 0x18);
    }
}
