/* Loader_DLL.xex 0x830B9AE8-0x830DA400, executable version 0.0.0.3. */
/* D3D push-buffer writers: reserve space (fn_830BB150 on overflow) and append command words. */
typedef unsigned int u32;
typedef struct Ts4lDev { char pad[0x30]; u32 *cur; u32 *pad2; u32 *limit; } Ts4lDev;
extern u32 *fn_830BB150(Ts4lDev *d);


void ts4l_push_4_830B9AE8(Ts4lDev *d)
{
    u32 *p = d->cur;
    if (p > d->limit)
        p = fn_830BB150(d);
    *++p = 0x5c8;
    *++p = 0x20000u;
    *++p = 0xd04;
    *++p = 0x0;
    d->cur = p;
}

void ts4l_push_2_830BB440(Ts4lDev *d)
{
    u32 *p = d->cur;
    if (p > d->limit)
        p = fn_830BB150(d);
    *++p = 0x5c8;
    *++p = 0x20000u;
    d->cur = p;
}

void ts4l_push_4_830C9470(Ts4lDev *d)
{
    u32 *p = d->cur;
    if (p > d->limit)
        p = fn_830BB150(d);
    *++p = 0x5c8;
    *++p = 0x20000u;
    *++p = 0xc0004600u;
    *++p = 0xd;
    d->cur = p;
}

void ts4l_push_2_830DA088(Ts4lDev *d)
{
    u32 *p = d->cur;
    if (p > d->limit)
        p = fn_830BB150(d);
    *++p = 0xc0003b00u;
    *++p = 0x300;
    d->cur = p;
}

void ts4l_push_3_830DA168(Ts4lDev *d, u32 a, u32 b)
{
    u32 *p = d->cur;
    if (p > d->limit)
        p = fn_830BB150(d);
    *++p = 0x12180u;
    *++p = a;
    *++p = b;
    d->cur = p;
}


void ts4l_push_2_830DA400(Ts4lDev *d, u32 a, u32 b)
{
    u32 *p = d->cur;
    if (p > d->limit)
        p = fn_830BB150(d);
    *++p = 0xc0003600u;
    *++p = ((b << 16) | a) | 0x80u;
    d->cur = p;
}

void ts4l_push_shift_830DE268(Ts4lDev *d, u32 a)
{
    u32 *p = d->cur;
    if (p > d->limit)
        p = fn_830BB150(d);
    *++p = 0xc0003601u;
    *++p = (a << 16) | 0x86;
    d->cur = p;
}
