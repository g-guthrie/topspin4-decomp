/* Swing_DLL.xex 0x887A5C00-0x887A5E08, executable version 0.0.0.3. */
typedef struct lua_State lua_State;
typedef struct Frame { lua_State **L; int idx; } Frame;
typedef struct Args { void *pad[2]; Frame f; } Args;
typedef struct Out { int v[2]; } Out;
extern int lib3_lua_type_88822738(lua_State *L, int idx);
extern double ts4_lua_tonumber_88822420(lua_State *L, int idx);
extern int fn_8884C318(int v);
extern int fn_8899C758(int v);
extern int fn_8899C7F0(int v);
extern void ts4_call_seq_u32_off0_881B1A98(Out *out, void *self, int v);

int ts4_script_push_converted_887A5C00(void *self, Args *a)
{
    Frame *f = &a->f;
    if (lib3_lua_type_88822738(*f->L, f->idx) == 3) {
        int n = (int)ts4_lua_tonumber_88822420(*f->L, f->idx);
        {
            Out o;
            ts4_call_seq_u32_off0_881B1A98(&o, self, fn_8884C318(n));
        }
        return 1;
    }
    return 0;
}

int ts4_script_push_converted_887A5CF8(void *self, Args *a)
{
    Frame *f = &a->f;
    if (lib3_lua_type_88822738(*f->L, f->idx) == 3) {
        int n = (int)ts4_lua_tonumber_88822420(*f->L, f->idx);
        {
            Out o;
            ts4_call_seq_u32_off0_881B1A98(&o, self, fn_8899C758(n));
        }
        return 1;
    }
    return 0;
}

int ts4_script_push_converted_887A5D80(void *self, Args *a)
{
    Frame *f = &a->f;
    if (lib3_lua_type_88822738(*f->L, f->idx) == 3) {
        int n = (int)ts4_lua_tonumber_88822420(*f->L, f->idx);
        {
            Out o;
            ts4_call_seq_u32_off0_881B1A98(&o, self, fn_8899C7F0(n));
        }
        return 1;
    }
    return 0;
}
