/* Swing_DLL.xex 0x885F6488-0x88600BB8, executable version 0.0.0.3. */
typedef unsigned int u32;
typedef unsigned short u16;
typedef struct { char p[0xc]; u16 a; u32 b; } Rec;
extern char *fn_88603F38(Rec *o, u32 off);



int ts4_write_u16_u32_fields_885F6488(Rec *o, u32 off)
{
    char *p = fn_88603F38(o, off) + off;
    *(u16 *)p = o->a; p += 2;
    *(u32 *)p = o->b; p += 4;
    return (int)(unsigned long)(p - off);
}

int ts4_write_u16_u32_fields_885FC2B8(Rec *o, u32 off)
{
    char *p = fn_88603F38(o, off) + off;
    *(u16 *)p = o->a; p += 2;
    *(u32 *)p = o->b; p += 4;
    return (int)(unsigned long)(p - off);
}

int ts4_write_u16_u32_fields_885FC810(Rec *o, u32 off)
{
    char *p = fn_88603F38(o, off) + off;
    *(u16 *)p = o->a; p += 2;
    *(u32 *)p = o->b; p += 4;
    return (int)(unsigned long)(p - off);
}

int ts4_write_u16_u32_fields_885FC8B8(Rec *o, u32 off)
{
    char *p = fn_88603F38(o, off) + off;
    *(u16 *)p = o->a; p += 2;
    *(u32 *)p = o->b; p += 4;
    return (int)(unsigned long)(p - off);
}

int ts4_write_u16_u32_fields_88600BB8(Rec *o, u32 off)
{
    char *p = fn_88603F38(o, off) + off;
    *(u16 *)p = o->a; p += 2;
    *(u32 *)p = o->b; p += 4;
    return (int)(unsigned long)(p - off);
}
