/* 0x88577860: One-time init: when the flag lbl_88D4E114 is 0, sets lbl_88D2E82C = -3 and the flag to 1; returns 0. */
/* Matched on /Oc /Os (agAH). Built /Os. The state store is written before the flag store; the scheduler emits the flag store first. */
extern int lbl_88D4E114;
extern int lbl_88D2E82C;
int fn_88577860(void)
{
    if (lbl_88D4E114 == 0) {
        lbl_88D2E82C = -3;
        lbl_88D4E114 = 1;
    }
    return 0;
}
