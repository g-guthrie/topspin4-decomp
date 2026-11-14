/* Swing_DLL.xex, MSVC 16.00.10224.00 /O2 /Oi. One macro per cluster; one line per original address. */
typedef unsigned int u32;

void fn_881992A8(void *, void *);
void *fn_8818BC98(void *);
void *fn_881909D0(void *);
void *ts4_if_call_seq_u32_off8_881929F8(void *);
void *fn_88197A28(void *);
void *fn_88198068(void *);
void *ts4_call_seq_u32_offc_881CCDF0(void *);
void *ts4_call_seq_u32_off28_881CD908(void *);
void *fn_881CEBD0(void *);
void *ts4_if_call_seq_u32_off14_881D4110(void *);
void *fn_881D4888(void *);
void *fn_881D57B8(void *);
void *ts4_if_call_seq_u32_off3c_881D5988(void *);
void *fn_881D6D90(void *);
void *ts4_if_call_seq_lbl_880E8618_881D9098(void *);
void *fn_881D9190(void *);
void *ts4_call_seq_u32_off1c_881DBB08(void *);
void *ts4_if_call_seq_u32_off1c_881DD6F8(void *);
void *fn_881DDF90(void *);
void *fn_881F0730(void *);
void *ts4_if_call_seq_u32_off44_881F1130(void *);
void *ts4_call_seq_lbl_880E9660_881F41E8(void *);
void *ts4_if_call_seq_lbl_880E97F0_881F8F40(void *);
void *ts4_if_call_seq_lbl_880E9890_881FC180(void *);
void *fn_881FDAC8(void *);
void *ts4_call_seq_u32_off24_88201338(void *);
void *ts4_if_call_seq_u32_offc_88206CA0(void *);
void *fn_88207420(void *);
void *ts4_if_call_seq_lbl_880E9E8C_882099C8(void *);
void *fn_88209AC0(void *);
void *fn_8820B580(void *);
void *fn_8820BFE8(void *);
void *ts4_call_seq_u32_off58_8820D100(void *);
void *ts4_call_seq_u32_offc_8863AF38(void *);
void *fn_887B5C98(void *);
void *fn_887B6788(void *);
void *fn_887C44E8(void *);

/* Calls destructor-like callee on self, then if (flags & 1) calls fn_881992A8(0, self); returns self.
   Looks like a scalar deleting destructor; callee roles not established. */
#define DTOR_THEN_CONDITIONAL_FREE(name, dtor) \
void *name(void *self, u32 flags) \
{ \
    dtor(self); \
    if (flags & 1) { \
        fn_881992A8(0, self); \
    } \
    return self; \
}

/* Swing_DLL.xex 0x8818BC40 */
DTOR_THEN_CONDITIONAL_FREE(ts4_dtor_then_conditional_free_8818BC40, fn_8818BC98)

/* Swing_DLL.xex 0x88190978 */
DTOR_THEN_CONDITIONAL_FREE(ts4_dtor_then_conditional_free_88190978, fn_881909D0)

/* Swing_DLL.xex 0x881929A0 */
DTOR_THEN_CONDITIONAL_FREE(ts4_dtor_then_conditional_free_881929A0, ts4_if_call_seq_u32_off8_881929F8)

/* Swing_DLL.xex 0x881979D0 */
DTOR_THEN_CONDITIONAL_FREE(ts4_dtor_then_conditional_free_881979D0, fn_88197A28)

/* Swing_DLL.xex 0x88198010 */
DTOR_THEN_CONDITIONAL_FREE(ts4_dtor_then_conditional_free_88198010, fn_88198068)

/* Swing_DLL.xex 0x881CD8B0 */
DTOR_THEN_CONDITIONAL_FREE(ts4_dtor_then_conditional_free_881CD8B0, ts4_call_seq_u32_off28_881CD908)

/* Swing_DLL.xex 0x881CEB78 */
DTOR_THEN_CONDITIONAL_FREE(ts4_dtor_then_conditional_free_881CEB78, fn_881CEBD0)

/* Swing_DLL.xex 0x881D40B8 */
DTOR_THEN_CONDITIONAL_FREE(ts4_dtor_then_conditional_free_881D40B8, ts4_if_call_seq_u32_off14_881D4110)

/* Swing_DLL.xex 0x881D4830 */
DTOR_THEN_CONDITIONAL_FREE(ts4_dtor_then_conditional_free_881D4830, fn_881D4888)

/* Swing_DLL.xex 0x881D5760 */
DTOR_THEN_CONDITIONAL_FREE(ts4_dtor_then_conditional_free_881D5760, fn_881D57B8)

/* Swing_DLL.xex 0x881D5930 */
DTOR_THEN_CONDITIONAL_FREE(ts4_dtor_then_conditional_free_881D5930, ts4_if_call_seq_u32_off3c_881D5988)

/* Swing_DLL.xex 0x881D6D38 */
DTOR_THEN_CONDITIONAL_FREE(ts4_dtor_then_conditional_free_881D6D38, fn_881D6D90)

