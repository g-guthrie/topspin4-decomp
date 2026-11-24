/* 0x8843F6C0: Sets lbl_88C21964 = ((float)(value / 8) - lbl_88029278) * lbl_88081B10 and lbl_88C21968 = lbl_88001A68 / that. */
/* Matched on /Oc /O2 (agAH). Signed /8 gives srawi/addze; the second line reads the global back (no local), which the compiler forwards from the register. */
extern const float lbl_88029278;
extern const float lbl_88081B10;
extern const float lbl_88001A68;
extern float lbl_88C21964;
extern float lbl_88C21968;

void fn_8843F6C0(int value)
{
    lbl_88C21964 = ((float)(value / 8) - lbl_88029278) * lbl_88081B10;
    lbl_88C21968 = lbl_88001A68 / lbl_88C21964;
}
