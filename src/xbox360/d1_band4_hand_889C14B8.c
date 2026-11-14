/* Swing_DLL.xex 0x889C14B8-0x889C14F8, executable version 0.0.0.3. */

extern void ts4_call_seq_lbl_880D72B0_88912AC0(void *);
extern char lbl_880D73FC[];
extern int KeTlsAlloc(void);
extern int lbl_88CACF08;
extern void fn_88563470(void (*)(void));
extern void ts4_get_u32_lbl_88CACF08_88AFF4C8(void);
extern void fn_88177110(void *);
extern void fn_88912090(void *);
extern void fn_88616A70(void *);
extern void fn_88935C70(void *);
extern void fn_8899B710(void *);
extern void fn_889BBD50(void *);
extern void RtlInitializeCriticalSection(void *);
extern char lbl_88B30F80[];
extern void ts4_addr_lbl_88000A3C_88AFF440(void);
extern void fn_8864C170(void *);
extern void fn_881B9148(void *);
extern void fn_889C0BC8(void *);

void ts4_reset_889C14B8(char *x)
{
    x[8] = 0;
    fn_881B9148(x + 0x10);
    fn_889C0BC8(x);
}
