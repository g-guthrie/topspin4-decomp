/* 0x882DD5F0: allocates a 0x10-byte refcounted object (vtable lbl_88004DBC), runs its vt+0x18 init with self and stores it to *out; releases it on failure. */
/* Matched on /O1 plain (agAC). Needs the block_relocations entry for 0x8876086C (D3DERR_INVALIDCALL). */
typedef struct Obj Obj;
typedef struct ObjVt { void *f[5]; void (*release)(Obj *o, int flags); int (*init)(Obj *o, void *owner); } ObjVt;
struct Obj { const ObjVt *vt; int refs; int f8; int fc; };
extern const ObjVt lbl_88004DBC;
void *fn_88888668(unsigned size, unsigned tag);
int ts4_create_refobj_882DD5F0(void *self, Obj **out)
{
    Obj *o, *p;
    int r;
    if (!out) return (int)0x8876086C;
    p = (Obj *)fn_88888668(0x10, 0x24810000);
    if (p) {
        p->vt = &lbl_88004DBC;
        p->fc = 0;
        p->f8 = 0;
        p->refs = 1;
        o = p;
    } else {
        o = 0;
    }
    if (!o) return (int)0x8007000E;
    r = o->vt->init(o, self);
    if (r < 0) {
        o->vt->release(o, 1);
        return r;
    }
    *out = o;
    return 0;
}
