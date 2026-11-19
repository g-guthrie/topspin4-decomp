/* 0x883CA2A0: clamps a level to [0,1] and stores it at +0x30; the leaf applies progress, gain and a random jitter (+0x84) and sends it to the owner voice. */
/* Near miss LTCG /O1 with context me_ts4_progress_ratio_883C9520.c (agY): 15 off, the level and the jitter swap f30/f31. */
#ifdef _MSC_VER
#define PTR_INT(p) ((int)(p))
#else
#define PTR_INT(p) ((int)(long)(p))
#endif
typedef struct Node Node;
typedef struct Owner { Node *node; char pad[0x14]; void *voice; } Owner;
typedef struct List { int count; Node **items; } List;
typedef struct Mix { char pad[8]; int count; int pc; Node **items; } Mix;
typedef struct Sub { char pad[0x38]; Mix *mix; } Sub;
typedef struct Sys { char pad[0x30]; Sub *sub; } Sys;
extern const float lbl_88001A20;
extern const float lbl_880023F0;
int ts4_crt_rand_88564110(void);
struct Node {
    char pad0[0x28];
    Sys *sys;
    char pad1[0x4];
    float val;
    float gain;
    char pad2[0x2c];
    short flags;
    char pad3[0x1e];
    float jitter;
    char pad4[0x20];
    List *list;
    Owner *owner;
};

float ts4_progress_ratio_883C9520(Node *n);
int ts4_fetch_then_use_float_88317A60(void *voice, float v);
static unsigned char is_grp(Node *n) { return (unsigned char)(((unsigned)n->flags >> 5) & 1); }

int fn_883CA2A0(Node *self, float v, unsigned char deep)
{
    int i, r;
    Node *n = self;
    if (v > 1.0f)
        v = 1.0f;
    if (v < lbl_88001A20)
        v = lbl_88001A20;
    if (deep) {
        if (n->owner ? n->owner->node : 0)
            n = n->owner ? n->owner->node : 0;
        n->val = v;
        if (is_grp(n)) {
            Mix *m = n->sys->sub->mix;
            int cnt = m->count;
            Node **items = m->items;
            for (i = 0; i < cnt; i++) {
                if (items[i] && (items[i]->owner ? items[i]->owner->node : 0) == n && (items[i]->flags & 0x80)) {
                    r = fn_883CA2A0(items[i], v, 0);
                    if (r)
                        return r;
                }
            }
        } else {
            for (i = 0; i < n->list->count; i++) {
                if (PTR_INT(n->list->items) != 0 && n->list->items[i]) {
                    r = fn_883CA2A0(n->list->items[i], v, 0);
                    if (r)
                        return r;
                }
            }
        }
    } else {
        self->val = v;
        if (self->owner ? self->owner->voice : 0) {
            float j;
            v = ts4_progress_ratio_883C9520(self) * self->gain * v;
            j = self->jitter;
            if (j != lbl_88001A20)
                v = ((float)ts4_crt_rand_88564110() * lbl_880023F0 * j + (1.0f - j)) * v;
            r = ts4_fetch_then_use_float_88317A60(self->owner ? self->owner->voice : 0, v);
            if (r)
                return r;
        }
    }
    return 0;
}
