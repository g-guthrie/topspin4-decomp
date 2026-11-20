/*
 * DRAFT (not byte-matched): Lua MatchStart_InitCoachObjectives (frontend-map section 2.1).
 *
 * 0x887964C8 (0x108) MatchStart_InitCoachObjectives(all): with all == "true" calls
 *   fn_8883D8D0([0x88D459E0]); otherwise sets the first word of each of the first four 0x14-byte slots
 *   (vector at +0x68/+0x6C, each guarded by the vector size) to -1.  Then fn_8884E478([0x88D459E0]).
 *   Returns 0.
 *   22 instructions off: the original loads [0x88D459E0] once before the branch on the string result
 *   and reloads it only after fn_8883D8D0; loading it before the branch in C changes the slot loop
 *   (no clrrwi reloads, 49 off), so the per-branch form is kept.
 * fn_equiv (work/equiv/pr2_887964C8.json): EQUIVALENT, 148 valid trials, 100% coverage.
 */
typedef unsigned int u32;
typedef unsigned char u8;
#ifdef _MSC_VER
#define INL static __forceinline
#else
#define INL static inline __attribute__((unused))
#endif
typedef struct Val { int type; u32 reserved; union { int integer; double number; } value; u8 payload[0x28]; } Val;
typedef struct Args { u8 reserved[0x380]; Val *items; u32 count; } Args;
typedef struct Ctx { u8 reserved[0x10]; Args *args; } Ctx;
extern Val *g_ts4_default_script_value;
extern const char g_ts4_true_string[];
INL Val *arg_at(Args *a, u32 i)
{
    if (a->count > i) {
        return &a->items[i];
    }
    return g_ts4_default_script_value;
}
typedef struct Slot { int player; u8 pad[0x10]; } Slot;
typedef struct SlotVec { Slot *begin; Slot *end; } SlotVec;
typedef struct PlayerSel { u8 pad[0x68]; SlotVec slots; } PlayerSel;
extern PlayerSel *lbl_88D459E0;
extern u8 ts4_script_string_equals(void *value, const char *text);
extern void fn_8883D8D0(PlayerSel *p);
extern void fn_8884E478(PlayerSel *p);
INL u32 slot_count(SlotVec *v) { return v->end - v->begin; }
INL Slot *slot_at(SlotVec *v, u32 i) { return &v->begin[i]; }

u32 ts4_script_match_start_init_coach_objectives_887964C8(Ctx *c)
{
    if (ts4_script_string_equals(arg_at(c->args, 0)->payload, g_ts4_true_string)) {
        fn_8883D8D0(lbl_88D459E0);
    } else {
        PlayerSel *p = lbl_88D459E0;
        u32 i;
        for (i = 0; i < 4; i++) {
            if (i < slot_count(&p->slots))
                slot_at(&p->slots, i)->player = -1;
        }
    }
    fn_8884E478(lbl_88D459E0);
    return 0;
}
