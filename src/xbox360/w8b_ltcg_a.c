typedef unsigned int u32;
struct W8bRelU32 { int off; u32 count; };
struct W8bCmd { u32 *idp; struct W8bRelU32 *tbl; u32 w08; u32 mask; };
struct W8bCmdList { u32 pad00; u32 pad04; struct W8bCmd *begin; struct W8bCmd *end; };
extern int ts4_rel_u32_index_of_886C5CB0(struct W8bRelU32 *self, const unsigned *key);

void ts4_poll_command_masks_886C5D20(struct W8bCmdList *l)
{
    struct W8bCmd *end = l->end;
    struct W8bCmd *p;
    for (p = l->begin; p != end; p++) {
        u32 id = *p->idp;
        int idx;
        if (id == 0) {
            p->mask = 0;
        } else {
            idx = ts4_rel_u32_index_of_886C5CB0(p->tbl, &id);
            p->mask = (idx >= 0) ? (1u << idx) : 0;
        }
    }
}
