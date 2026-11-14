/* SM1 batch h: array helpers, dispatch by kind, bernstein weights (default /O2). */
typedef unsigned int u32;
typedef unsigned long long u64;

typedef struct Ts4VObj7 { void **vt; } Ts4VObj7;

/* Swing_DLL.xex 0x88154758: run a destructor over the elements of an array, last to first */
void ts4_destroy_array_elements_reverse_88154758(char *base, int size, int count, void (*dtor)(void *)) { char *p = base + size * count; int i = count - 1; for (; i >= 0; i--) { p -= size; dtor(p); } }

/* 0x8820CA98: forward to a helper or a vtable slot depending on the low nibble of the kind byte */
extern void fn_8820F068(void *, void *);
typedef struct Ts4KindOwner { struct { char pad[8]; unsigned char kind; } *info; } Ts4KindOwner;
void ts4_dispatch_by_kind_8820CA98(Ts4KindOwner *t, Ts4VObj7 *a, void *b) { u32 k = t->info->kind & 0xf; if (k == 0xa) fn_8820F068(a, b); else if (k == 0xb) ((void (*)(Ts4VObj7 *, void *))a->vt[0x5c / 4])(a, b); }

/* 0x8834C558: store a float in one of two slots; slot 0 is capped by the value stored next to it */
int ts4_set_float_capped_by_index_adj1c_8834C558(char *t, int idx, float x) {
    char *p = t ? t - 0x1c : 0;
    if (idx == 0) {
        *(float *)(p + 0x144) = x;
        if (x < *(float *)(p + 0x148)) return 0;
        *(float *)(p + 0x144) = *(float *)(p + 0x148);
        return 0;
    }
    if (idx != 1) return 0;
    *(float *)(p + 0x13c) = x;
    return 0;
}

/* 0x883AFBC0: record the owner in the descriptor and run the defaults initialiser */
extern float lbl_88001A20;
extern int fn_883BEDA8(void *, void *, float, float, int, void *, float, float);
typedef struct Ts4Desc20 { char pad[0x20]; void *owner; } Ts4Desc20;
int ts4_init_descriptor_defaults_883AFBC0(void *t, Ts4Desc20 *a) { a->owner = t; fn_883BEDA8(t, a, lbl_88001A20, lbl_88001A20, 0, a, lbl_88001A20, lbl_88001A20); return 0; }

/* 0x88197D60: true when x lies in [a, b) or [c, d + a) */
typedef struct Ts4Ranges { char pad[0x7c]; u32 a; char pad2[8]; u32 b; u32 c; u32 d; } Ts4Ranges;
int ts4_address_in_ranges_88197D60(Ts4Ranges *t, u32 x) { if (x >= t->a && x < t->b) return 1; if (x >= t->c && x < t->d + t->a) return 1; return 0; }

/* 0x88274AD8: cubic Bernstein weights (1-t)^3, 3(1-t)^2 t, 3(1-t) t^2, t^3 */
extern float g_ts4_script_constants[];
void ts4_cubic_bernstein_weights_88274AD8(float t, int unused, float *w0, float *w1, float *w2, float *w3) {
    float t2 = t * t;
    float m = g_ts4_script_constants[0] - t;
    float c3 = g_ts4_script_constants[19];
    float t3 = t2 * t;
    float m2 = m * m;
    float mt2 = m * t2;
    float m2t = m2 * t;
    float m3 = m2 * m;
    (void)unused;
    *w0 = m3;
    *w1 = m2t * c3;
    *w2 = mt2 * c3;
    *w3 = t3;
}
