/* 0x883DBEF8: releases a list item: 0x21 when busy (+0x11) unless forced; unless forced, refuses (0x38) while its handle reports pending state or its active current/indexed child is locked (word flag tests via the unsigned-char shift form); detaches the handle at +0x18, closing it unless flag 0x400; unlinks, self-links and frees the item */
/* Matched on /O1 plain and LTCG (agX, v.py chk). */
typedef struct Mgr { int p0; void *heap; } Mgr;
extern Mgr *lbl_88B3302C;
extern char lbl_88039468[];
typedef struct Link { struct Link *next; struct Link *prev; } Link;
typedef struct C2 { char pad[0x188]; unsigned int flags; } C2;
typedef struct C1 { char pad[0x108]; C2 *c2; } C1;
typedef struct Info { char pad[0x24]; unsigned int flags; } Info;
typedef struct H H;
typedef struct HVt { void *f0, *f1; unsigned char (*active)(H *h); } HVt;
struct H {
    HVt *vt;
    char pad0[0x40 - 4];
    unsigned int flags;
    C1 *c1;
    char pad1[0x88 - 0x48];
    H **kids;
    H *cur;
    char pad2[0x9c - 0x90];
    int idx;
    char pad3[0x120 - 0xa0];
    Info *info;
};
typedef struct Item { int vt; Link link; int fc; char pad[1]; unsigned char busy; char pad2[2]; unsigned int flags; H *h; } Item;
void fn_88315F10(void *heap, void *buf, const char *file, int line);
int ts4_if_get_fn_8832BFC0_88316BB0(H *h, int *out, int a, int b);
int ts4_if_get_fn_8832BFC0_88317EC0(H *h);

int fn_883DBEF8(Item *it, unsigned char force)
{
    int st, r;
    H *h;
    if (it->busy && !force)
        return 0x21;
    if (it->h) {
        if (!force) {
            H *o;
            h = it->h;
            r = ts4_if_get_fn_8832BFC0_88316BB0(h, &st, 0, 0);
            if (r)
                return r;
            if (st)
                return 0x38;
            if (h->vt->active(h)) {
                o = h;
                if (h->cur)
                    h = h->cur;
                else if (h->kids)
                    h = h->kids[h->idx];
                if (h) {
                    if ((unsigned char)((h->info->flags >> 13) & 1) && !(o->flags & 0x40) && !(h->flags & 0x40))
                        return 0x38;
                    if ((unsigned char)((h->c1->c2->flags >> 4) & 1))
                        return 0x38;
                }
            }
        }
        {
            unsigned int fl = it->flags;
            h = it->h;
            it->h = 0;
            if (!(fl & 0x400)) {
                r = ts4_if_get_fn_8832BFC0_88317EC0(h);
                if (r)
                    return r;
            }
        }
    }
    it->link.prev->next = it->link.next;
    it->link.next->prev = it->link.prev;
    it->link.prev = &it->link;
    it->link.next = &it->link;
    it->fc = 0;
    fn_88315F10(lbl_88B3302C->heap, it, lbl_88039468, 0x92);
    return 0;
}
