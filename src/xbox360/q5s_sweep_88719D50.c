/* Top Spin 4 (Xbox 360, Swing_DLL.xex) 0x88719D50: releases the GPU resource (fence wait on the active device), then for each id in the vector at +0x1c that
 * is not in the library's skip list recursively releases lib->mats[id] (0x3c-byte objects of the same type) and removes the
 * id, then clears the id vector.
 * Byte-exact form found by tools/perm_auto.py --targeted from drafts/me_88719D50_nearmiss_agBI.c (Q5S sweep, 2026-11-24): four chained alias locals of the parameter (symbol numbering) and a block-local `first`; plain route only (the unit
 * reads __imp_VdGlobalDevice, which the LTCG check link cannot resolve).
 * See work/specs/Q5S/sweep_88719D50.json for route and flags. */
typedef unsigned int u32; typedef unsigned char u8;
typedef struct GpuRes { char p0[8]; u32 fence; } GpuRes;
extern char **__imp_VdGlobalDevice;
extern char **__imp_VdGlobalXamDevice;
extern int KeGetCurrentProcessType(void);
extern void fn_88292698(void *dev, u32 fence, u32 a, u32 b);
extern u32 ts4_if_atomic_interlocked_dec_88288530(void *res);
static __inline char *gpu_device(void)
{
    return KeGetCurrentProcessType() == 2 ? *__imp_VdGlobalXamDevice : *__imp_VdGlobalDevice;
}
static __inline void gpu_block_on_fence(void *dev, u32 fence)
{
    if (fence) fn_88292698(dev, fence, 5, 0);
}
typedef struct { int *first; int *last; } IVec;
typedef struct Obj { int res; char p4[0x18]; IVec ids; char p24[0x18]; } Obj;
typedef struct { char p[0x34]; char tbl[0x10]; int *lfirst; int *llast; char p2[8]; Obj *mats; } Lib;
typedef struct { char p[0x24]; Lib *lib; } Glob;
extern Glob *lbl_88D45AD4;
void ts4_material_release_88719D50(Obj *o);
void ts4_ptrvec_add_fin_88222B50(void *t, int id);
void *fn_88562DC0(void *d, const void *s, u32 n);
static int *icopy(int *first, int *last, int *dest) { u32 n; if (first == last) return dest; n = (char *)last - (char *)first; dest = (int *)fn_88562DC0(dest, first, n); return (int *)((char *)dest + n); }
static int *ivat(IVec *v, u32 i) { return &v->first[i]; }
static void iclear(IVec *v) { v->last = icopy(v->last, v->last, v->first); }
static u8 lib_has(Glob *g, int id) { int *e, *p; if (id < 0) return 0; e = g->lib->llast; for (p = g->lib->lfirst; e != p; p++) if ((u32)id == (u32)*p) return 0; return 1; }
void ts4_material_release_88719D50(Obj *o)
{ Obj* o1 = o;  Obj* o2 = o1;  Obj* o3 = o2;  Obj* obj = o3; 
  Glob *g; u32 i, n; IVec *v;
  GpuRes *r = (GpuRes *)obj->res;
  if (obj->res != 0) {
    gpu_block_on_fence(gpu_device(), r->fence);
    { GpuRes **pp = (GpuRes **)&obj->res; if (*pp && !ts4_if_atomic_interlocked_dec_88288530(*pp)) *pp = 0; }
    obj->res = 0;
  }
  v = &obj->ids; g = lbl_88D45AD4;
  { int * first = v->first; n = v->last - first; }
  for (i = 0; i < n; i++) {
    int id = *ivat(v, i);
    if (lib_has(g, id)) {
      ts4_material_release_88719D50(&g->lib->mats[id]);
      ts4_ptrvec_add_fin_88222B50((char *)g->lib + 0x34, id);
    }
  }
  iclear(v);
}
