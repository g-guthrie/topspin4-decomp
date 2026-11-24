/* 0x88647438: owner teardown: detach every child and node through the virtual detach_child/detach_node
   (slots 12/13), clear both pointer vectors, clear each node's item vector, release the refcounted resource at
   +0x34 and reset the sub-object at +0x10. Matched in C++ with real virtuals (the C vtable form loaded *nt before
   the slot; 2 off). */
typedef unsigned int u32;
extern "C" void *fn_88562DC0(void *dst, void *src, u32 n);
struct Vec { char *first; char *last; };
static __inline char *vcopy(char *first, char *last, char *dest)
{ if (first == last) { return dest; } else { u32 n = (u32)(last - first); dest = (char *)fn_88562DC0(dest, first, n); return dest + n; } }
static __inline void vclear(Vec *v) { v->last = vcopy(v->last, v->last, v->first); }
struct Node { char p[8]; int a; int b; char q[0xc]; Vec items; };
extern "C" void ts4_if_call_seq_u32_off2c_88646210(Node *n);
extern "C" void ts4_vec204_move_tail_881B9148(void *sub);
struct Res { virtual void destroy(int flags); unsigned short live; short refs; };
struct Owner {
 virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5();
 virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
 virtual void detach_child(void *c); virtual void detach_node(Node *n);
 char p4[4]; unsigned char ready; char p9[7]; char sub[0xc]; Vec nodes; char p24[4]; Vec children; char p30[4]; Res *res;
};

extern "C" void ts4_owner_teardown_88647438(Owner *o)
{
    void **it, **end; Node **nt, **nend; Res *r;
    end = (void **)o->children.last;
    for (it = (void **)o->children.first; it != end; it++) o->detach_child(*it);
    vclear(&o->children);
    nend = (Node **)o->nodes.last;
    for (nt = (Node **)o->nodes.first; nt != nend; nt++) {
        Node *n = *nt;
        vclear(&n->items); ts4_if_call_seq_u32_off2c_88646210(n); n->b = 0; n->a = 0;
        o->detach_node(*nt);
    }
    vclear(&o->nodes);
    r = o->res;
    if (r) { if (r->live && --r->refs == 0) r->destroy(1); o->res = 0; }
    o->ready = 0;
    ts4_vec204_move_tail_881B9148(o->sub);
}