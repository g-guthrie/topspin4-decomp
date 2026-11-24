/* near-miss 0x8867DC80 (plain /Oc): 62 instructions off, same size and flow. Open: missing clrrwi copy of the anim key before the first fn_8826C4F0 call (shifts everything by one), r28-r30 assignment of req/anims/e and row/ctx swapped. Tried ||-chained lookup (worse), mode-pointer inline (gave the second clrrwi), key accessor, if/else key local. */
/* 0x8867DC80: binds a shot request: picks the animation entry for the request key (alternate key when the actor is
 * mirrored, falling back to the first entry), selects the pose row by key (the 0x26296DD2 key wins when later and
 * the active body is flagged) and copies the row's timing into the output block. */
typedef unsigned int u32;
typedef struct RelTbl { int self_off; } RelTbl;
typedef struct AnimEnt { char p[0x1c]; int clip; char p2[0x2c - 0x20]; int frames; } AnimEnt;
typedef struct PoseRow { char p[0x3c]; char sub[0x58 - 0x3c]; int start; float time; char p2[0x6c - 0x60]; } PoseRow;
typedef struct ShotBank { char p[0x58]; RelTbl rows; char p2[0x64 - 0x5c]; RelTbl alt_rows; char p3[0xb8 - 0x68]; RelTbl anims; } ShotBank;
typedef struct KeyEnt { char p[0xbc]; u32 key; u32 mirror_key; } KeyEnt;
typedef struct ShotReq { char p[4]; u32 pose_key; u32 anim_key; char p2[0x10 - 0xc]; int id; } ShotReq;
typedef struct ShotFlags { char p[0x327]; unsigned char mirrored; } ShotFlags;
typedef struct ShotActor { char p[0x30]; ShotFlags *flags; } ShotActor;
typedef struct ShotBody { char p[0x10]; unsigned char flagged; } ShotBody;
typedef struct ShotMode { char p[0x10]; ShotBody **bodies; char p2[0x2c - 0x14]; int kind; } ShotMode;
typedef struct ShotOut2 { char p[0xf10]; float time; } ShotOut2;
typedef struct ShotCtx { ShotBody body; char p[0x18 - sizeof(ShotBody)]; int side; char p2[0x48 - 0x1c]; ShotActor *actor; ShotMode *mode;
    char p3[0x74 - 0x50]; ShotOut2 *out; char p4[0x7c - 0x78]; ShotReq *req; } ShotCtx;
typedef struct ShotDst { char p[0x50]; int clip; char p2[0x58 - 0x54]; int frames; int start; } ShotDst;
typedef struct ShotSrc { char p[0x18]; char sub[1]; } ShotSrc;
typedef struct ShotBind {
    char p[8]; ShotCtx *ctx; char p2[0x18 - 0xc]; ShotSrc *src; AnimEnt *anim; int row; char p3[0x28 - 0x24];
    ShotDst *dst; ShotBank *bank; PoseRow *pose;
} ShotBind;
KeyEnt *ts4_find_entry_by_key_8867AB78(ShotCtx *o, int key);
void *fn_8826C4F0(RelTbl *t, u32 *key);
void ts4_pick_entry_88671350(ShotBind *self);
void fn_886710B0(ShotBind *self, void *p);
int ts4_find_key_88661950(ShotBind *s, u32 key);
static __inline AnimEnt *find_anim(RelTbl *t, u32 key) { u32 k = key; return (AnimEnt *)fn_8826C4F0(t, &k); }
static __inline ShotBody *active_body(ShotMode *m, ShotCtx *c)
{
    if (m->kind == 2) return m->bodies[c->side == 0];
    return &c->body;
}
void fn_8867DC80(ShotBind *s)
{
    ShotReq *req = s->ctx->req;
    KeyEnt *e = ts4_find_entry_by_key_8867AB78(s->ctx, req->id);
    ShotBank *b = s->bank;
    RelTbl *anims = &b->anims;
    int row;
    ShotCtx *c;
    RelTbl *rows;
    req->anim_key = s->ctx->actor->flags->mirrored ? e->mirror_key : e->key;
    {
        AnimEnt *a = find_anim(anims, req->anim_key);
        if (a) s->anim = a;
        else {
            a = find_anim(anims, e->key);
            if (a) s->anim = a;
            else s->anim = (AnimEnt *)((char *)anims + anims->self_off);
        }
    }
    s->dst->clip = s->anim->clip;
    s->dst->frames = s->anim->frames;
    ts4_pick_entry_88671350(s);
    fn_886710B0(s, s->src->sub);
    row = ts4_find_key_88661950(s, req->pose_key);
    c = s->ctx;
    if (c->mode->kind == 2 && active_body(c->mode, c)->flagged) {
        int r2 = ts4_find_key_88661950(s, 0x26296DD2u);
        if (r2 >= row) row = r2;
    }
    s->row = row;
    if (row == -1) s->row = 0;
    rows = c->mode->kind == 2 ? &b->alt_rows : &b->rows;
    s->pose = (PoseRow *)(((char *)rows + s->row * sizeof(PoseRow)) + rows->self_off);
    s->dst->start = s->pose->start;
    fn_886710B0(s, s->pose->sub);
    s->ctx->out->time = s->pose->time;
}
