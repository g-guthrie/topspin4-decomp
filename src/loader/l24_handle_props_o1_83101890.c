/* Loader_DLL.xex 0x83101890-0x83104580, executable version 0.0.0.3. */

#ifdef _MSC_VER
#define TS4L_NOINLINE __declspec(noinline)
#else
#define TS4L_NOINLINE
#endif

/* Handle table: 512-entry pages of 12-byte entries, indexed by the low 16 bits of a handle. */
typedef struct ts4l_hent { unsigned short tag; unsigned short flags; void **ptr; } ts4l_hent;
typedef struct ts4l_htable { ts4l_hent *pages[136]; unsigned count; } ts4l_htable;
extern ts4l_htable lbl_8352F8F0;

typedef struct ts4l_fval { int type; float f; } ts4l_fval;
typedef struct ts4l_ival { int type; int i; } ts4l_ival;

/* Resolve a handle to its object (same-file copy of the shared lookup helper). */
TS4L_NOINLINE static int fn_830FF250(unsigned h, void **out)
{
    unsigned idx;
    ts4l_hent *e;
    char *o;
    if (!out) return 0x80070057;
    *out = 0;
    idx = h & 0xffff;
    if (h != 0 && idx < lbl_8352F8F0.count) {
        e = lbl_8352F8F0.pages[idx >> 9] + (idx & 0x1ff);
        if ((e->flags & 1) == 1 && e->tag == (h >> 16)) {
            o = (char *)e->ptr;
            if (o) {
                o = *(char **)(o + 0x20);
                if (o) {
                    *out = o;
                    return 0;
                }
            }
        }
    }
    return 0x8030000a;
}

extern int fn_830FD668(void *o, int v);
extern int fn_83101800(void *o, int v);
extern int fn_83121F68(void *o, int v);
extern int fn_8312ACB0(void *o, int v);
extern int fn_831354C8(void *o, int v);
extern int fn_831355E8(void *o, int v);
extern int ts4l_if_call_seq_u32_off94_83135580(void *o, int v);
extern int ts4l_if_get_u32_off8c_83135658(void *o, int v);

extern int fn_830FD5E0(void *o, float v);
extern int fn_830FD5E0(void *o, float v);
extern void fn_83131488(void *o, int v);
extern void fn_83131660(void *o, int v);

typedef struct ts4l_obj_83103950 { char pad0[0xc]; unsigned flags; char pad1[180]; float val; } ts4l_obj_83103950;
int ts4l_set_float_prop_83103950(void *self, unsigned h, ts4l_fval *v)
{
    ts4l_obj_83103950 *o;
    (void)self;
    fn_830FF250(h, (void **)&o);
    if (o && v->type == 4) {
        o->val = v->f;
        o->flags |= 2;
        return 0;
    }
    return 0x80070057;
}

typedef struct ts4l_obj_83103DF0 { char pad0[0xc]; unsigned flags; char pad1[152]; float val; } ts4l_obj_83103DF0;
int ts4l_set_float_prop_83103DF0(void *self, unsigned h, ts4l_fval *v)
{
    ts4l_obj_83103DF0 *o;
    (void)self;
    fn_830FF250(h, (void **)&o);
    if (o && v->type == 4) {
        o->val = v->f;
        o->flags |= 2;
        return 0;
    }
    return 0x80070057;
}

typedef struct ts4l_obj_83104050 { char pad0[0xc]; unsigned flags; char pad1[152]; float val; } ts4l_obj_83104050;
int ts4l_set_float_prop_83104050(void *self, unsigned h, ts4l_fval *v)
{
    ts4l_obj_83104050 *o;
    (void)self;
    fn_830FF250(h, (void **)&o);
    if (o && v->type == 4) {
        o->val = v->f;
        o->flags |= 2;
        return 0;
    }
    return 0x80070057;
}

typedef struct ts4l_obj_83104118 { char pad0[0xc]; unsigned flags; char pad1[152]; float val; } ts4l_obj_83104118;
int ts4l_set_float_prop_83104118(void *self, unsigned h, ts4l_fval *v)
{
    ts4l_obj_83104118 *o;
    (void)self;
    fn_830FF250(h, (void **)&o);
    if (o && v->type == 4) {
        o->val = v->f;
        o->flags |= 2;
        return 0;
    }
    return 0x80070057;
}

typedef struct ts4l_obj_83104180 { char pad0[0xc]; unsigned flags; char pad1[156]; float val; } ts4l_obj_83104180;
int ts4l_set_float_prop_83104180(void *self, unsigned h, ts4l_fval *v)
{
    ts4l_obj_83104180 *o;
    (void)self;
    fn_830FF250(h, (void **)&o);
    if (o && v->type == 4) {
        o->val = v->f;
        o->flags |= 2;
        return 0;
    }
    return 0x80070057;
}

