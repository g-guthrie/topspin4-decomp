/* Swing_DLL.xex 0x887A62D8-0x887A6F68, executable version 0.0.0.3. */
typedef struct lua_State lua_State;
typedef struct Frame { lua_State **L; int idx; } Frame;
typedef struct Args { void *pad[2]; Frame f1; } Args;
typedef struct Out { int v[2]; } Out;
typedef struct Rec { char pad[0x10]; int count; } Rec;
typedef struct RegA { char pad[0x44]; Rec *tabA; char pad2[4]; Rec *tabB; } RegA;
typedef struct RegB { char pad[0x40]; Rec *tabA; char pad2[4]; Rec *tabB; } RegB;
typedef struct RegC { char pad[0x34]; Rec *tabA; Rec *tabB; } RegC;
extern RegA *lbl_88D45894;
extern double ts4_lua_tonumber_88822420(lua_State *L, int idx);
extern void ts4_call_seq_u32_off0_881B1A98(Out *out, void *self, int v);

int ts4_script_count_for_kind_887A62D8(void *self, Args *a)
{
    unsigned int sel = (unsigned int)ts4_lua_tonumber_88822420(*a->f1.L, a->f1.idx);
    RegA *g = lbl_88D45894;
    if (g) {
        Out o;
        if (sel == 0xF5BF4F97u) {
            ts4_call_seq_u32_off0_881B1A98(&o, self, g->tabA->count);
        } else {
            ts4_call_seq_u32_off0_881B1A98(&o, self, g->tabB->count);
        }
    } else {
        Out o;
        ts4_call_seq_u32_off0_881B1A98(&o, self, -1);
    }
    return 1;
}

int ts4_script_count_for_kind_887A6718(void *self, Args *a)
{
    unsigned int sel = (unsigned int)ts4_lua_tonumber_88822420(*a->f1.L, a->f1.idx);
    RegB *g = (RegB *)lbl_88D45894;
    if (g) {
        Out o;
        if (sel == 0xF5BF4F97u) {
            ts4_call_seq_u32_off0_881B1A98(&o, self, g->tabA->count);
        } else {
            ts4_call_seq_u32_off0_881B1A98(&o, self, g->tabB->count);
        }
    } else {
        Out o;
        ts4_call_seq_u32_off0_881B1A98(&o, self, -1);
    }
    return 1;
}

int ts4_script_count_for_kind_887A6ED8(void *self, Args *a)
{
    unsigned int sel = (unsigned int)ts4_lua_tonumber_88822420(*a->f1.L, a->f1.idx);
    RegC *g = (RegC *)lbl_88D45894;
    if (g) {
        Out o;
        if (sel == 0xF5BF4F97u) {
            ts4_call_seq_u32_off0_881B1A98(&o, self, g->tabA->count);
        } else {
            ts4_call_seq_u32_off0_881B1A98(&o, self, g->tabB->count);
        }
    } else {
        Out o;
        ts4_call_seq_u32_off0_881B1A98(&o, self, -1);
    }
    return 1;
}
