/* Family SWA: switch jump-table function. One function per file: the fn_check label lookup is by name, and $LN names repeat per function. */

extern int fn_88581CB0(void);

/* Swing_DLL.xex 0x88883F38: maps the 1-based id from fn_88581CB0 to a 0-based slot (8 and 10 and 11 and 12 are permuted). */
int ts4_map_id_to_slot_88883F38(void)
{
    int result = 0;

    switch (fn_88581CB0()) {
    case 1: result = 0; break;
    case 2: result = 1; break;
    case 3: result = 2; break;
    case 4: result = 3; break;
    case 5: result = 4; break;
    case 6: result = 5; break;
    case 7: result = 6; break;
    case 8: result = 7; break;
    case 9: result = 11; break;
    case 10: result = 8; break;
    case 11: result = 10; break;
    case 12: result = 9; break;
    }
    return result;
}
