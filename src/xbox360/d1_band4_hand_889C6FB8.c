/* Swing_DLL.xex 0x889C6FB8-0x889C6FDC, executable version 0.0.0.3. */

extern int ts4_if_call_seq_lbl_880C1324_889BCD88(int);
extern int fn_888D7FA8(int);
extern void ts4_forward_to_fn_8864B268(void *);
extern void fn_888F70A0(void *);
extern void ts4_tailcall_NetDll_send_884F0350(void *, void *, void *, int);

typedef struct Holder { int a; int b; } Holder;
typedef struct Ref { void *vt; Holder *target; } Ref;

void ts4_forward_889C6FB8(Ref **self, void ***other)
{
    Ref *s = *self;
    if (s != 0) {
        void **p = *other;
        ts4_tailcall_NetDll_send_884F0350(s->target, p, *p, 0);
    }
}

typedef struct Obj { void **vtable; } Obj;
