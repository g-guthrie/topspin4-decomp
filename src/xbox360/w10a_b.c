/* W10A: registers two slot links then dispatches vslot 5 (Swing_DLL.xex 0x88687710). LTCG route: callee w10a_a.c as /Ob1 context, --include on it. */
typedef struct A2Vt { void (*slot[16])(void *self); } A2Vt;
typedef struct A2Svc { unsigned char pad[0x5e4]; int w5e4; } A2Svc;
typedef struct A2Q { unsigned char pad[0x28]; A2Svc *svc; } A2Q;
typedef struct A2P { unsigned char pad[0x10]; unsigned char b10; unsigned char pad2[0x60 - 0x11]; A2Q *q60; } A2P;
typedef struct A2O44 { A2Vt *vt; } A2O44;
typedef struct A2Obj { unsigned char pad[0x1c]; A2P *p1c; unsigned char pad2[0x44 - 0x20]; A2O44 *o44; unsigned char pad3[0x100 - 0x48]; unsigned w100; unsigned char pad4[0x590 - 0x104]; int sub590; } A2Obj;
extern void ga3_release_all_pooled_8867DB30(void *p, void *q);
extern void ts4_bind_slot_link_by_id_886C3FE0(int a, unsigned id, unsigned b, unsigned c);
void ts4_register_two_links_88687710(A2Obj *s)
{
    if (s->p1c->b10 == 0)
        ga3_release_all_pooled_8867DB30(&s->sub590, s->p1c);
    ts4_bind_slot_link_by_id_886C3FE0(s->p1c->q60->svc->w5e4, 0xCC20BAEAu, s->w100, 0);
    ts4_bind_slot_link_by_id_886C3FE0(s->p1c->q60->svc->w5e4, 0xEEEC65F2u, s->w100, 0);
    s->o44->vt->slot[5](s->o44);
}
