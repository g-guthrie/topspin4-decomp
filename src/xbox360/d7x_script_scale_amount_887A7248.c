/* Swing_DLL.xex 0x887A7248-0x887A73E0, executable version 0.0.0.3. */
typedef struct lua_State lua_State;
typedef struct Frame { lua_State **L; int idx; } Frame;
typedef struct Args { void *pad[2]; Frame f1; Frame f2; } Args;
typedef struct Out { int v[2]; } Out;
typedef struct Conf { char pad[0x1d]; unsigned char flag_a; char pad2; unsigned char flag_b; } Conf;
extern Conf *lbl_88D45A60;
extern float g_ts4_script_constants[];
extern int ts4_lua_toboolean_88822398(lua_State *L, int idx);
extern double ts4_lua_tonumber_88822420(lua_State *L, int idx);
extern void ts4_call_seq_u32_off0_881B1A98(Out *out, void *self, int v);

int ts4_script_scale_amount_887A7318(void *self, Args *a)
{
    unsigned char force = (unsigned char)(ts4_lua_toboolean_88822398(*a->f2.L, a->f2.idx) != 0);
    int n = (int)ts4_lua_tonumber_88822420(*a->f1.L, a->f1.idx);
    if (force || lbl_88D45A60->flag_a) {
        n = (int)((float)n * g_ts4_script_constants[85]);
    }
    {
        Out o;
        ts4_call_seq_u32_off0_881B1A98(&o, self, n);
    }
    return 1;
}

int ts4_script_scale_offset_amount_887A7248(void *self, Args *a)
{
    unsigned char force = (unsigned char)(ts4_lua_toboolean_88822398(*a->f2.L, a->f2.idx) != 0);
    int n = (int)ts4_lua_tonumber_88822420(*a->f1.L, a->f1.idx);
    if (force || lbl_88D45A60->flag_b) {
        n = (int)((float)n * g_ts4_script_constants[84] + g_ts4_script_constants[16]);
    }
    {
        Out o;
        ts4_call_seq_u32_off0_881B1A98(&o, self, n);
    }
    return 1;
}
