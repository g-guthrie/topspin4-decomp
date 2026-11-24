/* CW35 part a: script handler in 0x88790000-0x887B0000 (float round through the C library helper). */
typedef struct lua_State lua_State;
typedef struct Frame { lua_State **L; int idx; } Frame;
typedef struct Args { void *pad[2]; Frame f1; Frame f2; } Args;
typedef struct Out { int v[2]; } Out;

extern double ts4_lua_tonumber_88822420(lua_State *L, int idx);
extern void ts4_call_seq_u32_off0_881B1A98(Out *out, void *self, int v);
extern double fn_88564D28(float f);

/* 0x887A74A8: round the number argument and forward it */
int ts4_script_round_887A74A8(void *self, Args *a)
{
    float f = (float)fn_88564D28((float)ts4_lua_tonumber_88822420(*a->f1.L, a->f1.idx));
    {
        Out o;
        ts4_call_seq_u32_off0_881B1A98(&o, self, (int)f);
    }
    return 1;
}
