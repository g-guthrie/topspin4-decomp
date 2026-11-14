/* Swing_DLL.xex 0x883D0668-0x883D069C, executable version 0.0.0.3. */


int ts4_get_entry_883D0668(char *o, void **out)
{
    void *e = o != 0 ? o - 4 : 0;
    if (o == 0)
        return 0x24;
    if (out == 0)
        return 0x25;
    *out = e;
    return 0;
}
