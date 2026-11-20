/* Loader_DLL.xex 0x83326CC8-0x833DE048, executable version 0.0.0.3. */
#ifndef _MSC_VER
#define __forceinline inline
#endif

static __forceinline void ts4l_interp_plane(unsigned char *p, int step, int w, int h, int pitch, int *tmp)
{
    int y;
    int i;
    for (y = 0; y < h; y += step) {
        for (i = 0; i < w; i += 2)
            tmp[i] = p[i];
        for (i = 1; i < w - 1; i += 2)
            tmp[i] = (tmp[i - 1] + tmp[i + 1]) >> 1;
        tmp[w - 1] = tmp[w - 2];
        for (i = 0; i < w; i++)
            p[i] = (unsigned char)tmp[i];
        p += step * pitch;
    }
}

void ts4l_interp_planes_83326CC8(unsigned char *p0, unsigned char *p1, unsigned char *p2, int step,
                                 int w0, int h0, int w1, int h1, int pitch0, int pitch1, int *tmp)
{
    ts4l_interp_plane(p0, step, w0, h0, pitch0, tmp);
    ts4l_interp_plane(p1, step, w1, h1, pitch1, tmp);
    ts4l_interp_plane(p2, step, w1, h1, pitch1, tmp);
}

void ts4l_interp_planes_833DDDE0(unsigned char *p0, unsigned char *p1, unsigned char *p2, int step,
                                 int w0, int h0, int w1, int h1, int pitch0, int pitch1, int *tmp)
{
    ts4l_interp_plane(p0, step, w0, h0, pitch0, tmp);
    ts4l_interp_plane(p1, step, w1, h1, pitch1, tmp);
    ts4l_interp_plane(p2, step, w1, h1, pitch1, tmp);
}