/* Swing_DLL.xex 0x881D9040 */
DTOR_THEN_CONDITIONAL_FREE(ts4_dtor_then_conditional_free_881D9040, ts4_if_call_seq_lbl_880E8618_881D9098)

/* Swing_DLL.xex 0x881D9138 */
DTOR_THEN_CONDITIONAL_FREE(ts4_dtor_then_conditional_free_881D9138, fn_881D9190)

/* Swing_DLL.xex 0x881DBA88 */
DTOR_THEN_CONDITIONAL_FREE(ts4_dtor_then_conditional_free_881DBA88, ts4_call_seq_u32_off1c_881DBB08)

/* Swing_DLL.xex 0x881DD6A0 */
DTOR_THEN_CONDITIONAL_FREE(ts4_dtor_then_conditional_free_881DD6A0, ts4_if_call_seq_u32_off1c_881DD6F8)

/* Swing_DLL.xex 0x881DDF38 */
DTOR_THEN_CONDITIONAL_FREE(ts4_dtor_then_conditional_free_881DDF38, fn_881DDF90)

/* Swing_DLL.xex 0x881F06D8 */
DTOR_THEN_CONDITIONAL_FREE(ts4_dtor_then_conditional_free_881F06D8, fn_881F0730)

/* Swing_DLL.xex 0x881F10D8 */
DTOR_THEN_CONDITIONAL_FREE(ts4_dtor_then_conditional_free_881F10D8, ts4_if_call_seq_u32_off44_881F1130)

/* Swing_DLL.xex 0x881F4190 */
DTOR_THEN_CONDITIONAL_FREE(ts4_dtor_then_conditional_free_881F4190, ts4_call_seq_lbl_880E9660_881F41E8)

/* Swing_DLL.xex 0x881F8DA0 */
DTOR_THEN_CONDITIONAL_FREE(ts4_dtor_then_conditional_free_881F8DA0, ts4_if_call_seq_lbl_880E97F0_881F8F40)

/* Swing_DLL.xex 0x881FC128 */
DTOR_THEN_CONDITIONAL_FREE(ts4_dtor_then_conditional_free_881FC128, ts4_if_call_seq_lbl_880E9890_881FC180)

/* Swing_DLL.xex 0x881FD960 */
DTOR_THEN_CONDITIONAL_FREE(ts4_dtor_then_conditional_free_881FD960, fn_881FDAC8)

/* Swing_DLL.xex 0x882012E0 */
DTOR_THEN_CONDITIONAL_FREE(ts4_dtor_then_conditional_free_882012E0, ts4_call_seq_u32_off24_88201338)

/* Swing_DLL.xex 0x88206C48 */
DTOR_THEN_CONDITIONAL_FREE(ts4_dtor_then_conditional_free_88206C48, ts4_if_call_seq_u32_offc_88206CA0)

/* Swing_DLL.xex 0x882073C8 */
DTOR_THEN_CONDITIONAL_FREE(ts4_dtor_then_conditional_free_882073C8, fn_88207420)

/* Swing_DLL.xex 0x88209970 */
DTOR_THEN_CONDITIONAL_FREE(ts4_dtor_then_conditional_free_88209970, ts4_if_call_seq_lbl_880E9E8C_882099C8)

/* Swing_DLL.xex 0x88209A68 */
DTOR_THEN_CONDITIONAL_FREE(ts4_dtor_then_conditional_free_88209A68, fn_88209AC0)

/* Swing_DLL.xex 0x8820B528 */
DTOR_THEN_CONDITIONAL_FREE(ts4_dtor_then_conditional_free_8820B528, fn_8820B580)

/* Swing_DLL.xex 0x8820BF90 */
DTOR_THEN_CONDITIONAL_FREE(ts4_dtor_then_conditional_free_8820BF90, fn_8820BFE8)

/* Swing_DLL.xex 0x8820D0A8 */
DTOR_THEN_CONDITIONAL_FREE(ts4_dtor_then_conditional_free_8820D0A8, ts4_call_seq_u32_off58_8820D100)

/* Swing_DLL.xex 0x88210F78 */
DTOR_THEN_CONDITIONAL_FREE(ts4_dtor_then_conditional_free_88210F78, ts4_call_seq_u32_offc_881CCDF0)

/* Swing_DLL.xex 0x882133E8 */
DTOR_THEN_CONDITIONAL_FREE(ts4_dtor_then_conditional_free_882133E8, fn_887B6788)

/* Swing_DLL.xex 0x882134B8 */
DTOR_THEN_CONDITIONAL_FREE(ts4_dtor_then_conditional_free_882134B8, fn_887B5C98)

/* Swing_DLL.xex 0x882138B8 */
DTOR_THEN_CONDITIONAL_FREE(ts4_dtor_then_conditional_free_882138B8, fn_887C44E8)

/* Swing_DLL.xex 0x8827A290 */
DTOR_THEN_CONDITIONAL_FREE(ts4_dtor_then_conditional_free_8827A290, ts4_call_seq_u32_offc_8863AF38)

