/* Top Spin 4 (Xbox 360, Swing_DLL.xex) 0x888E9898: find the record for `key` in the table returned by the null-handle lookup of hash 0x042947AB;
 * when found, copy its +0x24 word to +0x28, clear the script property and service every u32 in the record's
 * self-relative array (+0x0 offset, +0x4 count).
 * Body unchanged from the equivalent-tier source named below (Q5S sweep, 2026-11-24): byte-exact now, see
 * work/specs/Q5S/sweep_888E9898.json for route and flags. */
/* from eq_q5_gameplay_small_h.c */
typedef unsigned int u32;
typedef struct Q5PropRec { int off; u32 count; char pad08[0x1c]; u32 f24; u32 f28; } Q5PropRec;
typedef struct Q5PropHolder Q5PropHolder;
extern void *ts4_hash_find_null_888E1D40(void);
extern Q5PropRec *ts4_find_record_by_key_881877A8(void *tbl, u32 *key);
extern void ts4_clear_script_prop_052C33A9_888C82D0(Q5PropHolder *self);
extern void ts4_hash_service_str_888C8370(Q5PropHolder *self, u32 value);

static __inline u32 *q5_rel_end(Q5PropRec *r)
{
    u32 *e = 0;
    if (r->off != -1)
        e = (u32 *)((char *)r + r->off) + r->count;
    return e;
}
static __inline u32 *q5_rel_begin(Q5PropRec *r)
{
    u32 *b = 0;
    if (r->off != -1)
        b = (u32 *)((char *)r + r->off);
    return b;
}

void ts4_apply_prop_record_888E9898(Q5PropHolder *self, u32 key)
{
    Q5PropRec *r = ts4_find_record_by_key_881877A8(ts4_hash_find_null_888E1D40(), &key);
    if (r) {
        u32 *it;
        u32 *end;
        r->f28 = r->f24;
        ts4_clear_script_prop_052C33A9_888C82D0(self);
        end = q5_rel_end(r);
        for (it = q5_rel_begin(r); it != end; it++)
            ts4_hash_service_str_888C8370(self, *it);
    }
}
