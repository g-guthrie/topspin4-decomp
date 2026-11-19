/* 0x8846D5E0: constructor. Installs the vtable, sets the halfword flag at +6 to 1, resets three 12-byte records at
 * +0x28 and thirteen at +0xF0 to (0, 0, 0x80000000), stores -47 at +0x98 and clears the halfword at +0x9C.
 * Matches plain /Oc. */
typedef struct Rec { int a, b; unsigned int c; } Rec;
typedef struct Self3 { void *vt; char p4[2]; unsigned short flag; char p8[0x20]; Rec r28[3]; char p4c[0x4c]; int m98; unsigned short h9c; char p9e[0x52]; Rec rf0[13]; } Self3;
extern char lbl_88086C3C[];
static __inline void rec_init(Rec *r) { r->a = 0; r->b = 0; r->c = 0x80000000u; }
Self3 *ts4_ctor_sentinel_records_8846D5E0(Self3 *s)
{
    s->vt = lbl_88086C3C;
    s->flag = 1;
    rec_init(&s->r28[0]); rec_init(&s->r28[1]); rec_init(&s->r28[2]);
    s->m98 = -0x2f;
    s->h9c = 0;
    rec_init(&s->rf0[0]); rec_init(&s->rf0[1]); rec_init(&s->rf0[2]); rec_init(&s->rf0[3]); rec_init(&s->rf0[4]);
    rec_init(&s->rf0[5]); rec_init(&s->rf0[6]); rec_init(&s->rf0[7]); rec_init(&s->rf0[8]); rec_init(&s->rf0[9]);
    rec_init(&s->rf0[10]); rec_init(&s->rf0[11]); rec_init(&s->rf0[12]);
    return s;
}
