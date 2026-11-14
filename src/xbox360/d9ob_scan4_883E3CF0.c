/* Swing_DLL.xex 0x883E3CF0-0x883E3D40, executable version 0.0.0.3. */
int ts4_lookup_then_forward_883173D8(void *a, void *b);

int ts4_scan4_883E3CF0(char *o, void *p)
{
    int i;
    int r;
    for (i = 0; i < 4; i++) {
        r = ts4_lookup_then_forward_883173D8(p, o + 0x14 + i * 0x4c);
        if (r != 0x49 && r != 0)
            return r;
    }
    return 0;
}