typedef struct ts4l_obj_83104350 { char pad0[0xc]; unsigned flags; char pad1[152]; float val; } ts4l_obj_83104350;
int ts4l_set_float_prop_83104350(void *self, unsigned h, ts4l_fval *v)
{
    ts4l_obj_83104350 *o;
    (void)self;
    fn_830FF250(h, (void **)&o);
    if (o && v->type == 4) {
        o->val = v->f;
        o->flags |= 2;
        return 0;
    }
    return 0x80070057;
}

typedef struct ts4l_obj_831043B8 { char pad0[0xc]; unsigned flags; char pad1[156]; float val; } ts4l_obj_831043B8;
int ts4l_set_float_prop_831043B8(void *self, unsigned h, ts4l_fval *v)
{
    ts4l_obj_831043B8 *o;
    (void)self;
    fn_830FF250(h, (void **)&o);
    if (o && v->type == 4) {
        o->val = v->f;
        o->flags |= 2;
        return 0;
    }
    return 0x80070057;
}

typedef struct ts4l_obj_83104580 { char pad0[0xc]; unsigned flags; char pad1[152]; float val; } ts4l_obj_83104580;
int ts4l_set_float_prop_83104580(void *self, unsigned h, ts4l_fval *v)
{
    ts4l_obj_83104580 *o;
    (void)self;
    fn_830FF250(h, (void **)&o);
    if (o && v->type == 4) {
        o->val = v->f;
        o->flags |= 2;
        return 0;
    }
    return 0x80070057;
}

typedef struct ts4l_obj_831045E8 { char pad0[0xc]; unsigned flags; char pad1[156]; float val; } ts4l_obj_831045E8;
int ts4l_set_float_prop_831045E8(void *self, unsigned h, ts4l_fval *v)
{
    ts4l_obj_831045E8 *o;
    (void)self;
    fn_830FF250(h, (void **)&o);
    if (o && v->type == 4) {
        o->val = v->f;
        o->flags |= 2;
        return 0;
    }
    return 0x80070057;
}

typedef struct ts4l_obj_83102A50 { char pad0[8]; int val; } ts4l_obj_83102A50;
int ts4l_set_int_prop_83102A50(void *self, unsigned h, ts4l_ival *v)
{
    ts4l_obj_83102A50 *o;
    (void)self;
    fn_830FF250(h, (void **)&o);
    if (o && v->type == 2) {
        o->val = v->i;
        return 0;
    }
    return 0x80070057;
}

typedef struct ts4l_obj_83102AA8 { char pad0[12]; int val; } ts4l_obj_83102AA8;
int ts4l_set_int_prop_83102AA8(void *self, unsigned h, ts4l_ival *v)
{
    ts4l_obj_83102AA8 *o;
    (void)self;
    fn_830FF250(h, (void **)&o);
    if (o && v->type == 2) {
        o->val = v->i;
        return 0;
    }
    return 0x80070057;
}

typedef struct ts4l_obj_83102B58 { char pad0[16]; int val; } ts4l_obj_83102B58;
int ts4l_set_int_prop_83102B58(void *self, unsigned h, ts4l_ival *v)
{
    ts4l_obj_83102B58 *o;
    (void)self;
    fn_830FF250(h, (void **)&o);
    if (o && v->type == 2) {
        o->val = v->i;
        return 0;
    }
    return 0x80070057;
}

typedef struct ts4l_obj_83102BB0 { char pad0[20]; int val; } ts4l_obj_83102BB0;
int ts4l_set_int_prop_83102BB0(void *self, unsigned h, ts4l_ival *v)
{
    ts4l_obj_83102BB0 *o;
    (void)self;
    fn_830FF250(h, (void **)&o);
    if (o && v->type == 2) {
        o->val = v->i;
        return 0;
    }
    return 0x80070057;
}

typedef struct ts4l_obj_83102C60 { char pad0[28]; int val; } ts4l_obj_83102C60;
int ts4l_set_int_prop_83102C60(void *self, unsigned h, ts4l_ival *v)
{
    ts4l_obj_83102C60 *o;
    (void)self;
    fn_830FF250(h, (void **)&o);
    if (o && v->type == 2) {
        o->val = v->i;
        return 0;
    }
    return 0x80070057;
}

int ts4l_forward_prop_83102EC0(void *self, unsigned h, ts4l_ival *v)
{
    void *o;
    int hr = fn_830FF250(h, &o);
    (void)self;
    if (hr < 0) return hr;
    if (v->type != 3) return 0x80070057;
    return ts4l_if_get_u32_off8c_83135658(o, v->i);
}

