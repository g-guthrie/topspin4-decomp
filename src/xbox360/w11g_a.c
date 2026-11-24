extern char lbl_880F378C[], ts4_vtbl_Ts4TrackerShell880D6B70[], lbl_880F37A4[], lbl_880F3794[];
void ts4_destroy_owned_object(void *object);
void ts4_object_dtor_886CA260(void *p);
void ts4_object_dtor_886DABD0(void *p);
void ts4_tracker_sub30_dtor_886D0EB0(void *p);

typedef struct S270 { void *vt; char pad[0x2c]; char sub30[0x30]; } S270;
static __inline void s270_dtor(S270 *s)
{
    s->vt = lbl_880F3794;
    ts4_tracker_sub30_dtor_886D0EB0(&s->sub30);
}
static __inline void rel_owned(void **pp) { if (*pp) ts4_destroy_owned_object(*pp); }
typedef struct S430 { void *vt; char pad[8]; void *o; } S430;
static __inline void s430_dtor(S430 *s)
{
    s->vt = lbl_880F37A4;
    rel_owned(&s->o);
}
typedef struct Big {
    void *vt;
    char p04[0x2c];
    char sub30[0x120];
    char sub150[0x120];
    S270 s270;
    char p2a0[0x414 - 0x2d0];
    void *o414;
    char p418[0x430 - 0x418];
    S430 s430;
    char p440[0x4d0 - 0x440];
    char sub4d0[0x540 - 0x4d0];
    void *vt540;
    char p544[0x5ac - 0x544];
    char sub5ac[0x5e8 - 0x5ac];
    void *o5e8;
} Big;

void ts4_object_dtor_886E34F8(Big *self)
{
    self->vt = lbl_880F378C;
    rel_owned(&self->o5e8);
    ts4_object_dtor_886CA260(self->sub5ac);
    self->vt540 = ts4_vtbl_Ts4TrackerShell880D6B70;
    ts4_object_dtor_886DABD0(self->sub4d0);
    s430_dtor(&self->s430);
    if (self->o414) ts4_destroy_owned_object(self->o414);
    s270_dtor(&self->s270);
    ts4_tracker_sub30_dtor_886D0EB0(self->sub150);
    ts4_tracker_sub30_dtor_886D0EB0(self->sub30);
}
