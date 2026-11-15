typedef unsigned int u32;
struct W8bCmdRec { unsigned char pad00[0xd8]; u32 frame; unsigned char scheduled; };
struct W8bRelHdr { int rel; };
struct W8bPlayer { unsigned char pad00[0x14]; u32 index; };
struct W8bGroup { unsigned char pad00[0x10]; struct W8bPlayer **begin; struct W8bPlayer **end; };
struct W8bMatch { unsigned char pad00[0x70]; struct W8bRelHdr hdr; unsigned char pad74[8]; int active_group; };
struct W8bInst { unsigned char pad00[0x10]; struct W8bGroup **groups; unsigned char pad14[0x1c]; struct W8bMatch *match; };

static __inline struct W8bPlayer **w8b_gbegin(struct W8bGroup *g) { return g->begin; }
static __inline int w8b_gsize(struct W8bGroup *g) { return g->end - g->begin; }

int ts4_find_scheduled_frame_8866E250(struct W8bInst *inst, u32 *out)
{
    struct W8bMatch *m = inst->match;
    struct W8bRelHdr *h = &m->hdr;
    int n = w8b_gsize(inst->groups[m->active_group]);
    int i;
    int ok = 0;
    for (i = 0; i < n; i++) {
        struct W8bCmdRec *r = (struct W8bCmdRec *)((char *)h + (w8b_gbegin(inst->groups[m->active_group])[i]->index * 0xe0 + h->rel));
        if (r->scheduled == 1) {
            *out = r->frame;
            ok = 1;
            break;
        }
    }
    return ok;
}
