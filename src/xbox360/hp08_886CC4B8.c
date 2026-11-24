typedef struct HP08H3 {
    unsigned a;
    unsigned b;
    unsigned c;
} HP08H3;

typedef struct HP08Ref {
    void *tgt;
    unsigned off;
    unsigned extra;
} HP08Ref;

typedef struct HP08Vt {
    void *s[10];
    unsigned (*f28)(void *t, HP08Ref *r, unsigned off, int n);
} HP08Vt;

typedef struct HP08Tgt {
    HP08Vt *vt;
} HP08Tgt;

extern HP08H3 *ts4_handle_forward_88610A48(HP08H3 *out, HP08H3 *h, unsigned *hash);
extern HP08Ref *ts4_handle_forward_88150770(HP08Ref *out, HP08H3 *h, unsigned *hash);
extern unsigned fn_88923530(unsigned a, unsigned long long b, unsigned long long c, unsigned d);

int ts4_offset_886CC4B8(unsigned long long hp, unsigned long long p2, unsigned *p3)
{
    unsigned v;
    unsigned res;
    unsigned hi;
    HP08H3 o;
    HP08Ref r;
    HP08Tgt *t;
    v = 0x88349c29u;
    ts4_handle_forward_88150770(&r, ts4_handle_forward_88610A48(&o, (HP08H3 *)&hp, &v), p3);
    t = (HP08Tgt *)r.tgt;
    res = t->vt->f28(t, &r, r.off, 4);
    hi = *(unsigned *)&p2;
    return (int)((res - fn_88923530(hi, hp, (unsigned long long)hi << 32, 0x80222bceu)) - 0x240);
}
