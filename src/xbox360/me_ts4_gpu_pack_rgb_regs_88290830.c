/* Swing_DLL.xex 0x88290830: packs the low byte of the x/y/z words of n 16-byte entries into 0x00ZZYYXX words at
 * device regs[0x9f8 + start] and sets dirty bit 56 at +0x20. agAD: /O1 (the /Oc build chains the ORs in fresh registers). */
typedef struct Rgbx { unsigned int x, y, z, w; } Rgbx;
typedef struct GpuState { char p0[0x20]; unsigned __int64 dirty; char p28[0x27e0 - 0x28]; unsigned int regs[64]; } GpuState;
void ts4_gpu_pack_rgb_regs_88290830(GpuState *d, unsigned int start, const Rgbx *c, unsigned int n)
{
    unsigned int *dst = &d->regs[start];
    do {
        *dst++ = ((c->z & 0xff) << 16) | ((c->y & 0xff) << 8) | (c->x & 0xff);
        c++;
    } while (--n);
    d->dirty |= 1ull << 56;
}
