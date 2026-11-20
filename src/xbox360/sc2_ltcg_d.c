/* SC2: 0x8820F740, a constructor with a base call and a 3x3 identity-style float block at +0x3c (LTCG route, no
   context). The one is read first and the zero after the +0x34 store, each into its own local, stores written in
   descending order as the target emits them. */
typedef unsigned int u32;
extern float g_ts4_event_value;
extern float g_ts4_script_constants[];
extern char lbl_880EA0C8[];
extern void *fn_881CCD90(void *o);
typedef struct Sc2Obj { void *vt; char pad[0x30]; u32 w34; u32 w38; float m[9]; } Sc2Obj;

/* Swing_DLL.xex 0x8820F740 */
Sc2Obj *ts4_matrix_obj_ctor_8820F740(Sc2Obj *o)
{
    float one, zero;
    fn_881CCD90(o);
    o->vt = lbl_880EA0C8;
    one = g_ts4_script_constants[0];
    o->w34 = 0;
    zero = g_ts4_event_value;
    o->m[8] = one; o->m[4] = one; o->m[0] = one;
    o->m[7] = zero; o->m[6] = zero; o->m[5] = zero; o->m[3] = zero; o->m[2] = zero; o->m[1] = zero;
    return o;
}
