/* Loader_DLL.xex 0x830AE828-0x830B0538, executable version 0.0.0.3. */
typedef unsigned int u32;
int ts4l_find_u32_830AE828(char *o, u32 key)
{
    u32 *p = (u32 *)(o + 0x2898);
    u32 i;
    for (i = 0; i < 8; i++) {
        if (*p == key)
            return i;
        p++;
    }
    return -1;
}

int ts4l_is_kind_830B0508(u32 k)
{
    if (k == 2 || k == 3 || k == 10 || k == 12)
        return 1;
    return 0;
}

int ts4l_not_kind_830B0538(u32 k)
{
    if (k == 5 || k == 7 || k == 15)
        return 0;
    return 1;
}
