/* CW2 batch d: C++ helpers (Swing_DLL.xex). Compiled with /Oc. */
typedef unsigned int cw2_u32;
typedef unsigned char cw2_u8;

extern "C" {

extern void *lbl_88D45B38;
void *ts4_crt_nh_malloc_88565258(cw2_u32 n);
void *ts4_node_dispatch_default_88613350(void *heap, cw2_u32 n);
void *fn_8815D160(cw2_u32 n);

/* Swing_DLL.xex 0x8815C980: allocate; sizes up to 0x80 use the small-block allocator */
void *ts4_cw2_alloc_8815C980(cw2_u32 n)
{
    void *r;
    if (n > 0x80) {
        void *heap = lbl_88D45B38;
        if (heap == 0)
            r = ts4_crt_nh_malloc_88565258(n);
        else
            r = ts4_node_dispatch_default_88613350(heap, n);
        return r;
    }
    return fn_8815D160(n);
}

void *ts4_if_call_seq_u32_lbl_88D45B38_88150878(void *alloc, cw2_u32 n);
void *fn_88562DC0(void *dst, const void *src, cw2_u32 n);
void ts4_destroy_owned_object(void *);

struct Cw2ByteVec {
    cw2_u8 *begin;
    cw2_u8 *end;
    cw2_u8 *cap;
};

/* Swing_DLL.xex 0x8815AE40: vector<byte>::operator= */
Cw2ByteVec *ts4_cw2_byte_vec_assign_8815AE40(Cw2ByteVec *t, Cw2ByteVec *x)
{
    if (x != t) {
        cw2_u8 *xb = x->begin;
        cw2_u8 *xe = x->end;
        cw2_u32 xs = x->end - x->begin;
        if (xs > (cw2_u32)(t->cap - t->begin)) {
            cw2_u8 *nb = xs != 0 ? (cw2_u8 *)ts4_if_call_seq_u32_lbl_88D45B38_88150878(&t->cap, xs) : 0;
            if (xe != xb)
                fn_88562DC0(nb, xb, xe - xb);
            ts4_destroy_owned_object(t->begin);
            t->begin = nb;
            t->cap = nb + xs;
        } else if ((cw2_u32)(t->end - t->begin) >= xs) {
            if (xe != xb)
                fn_88562DC0(t->begin, xb, xe - xb);
        } else {
            cw2_u8 *mid = xb + (t->end - t->begin);
            if (mid != xb)
                fn_88562DC0(t->begin, xb, mid - xb);
            mid = (t->end - t->begin) + x->begin;
            if (x->end != mid)
                fn_88562DC0(t->end, mid, x->end - mid);
        }
        t->end = t->begin + xs;
    }
    return t;
}

void *ts4_if_call_seq_fn_88883CD0_8860D250(void *heap);
void *fn_88613570(void *heap, cw2_u32 bytes, cw2_u32 align, void *cap_ptr);

}

static inline void *cw2_alloc(void *cap_ptr, cw2_u32 bytes)
{
    void *h;
    if (lbl_88D45B38 != 0)
        h = ts4_if_call_seq_fn_88883CD0_8860D250(lbl_88D45B38);
    else
        h = 0;
    return fn_88613570(h, bytes, 4, cap_ptr);
}

static inline const cw2_u32 &cw2_max(const cw2_u32 &a, const cw2_u32 &b)
{
    return a < b ? b : a;
}

struct Cw2E16 {
    cw2_u32 a, b, c, d;
};
struct Cw2Vec16 {
    Cw2E16 *begin;
    Cw2E16 *end;
    Cw2E16 *cap;
};

extern "C" {

/* slot setters: object +0x54 is an element index into a self-relative value table
   (descriptor reached via +0x20 -> +0x1c -> +0x20) */
struct Cw2SlotDesc {
    cw2_u8 pad0[0x3c];
    int rel3c;
};
struct Cw2SlotInfo {
    cw2_u8 pad[0x20];
    Cw2SlotDesc *desc;
};
struct Cw2SlotMid {
    cw2_u8 pad[0x1c];
    Cw2SlotInfo *info;
};
struct Cw2SlotObj {
    cw2_u8 pad0[0x20];
    Cw2SlotMid *mid;
    cw2_u8 pad1[0x54 - 0x24];
    int slot;
};

cw2_u32 fn_88163F18(void *obj, void *value);
cw2_u32 fn_88163E30(void *obj, void *value);

/* Swing_DLL.xex 0x8815F840: set the float value at the slot, converted to int */
cw2_u32 ts4_cw2_slot_set_float_as_int_8815F840(Cw2SlotObj *o)
{
    int slot = o->slot;
    if (slot != -1) {
        char *base = (char *)&o->mid->info->desc->rel3c;
        int v = (int)*(float *)(base + (slot * 4 + *(int *)base));
        return fn_88163F18(o, &v);
    }
    return 0;
}

}
