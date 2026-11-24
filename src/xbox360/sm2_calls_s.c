/* SM2: locked lookups, double dispatches, invalid-parameter style getters. */
extern int fn_88423730(void *p);
extern void fn_88423858(void *p, int n);
extern void fn_886E20A0(void *p, void *q);
extern void ts4_if_call_seq_u32_off4_8857A748(void *p);
extern void fn_88269C18(void *p);
extern void RtlEnterCriticalSection(void *cs);
extern void RtlLeaveCriticalSection(void *cs);
extern void *fn_884F6858(void *p, int a);
extern int fn_884FB328(void *p);
extern int ts4_get_u32_offcc_8859A000(void *p);
extern void fn_886DBF40(void *a, void *b, int c, int d, int e, int f);
extern int *ts4_if_call_seq_fn_8856CD88_88567ED8(void);
extern void fn_8856D2C0(void);
extern int lbl_88C31898;
extern int lbl_88C3189C;
extern int lbl_88C318A0;
extern int lbl_88D2E810;

void ts4_grow_if_needed_884285D0(char *p)
{
    int n = fn_88423730(p + 8);
    if (n <= *(int *)(p + 0x10)) fn_88423858(p + 8, n);
}
void ts4_copy_state_886E2290(char *p, char *q)
{
    fn_886E20A0(p, q + 0x58);
    *(float *)(p + 0x18) = *(float *)(q + 0x18);
    p[0x13] = q[0x13];
    *(float *)(p + 0x14) = *(float *)(q + 0x14);
}
void ts4_call_twice_nested_88668FD8(char *p)
{
    char *q = *(char **)(p + 0x28) + 0x5c;
    fn_88269C18(q + *(int *)q);
    q = *(char **)(p + 0x28) + 0x5c;
    fn_88269C18(q + *(int *)q + 0x134);
}
#define CALL_TWICE_OFF(NAME, OFF) \
    void NAME(void *a, char *b, int c, int d, int e, int f) \
    { \
        char *t = b + *(int *)b; \
        fn_886DBF40(a, t, c, d, e, f); \
        fn_886DBF40(a, t + (OFF), c, d, e, f); \
    }
#define GET_GLOBAL_CHECKED(NAME, G) \
    int NAME(int *out) \
    { \
        if (out == 0) { \
            *ts4_if_call_seq_fn_8856CD88_88567ED8() = 0x16; \
            fn_8856D2C0(); \
            return 0x16; \
        } \
        *out = G; \
        return 0; \
    }
