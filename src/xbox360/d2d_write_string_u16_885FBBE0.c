/* Swing_DLL.xex 0x885FBBE0-0x885FC590, executable version 0.0.0.3. */
typedef unsigned int u32;
typedef unsigned short u16;
typedef struct { char p[0xc]; const char *s; u16 a; } Rec;
extern char *fn_88603F38(Rec *o, u32 off);
extern u32 fn_88603D78(char *dst, const char *s);



int ts4_write_string_u16_885FBBE0(Rec *o, u32 off)
{
    char *p = fn_88603F38(o, off) + off;
    p += fn_88603D78(p, o->s);
    *(u16 *)p = o->a; p += 2;
    return (int)(unsigned long)(p - off);
}

int ts4_write_string_u16_885FC500(Rec *o, u32 off)
{
    char *p = fn_88603F38(o, off) + off;
    p += fn_88603D78(p, o->s);
    *(u16 *)p = o->a; p += 2;
    return (int)(unsigned long)(p - off);
}

int ts4_write_string_u16_885FC590(Rec *o, u32 off)
{
    char *p = fn_88603F38(o, off) + off;
    p += fn_88603D78(p, o->s);
    *(u16 *)p = o->a; p += 2;
    return (int)(unsigned long)(p - off);
}
