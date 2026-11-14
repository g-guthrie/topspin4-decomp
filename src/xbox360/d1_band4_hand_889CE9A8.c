/* Swing_DLL.xex 0x889CE9A8-0x889CF69C, executable version 0.0.0.3. */

extern void fn_889C6888(void *, int *);
extern int fn_8882E0D8(void *, char *, char *);
extern char lbl_880E17B0[];
extern char lbl_880C9990[];
extern double g_ts4_script_constants[];
extern void fn_888240B8(void *, double);
extern char lbl_88D4DABE;
extern void fn_889D1A88(void);
extern void ts4_get_fn_889D1918_889D19B8(void);
extern void fn_8830EC08(char *);
extern void fn_88563470(void (*)(void));
extern char lbl_88C6E268[];
extern void ts4_call_seq_lbl_88C6E268_88AFF458(void);
extern void *lbl_88D3EB60;
extern void fn_8857A1E0(void *);
extern void ts4_if_call_seq_u32_off0_8864BC08(void *);
extern void fn_88177110(void *);
extern void fn_88912090(void *);

int ts4_call_889CE9A8(void *x)
{
    fn_8882E0D8(x, lbl_880E17B0, lbl_880C9990);
    return 1;
}

int ts4_call_double_889CF668(void **p)
{
    fn_888240B8(*p, g_ts4_script_constants[11]);
    return 1;
}

