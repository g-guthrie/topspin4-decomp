extern const float g_ts4_script_constants[];
extern const float lbl_8814B45C;
typedef struct W10Vt { void *s[64]; } W10Vt;
struct W10C30 { unsigned char pad[0x330]; float f330; };
struct W10C38 { unsigned char pad[0x1d4]; int i1d4; };
struct W10C4 { unsigned char pad[0x30]; struct W10C30 *p30; unsigned char pad34[4]; struct W10C38 *p38; unsigned char pad2[0x4c - 0x3c]; void *p4c; };
struct W10C8 { unsigned char pad[0x34]; unsigned char b34; };
typedef struct W10Obj { W10Vt *vt; struct W10C4 *p4; struct W10C8 *p8; int w0c; int w10; int w14; int w18; } W10Obj;
typedef void (*W10Fn)(W10Obj *);
extern void fn_88674BC8(void *);

void ts4_state_enter_reset_88677918(W10Obj *o)
{
    o->w0c = 0;
    o->w10 = 0;
    o->w14 = 0;
    o->w18 = 1;
    ((W10Fn)o->vt->s[0x3c / 4])(o);
    ((W10Fn)o->vt->s[0x38 / 4])(o);
    ((W10Fn)o->vt->s[0x1c / 4])(o);
    fn_88674BC8(o->p4->p4c);
    o->p4->p30->f330 = g_ts4_script_constants[0];
    o->p8->b34 = 1;
}

void ts4_state_enter_reset_select_88677CE0(W10Obj *o)
{
    o->w0c = 0;
    ((W10Fn)o->vt->s[0x3c / 4])(o);
    ((W10Fn)o->vt->s[0x38 / 4])(o);
    ((W10Fn)o->vt->s[0x1c / 4])(o);
    fn_88674BC8(o->p4->p4c);
    o->p8->b34 = 1;
    if (o->p4->p38->i1d4 == 0x15)
        o->p4->p30->f330 = lbl_8814B45C;
    else
        o->p4->p30->f330 = g_ts4_script_constants[0];
}

void ts4_state_enter_reset_select_88677500(W10Obj *o)
{
    o->w10 = 0;
    o->w0c = 0;
    o->w14 = 0;
    o->w18 = 1;
    ((W10Fn)o->vt->s[0x38 / 4])(o);
    ((W10Fn)o->vt->s[0x3c / 4])(o);
    ((W10Fn)o->vt->s[0x1c / 4])(o);
    fn_88674BC8(o->p4->p4c);
    o->p8->b34 = 1;
    if (o->p4->p38->i1d4 == 0x15)
        o->p4->p30->f330 = lbl_8814B45C;
    else
        o->p4->p30->f330 = g_ts4_script_constants[0];
}
