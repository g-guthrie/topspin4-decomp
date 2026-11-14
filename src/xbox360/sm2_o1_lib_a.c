/* SM2: functions that only match with /O1 (library-style code). Spec flags: /O1. */
extern void ts4_if_call_seq_u32_off4_8857A748(void *p);
extern void RtlEnterCriticalSection(void *cs);
extern void RtlLeaveCriticalSection(void *cs);
extern void *fn_884F6858(void *p, int a);
extern int fn_884FB328(void *p);
extern int ts4_get_u32_offcc_8859A000(void *p);
extern int *ts4_if_call_seq_fn_8856CD88_88567ED8(void);
extern void fn_8856D2C0(void);
extern int lbl_88C31898;
extern int lbl_88C3189C;
extern int lbl_88C318A0;
extern int lbl_88D2E810;

int ts4_get_nested_field_884F65B8(const char *p, int i)
{
    const char *v = ((const char *const *)p)[i + 0x14];
    if (v != 0) {
        const char *w = *(const char *const *)(v + 8);
        if (w != 0) return *(const int *)(w + 0x90);
    }
    return 0;
}
int ts4_locked_lookup_884F74E8(char *p, int a)
{
    char *cs = p + 0xf0;
    int r = 0;
    void *v;
    RtlEnterCriticalSection(cs);
    v = fn_884F6858(p, a);
    if (v) r = fn_884FB328(v);
    RtlLeaveCriticalSection(cs);
    return r;
}
int ts4_locked_get_field_884F6560(char *p, int a)
{
    char *cs = p + 0xf0;
    int r = 0;
    void *v;
    RtlEnterCriticalSection(cs);
    v = ((void **)p)[a + 0x14];
    if (v) r = ts4_get_u32_offcc_8859A000(v);
    RtlLeaveCriticalSection(cs);
    return r;
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
GET_GLOBAL_CHECKED(ts4_get_global_checked_88574130, lbl_88C31898)
GET_GLOBAL_CHECKED(ts4_get_global_checked_88574090, lbl_88C3189C)
GET_GLOBAL_CHECKED(ts4_get_global_checked_885740E0, lbl_88C318A0)
GET_GLOBAL_CHECKED(ts4_get_global_checked_8856C390, lbl_88D2E810)
