/* Swing_DLL.xex 0x8877BF58 (/Oc): is the current session venue's surface hash (+0x280) one of
 * six listed surfaces?
 * Matching note: the hash is bound to a const reference local, so the venue chain stays in r11
 * (a by-value local puts the venue pointer in r8), and the result is a bool. */
struct Ts4Venue {
    char pad000[0x280];
    unsigned int surface_hash;  /* +0x280 */
};
struct Ts4SessionContext {
    char pad00[0x3C];
    Ts4Venue *venue;            /* +0x3C */
};
extern "C" Ts4SessionContext *g_ts4_session_context;

extern "C" bool ts4_venue_surface_is_listed_8877BF58(void)
{
    const unsigned int &h = g_ts4_session_context->venue->surface_hash;
    return h == 0x3028BCBEu || h == 0xD03E6335u || h == 0x9B3C8DEDu ||
           h == 0x5FF4B00Eu || h == 0x2EB587E4u || h == 0xCE89BAC4u;
}
