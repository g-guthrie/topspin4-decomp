/* Swing_DLL.xex 0x887A6930-0x887A6A78, executable version 0.0.0.3. */
typedef struct lua_State lua_State;
typedef struct Frame { lua_State **L; int idx; } Frame;
typedef struct Args { void *pad[2]; Frame f1; } Args;
typedef struct Out { int v[2]; } Out;
typedef struct Rec { char pad[0x14]; int val; } Rec;
typedef struct Tab { unsigned int first; unsigned int count; } Tab;
typedef struct Reg { char pad[0x3c]; void *tab; } Reg;
typedef struct RegT { char pad[0x3c]; Tab *tab; } RegT;
extern Reg *lbl_88D45894;
extern double ts4_lua_tonumber_88822420(lua_State *L, int idx);
extern Rec *fn_88216268(void *tab, int *key);
extern void ts4_call_seq_u32_off0_881B1A98(Out *out, void *self, int v);

int ts4_script_lookup_global_value_887A6930(void *self, Args *a)
{
    if (lbl_88D45894) {
        Rec *r;
        {
            int key = (int)ts4_lua_tonumber_88822420(*a->f1.L, a->f1.idx);
            r = fn_88216268(lbl_88D45894->tab, &key);
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

int ts4_script_lookup_global_entry_887A69C8(void *self, Args *a)
{
    int v;
    if (lbl_88D45894) {
        int idx = (int)ts4_lua_tonumber_88822420(*a->f1.L, a->f1.idx);
        v = -1;
        if (idx != -1) {
            Tab *t = ((RegT *)lbl_88D45894)->tab;
            if ((unsigned int)idx < t->count) {
                v = *(int *)((char *)t + t->first + idx * 24 + 0xc);
            }
        }
    } else {
        v = -1;
    }
    {
        Out o;
        ts4_call_seq_u32_off0_881B1A98(&o, self, v);
    }
    return 1;
}
