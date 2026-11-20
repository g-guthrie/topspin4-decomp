/* 0x883F1400: sum the float values of every entry of every item in an intrusive list (0x25 if out is null) */
/* Matched on /O1 plain only (agV, v.py chk). */
typedef struct Link { struct Link *next; struct Link *prev; } Link;
typedef struct Item { char pad[0x28]; void *h; } Item; /* link at +4 */
typedef struct Owner { char pad[0xc]; Link head; } Owner;

int ts4_lookup_then_forward_88317E20(void *h, int *count);
int ts4_if_call_seq_fn_8832F930_88317E68(void *h, int i, void **item);
int ts4_if_call_seq_fn_88322CA8_883177F0(void *item, float *v);

int fn_883F1400(Owner *t, float *out)
{
    float sum;
    Link *n;
    if (!out)
        return 0x25;
    sum = 0.0f;
    for (n = t->head.next; n && n != &t->head; n = n->next) {
        Item *it = n ? (Item *)((char *)n - 4) : 0;
        void *h = it->h;
        if (h) {
            int cnt, i, r;
            r = ts4_lookup_then_forward_88317E20(h, &cnt);
            if (r)
                return r;
            for (i = 0; i < cnt; i++) {
                void *e;
                float v;
                r = ts4_if_call_seq_fn_8832F930_88317E68(h, i, &e);
                if (r)
                    return r;
                r = ts4_if_call_seq_fn_88322CA8_883177F0(e, &v);
                if (r)
                    return r;
                sum = v + sum;
            }
        }
    }
    *out = sum;
    return 0;
}
