/* Swing_DLL.xex 0x8860DBC8-0x8860DC4C, executable version 0.0.0.3. */
/* Depth-first search over a child/sibling chain: the first node accepted by
   fn_881F04B8 gets its virtual handler called. */
extern "C" {
unsigned char fn_881F04B8(void *n);
unsigned char fn_8860DBC8(void *n, int a);
}
struct Node {
    virtual void s0();
    virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9();
    virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15(); virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19();
    virtual void s20(); virtual void s21(); virtual void s22(); virtual void s23(); virtual void s24(); virtual void s25(); virtual void s26(); virtual void s27(); virtual void s28(); virtual void s29();
    virtual void s30(); virtual void s31(); virtual void s32(); virtual void s33(); virtual void s34(); virtual void s35(); virtual void s36(); virtual void s37();
    virtual void on38(int a);
    char pad[0x40 - 4];
    Node *next;
};
extern "C" unsigned char ts4_node_visit_8860DBC8(Node *n, int a)
{
    unsigned char r = 0;
    Node *c;
    if (fn_881F04B8(n)) {
        n->on38(a);
        return 1;
    }
    c = n->next;
    while (1) {
        if (c == 0) break;
        r = fn_8860DBC8(c, a);
        c = c->next;
        if (r == 0) continue;
        break;
    }
    return r;
}
