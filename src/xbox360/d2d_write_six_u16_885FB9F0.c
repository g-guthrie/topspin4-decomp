/* Swing_DLL.xex 0x885FB9F0-0x885FC3D8, executable version 0.0.0.3. */
typedef unsigned int u32;
typedef unsigned short u16;
typedef struct { char p[0xc]; u16 a,b,c,d,e,f; } Rec;
extern char *fn_88603F38(Rec *o, u32 off);



int ts4_write_six_u16_fields_885FB9F0(Rec *o, u32 off)
{
    char *p = fn_88603F38(o, off) + off;
    *(u16 *)p = o->a; p += 2;
    *(u16 *)p = o->b; p += 2;
    *(u16 *)p = o->c; p += 2;
    *(u16 *)p = o->d; p += 2;
    *(u16 *)p = o->e; p += 2;
    *(u16 *)p = o->f; p += 2;
    return (int)(unsigned long)(p - off);
}

int ts4_write_six_u16_fields_885FC310(Rec *o, u32 off)
{
    char *p = fn_88603F38(o, off) + off;
    *(u16 *)p = o->a; p += 2;
    *(u16 *)p = o->b; p += 2;
    *(u16 *)p = o->c; p += 2;
    *(u16 *)p = o->d; p += 2;
    *(u16 *)p = o->e; p += 2;
    *(u16 *)p = o->f; p += 2;
    return (int)(unsigned long)(p - off);
}

int ts4_write_six_u16_fields_885FC3D8(Rec *o, u32 off)
{
    char *p = fn_88603F38(o, off) + off;
    *(u16 *)p = o->a; p += 2;
    *(u16 *)p = o->b; p += 2;
    *(u16 *)p = o->c; p += 2;
    *(u16 *)p = o->d; p += 2;
    *(u16 *)p = o->e; p += 2;
    *(u16 *)p = o->f; p += 2;
    return (int)(unsigned long)(p - off);
}
