/* Swing_DLL.xex 0x8899FE68: with the online context ready, converts five match stats (+0x4c..+0x5c; two unsigned) to float graph inputs, evaluates the graph set at +0xd4 in mode 0x054AB17F (else +0x120) and writes the truncated graph result to out+8; returns 1, or 0 when not ready.
 * /Oc. The inputs are written through a float* to the input array (the target keeps the dead addi of its address); the input block is self-relative (vars + vars->inputsOff). */
typedef struct SessionState { char pad[0x2d0]; unsigned int modeHash; } SessionState;
typedef struct SessionContext { char pad[0x3c]; SessionState *state; } SessionContext;
typedef struct GraphInputs { char pad[0x14]; float values[5]; } GraphInputs;
typedef struct GraphVars { int inputsOff; char pad[0xc - 0x4]; float result; } GraphVars;
typedef struct GraphHeader { char pad[0x80]; GraphVars vars; } GraphHeader;
typedef struct OnlineContext {
    char pad[0x2c]; GraphHeader *graphs; char pad1[0xc8 - 0x30]; void *ready; char pad2[0xd4 - 0xcc];
    char modeGraphs[0x120 - 0xd4]; char defaultGraphs[4];
} OnlineContext;
typedef struct MatchStats { char pad[0x4c]; unsigned int a; int b; unsigned int c; int d; int e; } MatchStats;
typedef struct GraphResult { char pad[0x8]; int value; } GraphResult;
extern SessionContext *g_ts4_session_context;
extern OnlineContext *g_ts4_online_context;
void ts4_loop_call_seq_u32_off2c_8890E988(void *analysers);

int fn_8899FE68(GraphResult *out, const MatchStats *s)
{
    OnlineContext *oc = g_ts4_online_context;
    unsigned int mode = g_ts4_session_context->state->modeHash;
    GraphVars *vars;
    float *v;
    if (!oc || !oc->ready)
        return 0;
    vars = &oc->graphs->vars;
    v = ((GraphInputs *)((char *)vars + vars->inputsOff))->values;
    v[2] = (float)s->b;
    v[1] = (float)s->c;
    v[3] = (float)s->d;
    v[0] = (float)s->a;
    v[4] = (float)s->e;
    ts4_loop_call_seq_u32_off2c_8890E988(mode == 0x054AB17F ? oc->modeGraphs : oc->defaultGraphs);
    out->value = (int)vars->result;
    return 1;
}
