/* CW35 part d: script handlers using the reference-counted string release. */
#include "fam4_refstr.h"
typedef unsigned int u32;
typedef unsigned char u8;
typedef struct lua_State lua_State;
typedef struct Frame { lua_State **L; int idx; } Frame;
typedef struct Args { void *pad[2]; Frame f1; Frame f2; } Args;
typedef struct Out { int v[2]; } Out;
extern double ts4_lua_tonumber_88822420(lua_State *L, int idx);
extern void ts4_loop_call_seq_u32_off0_881B1B68(Out *out, void *self, u32 v);

extern u32 *fn_8879D8B0(char **out, int n);

int ts4_script_name_lookup_887AB768(void *self, Args *a)
{
    char *s;
    u32 v;
    int n = (int)ts4_lua_tonumber_88822420(*a->f1.L, a->f1.idx);
    v = *fn_8879D8B0(&s, n);
    ts4_str_release(s);
    {
        Out o;
        ts4_loop_call_seq_u32_off0_881B1B68(&o, self, v);
    }
    return 1;
}
