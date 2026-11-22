/* Q5h1 clone: derived constructors that install a vtable after the base constructor (equivalent tier).
 * Clones of ts4_ctor_vtable_880E4528_887F4C18 (eq_q5_forwarders.c, template 0x887F4C18). Each sister has the
 * same body: call the base constructor fn_887F4BA0, then store a different vtable label through the pointer it
 * returns:
 *   0x887F4C60 -> lbl_880E4760      0x887F4CB0 -> lbl_880E4528
 *   0x887F4CF8 -> lbl_880E47F0      0x887F4EC8 -> lbl_880E4880
 * The original keeps a dead save of self in r31 and stores through the base constructor's returned r3, as the
 * template does. */
typedef struct Q5h1Obj887F4BA0 { const void *vtable; } Q5h1Obj887F4BA0;
extern const void *lbl_880E4528[];
extern const void *lbl_880E4760[];
extern const void *lbl_880E47F0[];
extern const void *lbl_880E4880[];
/* Base constructor; like every constructor it returns its object pointer. */
extern Q5h1Obj887F4BA0 *fn_887F4BA0(Q5h1Obj887F4BA0 *self);

/* Swing_DLL.xex 0x887F4C60 */
Q5h1Obj887F4BA0 *ts4_ctor_vtable_880E4760_887F4C60(Q5h1Obj887F4BA0 *self)
{
    Q5h1Obj887F4BA0 *obj = fn_887F4BA0(self);
    obj->vtable = lbl_880E4760;
    return obj;
}

/* Swing_DLL.xex 0x887F4CB0 */
Q5h1Obj887F4BA0 *ts4_ctor_vtable_880E4528_887F4CB0(Q5h1Obj887F4BA0 *self)
{
    Q5h1Obj887F4BA0 *obj = fn_887F4BA0(self);
    obj->vtable = lbl_880E4528;
    return obj;
}

/* Swing_DLL.xex 0x887F4CF8 */
Q5h1Obj887F4BA0 *ts4_ctor_vtable_880E47F0_887F4CF8(Q5h1Obj887F4BA0 *self)
{
    Q5h1Obj887F4BA0 *obj = fn_887F4BA0(self);
    obj->vtable = lbl_880E47F0;
    return obj;
}

/* Swing_DLL.xex 0x887F4EC8 */
Q5h1Obj887F4BA0 *ts4_ctor_vtable_880E4880_887F4EC8(Q5h1Obj887F4BA0 *self)
{
    Q5h1Obj887F4BA0 *obj = fn_887F4BA0(self);
    obj->vtable = lbl_880E4880;
    return obj;
}
