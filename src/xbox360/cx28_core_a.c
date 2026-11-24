/* CX28 batch a: game core slot setters and small helpers (Swing_DLL.xex). */
typedef unsigned int cx28_u32;
typedef unsigned char cx28_u8;

void *fn_88163E30(void *self, void *slot_ptr);
void *fn_88163F18(void *self, void *slot_ptr);

/* Swing_DLL.xex 0x8815F710 */
void *ts4_cx28_apply_slot_a_8815F710(char *self)
{
    int slot = *(int *)(self + 0x54);
    char *base;
    char *p;
    char *q;
    int pad0 = 0, pad1 = 0, pad2 = 0, pad3 = 0;
    (void)pad0; (void)pad1; (void)pad2; (void)pad3;
    if (slot != -1) {
        base = *(char **)(*(char **)(*(char **)(self + 0x20) + 0x1c) + 0x20);
        p = base + 0x3c;
        q = slot * 4 + p;
        return fn_88163E30(self, q + *(int *)p);
    }
    return 0;
}

/* Swing_DLL.xex 0x8815F7A8 */
void *ts4_cx28_apply_slot_b_8815F7A8(char *self)
{
    int slot = *(int *)(self + 0x54);
    char *base;
    char *p;
    char *q;
    int pad0 = 0, pad1 = 0, pad2 = 0, pad3 = 0;
    (void)pad0; (void)pad1; (void)pad2; (void)pad3;
    if (slot != -1) {
        base = *(char **)(*(char **)(*(char **)(self + 0x20) + 0x1c) + 0x20);
        p = base + 0x24;
        q = slot * 4 + p;
        return fn_88163F18(self, q + *(int *)p);
    }
    return 0;
}

/* three-word byte string (begin, end, capacity) */
typedef struct cx28_str {
    char *b;
    char *e;
    char *c;
} cx28_str;

extern unsigned char lbl_880C1320[];
cx28_u8 fn_8822BF98(void *, void *);
void *fn_88162C60(void *, void *);
void ts4_destroy_owned_object(void *);
cx28_str *fn_88163300(cx28_str *out, cx28_str *a, void *b);
void *ts4_if_call_seq_u32_off0_8816D140(void *self, cx28_str *s);

typedef struct cx28_vobj {
    void **vt;
    int pad[3];
    cx28_str s;
} cx28_vobj;

/* Swing_DLL.xex 0x8815EFE8: build a string from other's virtual slot 0x5c and other+0x10, then append it to this */
void *ts4_cx28_assign_vcall_str_8815EFE8(void *self, cx28_vobj *other)
{
    cx28_str a;
    cx28_str b;
    cx28_str *s;
    s = fn_88163300(&b, ((cx28_str *(*)(cx28_str *, void *))other->vt[0x5c / 4])(&a, other), &other->s);
    ts4_if_call_seq_u32_off0_8816D140(self, s);
    ts4_destroy_owned_object(b.b);
    ts4_destroy_owned_object(a.b);
    return self;
}

void *fn_88163E30(void *self, void *slot_ptr);

/* Swing_DLL.xex 0x8815F918: convert the int in slot table entry to float, pass its address */
void *ts4_cx28_apply_slot_float_8815F918(char *self)
{
    int slot = *(int *)(self + 0x54);
    char *base;
    char *p;
    float f;
    if (slot != -1) {
        base = *(char **)(*(char **)(*(char **)(self + 0x20) + 0x1c) + 0x20);
        p = base + 0x24;
        f = (float)*(int *)(p + (slot * 4 + *(int *)p));
        return fn_88163E30(self, &f);
    }
    return 0;
}

