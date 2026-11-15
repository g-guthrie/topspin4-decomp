/*
 * Attribute-request lookup used by Lua ExecuteAttributeRequest (frontend-map section 2.1).
 *
 * 0x8879CD88 (0xEC) Tri *run(out, mgr, key): searches the request table at mgr+0x318 (self-relative
 * array {rel, count}, 0x18-byte records with the hash at +0x10) for key->hash (+4).  Found: evaluates
 * the request with fn_8879C7C0(&vec, mgr, record, key), which returns a vector of 0x1C-byte values;
 * when it is non-empty and the first value has type 2 (+0x18) its handle (first 12 bytes) is the
 * result, otherwise the null handle {0, 0xFFFFF, 0}; the vector storage is freed.  Not found: the null
 * handle.
 */
typedef unsigned int u32;
typedef unsigned char u8;
typedef struct Tri { u32 a; u32 b; u32 c; } Tri;
typedef struct AttrVal { u32 a; u32 b; u32 c; u8 pad[0xc]; u8 type; u8 pad19[3]; } AttrVal;
typedef struct AttrVec { AttrVal *begin; AttrVal *end; } AttrVec;
typedef struct ReqEnt { u8 pad[0x10]; u32 hash; u8 pad14[4]; } ReqEnt;
typedef struct ReqArr { int rel; int count; } ReqArr;
typedef struct AttrMgr { u8 pad[0x318]; ReqArr *reqs; } AttrMgr;
typedef struct ReqKey { u32 f0; u32 hash; } ReqKey;
extern void fn_8879C7C0(AttrVec *out, AttrMgr *m, ReqEnt *e, ReqKey *key);
extern void ts4_destroy_owned_object(void *p);

Tri *ts4_attr_request_run_8879CD88(Tri *out, AttrMgr *m, ReqKey *key)
{
    ReqArr *a = m->reqs;
    int i;
    for (i = 0; i < a->count; i++) {
        ReqEnt *e = (ReqEnt *)((char *)a + (i * 0x18 + a->rel));
        if (e->hash == key->hash) {
            AttrVec v;
            u32 x, y, z;
            fn_8879C7C0(&v, m, e, key);
            x = 0;
            z = 0;
            y = 0xFFFFF;
            if (v.end - v.begin != 0 && v.begin->type == 2) {
                x = v.begin->a;
                y = v.begin->b;
                z = v.begin->c;
            }
            out->a = x;
            out->b = y;
            out->c = z;
            if (v.begin)
                ts4_destroy_owned_object(v.begin);
            return out;
        }
    }
    out->a = 0;
    out->c = 0;
    out->b = 0xFFFFF;
    return out;
}
