typedef unsigned int u32;
typedef unsigned char u8;
struct W8bRet { u32 v; };
struct W8bVt { unsigned char pad00[0x28]; struct W8bRet *(*slot)(struct W8bRet *ret, void *self, u32 a, int b, int c); };
struct W8bObjV { struct W8bVt *vt; };
struct W8bMgrG { unsigned char pad00[0x220]; struct W8bObjV *obj; };
extern struct W8bMgrG *lbl_88D45B1C;
extern struct W8bObjV *lbl_88D45B2C;
struct W8bOut { u32 v; };

struct W8bOut *ts4_query_handle_88655800(struct W8bOut *out, const u8 *flag, u32 key)
{
    struct W8bRet tmp;
    struct W8bRet *r;
    u8 f = *flag;
    out->v = 0;
    if (f != 0) {
        struct W8bObjV *o = lbl_88D45B1C->obj;
        r = o->vt->slot(&tmp, o, key, 2, 0);
        out->v = r->v;
    } else if (lbl_88D45B2C != 0) {
        r = lbl_88D45B2C->vt->slot(&tmp, lbl_88D45B2C, key, 2, 0);
        out->v = r->v;
    }
    return out;
}
