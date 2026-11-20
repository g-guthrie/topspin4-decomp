/* agAO near-miss (2 off, /Oc): 0x888E9840 looks up a record by key in the null-hash table; if found, copies
 * f28 into f24 and clears script prop B1CA7E98 on obj.
 * Remaining diff: the target does `mr r31,r3` before the `stw r4,0x7c(r1)` home store; we store first.
 * /Os, LTCG, a .cpp extern "C" build, and an int key all give the same order. */
typedef unsigned int u32; typedef unsigned char u8;
typedef struct Rec24 { u8 pad[0x24]; u32 f24; u32 f28; } Rec24;
extern void *ts4_hash_find_null_888E1D40(void);
extern Rec24 *ts4_find_record_by_key_881877A8(void *tbl, u32 *key);
extern void ts4_clear_script_prop_B1CA7E98_888C8190(void *obj);

void ts4_restore_record_and_clear_prop_888E9840(void *obj, u32 key)
{
    Rec24 *r = ts4_find_record_by_key_881877A8(ts4_hash_find_null_888E1D40(), &key);
    if (r) {
        r->f24 = r->f28;
        ts4_clear_script_prop_B1CA7E98_888C8190(obj);
    }
}
