/* nearmiss: 31 off (one missing lis/addi pair shifts the tail; every other instruction matches);
 * concrete blocker: the game materializes lbl_880D6B70 twice (lis r11 and lis r9, for the +0xA0 and +0x74
 * sub-object vtables) while MSVC CSEs one address for both stores. The likely cause is two distinct vtable
 * symbols that the linker folded to one address; one symbol name cannot express that, and declaring a second
 * name for the same address would be a fake symbol. Tried: per-sub-object inline vt helpers, direct stores.
 * 0x886D0EB0: tracker sub-object (owner +0x30) destructor: destroys the +0xD4 u32 vector (element loop, then
 * storage), resets the +0xA0/+0x90/+0x74/+0x58 sub-object vtables, frees the +0x58 owned pointer and the
 * storage of the +0x4C/+0x40/+0x34 vectors. The +0x58 helper passes &o->p to a deeper helper (DA1: dead addi). */
extern char lbl_880F3790[];
extern char lbl_880D6B70[];
extern char lbl_880F4460[];
extern char lbl_880D75FC[];
extern void ts4_destroy_owned_object(void *p);
extern void ts4_loop_get_u32_off0_882666E0(unsigned *p, unsigned *e);
typedef struct Q5sVec { unsigned *begin; unsigned *end; unsigned *cap; } Q5sVec;
typedef struct Q5sOwned { void *vt; void *p; } Q5sOwned;
typedef struct Q5sVtOnly { void *vt; } Q5sVtOnly;
typedef struct Q5sTracker30 {
    void *vt;
    unsigned char pad04[0x34 - 0x04];
    Q5sVec s34, s40, s4c;
    Q5sOwned s58;
    unsigned char pad60[0x74 - 0x60];
    Q5sVtOnly s74;
    unsigned char pad78[0x90 - 0x78];
    Q5sVtOnly s90;
    unsigned char pad94[0xa0 - 0x94];
    Q5sVtOnly sa0;
    unsigned char pada4[0xd4 - 0xa4];
    Q5sVec v;
} Q5sTracker30;
static __inline void q5s_vec_free(Q5sVec *v) { if (v->begin) ts4_destroy_owned_object(v->begin); }
static __inline void q5s_vec_dtor(Q5sVec *v) { ts4_loop_get_u32_off0_882666E0(v->begin, v->end); q5s_vec_free(v); }
static __inline void q5s_ptr_free(void **pp) { if (*pp) ts4_destroy_owned_object(*pp); }
static __inline void q5s_vt_dtor(Q5sVtOnly *o) { o->vt = lbl_880D6B70; }
static __inline void q5s_owned_dtor(Q5sOwned *o) { o->vt = lbl_880D75FC; q5s_ptr_free(&o->p); }
void fn_886D0EB0(Q5sTracker30 *s)
{
    s->vt = lbl_880F3790;
    q5s_vec_dtor(&s->v);
    s->sa0.vt = lbl_880D6B70;
    s->s90.vt = lbl_880F4460;
    s->s74.vt = lbl_880D6B70;
    q5s_owned_dtor(&s->s58);
    q5s_vec_free(&s->s4c);
    q5s_vec_free(&s->s40);
    q5s_vec_free(&s->s34);
}
