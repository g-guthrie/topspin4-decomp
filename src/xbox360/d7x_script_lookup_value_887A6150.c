/* Swing_DLL.xex 0x887A6150-0x887A6D08, executable version 0.0.0.3. */
typedef struct lua_State lua_State;
typedef struct Frame { lua_State **L; int idx; } Frame;
typedef struct Args { void *pad[2]; Frame f1; Frame f2; } Args;
typedef struct Out { int v[2]; } Out;
typedef struct Rec { char pad[0x14]; int val; } Rec;
typedef struct Reg { char pad[0x44]; void *tabA; char pad2[4]; void *tabB; } Reg;
typedef struct RegC { char pad[0x34]; void *tabA; void *tabB; } RegC;
typedef struct RegB { char pad[0x40]; void *tabA; char pad2[4]; void *tabB; } RegB;
extern Reg *lbl_88D45894;
extern double ts4_lua_tonumber_88822420(lua_State *L, int idx);
extern Rec *fn_88216268(void *tab, int *key);
extern void ts4_call_seq_u32_off0_881B1A98(Out *out, void *self, int v);

int ts4_script_lookup_value_887A6150(void *self, Args *a)
{
    unsigned int sel = (unsigned int)ts4_lua_tonumber_88822420(*a->f1.L, a->f1.idx);
    if (lbl_88D45894) {
        Rec *r;
        {
            int key = (int)ts4_lua_tonumber_88822420(*a->f2.L, a->f2.idx);
            Reg *g = lbl_88D45894;
            int *kp = &key;
            if (sel == 0xF5BF4F97u) r = fn_88216268(g->tabA, kp); else r = fn_88216268(g->tabB, kp);
        }
        if (r) {
            Out o;
            ts4_call_seq_u32_off0_881B1A98(&o, self, r->val);
        }
    } else {
        Out o;
        ts4_call_seq_u32_off0_881B1A98(&o, self, 0);
    }
    return 1;
}

int ts4_script_lookup_value_887A6590(void *self, Args *a)
{
    unsigned int sel = (unsigned int)ts4_lua_tonumber_88822420(*a->f1.L, a->f1.idx);
    if ((RegB *)lbl_88D45894) {
        Rec *r;
        {
            int key = (int)ts4_lua_tonumber_88822420(*a->f2.L, a->f2.idx);
            RegB *g = (RegB *)lbl_88D45894;
            int *kp = &key;
            if (sel == 0xF5BF4F97u) r = fn_88216268(g->tabA, kp); else r = fn_88216268(g->tabB, kp);
        }
        if (r) {
            Out o;
            ts4_call_seq_u32_off0_881B1A98(&o, self, r->val);
        }
    } else {
        Out o;
        ts4_call_seq_u32_off0_881B1A98(&o, self, 0);
    }
    return 1;
}

int ts4_script_lookup_value_887A6D50(void *self, Args *a)
{
    unsigned int sel = (unsigned int)ts4_lua_tonumber_88822420(*a->f1.L, a->f1.idx);
    if (lbl_88D45894) {
        Rec *r;
        {
            int key = (int)ts4_lua_tonumber_88822420(*a->f2.L, a->f2.idx);
            RegC *g = (RegC *)lbl_88D45894;
            int *kp = &key;
            if (sel == 0xF5BF4F97u) r = fn_88216268(g->tabA, kp); else r = fn_88216268(g->tabB, kp);
        }
        if (r) {
            Out o;
            ts4_call_seq_u32_off0_881B1A98(&o, self, r->val);
        }
    } else {
        Out o;
        ts4_call_seq_u32_off0_881B1A98(&o, self, 0);
    }
    return 1;
}
