/* Loader_DLL.xex 0x830A14B8-0x830A1580, executable version 0.0.0.3. */
/* Scalar deleting destructors: restore vtables, destroy members, free when flag bit 0 is set. */
typedef unsigned int u32;
struct Ts4lIf {
    virtual void s0();
    virtual void s1();
};
struct Ts4lObj1 {
    void *vtbl;
    int a, b;
    Ts4lIf *m;
};
extern "C" {
extern char lbl_83085EF0[];
extern void ts4_tailcall_fn_833E74C0_833E1758(void *);
extern char lbl_83085DBC[];
extern char lbl_83085DB8[];
extern void fn_830A23D8(void *);


Ts4lObj1 *ts4l_sdtor_830A14B8(Ts4lObj1 *self, u32 flags)
{
    self->vtbl = lbl_83085EF0;
    self->m->s1();
    if (flags & 1)
        ts4_tailcall_fn_833E74C0_833E1758(self);
    return self;
}

struct Ts4lSub {
    char *vtbl;
    int pad[2];
};

void *ts4l_sdtor_830A1580(char *self, u32 flags)
{
    Ts4lSub *s = (Ts4lSub *)(self + 4);
    *(char **)self = lbl_83085DBC;
    s->vtbl = lbl_83085DB8;
    fn_830A23D8((char *)s + 8);
    if (flags & 1)
        ts4_tailcall_fn_833E74C0_833E1758(self);
    return self;
}
}
