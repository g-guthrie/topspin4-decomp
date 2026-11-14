/* Swing_DLL.xex 0x8863A1C0-0x8863A208, executable version 0.0.0.3. */
typedef struct Ts4Seg { char pad[8]; unsigned size; } Ts4Seg;
typedef struct Ts4W { char pad[0x488]; int enabled; Ts4Seg *seg; unsigned off; char pad2[7]; unsigned char flag; } Ts4W;
void ts4_seg_step_8863A1C0(Ts4W *w, const unsigned char *f)
{
    if (w->enabled == 0) { return; }
    w->flag = *f;
    if (*f != 0) {
        w->off = w->seg->size + w->off;
        return;
    }
    w->off = w->off - w->seg->size;
}
