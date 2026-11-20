/* Swing_DLL.xex 0x8899DBB0: find a 36-byte item by id in the nested self-relative group tables at state+0x44c (16-byte groups, each with its own self-relative item array); 0 when absent.
 * /Oc. Plain nested for loops with array-of-self-relative indexing; matched first try. */
typedef struct Item36 { unsigned int id; char pad[0x24 - 4]; } Item36;
typedef struct RelGroup { int off; unsigned int count; char pad[0x10 - 8]; } RelGroup;
typedef struct RelGroups { int off; unsigned int count; } RelGroups;
typedef struct SessionState { char pad[0x44c]; RelGroups groups; } SessionState;
typedef struct SessionContext { char pad[0x3c]; SessionState *state; } SessionContext;
extern SessionContext *g_ts4_session_context;

Item36 *fn_8899DBB0(unsigned int id)
{
    RelGroups *gs = &g_ts4_session_context->state->groups;
    unsigned int g;
    unsigned int i;
    for (g = 0; g < gs->count; g++) {
        RelGroup *grp = &((RelGroup *)((char *)gs + gs->off))[g];
        for (i = 0; i < grp->count; i++) {
            Item36 *it = &((Item36 *)((char *)grp + grp->off))[i];
            if (it->id == id)
                return it;
        }
    }
    return 0;
}
