/* Swing_DLL.xex 0x889CFA78-0x889D1EAC, executable version 0.0.0.3. */

extern void fn_888860A0(void *);
extern double ts4_lua_opt_number_default_8882EA98(void *, int);
extern void fn_888240B8(void *, double);
extern double sqrt(double);
extern double fabs(double);
extern double g_ts4_script_constants[];
extern double fn_88563F20(double);
extern double lbl_88D45BB0;
extern int KeTlsAlloc(void);
extern int lbl_88C6E1A8;
extern void fn_8856C178(char *);
extern char lbl_880FCB8C[];
extern void *fn_8860DCF8(void *, int, int, int);
extern void *fn_889BB7F0(void *);
extern void *fn_8864B468(void *);
extern void *lbl_88D45910;
extern void *fn_885805C0(void *, int, void *);
extern void *ts4_get_u32_lbl_88D4E11C_88581A90(void);
extern char lbl_880D7570[];
extern char lbl_880D6B70[];
extern void fn_88616758(void *, int, int);
extern void fn_889C6888(void *, int *);

typedef struct P0 { void *p; } P0;
typedef struct P4 { int pad; void *p; } P4;
int ts4_sqrt_889CFC38(void *x)
{
    fn_888240B8(x, sqrt(ts4_lua_opt_number_default_8882EA98(x, 1)));
    return 1;
}

int ts4_fabs_889CFF38(void *x)
{
    fn_888240B8(x, fabs(ts4_lua_opt_number_default_8882EA98(x, 1)));
    return 1;
}

int ts4_scale_889CFA78(void *x)
{
    fn_888240B8(x, ts4_lua_opt_number_default_8882EA98(x, 1) * g_ts4_script_constants[327]);
    return 1;
}

int ts4_scale_889CFAC8(void *x)
{
    fn_888240B8(x, ts4_lua_opt_number_default_8882EA98(x, 1) * g_ts4_script_constants[328]);
    return 1;
}

void ts4_init_889D1E68(void)
{
    lbl_88D45BB0 = fn_88563F20(g_ts4_script_constants[331]) * g_ts4_script_constants[332];
}

typedef struct B0C { int pad[3]; void *h; } B0C;
typedef struct S4 { void *vt; int pad[3]; void *a; } S4;
int ts4_check_889D0150(char *s)
{
    void *p = *(void **)s;
    void *r = fn_885805C0(ts4_get_u32_lbl_88D4E11C_88581A90(), 0, p);
    *(void **)(s + 4) = r;
    return r != 0;
}

typedef struct M80 { void *vt; char pad[0x1c]; int a; int b; int pad2; void *c; } M80;
