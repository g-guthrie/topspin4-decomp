/* Swing_DLL.xex 0x889158E8: when the list at g_ts4_session_context->+0x40 holds more than 19 entries, clears the four words
 * at +0x130 of the record it points to (+4). agO: plain and LTCG; the int *w local gives the target register reuse. */
typedef struct Rec { char pad[0x130]; int w[4]; } Rec;
typedef struct List { int f0; Rec *rec; unsigned count; } List;
typedef struct Global { char pad[0x40]; List *list; } Global;
extern Global *g_ts4_session_context;

void fn_889158E8(void)
{
    List *l = g_ts4_session_context->list;
    if (l->count > 19) {
        int *w = l->rec->w;
        w[0] = 0;
        w[1] = 0;
        w[2] = 0;
        w[3] = 0;
    }
}
