/* 0x889A4930 near miss (agW, /Oc plain and LTCG): 2 off, the target reuses r11 for the ->c->id chain; here it uses r8. */
/* Calls ts4_grid_valid_889A0478(o+0xbc) when the session context id (+0x3c -> +0x2d0) is 0x054AB17F or 0x582B3086; otherwise returns 1. */
typedef struct { char pad[0x2d0]; unsigned int id; } C;
typedef struct { char pad[0x3c]; C *c; } Ctx;
extern Ctx *g_ts4_session_context;
unsigned int ts4_grid_valid_889A0478(void *g);
typedef struct { char pad[0xbc]; char grid[4]; } O;
unsigned int ts4_grid_valid_if_id_889A4930(O *o)
{
    unsigned int id = g_ts4_session_context->c->id;
    if (id == 0x054AB17F || id == 0x582B3086) return ts4_grid_valid_889A0478(o->grid);
    return 1;
}
