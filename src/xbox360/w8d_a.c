/* W8D: self-relative record counter bumps (plain route, /Oc) */

#ifdef _MSC_VER
#define W8D_UNUSED
#else
#define W8D_UNUSED __attribute__((unused))
#endif

/* Swing_DLL.xex 0x88667ED0: ts4_bump_side_counts_88667ED0 */
typedef struct W8dH_88667ED0 { int rel; } W8dH_88667ED0;
typedef struct W8dR_88667ED0 { char pad[0x88]; int w88, w8c, w90, w94; char p2[0x134 - 0x98]; } W8dR_88667ED0;
typedef struct W8dB_88667ED0 { char pad[0x5c]; W8dH_88667ED0 hdr; } W8dB_88667ED0;
typedef struct W8dP_88667ED0 { char pad[0x90]; int w90; char p2[0xc4 - 0x94]; unsigned char bc4; char p3[0xcc - 0xc5]; unsigned char bcc; char p4[0xd7 - 0xcd]; unsigned char bd7; int wd8; } W8dP_88667ED0;
typedef struct W8dS_88667ED0 { char pad[0x20]; W8dP_88667ED0 *p; char p2[4]; W8dB_88667ED0 *b; } W8dS_88667ED0;
static __inline int *w8d_inc_88667ED0(int *p) { *p = *p + 1; return p; }
static __inline W8dR_88667ED0 *w8d_rec_88667ED0(W8dS_88667ED0 *s, int i)
{
    W8dH_88667ED0 *h = &s->b->hdr;
    return (W8dR_88667ED0 *)((char *)h + i * 0x134 + h->rel);
}
void ts4_bump_side_counts_88667ED0(W8dS_88667ED0 *s)
{
    int pad0 W8D_UNUSED = 0, pad1 W8D_UNUSED = 0;
    W8dP_88667ED0 *p = s->p;
    int i;
    if (p->bcc == 0) return;
    if (p->bd7 != 0) return;
    if (p->bc4 != 0) return;
    i = p->w90;
    w8d_inc_88667ED0(&w8d_rec_88667ED0(s, i)->w88);
    w8d_inc_88667ED0(&w8d_rec_88667ED0(s, i ^ 1)->w8c);
    if (p->wd8 == -1) return;
    if (p->wd8 == i)
        w8d_inc_88667ED0(&w8d_rec_88667ED0(s, p->wd8)->w90);
    else
        w8d_inc_88667ED0(&w8d_rec_88667ED0(s, p->wd8)->w94);
}

/* Swing_DLL.xex 0x88668490: ts4_bump_side_tally_88668490 */
typedef struct W8dH_88668490 { int rel; } W8dH_88668490;
typedef struct W8dA_88668490 { char pad[0x14]; int w14, w18; char p2[0x40 - 0x1c]; } W8dA_88668490;
typedef struct W8dBr_88668490 { char pad[0x20]; int w20, w24; char p2[0x134 - 0x28]; } W8dBr_88668490;
typedef struct W8dBA_88668490 { char pad[0x4c]; W8dH_88668490 hdr; } W8dBA_88668490;
typedef struct W8dBB_88668490 { char pad[0x5c]; W8dH_88668490 hdr; } W8dBB_88668490;
typedef struct W8dP_88668490 { char pad[0x9a]; unsigned char b9a; char p2[0xd0 - 0x9b]; unsigned wd0; char p3[3]; unsigned char bd7; int wd8; } W8dP_88668490;
typedef struct W8dS_88668490 { char pad[0x20]; W8dP_88668490 *p; char p2[4]; W8dBA_88668490 *ba; } W8dS_88668490;
static __inline int *w8d_inc_88668490(int *p) { *p = *p + 1; return p; }
static __inline W8dA_88668490 *w8d_ra_88668490(W8dS_88668490 *s, int i)
{
    W8dH_88668490 *h = &((W8dBA_88668490 *)s->ba)->hdr;
    return (W8dA_88668490 *)((char *)h + i * 0x40 + h->rel);
}
static __inline W8dBr_88668490 *w8d_rb_88668490(W8dS_88668490 *s, int i)
{
    W8dH_88668490 *h = &((W8dBB_88668490 *)s->ba)->hdr;
    return (W8dBr_88668490 *)((char *)h + i * 0x134 + h->rel);
}
void ts4_bump_side_tally_88668490(W8dS_88668490 *s, int side)
{
    if (s->p->bd7 != 0) return;
    if (s->p->wd0 == 0xc9238771u) return;
    if (s->p->wd8 != side) return;
    if (s->p->b9a == 0) {
        w8d_inc_88668490(&w8d_ra_88668490(s, side)->w14);
        w8d_inc_88668490(&w8d_rb_88668490(s, side)->w20);
    } else {
        w8d_inc_88668490(&w8d_ra_88668490(s, side)->w18);
        w8d_inc_88668490(&w8d_rb_88668490(s, side)->w24);
    }
}
