/*
 * DRAFT (not part of the matching build). PR2 near misses on the section 3 path.
 *
 * fn_888E6FF8 (0x888E6FF8, size 0xF8), 2 instructions off: `ori r4` (hash 0xC750E1AC) and `addi r5,r1,0x68`
 *   (key address) are scheduled in the opposite order. Tried: statement permutation (permute.py, 400
 *   candidates), key/handle declaration order, a forceinline lookup helper, a key pointer local, a hash local,
 *   a C++ reference parameter. Called by CLoadingManager slot 17 (mode 2) when the new part is InGame.
 *   What it does: read GameDB:/GameDB/MatchSettings/@MatchType (XData handle via ts4_if_set_u32_off0_8862BE08);
 *   if the handle is valid and the hash (fn_88169350) is not 0xFB595DB2, look up entry 0xC750E1AC in the
 *   hash table [0x88D458F0] with key {engine+0x27c, 0x1DCA7285 (InGame), 1} and copy its +0x14 into +0x10.
 *   Then, when [0x88D45B0C] is set, call ts4_loop_call_seq_lbl_880D82D0_888E6DE0 (CurrentVenue/@Key users).
 *
 * fn_888EE258 (0x888EE258, size 0x134), 11 instructions off: r28 and r29 (self and the 0xFFFFF null-handle
 *   constant) are swapped; everything else matches. Tried: declaration orders, a shared/separate handle,
 *   a copy of self, statement permutation, the LTCG route.
 *   What it does: CInitPlayerSetups Init. Base Init (fn_88627EC0), resolve its XData node (hash 0xEFAD64BD),
 *   +0x1c = the node's relative reference at +0x20 (refreshed with fn_8892EE88), +0x20 = service 0x020CAFE9,
 *   +0x24 = service 0x8C5A4922 ->vt[0x4c](0), then fn_888EE0E8(self, v) where v is the word behind the
 *   optional reference at node+0x38 (present when node+0x34) or 0.
 */
typedef unsigned int u32;
typedef unsigned char u8;
#ifdef _MSC_VER
#define INL static __forceinline
#else
#define INL static inline __attribute__((unused))
#endif
typedef struct Tri { u32 a, b, c; } Tri;
typedef struct Ts4HashTable Ts4HashTable;
typedef struct Rec { u8 pad[0x10]; u32 f10; u32 f14; } Rec;
typedef struct Engine { u8 pad[0x27c]; u32 f27c; } Engine;
typedef struct Key3 { u32 a, b, c; } Key3;
extern Ts4HashTable *lbl_88D458F0;
extern Engine *lbl_88D45B1C;
extern void *lbl_88D45B0C;
extern Rec *ts4_hash_find_arg_88180F08(Ts4HashTable *table, u32 hash, Key3 *b, Tri h);
extern void ts4_if_set_u32_off0_8862BE08(void *out, const void *path);
extern void fn_88169350(u32 *out, Tri *in);
extern void ts4_loop_call_seq_lbl_880D82D0_888E6DE0(void);
extern const char lbl_880D891C[];

INL u8 handle_is_null(Tri *h, u32 nul)
{
    if (h->a == 0 || h->b == nul)
        return 1;
    return 0;
}

/* 0x888E6FF8 */
void ts4_match_type_apply_888E6FF8(void)
{
    Tri x;
    u32 nul;
    ts4_if_set_u32_off0_8862BE08(&x, lbl_880D891C);
    nul = 0xFFFFF;
    if (!handle_is_null(&x, nul)) {
        u32 h;
        fn_88169350(&h, &x);
        if (h != 0xFB595DB2) {
            Key3 k;
            Tri n;
            Rec *r;
            n.a = 0;
            n.b = nul;
            n.c = 0;
            k.a = lbl_88D45B1C->f27c;
            k.c = 1;
            k.b = 0x1DCA7285;
            r = ts4_hash_find_arg_88180F08(lbl_88D458F0, 0xC750E1AC, &k, n);
            r->f10 = r->f14;
        }
    }
    if (lbl_88D45B0C != 0)
        ts4_loop_call_seq_lbl_880D82D0_888E6DE0();
}

typedef struct RelRef { u32 f0; u32 off; u8 valid; u8 relative; u8 pad[2]; } RelRef;
typedef struct SetupNode { u8 pad[0x20]; RelRef ref20; u8 pad2c[8]; u8 has38; u8 pad35[3]; RelRef ref38; } SetupNode;
typedef struct SvcO SvcO;
typedef struct SvcV { u8 pad[0x4c]; void *(*get)(SvcO *, int); } SvcV;
struct SvcO { SvcV *vt; };
typedef struct InitPlayerSetups { u8 pad[0x1c]; u32 *f1c; void *f20; void *f24; } InitPlayerSetups;
extern void fn_88627EC0(void *self, Tri value);
extern SetupNode *fn_88923530(u32 pool, Tri h, u32 hash);
extern void fn_8892EE88(RelRef *ref, Tri h, u32 z);
extern u32 *ts4_if_call_seq_fn_8892EE88_88165000(RelRef *ref, Tri h, u32 z);
extern void *ts4_find_service(u32 id);
extern void fn_888EE0E8(InitPlayerSetups *self, u32 v);

INL void null_handle2(Tri *h) { h->a = 0; h->b = 0xFFFFF; h->c = 0; }
#define RELREF_RESOLVE(ref) \
    ((ref)->valid ? ((ref)->relative ? (u32 *)((char *)(ref) - (ref)->off) : (u32 *)(unsigned long)(ref)->off) : 0)

INL u32 *relref_get(RelRef *r, u32 z)
{
    Tri h;
    null_handle2(&h);
    fn_8892EE88(r, h, z);
    return RELREF_RESOLVE(r);
}

/* 0x888EE258: CInitPlayerSetups Init */
void ts4_init_player_setups_init_888EE258(InitPlayerSetups *self, Tri value)
{
    SetupNode *n;
    u32 v;
    fn_88627EC0(self, value);
    n = fn_88923530(value.c, value, 0xEFAD64BD);
    self->f1c = relref_get(&n->ref20, 0);
    v = 0;
    self->f20 = ts4_find_service(0x020CAFE9);
    if (n->has38) {
        RelRef *r = &n->ref38;
        u32 *p;
        Tri h;
        null_handle2(&h);
        fn_8892EE88(r, h, 1);
        p = ts4_if_call_seq_fn_8892EE88_88165000(r, h, 0);
        if (p)
            v = *p;
    }
    {
        SvcO *s = ts4_find_service(0x8C5A4922);
        self->f24 = s->vt->get(s, 0);
    }
    fn_888EE0E8(self, v);
}
