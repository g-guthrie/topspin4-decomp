/* agAM: 1 off (plain and LTCG). The key compare comes out cmplw r8,r7 where the target has r7,r8; writing *k==e->key in this loop form gives 3 off. It finds the entry with key *k in the pointer vector at +0x40; if that entry has a resource, it decrements refs and releases the resource. */
typedef unsigned char u8; typedef unsigned int u32;
extern void fn_88472130(void *p); typedef struct { char p[0x10]; void *res; u32 key; char q[0x34-0x18]; int refs; } E; typedef struct { char p[0x40]; E **b; E **e; } O;
void f(O *o, int unused, const u32 *k){ E **i=o->b, **end=o->e; for(;i!=end;i++){ E *e=*i; if (e && e->key==*k){ if (e->res){ e->refs--; fn_88472130(e->res);} return; } } }
