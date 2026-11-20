/* SM1 batch j (default /O2). */
/* Swing_DLL.xex 0x8826A1A0: forward the child pointer at +0x1c when present */
extern void ts4_loop_call_seq_u32_offc0_886AB080(void *);
typedef struct Ts4Child1C2 { char pad[0x1c]; void *child; } Ts4Child1C2;
void ts4_call_with_child1c_if_nonnull_8826A1A0(Ts4Child1C2 *t) { void *p = t->child; if (p) ts4_loop_call_seq_u32_offc0_886AB080(p); }
