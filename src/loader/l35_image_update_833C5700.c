/* Loader_DLL.xex 0x833C5700-0x833C5794, executable version 0.0.0.3. */
typedef unsigned long u32;
struct Dev { char p[0xdac]; void *res; };
struct Img { char p0[0xc]; u32 off0, off1, off2; char p18[8]; u32 stride0, stride1; struct Dev *dev; };
extern void fn_830B0108(void *res, u32 off, u32 size, u32 flags);
void ts4l_image_update_833C5700(struct Img *im, int row)
{
    fn_830B0108(im->dev->res, im->off0 + im->stride0 * row, im->stride0, 0);
    fn_830B0108(im->dev->res, im->off1 + im->stride1 * row, im->stride1, 0);
    fn_830B0108(im->dev->res, im->off2 + im->stride1 * row, im->stride1, 0);
}
