/* 0x884E72B0: converts src into a 0x30-byte temporary through ts4_call_seq_fn_88420B68_88420BF0, then forwards it with the float and int arguments to fn_884E7130 */
/* Matched on /Oc (agAH). The float occupies the r5 slot, so r5 is never set. A temporary of 0x30 bytes gives the 0xA0 frame. */
typedef struct Tmp { char b[0x30]; } Tmp;
void ts4_call_seq_fn_88420B68_88420BF0(Tmp *dst, void *src);
void fn_884E7130(void *self, Tmp *t, float x, int d);
void fn_884E72B0(void *self, void *src, float x, int d)
{
    Tmp t;
    ts4_call_seq_fn_88420B68_88420BF0(&t, src);
    fn_884E7130(self, &t, x, d);
}
