/* Swing_DLL.xex counted-reference constructors, destructors and appends (0x8843A1C8, 0x8844BAA8, 0x8843B3A0, 0x88476860). */
typedef unsigned int u32;
struct Ts4W1Counted {
    virtual void *destroy(int flags);
    unsigned short live;
    short refs;
};
struct Ts4W1Vec {
    Ts4W1Counted **data;
    int count;
    u32 cap;
};
struct Ts4W1Dtor { void *vt; char pad4[0xC]; Ts4W1Counted *ref; char pad14[4]; };
struct Ts4W1FloatObj { void *vt; char pad4[0xC]; void *vt10; char pad14[4]; Ts4W1Counted *ref; char pad1c[4]; float value; };
struct Ts4W1Obj3b { char pad[0xC]; Ts4W1Counted *ref; };
struct Ts4W1Obj3 { void *vt; char pad4[2]; short refs; void *f8; Ts4W1Counted *ref; unsigned short flag10; char pad12[0xA]; float f1c; };
struct Ts4W1Vec30 { char pad[0x30]; Ts4W1Vec vec; };
struct Ts4W1Arr { void *vt; char pad[0xDC]; Ts4W1Counted *items[3]; };
extern "C" {
extern char lbl_8807FF98[], lbl_8803A308[], lbl_88081250[], lbl_8808122C[], lbl_880870F4[], lbl_88084834[];
extern float lbl_880038E0;
void ts4_ref_holder_dtor_88436F58(void *p);
void fn_8843C308(void *p, int n);
void fn_8841C678(Ts4W1Vec *vec, int n);
void ts4_set_u32_off8_8847FA60(void *dst, void *src);

static Ts4W1FloatObj *ts4_if_call_seq_fn_8843C308_8844BAA8(Ts4W1FloatObj *o, Ts4W1Counted *ref, float value)
{
    fn_8843C308(o, 8);
    o->value = value;
    o->ref = ref;
    o->vt = lbl_88081250;
    o->vt10 = lbl_8808122C;
    if (ref->live != 0)
        ref->refs = ref->refs + 1;
    return o;
}

void ts4_destroy_ref_array3_88476860(Ts4W1Arr *o)
{
    Ts4W1Counted **p = o->items;
    int n = 3;
    o->vt = lbl_88084834;
    do {
        Ts4W1Counted *r = *p;
        if (r != 0 && r->live != 0) {
            if (--r->refs == 0)
                r->destroy(1);
        }
        ++p;
    } while (--n != 0);
    o->vt = lbl_8803A308;
}
}
