/* Q5 batch J (Opus A): small gameplay helpers byte-matched on b215 (TS4_MATCHING_DIR=work/matching-b215),
 * with and without /Oc. */
typedef unsigned int u32;
typedef unsigned short u16;
typedef struct Q5KeyVal { u32 key; u32 aux; u32 value; } Q5KeyVal;
typedef struct Q5KeyTable { char pad[0x84]; Q5KeyVal *begin; Q5KeyVal *end; } Q5KeyTable;
typedef struct Q5Global70 { char pad[0x70]; void *owner; } Q5Global70;
typedef struct Q5Engine27C { char pad[0x27c]; u32 none; } Q5Engine27C;
extern Q5Global70 *lbl_88D41FC4;
extern Q5Engine27C *lbl_88D45B1C;
extern void fn_882107D0(void *owner, u32 *hash, int flag);

/* Swing_DLL.xex 0x8886B840: find key in the 12-byte (key, aux, value) table at +0x84 (falls through to the end slot);
 * when its value is set, release it through the owner service (882107D0) and reset it to the engine's "none" handle, returning 1 */
unsigned char ts4_keytable_release_8886B840(Q5KeyTable *self, u32 key)
{
    Q5KeyVal *it = self->begin;
    u32 *v;
    while (it != self->end && key != it->key)
        it++;
    v = &it->value;
    if (*v) {
        fn_882107D0(lbl_88D41FC4->owner, v, 0);
        *v = lbl_88D45B1C->none;
        return 1;
    }
    return 0;
}

typedef struct Q5Vec16 { u16 *first; u16 *last; u16 *end; } Q5Vec16;
typedef struct Q5WordVec { u32 *first; u32 *last; u32 *end; } Q5WordVec;
typedef struct Q5SlotRef { char pad[0x14]; u32 index; } Q5SlotRef;
typedef struct Q5Layout { u32 tag; u32 width; } Q5Layout;
typedef struct Q5LayoutItem {
    Q5Vec16 marks; char pad0c[0x28 - 0xc];
    Q5SlotRef *slot;
    Q5WordVec words;
} Q5LayoutItem;
typedef struct Q5LayoutPool { char pad[0x68]; char cfg[0xf0 - 0x68]; Q5Layout **layouts; } Q5LayoutPool;
typedef struct Q5LayoutMode { char pad[8]; u32 mode; } Q5LayoutMode;
typedef struct Q5LayoutCtx { char pad[0x10]; Q5LayoutPool *pool; char pad14[8]; Q5LayoutMode *mode; } Q5LayoutCtx;
typedef struct Q5LayoutSys { Q5LayoutCtx *ctx; void *owner; char pad[0x18]; u32 extra; } Q5LayoutSys;
extern unsigned char fn_886CF518(Q5Layout *layout, Q5WordVec *words, u32 mode, Q5SlotRef *slot);
extern void ts4_vec16_resize_88262F70(Q5Vec16 *v, u32 n);
extern void fn_886CF1E0(Q5Layout *layout, Q5LayoutItem *item, u32 *first, u32 *last);
extern void fn_886C9AC0(void *owner, Q5LayoutItem *item, void *cfg, u32 extra);
/* Swing_DLL.xex 0x886D3A00: re-evaluate the item's layout (886CF518) against its slot and the context mode; when it changed
 * or force is set, clear the 16-bit marks, rebuild the item from its word list (886CF1E0) and notify the owner (886C9AC0) */
void ts4_layout_refresh_886D3A00(Q5LayoutSys *self, Q5LayoutItem *item, unsigned char force)
{
    Q5LayoutCtx *ctx = self->ctx;
    Q5LayoutPool *pool = ctx->pool;
    void *cfg = pool->cfg;
    Q5Layout *layout = pool->layouts[item->slot->index];
    if (fn_886CF518(layout, &item->words, ctx->mode->mode, item->slot) || force) {
        ts4_vec16_resize_88262F70(&item->marks, 0);
        fn_886CF1E0(layout, item, item->words.first, item->words.first + layout->width);
        fn_886C9AC0(self->owner, item, cfg, self->extra);
    }
}

typedef struct Q5TRef { int off; u32 kind; } Q5TRef;
typedef struct Q5TBranch { int off; char pad[0x10]; u32 order; } Q5TBranch;
typedef struct Q5TLeaf { char pad[4]; u32 index; } Q5TLeaf;
typedef struct Q5TRecord { char pad[0x8c]; } Q5TRecord;
typedef struct Q5TTable { char pad[8]; int off; } Q5TTable;
typedef struct Q5TWalker { char pad[0x18]; Q5TTable *table; } Q5TWalker;
extern Q5TRecord *fn_8826D8E0(int *records, Q5TLeaf *leaf);
static Q5TRecord *q5_records(int *rel) { return (Q5TRecord *)((char *)rel + *rel); }
/* Swing_DLL.xex 0x8865A9C8: number a self-relative tree: every branch node (kind 0x48BFC8B8) gets the next counter value at
 * +0x14 and its first child list is walked recursively; the leaf gets its record index in the walker's 0x8c-byte table */
void ts4_tree_number_8865A9C8(Q5TWalker *self, Q5TRef *node, u32 *counter)
{
    Q5TLeaf *leaf;
    Q5TRecord *rec;
    while (node->kind == 0x48BFC8B8) {
        int off = node->off;
        Q5TBranch *b = (Q5TBranch *)((char *)node + off);
        Q5TRef *kids;
        b->order = *counter;
        (*counter)++;
        ts4_tree_number_8865A9C8(self, (Q5TRef *)((char *)b + b->off), counter);
        kids = (Q5TRef *)((char *)b + b->off);
        node = &kids[1];
    }
    leaf = (Q5TLeaf *)((char *)node + node->off);
    rec = fn_8826D8E0(&self->table->off, leaf);
    leaf->index = (u32)(rec - q5_records(&self->table->off));
}
