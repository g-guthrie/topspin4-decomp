/* 0x883F7108: 0x25 for a null out; sums the float of every item of the def->f_ac->f18 collection (count 88317E20, item 88317E68, value 883177F0) into *out, starting from 0.0f */
/* Matched on /O1 plain only (agT, v.py chk). */
typedef struct Rec { char pad[0x18]; void *h; } Rec;
typedef struct Def { char pad[0xac]; Rec *rec; } Def;
typedef struct T { int f0; Def *def; } T;
int ts4_lookup_then_forward_88317E20(void *h, int *count);
int ts4_if_call_seq_fn_8832F930_88317E68(void *h, int i, void **item);
int ts4_if_call_seq_fn_88322CA8_883177F0(void *item, float *v);
int ts4_sum_item_floats_883F7108(T *t, float *out)
{
    float sum;
    void *h;
    int n, i, r;
    void *item;
    float v;
    if (!out)
        return 0x25;
    sum = 0.0f;
    h = t->def->rec ? t->def->rec->h : 0;
    if (h) {
        r = ts4_lookup_then_forward_88317E20(h, &n);
        if (r)
            return r;
        for (i = 0; i < n; i++) {
            r = ts4_if_call_seq_fn_8832F930_88317E68(h, i, &item);
            if (r)
                return r;
            r = ts4_if_call_seq_fn_88322CA8_883177F0(item, &v);
            if (r)
                return r;
            sum = v + sum;
        }
    }
    *out = sum;
    return 0;
}
