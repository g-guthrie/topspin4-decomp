/* DRAFT helper (not built): LTCG context for drafts/pr1_execute_pass_commands.c, see its header. */
/* LTCG context stubs: callees of ExecutePassCommands that do not write g_Display (lbl_88D45AD4).
   Each stub touches only its own static data but uses every volatile GPR, so LTCG treats r3-r12 as clobbered. */
#ifdef _MSC_VER
#define PR1_NOINLINE __declspec(noinline)
#else
#define PR1_NOINLINE
#endif
typedef unsigned int u32;
typedef struct Pr1SurfDesc { u32 w[8]; } Pr1SurfDesc;
static u32 s_pr1_scratch[16];
#define PR1_CLOBBER(seed) do { \
    u32 *q = s_pr1_scratch; \
    u32 a0 = q[0] + (seed), a1 = q[1], a2 = q[2], a3 = q[3], a4 = q[4], a5 = q[5], a6 = q[6], a7 = q[7], a8 = q[8], a9 = q[9]; \
    q[10] = a0 * a1 + a2 * a3; q[11] = a4 * a5 + a6 * a7; q[12] = a8 * a9 + a0 * a5; \
    q[13] = a1 * a6 + a2 * a7; q[14] = a3 * a8 + a4 * a9; q[15] = a0 ^ a1 ^ a2 ^ a3 ^ a4 ^ a5 ^ a6 ^ a7 ^ a8 ^ a9; \
} while (0)
PR1_NOINLINE void fn_88289D38(void *tex, u32 level, Pr1SurfDesc *desc) { PR1_CLOBBER(level); desc->w[0] = level; (void)tex; }
/* register footprint like the real 0x886EB3E8 (r3, r8-r12): callers may keep a value in r7 across it */
static u32 s_pr1_fmt[8];
PR1_NOINLINE int fn_886EB3E8(u32 format)
{
    u32 *q = s_pr1_fmt;
    u32 a = q[0], b = q[1];
    q[6] = a*b + format;
    return (int)(a+b + format);
}
PR1_NOINLINE void fn_88292698(void *dev, u32 fence, u32 a, u32 b) { PR1_CLOBBER(a); *(u32 *)dev = fence + a + b; }
PR1_NOINLINE u32 ts4_if_atomic_interlocked_dec_88288530(void *res) { PR1_CLOBBER(0); return --*(u32 *)res; }
PR1_NOINLINE int KeGetCurrentProcessType(void) { PR1_CLOBBER(1); return 1; }
