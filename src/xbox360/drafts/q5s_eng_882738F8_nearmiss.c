/* nearmiss: 2 off (LTCG /Oc, context flags(/Ob1):me_keyed_entry_dispatch_88657C70.c + pp1_pool_primer.c, --include ts4_keyed_entry_dispatch_88657C70).
 * Only the hash constant register differs: target `lis r8; ori r7,r8,0x50ea; stw r7`, candidate keeps r8.
 * Tried: local, inline getter, one-member struct (Ga3Id) by value through an inline setter, volatile store, int field,
 * C++ member with KHash ctor, statement orders; perm_auto (140 candidates) found nothing.
 * Blocker: the lis/ori split register needs an extra live temp at that point; likely the caller-side shape of the
 * message struct (built by an unmatched inline ctor in the original) - revisit when the W8d message type is shared. */
typedef unsigned int u32;
typedef unsigned char u8;
typedef struct KObj KObj;
typedef struct KObjVt { void *slot[19]; u32 (*get_id)(KObj *o); } KObjVt;
struct KObj { const KObjVt *vt; };
typedef struct KMsg { u32 kind; u32 hash; u32 value; } KMsg;
u8 ts4_keyed_entry_dispatch_88657C70(KObj *o, KMsg *a, u32 id);
void ts4_kobj_post_id_882738F8(KObj *o, KMsg *m)
{
    m->kind = 0xc;
    m->value = o->vt->get_id(o);
    m->hash = 0x487850EA;
    ts4_keyed_entry_dispatch_88657C70(o, m, 0);
}
