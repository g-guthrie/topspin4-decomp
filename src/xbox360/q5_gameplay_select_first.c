/* Q5 gameplay: 0x887F1050 selects the manager entry for the first id of the
 * object's id list (vtable slot 0x44, flag 1). Byte-matches with the default flags.
 * Codegen: `srawi.` plus `clrrwi r4,r10,0` come from an unsigned size() helper
 * tested with `> 0` and a separate front() helper re-reading begin. */
typedef unsigned int u32;
typedef struct Q5Sel Q5Sel;
typedef struct Q5SelVt {
    void *s[0x11];
    void (*select)(Q5Sel *self, void *entry, int flag);     /* +0x44 */
} Q5SelVt;
typedef struct Q5U32Vec { u32 *begin; u32 *end; } Q5U32Vec;
struct Q5Sel {
    Q5SelVt *vt;
    char pad4[0xe4];
    Q5U32Vec ids;       /* +0xe8 */
};
extern void *fn_887F0CA0(Q5Sel *self, u32 *id);

static __inline unsigned q5_vec_size(Q5U32Vec *v) { return v->end - v->begin; }
static __inline u32 *q5_vec_front(Q5U32Vec *v) { return v->begin; }

/* Swing_DLL.xex 0x887F1050 */
void ts4_select_first_887F1050(Q5Sel *self)
{
    if (q5_vec_size(&self->ids) > 0)
        self->vt->select(self, fn_887F0CA0(self, q5_vec_front(&self->ids)), 1);
}
