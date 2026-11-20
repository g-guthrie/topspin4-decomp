/* Swing_DLL.xex 0x885FC388-0x88603FA8, executable version 0.0.0.3. */
typedef unsigned int u32;
typedef struct { char p[0xc]; u32 v; } Rec;
extern char *fn_88603F38(Rec *o, u32 off);



int ts4_write_u32_field_c_885FC388(Rec *o, u32 off)
{
    char *p = fn_88603F38(o, off) + off;
    *(u32 *)p = o->v;
    p += 4;
    return (int)(unsigned long)(p - off);
}

int ts4_write_u32_field_c_885FC450(Rec *o, u32 off)
{
    char *p = fn_88603F38(o, off) + off;
    *(u32 *)p = o->v;
    p += 4;
    return (int)(unsigned long)(p - off);
}

int ts4_write_u32_field_c_885FC540(Rec *o, u32 off)
{
    char *p = fn_88603F38(o, off) + off;
    *(u32 *)p = o->v;
    p += 4;
    return (int)(unsigned long)(p - off);
}

int ts4_write_u32_field_c_885FCB28(Rec *o, u32 off)
{
    char *p = fn_88603F38(o, off) + off;
    *(u32 *)p = o->v;
    p += 4;
    return (int)(unsigned long)(p - off);
}

int ts4_write_u32_field_c_88601C78(Rec *o, u32 off)
{
    char *p = fn_88603F38(o, off) + off;
    *(u32 *)p = o->v;
    p += 4;
    return (int)(unsigned long)(p - off);
}

int ts4_write_u32_field_c_88603FA8(Rec *o, u32 off)
{
    char *p = fn_88603F38(o, off) + off;
    *(u32 *)p = o->v;
    p += 4;
    return (int)(unsigned long)(p - off);
}
