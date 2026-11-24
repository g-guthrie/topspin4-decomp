/* nearmiss (q5s 2026-11-24): 2 off; reg of size-8 (r10 vs r8); tried block scopes, size-=8, sizeof form, nested if */
/* NEAR MISS 0x88600D88 (2 instructions off on plain /Oc and LTCG, work/army/ME/v.py chk, matching-b129):
 * create an object from a serialized blob. The 8-byte header {u16 type, u16 sub, int} is copied and the object is
 * made by ts4_make_by_key_889BD910(type, sub). If made, its vtable slot 3 loads the payload (blob + 8, size - 8 by
 * pointer); on a false return the object is released through fn_889BD8B0 (the type-table dispatch at 0x889BD8B0,
 * matched as me_ts4_dispatch_message_by_id_889BD8B0) and 0 is returned.
 * Residue: only the register of `size - 8` (target r10, candidate r8). Tried: all 6 declaration orders, 0-8
 * operand-order pads, inline make(Key) wrapper, Key* parameter, unsigned/sizeof form, C++ virtual bool. */
typedef struct Key { unsigned short type; unsigned short sub; int extra; } Key;
typedef struct Obj Obj;
typedef struct ObjVt { void *s[3]; unsigned char (*load)(Obj *, const void *data, int *size); } ObjVt;
struct Obj { ObjVt *vt; };
Obj *ts4_make_by_key_889BD910(unsigned type, unsigned sub);
void fn_889BD8B0(Obj *o);
Obj *fn_88600D88(Key *b, int size)
{
    Key k = *b;
    Obj *o = ts4_make_by_key_889BD910(k.type, k.sub);
    int n = size - 8;
    if (o && !o->vt->load(o, b + 1, &n)) {
        fn_889BD8B0(o);
        o = 0;
    }
    return o;
}
