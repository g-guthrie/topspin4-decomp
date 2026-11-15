/* CX43 part l: Swing_DLL.xex 0x889Axxxx-0x889Bxxxx. */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

/* 0x889A4888 */
typedef struct Cx43Ent { u8 pad[0x60]; u32 w60; } Cx43Ent;
typedef struct Cx43Set { u8 pad[0x14]; Cx43Ent *p14; Cx43Ent **first; Cx43Ent **last; u8 pad1[0xbc - 0x20]; u8 sub[8]; u32 wc4; u32 wc8; u32 wcc; } Cx43Set;
extern void fn_889A0540(void *g, u32 n);
void ts4_renumber_889A4888(Cx43Set *self)
{
    if (self->wc4 <= 0) {
        Cx43Ent **p;
        Cx43Ent **end;
        u32 i;
        u32 z = 0;
        self->p14->w60 = z;
        i = 1;
        end = self->last;
        for (p = self->first; p != end; p++) {
            Cx43Ent *e = *p;
            e->w60 = i;
            i++;
        }
        fn_889A0540(self->sub, i);
        self->wc8 = z;
        self->wcc = z;
    }
}

/* 0x889B4580 */
typedef struct Cx43Out { int w0; u32 w4; int w8; } Cx43Out;
typedef struct Cx43Svc { u8 pad[0x60]; u32 w60; } Cx43Svc;
extern void *lbl_88D459E0;
extern Cx43Svc *ts4_member_field_addr_8883B318(void *t, u32 a);
extern int ts4_if_call_seq_fn_88838B00_8884EF00(void *t, u32 a);
extern u32 fn_88838A48(void *t, int v, u32 a);
#if 0 /* near miss, not byte-identical */
Cx43Out *ts4_apply_bonus_889B4580(Cx43Out *out, int v)
{
    int extra = 0;
    u32 r;
    if (ts4_member_field_addr_8883B318(lbl_88D459E0, 0)->w60 != 0xDFA2AFF1) {
        extra = ts4_if_call_seq_fn_88838B00_8884EF00(lbl_88D459E0, 0) * v / 100;
        v = extra + v;
    }
    r = fn_88838A48(lbl_88D459E0, v, 0);
    out->w0 = v;
    out->w4 = r;
    out->w8 = extra;
    return out;
}
#endif

/* 0x889A74D8 */
extern void *fn_889395D8(void *src, u32 *dst);
extern void fn_88938F38(void *a, void *p, u32 n);
extern void ts4_if_get_u32_off0_88936CE8(void *p, u32 *v);
typedef struct Cx43Bits { void **vt; } Cx43Bits;
#if 0 /* near miss, not byte-identical */
void ts4_load_bits_889A74D8(u8 *self, void *a)
{
    u32 n = 0;
    u32 cnt;
    Cx43Bits *bits = (Cx43Bits *)(self + 0x42c);
    *(u32 *)(self + 0x430) = 0;
    *(u32 *)(self + 0x434) = 0;
    *(u32 *)(self + 0x438) = 0;
    fn_889395D8(a, &n);
    cnt = n;
    fn_88938F38(a, ((void *(*)(void *))(*(void ***)bits)[1])(bits), cnt);
    n = cnt << 3;
    ts4_if_get_u32_off0_88936CE8(bits, &n);
}
#endif
