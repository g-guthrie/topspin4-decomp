/* Swing_DLL.xex functions whose code is identical (after masking relocations) to
   matched Loader_DLL.xex functions; source form ported from src/loader/l10_settings_init_o1_835160F8.c.
   Reconstructed from disassembly; no upstream source, no Microsoft source. */
typedef unsigned ts4_u32;

typedef struct { char b[0x48]; } Ts4lDefaults;
typedef struct {
    char head[0x210];
    Ts4lDefaults table;
    char tail[0x1b8];
    ts4_u32 w[7];
} Ts4lSettings;

#ifdef _MSC_VER
extern void *memset();
#else
#include <string.h>
#endif
extern Ts4lDefaults lbl_8808D820;
extern Ts4lSettings lbl_88C326F8;
extern Ts4lSettings lbl_88C32B28;
extern Ts4lSettings lbl_88C32F58;
extern Ts4lSettings lbl_88C33388;
extern Ts4lSettings lbl_88C337B8;
extern Ts4lSettings lbl_88C33BE8;
extern Ts4lSettings lbl_88C34018;

/* Swing_DLL.xex 0x88AFE238 */
void ts4_init_settings_88AFE238(void)
{
    Ts4lSettings *g = &lbl_88C326F8;
    memset(g->head + 0x18, 0, 0x1f8);
    g->table = lbl_8808D820;
    memset(g->tail, 0, 0x1b8);
    g->w[0] = 1;
    g->w[1] = 0;
    g->w[2] = 9;
    g->w[3] = 1;
    g->w[4] = 1;
    g->w[5] = 1;
    g->w[6] = 1;
}

/* Swing_DLL.xex 0x88AFE2C8 */
void ts4_init_settings_88AFE2C8(void)
{
    Ts4lSettings *g = &lbl_88C32B28;
    memset(g->head + 0x1a, 0, 0x1f6);
    g->table = lbl_8808D820;
    memset(g->tail, 0, 0x1b8);
    g->w[0] = 11;
    g->w[1] = 1;
    g->w[2] = 0;
    g->w[3] = 1;
    g->w[4] = 1;
    g->w[5] = 1;
    g->w[6] = 1;
}

/* Swing_DLL.xex 0x88AFE358 */
void ts4_init_settings_88AFE358(void)
{
    Ts4lSettings *g = &lbl_88C32F58;
    memset(g->head + 0x1e, 0, 0x1f2);
    g->table = lbl_8808D820;
    memset(g->tail, 0, 0x1b8);
    g->w[0] = 1;
    g->w[1] = 0;
    g->w[2] = 63;
    g->w[3] = 1;
    g->w[4] = 1;
    g->w[5] = 1;
    g->w[6] = 1;
}

/* Swing_DLL.xex 0x88AFE3E8 */
void ts4_init_settings_88AFE3E8(void)
{
    Ts4lSettings *g = &lbl_88C33388;
    memset(g->head + 0x30, 0, 0x1e0);
    g->table = lbl_8808D820;
    memset(g->tail, 0, 0x1b8);
    g->w[0] = 1;
    g->w[1] = 0;
    g->w[2] = 10;
    g->w[3] = 1;
    g->w[4] = 1;
    g->w[5] = 1;
    g->w[6] = 1;
}

/* Swing_DLL.xex 0x88AFE478 */
void ts4_init_settings_88AFE478(void)
{
    Ts4lSettings *g = &lbl_88C337B8;
    memset(g->head + 0x2c, 0, 0x1e4);
    g->table = lbl_8808D820;
    memset(g->tail, 0, 0x1b8);
    g->w[0] = 1;
    g->w[1] = 0;
    g->w[2] = 11;
    g->w[3] = 1;
    g->w[4] = 1;
    g->w[5] = 1;
    g->w[6] = 1;
}

/* Swing_DLL.xex 0x88AFE508 */
void ts4_init_settings_88AFE508(void)
{
    Ts4lSettings *g = &lbl_88C33BE8;
    memset(g->head + 0x28, 0, 0x1e8);
    g->table = lbl_8808D820;
    memset(g->tail, 0, 0x1b8);
    g->w[0] = 1;
    g->w[1] = 0;
    g->w[2] = 63;
    g->w[3] = 1;
    g->w[4] = 1;
    g->w[5] = 1;
    g->w[6] = 1;
}

/* Swing_DLL.xex 0x88AFE598 */
void ts4_init_settings_88AFE598(void)
{
    Ts4lSettings *g = &lbl_88C34018;
    memset(g->head + 0x1e, 0, 0x1f2);
    g->table = lbl_8808D820;
    memset(g->tail, 0, 0x1b8);
    g->w[0] = 1;
    g->w[1] = 0;
    g->w[2] = 30;
    g->w[3] = 1;
    g->w[4] = 1;
    g->w[5] = 1;
    g->w[6] = 1;
}

