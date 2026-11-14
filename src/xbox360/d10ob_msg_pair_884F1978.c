/* Swing_DLL.xex 0x884F1978-0x884F19FC, executable version 0.0.0.3. */
extern char lbl_88D26FF0[];
int ts4_tailcall_fn_884F0178_884F0228(int a, void *b);
int fn_884F2478(void *g, unsigned int a, unsigned int b);

int ts4_msg_pair_884F1978(unsigned int *p)
{
    char buf[0x190];
    int r;
    if (p == 0 || p[0] == 0 || p[1] == 0)
        return 0x57;
    r = ts4_tailcall_fn_884F0178_884F0228(2, buf);
    if (r != 0)
        return r;
    return fn_884F2478(lbl_88D26FF0, p[0], p[1]) < 0 ? 0x65b : 0;
}
