/* Top Spin 4 (Xbox 360, Swing_DLL.xex) 0x888B3BF0 - EQUIVALENT tier, not byte-matched.
 * Not byte-matchable from C: the jump table lands on case bodies that are separate functions.
 * fn_equiv/4 evidence: work/q5/evidence/eq_q5f_command_dispatch.equiv.json (flags /Oc) */
typedef unsigned char u8;
typedef unsigned int u32;
/* ---- 0x888B3BF0: camera/menu command dispatch by index 0..14. The original's jump table
 * lands on the small case bodies that the split carries as separate functions (sm3_a,
 * sm3_b, fj_small_a, forward_thunks, fk_024); only case 14 (toggle +0x69) sits inside
 * the function. Each of those bodies passes `self` (r3) on to its callee untouched, so
 * they are declared here with that parameter. Not byte-matched: the case bodies are
 * separate functions, so C cannot reproduce the table. */
typedef struct Q5Cmd { char pad[0x68]; u8 flag68; u8 flag69; } Q5Cmd;
extern void ts4_call_with_const14_888B3D34(Q5Cmd *self);
extern void ts4_call_with_const0_888B3D28(Q5Cmd *self);
extern void ts4_call_with_const0_888B3D0C(Q5Cmd *self);
extern void ts4_call_with_const14_888B3D18(Q5Cmd *self);
extern void ts4_call_with_const0_888B3C70(Q5Cmd *self);
extern void ts4_call_with_const14_888B3C60(Q5Cmd *self);
extern void ts4_dispatch_const14_by_flag_888B3CB0(Q5Cmd *self);
extern void ts4_select_call_by_flag_with_constant_888B3C94(Q5Cmd *self);
extern void ts4_dispatch_const14_by_flag_888B3CD0(Q5Cmd *self);
extern void ts4_select_call_by_flag_with_constant_888B3CF0(Q5Cmd *self);
extern void ts4_call_with_const0_888B3D54(Q5Cmd *self);
extern void ts4_call_with_const14_888B3D44(Q5Cmd *self);
extern void ts4_forward_888B3C90(Q5Cmd *self);
extern u8 ts4_get_u8_off68_888B3C7C(Q5Cmd *self);

/* Swing_DLL.xex 0x888B3BF0 */
void ts4_command_dispatch_888B3BF0(Q5Cmd *self, u32 cmd)
{
    switch (cmd) {
    case 0: ts4_call_with_const14_888B3D34(self); break;
    case 1: ts4_call_with_const0_888B3D28(self); break;
    case 2: ts4_call_with_const0_888B3D0C(self); break;
    case 3: ts4_call_with_const14_888B3D18(self); break;
    case 4: ts4_call_with_const0_888B3C70(self); break;
    case 5: ts4_call_with_const14_888B3C60(self); break;
    case 6: ts4_dispatch_const14_by_flag_888B3CB0(self); break;
    case 7: ts4_select_call_by_flag_with_constant_888B3C94(self); break;
    case 8: ts4_dispatch_const14_by_flag_888B3CD0(self); break;
    case 9: ts4_select_call_by_flag_with_constant_888B3CF0(self); break;
    case 10: ts4_call_with_const0_888B3D54(self); break;
    case 11: ts4_call_with_const14_888B3D44(self); break;
    case 12: ts4_forward_888B3C90(self); break;
    case 13: (void)ts4_get_u8_off68_888B3C7C(self); break;
    case 14: self->flag69 = !self->flag69; break;
    }
}
