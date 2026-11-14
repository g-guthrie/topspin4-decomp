/* Swing_DLL.xex 0x885FBB40-0x88603350, executable version 0.0.0.3. */
typedef unsigned int u32;
typedef struct { char p[0xc]; unsigned short v; } Rec;
extern char *fn_88603F38(Rec *o, u32 off);



int ts4_write_u16_field_c_885FBB40(Rec *o, u32 off)
{
    char *p = fn_88603F38(o, off) + off;
    *(unsigned short *)p = o->v;
    p += 2;
    return (int)(unsigned long)(p - off);
}

int ts4_write_u16_field_c_885FBD58(Rec *o, u32 off)
{
    char *p = fn_88603F38(o, off) + off;
    *(unsigned short *)p = o->v;
    p += 2;
    return (int)(unsigned long)(p - off);
}

int ts4_write_u16_field_c_885FBF10(Rec *o, u32 off)
{
    char *p = fn_88603F38(o, off) + off;
    *(unsigned short *)p = o->v;
    p += 2;
    return (int)(unsigned long)(p - off);
}

int ts4_write_u16_field_c_885FC0D8(Rec *o, u32 off)
{
    char *p = fn_88603F38(o, off) + off;
    *(unsigned short *)p = o->v;
    p += 2;
    return (int)(unsigned long)(p - off);
}

int ts4_write_u16_field_c_885FC868(Rec *o, u32 off)
{
    char *p = fn_88603F38(o, off) + off;
    *(unsigned short *)p = o->v;
    p += 2;
    return (int)(unsigned long)(p - off);
}

int ts4_write_u16_field_c_885FCB78(Rec *o, u32 off)
{
    char *p = fn_88603F38(o, off) + off;
    *(unsigned short *)p = o->v;
    p += 2;
    return (int)(unsigned long)(p - off);
}

int ts4_write_u16_field_c_88601E00(Rec *o, u32 off)
{
    char *p = fn_88603F38(o, off) + off;
    *(unsigned short *)p = o->v;
    p += 2;
    return (int)(unsigned long)(p - off);
}

int ts4_write_u16_field_c_88603350(Rec *o, u32 off)
{
    char *p = fn_88603F38(o, off) + off;
    *(unsigned short *)p = o->v;
    p += 2;
    return (int)(unsigned long)(p - off);
}
