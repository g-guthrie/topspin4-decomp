/* Top Spin 4 (Xbox 360, Swing_DLL.xex) 0x888E9840: restore a keyed record's saved value (+0x28 into +0x24) and clear script property B1CA7E98 on the object.
 * Body unchanged from the equivalent-tier source named below (Q5S sweep, 2026-11-24): byte-exact now, see
 * work/specs/Q5S/sweep_888E9840.json for route and flags. */
/* from eq_q5_gameplay_small_c.c */
typedef unsigned int u32;
typedef unsigned char u8;
typedef struct Q5SavedRec { u8 pad[0x24]; u32 current; u32 saved; } Q5SavedRec;
extern void *ts4_hash_find_null_888E1D40(void);
extern Q5SavedRec *ts4_find_record_by_key_881877A8(void *tbl, u32 *key);
extern void ts4_clear_script_prop_B1CA7E98_888C8190(void *obj);

void ts4_restore_record_and_clear_prop_888E9840(void *obj, u32 key)
{
    Q5SavedRec *r = ts4_find_record_by_key_881877A8(ts4_hash_find_null_888E1D40(), &key);
    if (r) {
        r->current = r->saved;
        ts4_clear_script_prop_B1CA7E98_888C8190(obj);
    }
}
