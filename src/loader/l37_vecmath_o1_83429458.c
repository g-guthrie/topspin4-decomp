/* Loader_DLL.xex 0x83429458-0x83429C20, executable version 0.0.0.3. */
typedef unsigned int u32;
extern double lbl_8300C968;
extern double lbl_83005ED8;
extern double lbl_8300CA90;
extern double fn_833E4DA0(double);
extern double fn_833E10B0(double, double);
extern double fn_833E68F8(double);
extern double fn_833E69D8(double);
extern double fn_833E3390(double);
extern double ts4_tailcall_fn_833E3298_833E3458(double);
extern double fn_833E6B80(double);
extern double fn_833E6C68(double, double);
extern double sqrt(double);
extern double fabs(double);
#ifdef _MSC_VER
#pragma intrinsic(sqrt, fabs)
#endif

void ts4l_vneg_83429458(u32 n, double **in, double *out)
{
    u32 i;
    for (i = 0; i < n; i++) out[i] = -in[0][i];
}
void ts4l_vrecip_83429488(u32 n, double **in, double * __restrict out)
{
    u32 i;
    for (i = 0; i < n; i++) out[i] = lbl_83005ED8 / in[0][i];
}
void ts4l_vcall_83429640(u32 n, double **in, double *out)
{
    u32 i;
    for (i = 0; i < n; i++) out[i] = fn_833E68F8(in[0][i]);
}
void ts4l_vcall_83429688(u32 n, double **in, double *out)
{
    u32 i;
    for (i = 0; i < n; i++) out[i] = fn_833E69D8(in[0][i]);
}
void ts4l_vcall_834296D0(u32 n, double **in, double *out)
{
    u32 i;
    for (i = 0; i < n; i++) out[i] = fn_833E3390(in[0][i]);
}
void ts4l_vcall_83429718(u32 n, double **in, double *out)
{
    u32 i;
    for (i = 0; i < n; i++) out[i] = ts4_tailcall_fn_833E3298_833E3458(in[0][i]);
}
void ts4l_vcall_83429760(u32 n, double **in, double *out)
{
    u32 i;
    for (i = 0; i < n; i++) out[i] = fn_833E6B80(in[0][i]);
}
void ts4l_vcall2_83429948(u32 n, double **in, double *out)
{
    u32 i;
    for (i = 0; i < n; i++) out[i] = fn_833E6C68(in[0][i], in[1][i]);
}
void ts4l_vcall2s_83429BD0(u32 n, double **in, double *out)
{
    u32 i;
    for (i = 0; i < n; i++) out[i] = fn_833E6C68(*in[0], in[1][i]);
}
void ts4l_vmin_834297A8(u32 n, double **in, double *out)
{
    u32 i;
    for (i = 0; i < n; i++) { double a = in[0][i], b = in[1][i]; out[i] = a < b ? a : b; }
}
void ts4l_vmax_834297E8(u32 n, double **in, double *out)
{
    u32 i;
    for (i = 0; i < n; i++) { double a = in[0][i], b = in[1][i]; out[i] = a > b ? a : b; }
}
void ts4l_vmin_s_83429A30(u32 n, double **in, double *out)
{
    u32 i;
    for (i = 0; i < n; i++) { double a = *in[0], b = in[1][i]; out[i] = a < b ? a : b; }
}
void ts4l_vmax_s_83429A70(u32 n, double **in, double *out)
{
    u32 i;
    for (i = 0; i < n; i++) { double a = *in[0], b = in[1][i]; out[i] = a > b ? a : b; }
}
void ts4l_vlt_83429828(u32 n, double **in, double * __restrict out)
{
    u32 i;
    for (i = 0; i < n; i++) out[i] = in[0][i] < in[1][i] ? lbl_83005ED8 : lbl_8300C968;
}
void ts4l_vge_83429880(u32 n, double **in, double * __restrict out)
{
    u32 i;
    for (i = 0; i < n; i++) out[i] = in[0][i] >= in[1][i] ? lbl_83005ED8 : lbl_8300C968;
}
void ts4l_vlt_s_83429AB0(u32 n, double **in, double * __restrict out)
{
    u32 i;
    for (i = 0; i < n; i++) out[i] = *(volatile double *)in[0] < in[1][i] ? lbl_83005ED8 : lbl_8300C968;
}
void ts4l_vge_s_83429B08(u32 n, double **in, double * __restrict out)
{
    u32 i;
    for (i = 0; i < n; i++) out[i] = *(volatile double *)in[0] >= in[1][i] ? lbl_83005ED8 : lbl_8300C968;
}
void ts4l_vadd_834298D8(u32 n, double **in, double *out)
{
    u32 i;
    for (i = 0; i < n; i++) out[i] = in[0][i] + in[1][i];
}
void ts4l_vmul_83429910(u32 n, double **in, double *out)
{
    u32 i;
    for (i = 0; i < n; i++) out[i] = in[0][i] * in[1][i];
}
void ts4l_vadd_s_83429B60(u32 n, double **in, double *out)
{
    u32 i;
    for (i = 0; i < n; i++) out[i] = in[1][i] + *in[0];
}
void ts4l_vmul_s_83429B98(u32 n, double **in, double *out)
{
    u32 i;
    for (i = 0; i < n; i++) out[i] = in[1][i] * *in[0];
}
void ts4l_dot_83429998(u32 n, double **in, double *out)
{
    u32 i;
    out[0] = lbl_8300C968;
    for (i = 0; i < n; i++) out[0] += in[0][i] * in[1][i];
}
void ts4l_dot_s_83429C20(u32 n, double **in, double *out)
{
    u32 i;
    out[0] = lbl_8300C968;
    for (i = 0; i < n; i++) out[0] += in[1][i] * *in[0];
}
void ts4l_vrsqrt_83429600(u32 n, double **in, double * __restrict out)
{
    u32 i;
    for (i = 0; i < n; i++) out[i] = lbl_83005ED8 / sqrt(fabs(in[0][i]));
}
void ts4l_dot_pairs_834299E0(u32 n, double **in, double *out)
{
    u32 i, h = n >> 1;
    out[0] = lbl_8300C968;
    for (i = 0; i < h; i++) out[0] += *in[h + i] * *in[i];
}
