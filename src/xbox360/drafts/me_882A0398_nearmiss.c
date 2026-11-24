/* 0x882A0398: stores min(length(s), 0x27FD8) into lbl_88C45E84 (length called twice, MIN macro shape) and returns 1 */
/* Near miss (agAH): 1 off: the target sign-extends the second length result (extsw r11,r3) before the stw; int, size_t, long long and __int64 spellings of the length, the limit and the global all give mr. */
typedef unsigned int size_t;
extern size_t ts4_tailcall_fn_88564B00_88564770(const char *s);
extern int lbl_88C45E84;
#define MIN(a, b) ((a) < (b) ? (a) : (b))
int fn_882A0398(const char *s)
{
    lbl_88C45E84 = (int)MIN(ts4_tailcall_fn_88564B00_88564770(s), 0x27FD8);
    return 1;
}
