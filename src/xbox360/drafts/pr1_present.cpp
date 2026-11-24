/*
 * DRAFT (not part of the matching build). PR1, wave PR1. C++ (function-local statics with dynamic init).
 * 0x8875EB68 CDisplay::Present (0x260 B), names from docs/renderer-map.md section 1.2.
 *
 * Status: 32 instructions differ, all of them saved-register renames (target: self r31, lock r29,
 * s_front r30, &dev r28; this candidate: self r30, lock r28, s_front r29, &dev r31). Code, order, stack
 * layout (the timer locals in a block so the fctiwz temp reuses sp+0x58) and relocations are otherwise exact.
 * Tried: member function, RAII lock guard, dev through a local or direct, declaration orders, wrapping the
 * body, LTCG route.
 *
 * What it does (self = g_Display):
 *  1. if byte self+0x15649 != 0 (presentation suspended) return.
 *  2. lock the RHI (*(0x88D45A4C) + 0x154, vtable slot 1; slot 2 unlocks at the end).
 *  3. now = (float)(QueryPerformanceCounter / QueryPerformanceFrequency) via 0x8857AFF0/0x8857B010 (s64 out
 *     params); stored to self+0x15638.
 *  4. function-local statics (guard word 0x88D4D9E8 bits 0/1): s_back = index of "BackBuffer"
 *     (CRC32 0x623CC12C, stored at 0x88D4D9E4, computed but unused here), s_front = index of "FrontBuffer"
 *     (0x7E6E6B46, at 0x88D4D9E0), both looked up in the render-texture table self+0x10.
 *  5. frame limiter: if self+0x15804 (minimum frame time, s) > 0 and now - self+0x15634 (last frame start)
 *     is smaller, Sleep((int)((limit - dt) * g_ts4_script_constants[15])) through 0x8857AFE8 (the constant
 *     is the s->ms factor).
 *  6. dev = *(self+0x15720). If self+0x1562C != 0: SetShaderGPRAllocation(dev,0,0) (0x882910E8), pre-swap sync
 *     0x882957C8(dev,0), ResolveRT(*(*(self+0x3C)+0x10), FrontBuffer texture), then Swap.
 *     Else: sync, SetShaderGPRAllocation, Swap. Both swap the FrontBuffer texture:
 *     D3DDevice_Swap 0x88295D00(dev, tbl->ent[s_front].tex, 0). (The map's step 5 says BackBuffer for the
 *     second path; the code uses the FrontBuffer index in both.)
 *  7. unlock.
 * fn_equiv: see the PR1 report (work/equiv/pr1_8875EB68.json).
 */
#ifndef _MSC_VER
#define __forceinline inline
#endif
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
typedef unsigned int u32;
typedef unsigned char u8;
typedef long long s64;
struct Pr1Pair { u32 hash; int idx; };
struct Pr1RTex { u8 p0[8]; void *tex; u8 p1[0x38]; };
struct Pr1TexTab { u32 p0; Pr1Pair *first; Pr1Pair *last; u8 p1[0x18]; Pr1RTex *ent; };
struct Pr1Lock { void **vt; };
typedef void (*Pr1VFn)(void *);
extern "C" {
extern char *lbl_88D45A4C;
extern float lbl_8814B440;
extern float g_ts4_script_constants[];
void fn_8857AFF0(s64 *counter);
void fn_8857B010(s64 *frequency);
void ts4_tailcall_fn_88584548_8857AFE8(int ms);
void fn_882910E8(void *dev, u32 vs, u32 ps);
void fn_882957C8(void *dev, u32 a);
void fn_887561A8(void *rt, void *dest);
void fn_88295D00(void *dev, void *front, u32 params);
}
#define W(p, o) (*(u32 *)((char *)(p) + (o)))
#define F(p, o) (*(float *)((char *)(p) + (o)))
static __forceinline Pr1Pair *pr1_findp(Pr1TexTab *t, u32 h)
{
    Pr1Pair *e = t->last;
    Pr1Pair *p = t->first;
    for (; p != e; p++)
        if (p->hash == h) break;
    return p;
}
static __forceinline int pr1_find(Pr1TexTab *t, u32 h)
{
    Pr1Pair *p = pr1_findp(t, h);
    if (p != t->last) return p->idx;
    return -1;
}
extern "C" void ts4_display_present_8875EB68(char *self)
{
    Pr1Lock *lk;
    float now;
    if (*(u8 *)(self + 0x15649) != 0) return;
    lk = (Pr1Lock *)(lbl_88D45A4C + 0x154);
    ((Pr1VFn)lk->vt[1])(lk);
    {
        s64 cnt, freq;
        fn_8857AFF0(&cnt);
        fn_8857B010(&freq);
        now = (float)((double)cnt / (double)freq);
    }
    F(self, 0x15638) = now;
    static int s_back = pr1_find(*(Pr1TexTab **)(self + 0x10), 0x623CC12Cu);
    static int s_front = pr1_find(*(Pr1TexTab **)(self + 0x10), 0x7E6E6B46u);
    if (F(self, 0x15804) > lbl_8814B440) {
        float dt = now - F(self, 0x15634);
        if (dt < F(self, 0x15804))
            ts4_tailcall_fn_88584548_8857AFE8((int)((F(self, 0x15804) - dt) * g_ts4_script_constants[15]));
    }
    int front = s_front;
    void **pdev = (void **)(self + 0x15720);
    void *tex;
    /* g+0x1562C != 0: resolve the main render target into FrontBuffer, then swap that texture */
    if (*(int *)(self + 0x1562c) != 0) {
        fn_882910E8(*pdev, 0, 0);
        fn_882957C8(*pdev, 0);
        fn_887561A8(*(void **)(*(char **)(self + 0x3c) + 0x10), (*(Pr1TexTab **)(self + 0x10))->ent[front].tex);
        tex = (*(Pr1TexTab **)(self + 0x10))->ent[front].tex;
    } else {
        fn_882957C8(*pdev, 0);
        fn_882910E8(*pdev, 0, 0);
        tex = (*(Pr1TexTab **)(self + 0x10))->ent[front].tex;
    }
    fn_88295D00(*pdev, tex, 0);
    ((Pr1VFn)lk->vt[2])(lk);
}
