/* Swing_DLL.xex 0x887A73E0-0x887A7824, executable version 0.0.0.3. */
typedef struct lua_State lua_State;
typedef struct Frame { lua_State **L; int idx; } Frame;
typedef struct Args { void *pad[2]; Frame f1; Frame f2; } Args;
typedef struct Out { int v[2]; } Out;
typedef struct Conf { char pad[0x1e]; unsigned char flag_c; } Conf;
extern Conf *lbl_88D45A60;
extern float g_ts4_script_constants[];
extern int ts4_lua_toboolean_88822398(lua_State *L, int idx);
extern double ts4_lua_tonumber_88822420(lua_State *L, int idx);
extern int lib3_lua_type_88822738(lua_State *L, int idx);
extern const char *lib3_lua_tostring_88822888(lua_State *L, int idx);
extern unsigned int fn_88608590(unsigned int zero, const char *s);
extern void ts4_call_seq_u32_off0_881B1A98(Out *out, void *self, int v);

int ts4_script_scale_amount_887A73E0(void *self, Args *a)
{
    unsigned char force = (unsigned char)(ts4_lua_toboolean_88822398(*a->f2.L, a->f2.idx) != 0);
    int n = (int)ts4_lua_tonumber_88822420(*a->f1.L, a->f1.idx);
    if (force || lbl_88D45A60->flag_c) {
        n = (int)((float)n * g_ts4_script_constants[86]);
    }
    {
        Out o;
        ts4_call_seq_u32_off0_881B1A98(&o, self, n);
    }
    return 1;
}

int ts4_script_hash_string_arg_887A7790(void *self, Args *a)
{
    Frame *f = &a->f1;
    int t = lib3_lua_type_88822738(*f->L, f->idx);
    if (t == 4) goto ok;
    if (t == 3) goto ok;
    if (t == 9) goto ok;
    return 0;
ok:
    {
        Out o;
        ts4_call_seq_u32_off0_881B1A98(&o, self, fn_88608590(0, lib3_lua_tostring_88822888(*f->L, f->idx)));
    }
    return 1;
}
