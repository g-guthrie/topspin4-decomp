/* 0x882D0F38: checks the format flags, wraps in/out (882DC6E0), then tries ten converters until one succeeds; always releases both wrappers. */
/* Matched on /O1 plain (agAC): the alloc tests and the || chain must be nested in one if so the S_OK block comes before E_FAIL. */
typedef struct Obj Obj;
typedef struct ObjVt { void (*destroy)(Obj *o, int flags); } ObjVt;
struct Obj { const ObjVt *vt; };
typedef struct Src { char pad[0x40]; unsigned f40; unsigned f44; unsigned f48; } Src;
typedef struct Ctx { Obj *out; Obj *in; unsigned flags; } Ctx;
Obj *fn_882DC6E0(Src *s);
int ts4_if_call_seq_u32_off8_882D1E88(Obj *in, Obj *out);
int fn_882CE298(Ctx *c);
int fn_882CE428(Ctx *c);
int fn_882CE560(Ctx *c);
int fn_882CE7B0(Ctx *c);
int fn_882CE9D0(Ctx *c);
int fn_882CEE78(Ctx *c);
int fn_882CF418(Ctx *c);
int fn_882CF778(Ctx *c);
int fn_882D0810(Ctx *c);
int fn_882D0030(Ctx *c);
int ts4_convert_surface_882D0F38(Ctx *c, Src *in, Src *out, unsigned flags)
{
    int r;
    c->flags = flags;
    c->out = 0;
    c->in = 0;
    if (!(flags & 0xFFFF) || (flags & 0xFFFF) > 5 || (flags & 0xFF800000))
        return (int)0x8876086C;
    out->f48 = flags & 0x00200000;
    in->f48 = flags & 0x00400000;
    in->f40 = flags & 0x00080000;
    in->f44 = flags & 0x00100000;
    c->in = fn_882DC6E0(in);
    if (c->in && (c->out = fn_882DC6E0(out)) != 0) {
        r = ts4_if_call_seq_u32_off8_882D1E88(c->in, c->out);
        if (r < 0) goto done;
        if (fn_882CE298(c) >= 0 || fn_882CE428(c) >= 0 || fn_882CE560(c) >= 0 || fn_882CE7B0(c) >= 0 || fn_882CE9D0(c) >= 0 || fn_882CEE78(c) >= 0 || fn_882CF418(c) >= 0 || fn_882CF778(c) >= 0 || fn_882D0810(c) >= 0 || fn_882D0030(c) >= 0) { r = 0; goto done; }
    }
    r = (int)0x80004005;
done:
    if (c->in) {
        c->in->vt->destroy(c->in, 1);
        c->in = 0;
    }
    if (c->out) {
        c->out->vt->destroy(c->out, 1);
        c->out = 0;
    }
    return r;
}