int ts4l_forward_prop_83102F18(void *self, unsigned h, ts4l_ival *v)
{
    void *o;
    int hr = fn_830FF250(h, &o);
    (void)self;
    if (hr < 0) return hr;
    if (v->type != 5) return 0x80070057;
    return fn_83121F68(o, v->i);
}

int ts4l_forward_prop_83102F70(void *self, unsigned h, ts4l_ival *v)
{
    void *o;
    int hr = fn_830FF250(h, &o);
    (void)self;
    if (hr < 0) return hr;
    if (v->type != 5) return 0x80070057;
    return fn_831355E8(o, v->i);
}

int ts4l_forward_prop_83102FC8(void *self, unsigned h, ts4l_ival *v)
{
    void *o;
    int hr = fn_830FF250(h, &o);
    (void)self;
    if (hr < 0) return hr;
    if (v->type != 1) return 0x80070057;
    return fn_8312ACB0(o, v->i);
}

int ts4l_forward_prop_83103020(void *self, unsigned h, ts4l_ival *v)
{
    void *o;
    int hr = fn_830FF250(h, &o);
    (void)self;
    if (hr < 0) return hr;
    if (v->type != 1) return 0x80070057;
    return fn_831354C8(o, v->i);
}

int ts4l_forward_prop_83103078(void *self, unsigned h, ts4l_ival *v)
{
    void *o;
    int hr = fn_830FF250(h, &o);
    (void)self;
    if (hr < 0) return hr;
    if (v->type != 1) return 0x80070057;
    return ts4l_if_call_seq_u32_off94_83135580(o, v->i);
}

int ts4l_forward_sub_prop_83101890(void *self, unsigned h, ts4l_ival *v)
{
    char *o;
    int hr = fn_830FF250(h, (void **)&o);
    (void)self;
    if (hr < 0) return hr;
    if (o && v->type == 5)
        return fn_83101800(o + 4, v->i);
    return 0x80070057;
}

int ts4l_forward_sub_prop_83101950(void *self, unsigned h, ts4l_ival *v)
{
    char *o;
    int hr = fn_830FF250(h, (void **)&o);
    (void)self;
    if (hr < 0) return hr;
    if (o && v->type == 3)
        return fn_830FD668(o + 4, v->i);
    return 0x80070057;
}

int ts4l_forward_sub_prop_83102268(void *self, unsigned h, ts4l_ival *v)
{
    char *o;
    int hr = fn_830FF250(h, (void **)&o);
    (void)self;
    if (hr < 0) return hr;
    if (o && v->type == 5)
        return fn_83101800(o + 4, v->i);
    return 0x80070057;
}

int ts4l_forward_sub_prop_83102328(void *self, unsigned h, ts4l_ival *v)
{
    char *o;
    int hr = fn_830FF250(h, (void **)&o);
    (void)self;
    if (hr < 0) return hr;
    if (o && v->type == 3)
        return fn_830FD668(o + 4, v->i);
    return 0x80070057;
}

int ts4l_forward_sub_float_prop_831018F0(void *self, unsigned h, ts4l_fval *v)
{
    char *o;
    int hr = fn_830FF250(h, (void **)&o);
    (void)self;
    if (hr < 0) return hr;
    if (o && v->type == 4)
        return fn_830FD5E0(o + 4, v->f);
    return 0x80070057;
}

int ts4l_forward_sub_float_prop_831022C8(void *self, unsigned h, ts4l_fval *v)
{
    char *o;
    int hr = fn_830FF250(h, (void **)&o);
    (void)self;
    if (hr < 0) return hr;
    if (o && v->type == 4)
        return fn_830FD5E0(o + 4, v->f);
    return 0x80070057;
}

int ts4l_call_prop_83102B00(void *self, unsigned h, ts4l_ival *v)
{
    void *o;
    (void)self;
    fn_830FF250(h, &o);
    if (o && v->type == 2) {
        fn_83131488(o, v->i);
        return 0;
    }
    return 0x80070057;
}

int ts4l_call_prop_83102C08(void *self, unsigned h, ts4l_ival *v)
{
    void *o;
    (void)self;
    fn_830FF250(h, &o);
    if (o && v->type == 2) {
        fn_83131660(o, v->i);
        return 0;
    }
    return 0x80070057;
}

typedef struct ts4l_obj_831030D0 { char pad0[8]; int val; unsigned char set; } ts4l_obj_831030D0;
int ts4l_set_flagged_int_prop_831030D0(void *self, unsigned h, ts4l_ival *v)
{
    ts4l_obj_831030D0 *o;
    int hr = fn_830FF250(h, (void **)&o);
    (void)self;
    if (hr < 0) return hr;
    if (o && v->type == 3) {
        { int t = v->i; o->set = 1; o->val = t; }
        return 0;
    }
    return 0x80070057;
}

