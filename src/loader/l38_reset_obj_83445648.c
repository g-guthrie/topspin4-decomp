/* Loader_DLL.xex 0x83445648-0x83445740, executable version 0.0.0.3. */
typedef unsigned long u32;
extern void fn_83452518(void *p);
extern void fn_8344C6B0(void *o, u32 v);
extern void *fn_833E3A30(void *dst, int v, u32 n);
typedef struct { char p0[0x540]; u32 k0; u32 k1; u32 k2; char p1[0x564 - 0x54c]; char sub[0x38]; u32 a59c; char p2[0x5d8 - 0x5a0]; u32 a5d8, a5dc, a5e0, a5e4, a5e8, a5ec; char p3[0x684 - 0x5f0]; u32 a684, a688, a68c, a690, a694; } Obj;
typedef struct { char b[0x540]; } Blk;
void ts4l_reset_obj_83445648(Obj *o)
{
    Blk save;
    u32 k0, k1, k2;
    fn_83452518(o->sub);
    fn_8344C6B0(o, o->a59c);
    fn_8344C6B0(o, o->a5dc);
    fn_8344C6B0(o, o->a5d8);
    fn_8344C6B0(o, o->a5e0);
    fn_8344C6B0(o, o->a5e4);
    fn_8344C6B0(o, o->a5e8);
    fn_8344C6B0(o, o->a5ec);
    fn_8344C6B0(o, o->a684);
    fn_8344C6B0(o, o->a688);
    fn_8344C6B0(o, o->a68c);
    fn_8344C6B0(o, o->a690);
    fn_8344C6B0(o, o->a694);
    save = *(Blk *)o;
    k0 = o->k0; k1 = o->k1; k2 = o->k2;
    fn_833E3A30(o, 0, 0x6a0);
    o->k0 = k0; o->k1 = k1; o->k2 = k2;
    *(Blk *)o = save;
}
