/* 0x883E18E8: when flag 2 or 0x10 at +0x24 is set, probes the handle at +0x34 (88317788; codes 0x24/0xB are success) and, if flagged, reads a word via 88317910; *out = 1 when its bit 0 is clear, else 0 */
/* Matched on /O1 plain and LTCG (agT, v.py chk). */
typedef struct T { char pad[0x24]; unsigned int flags; char pad2[0xc]; void *h; } T;
int ts4_if_call_seq_fn_88322CA8_88317788(void *h, unsigned char *flag);
int ts4_if_call_seq_fn_88322CA8_88317910(void *h, unsigned int *v);
int fn_883E18E8(T *t, unsigned char *out)
{
    unsigned char res = 0;
    unsigned char flag;
    unsigned int v;
    int r;
    if (t->flags & 2 || t->flags & 0x10) {
        flag = 0;
        r = ts4_if_call_seq_fn_88322CA8_88317788(t->h, &flag);
        if (r == 0x24 || r == 0xb)
            r = 0;
        if (r)
            return r;
        if (flag) {
            r = ts4_if_call_seq_fn_88322CA8_88317910(t->h, &v);
            if (r)
                return r;
            if (!(v & 1))
                res = 1;
        }
    }
    *out = res;
    return 0;
}
