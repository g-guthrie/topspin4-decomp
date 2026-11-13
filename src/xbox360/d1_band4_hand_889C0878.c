/* Swing_DLL.xex 0x889C0878-0x889D13C0, executable version 0.0.0.3. */

extern void *ts4_get_u32_lbl_88D4E11C_88581A90(void);
extern void fn_88580EB8(void *, int, void *);
extern void fn_889D1D28(void *);
extern int ts4_if_call_seq_u32_off0_8864BC08(void *);
extern int fn_8864D0A0(void *, void *);
typedef struct D1358 { char pad[0x18]; void *a; void *b; } D1358;
void ts4_release_889D1358(D1358 *s)
{
    void *a = s->a;
    fn_88580EB8(ts4_get_u32_lbl_88D4E11C_88581A90(), 0, a);
    {
        void *b = s->b;
        if (b != 0) {
            fn_889D1D28(b);
            fn_88580EB8(ts4_get_u32_lbl_88D4E11C_88581A90(), 0, b);
        }
    }
}
typedef struct D878 { int pad; int flag; char pad2[0x22c]; unsigned char done; } D878;
int ts4_finish_889C0878(D878 *s, void *x)
{
    if (s->flag != 0) {
        ts4_if_call_seq_u32_off0_8864BC08(s);
    }
    if (fn_8864D0A0(s, x) != 0) {
        return -1;
    }
    s->done = 1;
    return 0;
}
