/* Swing_DLL.xex 0x8899C8F8: return the current 16-byte entry of the self-relative table at state+0x3e8+0x64 (index at +0xc).
 * /Oc. The table pointer is a local and the index is read through the block (b->table.current); reading it through t gives 8 off. */
typedef struct Entry16 { unsigned int w[4]; } Entry16;
typedef struct RelTable16 { int off; char pad[0xc - 0x4]; int current; } RelTable16;
typedef struct TableBlock { char pad[0x64]; RelTable16 table; } TableBlock;
typedef struct SessionState { char pad[0x3e8]; TableBlock block3e8; } SessionState;
typedef struct SessionContext { char pad[0x3c]; SessionState *state; } SessionContext;
extern SessionContext *g_ts4_session_context;

Entry16 *fn_8899C8F8(void)
{
    TableBlock *b = &g_ts4_session_context->state->block3e8;
    RelTable16 *t = &b->table;
    return &((Entry16 *)((char *)t + t->off))[b->table.current];
}
