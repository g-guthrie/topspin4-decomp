/* Loader_DLL.xex 0x830CD5D8-0x830CD65C, executable version 0.0.0.3. */
typedef unsigned int u32;
struct Dev { char pad[0x6c]; int flags; char pad2[0x0c]; int cnt_a; int cnt_b; };
struct Seg {
    struct Dev *dev; char pad0[0x1c]; u32 kind; char pad1[4]; int end; u32 *hdr; u32 hflags;
    char pad2[12]; int start; char pad3[4]; int result;
};

int ts4l_seg_close_830CD5D8(struct Seg *s)
{
    u32 *h;
    u32 f;
    int n;
    if ((s->dev->flags & 0xF) == 7) return 0;
    h = s->hdr;
    if (h == 0) return -1;
    f = s->hflags & 0xBFFFFFFFu;
    s->hflags = f;
    *h = f;
    n = (s->end - s->start) >> 2;
    if (s->kind & 1) s->dev->cnt_a += n;
    else s->dev->cnt_b += n;
    return s->result;
}
