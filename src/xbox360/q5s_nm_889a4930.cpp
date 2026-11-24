/* Swing_DLL.xex 0x889A4930 (/Oc): when the session venue's mode id (+0x2D0) is 0x054AB17F or
 * 0x582B3086, return whether the grid at self+0xBC is valid; otherwise 1.
 * Matching note: binding the id to a const reference local keeps the session->venue chain in r11;
 * a by-value local (cx43_a.c's #if 0 copy) puts the venue pointer in r8 (2 off). */
struct Ts4Venue {
    char pad000[0x2D0];
    unsigned int mode_id;       /* +0x2D0 */
};
struct Ts4SessionContext {
    char pad00[0x3C];
    Ts4Venue *venue;            /* +0x3C */
};
extern "C" Ts4SessionContext *g_ts4_session_context;
extern "C" int ts4_grid_valid_889A0478(void *grid);

extern "C" int ts4_check_mode_889A4930(unsigned char *self)
{
    const unsigned int &id = g_ts4_session_context->venue->mode_id;
    if (id == 0x054AB17F || id == 0x582B3086)
        return ts4_grid_valid_889A0478(self + 0xBC);
    return 1;
}
