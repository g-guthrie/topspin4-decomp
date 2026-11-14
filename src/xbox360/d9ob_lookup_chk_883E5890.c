/* Swing_DLL.xex 0x883E5890-0x883E58FC, executable version 0.0.0.3. */
typedef struct Ts4Ob2Q1 { char pad0[0x10]; void *f10; } Ts4Ob2Q1;
int ts4_if_call_seq_fn_88322CA8_88317910(void *p, void *out);
int ts4_lookup_then_forward_88316FB0(void *p, int x);

int ts4_chk_883E5890(Ts4Ob2Q1 *o)
{
    unsigned char z;
    char tmp[16];
    int r;
    if (o->f10 == 0)
        z = 0;
    else
        z = ts4_if_call_seq_fn_88322CA8_88317910(o->f10, tmp) == 0;
    if (z) {
        r = ts4_lookup_then_forward_88316FB0(o->f10, 1);
        if (r != 0)
            return r;
    }
    return 0;
}
