/* DRAFT (Q5, escalated): 0x888795F8. fn_equiv agrees on every valid trial (2859 of 4000,
 * seed 1, /Oc) but coverage stays at 8/9 blocks (89%): the one uncovered block is the
 * negative-index path, which sets the item to null and then reads +0x70 of it, so the
 * original faults on every input that reaches it and those trials are discarded.
 * Equivalent-route source below; see work/q5/escalate.json. */
typedef unsigned int u32;
typedef unsigned char u8;

/* ---- 0x888795F8: 1 when any mapped item's key (+0x70) passes fn_881643D0(arg, key);
 * the map (+0x20) holds item indices into +0x8, a negative one meaning none (the
 * original then reads +0x70 of a null item, kept as is).
 * Not byte-matched: the original hoists the map pointer and keeps a byte offset
 * beside the counter. */
typedef struct Q5Itm { char p[0x70]; void *key; } Q5Itm;
typedef struct Q5Cnt { char p[0x10]; int n; } Q5Cnt;
typedef struct Q5Tbl { char p[8]; Q5Itm **items; char pc[0x14]; int *map; char p24[8]; Q5Cnt *cnt; } Q5Tbl;
typedef struct Q5TblOwner { char p[0x10]; Q5Tbl *tbl; } Q5TblOwner;
extern u8 fn_881643D0(void *arg, void *key);

/* Swing_DLL.xex 0x888795F8 */
int ts4_tbl_any_match_888795F8(Q5TblOwner *self, void *arg)
{
    Q5Tbl *t = self->tbl;
    int i;
    int n = t->cnt->n;
    for (i = 0; i < n; i++) {
        int h = t->map[i];
        Q5Itm *it = h < 0 ? 0 : t->items[h];
        if (fn_881643D0(arg, it->key))
            return 1;
    }
    return 0;
}

