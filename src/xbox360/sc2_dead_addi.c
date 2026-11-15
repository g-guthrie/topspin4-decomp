/* SC2: 0x88265498, a factory that allocates a 0x3c-byte object and inlines its constructor. The dead
   `addi r10,r3,0x14` is the address of the member sub-object at +0x14 handed to a nested inline init
   (DA1 rule: the pointer is used for derived addresses `&m->v0` etc.). Plain route, no flags. */
typedef unsigned int u32;
extern void *lbl_88D45B38;
extern void *ts4_node_dispatch_with_target_88613268(void *heap, u32 size, u32 alignment, u32 flags, u32 pool);
typedef struct Sc2Vec { u32 b, e, c; } Sc2Vec;
typedef struct Sc2Members { u32 w14; Sc2Vec v0, v1, v2; } Sc2Members;
typedef struct Sc2Obj3c { u32 w0, w4, w8, wc, w10; Sc2Members m; } Sc2Obj3c;
static __inline void sc2_vec_init(Sc2Vec *v) { v->b = 0; v->e = 0; v->c = 0; }
static __inline void sc2_members_init(Sc2Members *m)
{
    sc2_vec_init(&m->v0);
    sc2_vec_init(&m->v1);
    sc2_vec_init(&m->v2);
}
/* Swing_DLL.xex 0x88265498 */
Sc2Obj3c *ts4_obj3c_new_88265498(void)
{
    Sc2Obj3c *o = (Sc2Obj3c *)ts4_node_dispatch_with_target_88613268(lbl_88D45B38, 0x3c, 4, 0, 2);
    if (o != 0) {
        o->w8 = 0;
        sc2_members_init(&o->m);
        o->w0 = 0;
        o->w4 = 0;
        o->wc = 0;
        o->w10 = 0;
        return o;
    }
    return 0;
}
