/* 0x8877BF58: Returns whether the current session venue hash (+0x280) is one of six listed surface hashes. */
/* Near miss (agAH): /Oc, 2 off: the venue pointer is loaded into r8 instead of reusing r11. */
typedef struct Venue { char p0[0x280]; unsigned int surface_hash; } Venue;
typedef struct Session { char p0[0x3c]; Venue *venue; } Session;
extern Session *g_ts4_session_context;
unsigned char fn_8877BF58(void)
{
    unsigned int h = g_ts4_session_context->venue->surface_hash;
    return h == 0x3028BCBEu || h == 0xD03E6335u || h == 0x9B3C8DEDu || h == 0x5FF4B00Eu || h == 0x2EB587E4u || h == 0xCE89BAC4u;
}
