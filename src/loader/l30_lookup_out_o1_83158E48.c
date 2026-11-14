/* Loader_DLL.xex 0x83158E48-0x8315ED30, executable version 0.0.0.3. */
extern int fn_830C23C0(void *p);
extern int fn_830C1E70(void *p);
extern int fn_830C1A08(void *p);

int ts4l_lookup_out_o1_83158E48(void *u, void *key, int *out)
{
    int r;
    (void)u;
    r = fn_830C23C0(key);
    *out = r;
    if (r == 0) return (int)0x8007000E;
    return 0;
}

int ts4l_lookup_out_o1_8315E620(void *u, void *key, int *out)
{
    int r;
    (void)u;
    r = fn_830C1E70(key);
    *out = r;
    if (r == 0) return (int)0x8007000E;
    return 0;
}

int ts4l_lookup_out_o1_8315E668(void *u, void *key, int *out)
{
    int r;
    (void)u;
    r = fn_830C1A08(key);
    *out = r;
    if (r == 0) return (int)0x8007000E;
    return 0;
}

int ts4l_lookup_out_o1_8315ECA0(void *u, void *key, int *out)
{
    int r;
    (void)u;
    r = fn_830C1E70(key);
    *out = r;
    if (r == 0) return (int)0x8007000E;
    return 0;
}

int ts4l_lookup_out_o1_8315ECE8(void *u, void *key, int *out)
{
    int r;
    (void)u;
    r = fn_830C1A08(key);
    *out = r;
    if (r == 0) return (int)0x8007000E;
    return 0;
}

int ts4l_lookup_out_o1_8315ED30(void *u, void *key, int *out)
{
    int r;
    (void)u;
    r = fn_830C23C0(key);
    *out = r;
    if (r == 0) return (int)0x8007000E;
    return 0;
}
