/* 0x88434530: Looks up the named field lbl_88043BF4 on src (ts4_if_call_seq_u32_off4_88428890) and fills its 8 ints with -1; the first argument is unused. */
/* Matched on /Oc (agAH). Same Ref accessor pattern as 8842BC60; plain index loop gives the stwu/bdnz fill. */
typedef struct Ref { void *a; void *b; } Ref;
extern const char lbl_88043BF4[];
extern Ref *ts4_if_call_seq_u32_off4_88428890(Ref *out, void *src, const char *name);
extern int *ts4_get_u32_off0_884289C8(Ref *r, int i);
void fn_88434530(void *unused, void *src)
{
    Ref r;
    int *p;
    int i;
    ts4_if_call_seq_u32_off4_88428890(&r, src, lbl_88043BF4);
    p = ts4_get_u32_off0_884289C8(&r, 0);
    for (i = 0; i < 8; i++)
        p[i] = -1;
}
