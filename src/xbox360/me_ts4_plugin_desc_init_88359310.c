/* Swing_DLL.xex 0x88359310: fills the static plugin descriptor lbl_88B364E0 (name lbl_8802B5B8, version 0x10100, kind 0xB, flags 0x3060)
 * with its callback thunks and returns it. Store order matters: f18 before f20, f78 before kind. agAE: /Oc. */
typedef void (*Fn)(void);
typedef struct PluginDesc {
    const char *name; unsigned int version; int a8; int ac; Fn f10; Fn f14; Fn f18; char pad1c[4]; Fn f20;
    char pad24[0x40 - 0x24]; int kind; int flags; char pad48[0x5c - 0x48]; Fn f5c; Fn f60; Fn f64; char pad68[0x74 - 0x68];
    Fn f74; Fn f78;
} PluginDesc;
extern PluginDesc lbl_88B364E0;
extern const char lbl_8802B5B8[];
void *ts4_memset(void *p, int v, unsigned int n);
void ts4_adjust_minus_28_thunk_883592F8(void);
void ts4_adjust_minus_28_thunk_88356CF0(void);
void ts4_adjust_minus_28_thunk_88358720(void);
void ts4_adjust_minus_28_thunk_88358708(void);
void ts4_adjust_minus_28_thunk_88356D08(void);
void ts4_adjust_minus_28_thunk_88356D20(void);
void ts4_adjust_minus_28_thunk_88356D38(void);
void ts4_adjust_minus_28_thunk_88356D50(void);
void ts4_get_float_off2DD4_adj1c_88356D68(void);
PluginDesc *fn_88359310(void)
{
    PluginDesc *d = &lbl_88B364E0;
    ts4_memset(d, 0, sizeof(PluginDesc));
    d->name = lbl_8802B5B8;
    d->version = 0x10100;
    d->ac = 2;
    d->a8 = 1;
    d->f10 = ts4_adjust_minus_28_thunk_883592F8;
    d->f14 = ts4_adjust_minus_28_thunk_88356CF0;
    d->f18 = ts4_adjust_minus_28_thunk_88358708;
    d->f20 = ts4_adjust_minus_28_thunk_88358720;
    d->f5c = ts4_adjust_minus_28_thunk_88356D08;
    d->f60 = ts4_adjust_minus_28_thunk_88356D20;
    d->f64 = ts4_adjust_minus_28_thunk_88356D38;
    d->f74 = ts4_adjust_minus_28_thunk_88356D50;
    d->f78 = ts4_get_float_off2DD4_adj1c_88356D68;
    d->kind = 0xb;
    d->flags = 0x3060;
    return d;
}
