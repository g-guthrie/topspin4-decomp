/* Loader_DLL.xex 0x833C6868-0x833C68C8, executable version 0.0.0.3. */
extern int lbl_8352BF50[];
extern int lbl_83050D78[];
void ts4l_coord_adjust_833C6868(int unused0, int unused1, int unused2, int x, int y, int *outx, int *outy, int mode)
{
    (void)unused0; (void)unused1; (void)unused2;
    *outx = (lbl_8352BF50[x & 3] + x) >> 1;
    if (mode)
        *outy = lbl_83050D78[y & 15] + ((y >> 4) * 8);
    else
        *outy = (lbl_8352BF50[y & 3] + y) >> 1;
}
