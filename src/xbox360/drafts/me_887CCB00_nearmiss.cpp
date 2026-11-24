/* 0x887CCB00: creates an object with ts4_if_call_seq_u32_lbl_88D45B38_88211A08(size) and initialises it with fn_887CCA98(o, a, b); on failure destroys it through vtable slot 0 and returns 0. */
/* Near miss (agAF, /Oc): 3 off at +0x40, the target sets r3 before li r4,1 for the destroy call; the C++ virtual form gives the same order. */
typedef struct Obj Obj;
typedef struct ObjVt { void (*destroy)(Obj *o, int del); } ObjVt;
struct Obj { ObjVt *vt; };
extern Obj *ts4_if_call_seq_u32_lbl_88D45B38_88211A08(unsigned int size);
extern unsigned char fn_887CCA98(Obj *o, void *a, void *b);
Obj *fn_887CCB00(unsigned int size, void *a, void *b)
{
    Obj *o = ts4_if_call_seq_u32_lbl_88D45B38_88211A08(size);
    if (o) {
        if (!fn_887CCA98(o, a, b)) {
            o->vt->destroy(o, 1);
            return 0;
        }
    }
    return o;
}
