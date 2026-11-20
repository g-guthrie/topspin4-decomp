/* Loader_DLL.xex 0x835160F8-0x83516458, executable version 0.0.0.3.
   Initialisers for a family of 0x42C-byte settings blocks: clear the
   leading and trailing regions, copy a shared 0x48-byte default table in
   the middle and set seven mode words. */
typedef unsigned ts4l_u32;
extern void *fn_833E3A30();

typedef struct { char b[0x48]; } Ts4lDefaults;
extern Ts4lDefaults lbl_83008928;
typedef struct {
    char head[0x210];
    Ts4lDefaults table;
    char tail[0x1b8];
    ts4l_u32 w[7];
} Ts4lSettings;

extern Ts4lSettings lbl_835280C8;
extern Ts4lSettings lbl_835284F8;
extern Ts4lSettings lbl_83528928;
extern Ts4lSettings lbl_83528D58;
extern Ts4lSettings lbl_83529188;
extern Ts4lSettings lbl_835295B8;
extern Ts4lSettings lbl_835299E8;
void ts4l_init_settings_835160F8(void)
{
    Ts4lSettings *g = &lbl_835280C8;
    fn_833E3A30(g->head + 0x18, 0, 0x1f8);
    g->table = lbl_83008928;
    fn_833E3A30(g->tail, 0, 0x1b8);
    g->w[0] = 1;
    g->w[1] = 0;
    g->w[2] = 9;
    g->w[3] = 1;
    g->w[4] = 1;
    g->w[5] = 1;
    g->w[6] = 1;
}

void ts4l_init_settings_83516188(void)
{
    Ts4lSettings *g = &lbl_835284F8;
    fn_833E3A30(g->head + 0x1a, 0, 0x1f6);
    g->table = lbl_83008928;
    fn_833E3A30(g->tail, 0, 0x1b8);
    g->w[0] = 11;
    g->w[1] = 1;
    g->w[2] = 0;
    g->w[3] = 1;
    g->w[4] = 1;
    g->w[5] = 1;
    g->w[6] = 1;
}

void ts4l_init_settings_83516218(void)
{
    Ts4lSettings *g = &lbl_83528928;
    fn_833E3A30(g->head + 0x1e, 0, 0x1f2);
    g->table = lbl_83008928;
    fn_833E3A30(g->tail, 0, 0x1b8);
    g->w[0] = 1;
    g->w[1] = 0;
    g->w[2] = 63;
    g->w[3] = 1;
    g->w[4] = 1;
    g->w[5] = 1;
    g->w[6] = 1;
}

void ts4l_init_settings_835162A8(void)
{
    Ts4lSettings *g = &lbl_83528D58;
    fn_833E3A30(g->head + 0x30, 0, 0x1e0);
    g->table = lbl_83008928;
    fn_833E3A30(g->tail, 0, 0x1b8);
    g->w[0] = 1;
    g->w[1] = 0;
    g->w[2] = 10;
    g->w[3] = 1;
    g->w[4] = 1;
    g->w[5] = 1;
    g->w[6] = 1;
}

void ts4l_init_settings_83516338(void)
{
    Ts4lSettings *g = &lbl_83529188;
    fn_833E3A30(g->head + 0x2c, 0, 0x1e4);
    g->table = lbl_83008928;
    fn_833E3A30(g->tail, 0, 0x1b8);
    g->w[0] = 1;
    g->w[1] = 0;
    g->w[2] = 11;
    g->w[3] = 1;
    g->w[4] = 1;
    g->w[5] = 1;
    g->w[6] = 1;
}

void ts4l_init_settings_835163C8(void)
{
    Ts4lSettings *g = &lbl_835295B8;
    fn_833E3A30(g->head + 0x28, 0, 0x1e8);
    g->table = lbl_83008928;
    fn_833E3A30(g->tail, 0, 0x1b8);
    g->w[0] = 1;
    g->w[1] = 0;
    g->w[2] = 63;
    g->w[3] = 1;
    g->w[4] = 1;
    g->w[5] = 1;
    g->w[6] = 1;
}

void ts4l_init_settings_83516458(void)
{
    Ts4lSettings *g = &lbl_835299E8;
    fn_833E3A30(g->head + 0x1e, 0, 0x1f2);
    g->table = lbl_83008928;
    fn_833E3A30(g->tail, 0, 0x1b8);
    g->w[0] = 1;
    g->w[1] = 0;
    g->w[2] = 30;
    g->w[3] = 1;
    g->w[4] = 1;
    g->w[5] = 1;
    g->w[6] = 1;
}
