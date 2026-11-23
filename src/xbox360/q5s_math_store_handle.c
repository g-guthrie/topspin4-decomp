/*
 * 0x88655718: loads a handle for a key from one of two stores. Clears the out handle; when *flag is
 * set it asks the object held at +0x220 of the global manager (lbl_88D45B1C), otherwise the fallback
 * store lbl_88D45B2C (when present). Both go through vtable slot +0x30 with kind 3, -1, 0, which
 * returns a pointer to a temporary handle; its word is copied out.
 * Callers: me_ts4_load_tagged_resource.c and w9d_88658b90.c (same prototype).
 *
 * Codegen: read the flag byte into a local before clearing out->v (the target loads the byte first),
 * and keep the sret-style struct returns, as in the sibling w8b_88655800.c.
 */
typedef unsigned int u32;
typedef unsigned char u8;

struct Q5sHKey;
typedef struct Q5sHRet {
    u32 v;
} Q5sHRet;

typedef struct Q5sHStoreVt {
    unsigned char pad00[0x30];
    Q5sHRet *(*load)(Q5sHRet *ret, void *self, struct Q5sHKey *key, int kind, int a, int b); /* +0x30 */
} Q5sHStoreVt;

typedef struct Q5sHStore {
    Q5sHStoreVt *vt;
} Q5sHStore;

typedef struct Q5sHMgr {
    unsigned char pad00[0x220];
    Q5sHStore *store; /* +0x220 */
} Q5sHMgr;

extern Q5sHMgr *lbl_88D45B1C;
extern Q5sHStore *lbl_88D45B2C;

typedef struct Q5sHOut {
    u32 v;
} Q5sHOut;

Q5sHOut *ts4_store_load_handle_88655718(Q5sHOut *out, const u8 *flag, struct Q5sHKey *key)
{
    Q5sHRet tmp;
    Q5sHRet *r;
    u8 f = *flag;
    out->v = 0;
    if (f != 0) {
        Q5sHStore *s = lbl_88D45B1C->store;
        r = s->vt->load(&tmp, s, key, 3, -1, 0);
        out->v = r->v;
    } else if (lbl_88D45B2C != 0) {
        r = lbl_88D45B2C->vt->load(&tmp, lbl_88D45B2C, key, 3, -1, 0);
        out->v = r->v;
    }
    return out;
}
