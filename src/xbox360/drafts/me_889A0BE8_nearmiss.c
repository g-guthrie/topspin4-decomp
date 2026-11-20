/* NEAR MISS (agO round 3, 2026-11-19): 4 off on plain and LTCG (/Oc), registers only: the self-relative add writes r9 (over the
 * offset) in the target and r11 (over the base) here. The int result = 0 local gives the target's r31 zero. */
/* Swing_DLL.xex 0x889A0BE8: follows the self-relative pointer at self->+0x24 +0x214 to its record, looks up the record's +0x30 key
 * in the session table (g_ts4_session_context->+0x68, +0x13c0) with ts4_find_entry_by_alt_id_88866C30 and returns the hit's word at +0xa8, or 0. */
typedef struct Hit { char pad[0xa8]; int value; } Hit;
typedef struct Rec { char pad[0x30]; int key; } Rec;
typedef struct Blob { char pad[0x214]; int rel; } Blob;
typedef struct Obj { char pad[0x24]; Blob *blob; } Obj;
typedef struct Sess { char pad[0x68]; char *tables; } Sess;
extern Sess *g_ts4_session_context;
Hit *ts4_find_entry_by_alt_id_88866C30(int key, void *table);

int fn_889A0BE8(Obj *o)
{
    int result = 0;
    Rec *r;
    Hit *h;
    int *rel = &o->blob->rel;
    r = (Rec *)((char *)rel + *rel);
    h = ts4_find_entry_by_alt_id_88866C30(r->key, g_ts4_session_context->tables + 0x13c0);
    if (h)
        result = h->value;
    return result;
}