typedef struct ts4l_obj_83103318 { char pad0[8]; int val; unsigned char set; } ts4l_obj_83103318;
int ts4l_set_flagged_int_prop_83103318(void *self, unsigned h, ts4l_ival *v)
{
    ts4l_obj_83103318 *o;
    int hr = fn_830FF250(h, (void **)&o);
    (void)self;
    if (hr < 0) return hr;
    if (o && v->type == 3) {
        { int t = v->i; o->set = 1; o->val = t; }
        return 0;
    }
    return 0x80070057;
}

typedef struct ts4l_obj_83103138 { char pad0[0x84]; int val; } ts4l_obj_83103138;
int ts4l_set_int_prop84_83103138(void *self, unsigned h, ts4l_ival *v)
{
    ts4l_obj_83103138 *o;
    int hr = fn_830FF250(h, (void **)&o);
    (void)self;
    if (hr < 0) return hr;
    if (v->type != 3) return 0x80070057;
    o->val = v->i;
    return 0;
}

typedef struct ts4l_obj_83103380 { char pad0[0x84]; int val; } ts4l_obj_83103380;
int ts4l_set_int_prop84_83103380(void *self, unsigned h, ts4l_ival *v)
{
    ts4l_obj_83103380 *o;
    int hr = fn_830FF250(h, (void **)&o);
    (void)self;
    if (hr < 0) return hr;
    if (v->type != 3) return 0x80070057;
    o->val = v->i;
    return 0;
}

typedef struct ts4l_obj_831039B8 { char pad0[0xc]; unsigned flags; char pad1[196]; float x, y, z, w; } ts4l_obj_831039B8;
typedef struct ts4l_vec4val_831039B8 { int type; float x, y, z, w; } ts4l_vec4val_831039B8;
int ts4l_set_vec4_prop_831039B8(void *self, unsigned h, ts4l_vec4val_831039B8 *v)
{
    ts4l_obj_831039B8 *o;
    (void)self;
    fn_830FF250(h, (void **)&o);
    if (o && v->type == 8) {
        o->x = v->x;
        o->y = v->y;
        o->z = v->z;
        o->w = v->w;
        o->flags |= 2;
        return 0;
    }
    return 0x80070057;
}

typedef struct ts4l_obj_83103F70 { char pad0[0xc]; unsigned flags; char pad1[152]; float x, y, z, w; } ts4l_obj_83103F70;
typedef struct ts4l_vec4val_83103F70 { int type; float x, y, z, w; } ts4l_vec4val_83103F70;
int ts4l_set_vec4_prop_83103F70(void *self, unsigned h, ts4l_vec4val_83103F70 *v)
{
    ts4l_obj_83103F70 *o;
    (void)self;
    fn_830FF250(h, (void **)&o);
    if (o && v->type == 8) {
        o->x = v->x;
        o->y = v->y;
        o->z = v->z;
        o->w = v->w;
        o->flags |= 2;
        return 0;
    }
    return 0x80070057;
}


typedef struct ts4l_obj_83103A38 { char pad0[0xe8]; int val; } ts4l_obj_83103A38;
extern int ts4l_if_call_seq_u32_off8_830FE958(unsigned h, void *o);
int ts4l_set_int_notify_83103A38(void *self, unsigned h, ts4l_ival *v)
{
    ts4l_obj_83103A38 *o;
    (void)self;
    fn_830FF250(h, (void **)&o);
    if (o && v->type == 3) {
        o->val = v->i;
        ts4l_if_call_seq_u32_off8_830FE958(h, (char *)o + 4);
        return 0;
    }
    return 0x80070057;
}

typedef struct ts4l_obj_83103678 { char pad0[4]; unsigned flags; char pad1[0x18]; int val; } ts4l_obj_83103678;
int ts4l_set_int_flag_83103678(void *self, unsigned h, ts4l_ival *v)
{
    ts4l_obj_83103678 *o;
    int hr = fn_830FF250(h, (void **)&o);
    (void)self;
    if (hr < 0) return hr;
    if (o && v->type == 1) {
        o->val = v->i;
        o->flags |= 2;
        return 0;
    }
    return 0x80070057;
}

typedef struct ts4l_obj_83103AA0 { char pad0[0xec]; int val; } ts4l_obj_83103AA0;
int ts4l_set_int_notify_83103AA0(void *self, unsigned h, ts4l_ival *v)
{
    ts4l_obj_83103AA0 *o;
    (void)self;
    fn_830FF250(h, (void **)&o);
    if (o && v->type == 3) {
        o->val = v->i;
        ts4l_if_call_seq_u32_off8_830FE958(h, (char *)o + 4);
        return 0;
    }
    return 0x80070057;
}
