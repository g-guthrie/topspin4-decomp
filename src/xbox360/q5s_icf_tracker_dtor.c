/* 0x886D0EB0: tracker sub-object (owner +0x30) destructor: destroys the +0xD4 u32 vector (element loop, then
 * storage), resets the +0xA0/+0x90/+0x74/+0x58 sub-object vtables, frees the +0x58 owned pointer and the
 * storage of the +0x4C/+0x40/+0x34 vectors. The +0x58 helper passes &o->p to a deeper helper (dead addi).
 * The +0xA0 and +0x74 sub-objects are of two classes whose identical vtables the original linker folded
 * (/OPT:ICF) to 0x880D6B70: the code loads that address twice (lis r11, lis r9). The second name is the
 * reviewed alias lbl_880D6B70_icf_b (config/54540859/icf_aliases.json); with one name the compiler loads
 * the address once. */
extern char lbl_880F3790[];
extern char lbl_880D6B70[];       /* vtable of the +0x74 sub-object class */
extern char lbl_880D6B70_icf_b[]; /* vtable of the +0xA0 sub-object class: same address (folded) */
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
static __inline void q5s_owned_dtor(Q5sOwned *o) { o->vt = lbl_880D75FC; q5s_ptr_free(&o->p); }
void ts4_tracker_sub30_dtor_886D0EB0(Q5sTracker30 *s)
{
    s->vt = lbl_880F3790;
    q5s_vec_dtor(&s->v);
    s->sa0.vt = lbl_880D6B70_icf_b;
    s->s90.vt = lbl_880F4460;
    s->s74.vt = lbl_880D6B70;
    q5s_owned_dtor(&s->s58);
    q5s_vec_free(&s->s4c);
    q5s_vec_free(&s->s40);
    q5s_vec_free(&s->s34);
}
