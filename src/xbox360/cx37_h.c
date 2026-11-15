/* CX37: vector teardown helpers that contain a divide (needs /Oc), Swing_DLL.xex 0x8895xxxx. */
#ifdef _MSC_VER
#define CX37_INL static __forceinline
#else
#define CX37_INL static inline
#endif
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct Cx37E4c { u32 w0; u8 pad[0x48]; } Cx37E4c;
typedef struct Cx37V4c { Cx37E4c *first; Cx37E4c *last; } Cx37V4c;
extern void fn_88950190(void *out, u32 v);
extern void ts4_byte_string_assign_8815F510(Cx37E4c *dst, Cx37E4c *src);
CX37_INL Cx37E4c *cx37_copy4c(Cx37E4c *first, Cx37E4c *last, Cx37E4c *dst)
{
    int n = last - first;
    Cx37E4c *s = first;
    Cx37E4c *p = dst;
    if (n > 0)
        s = first;
    while (n > 0) {
        ts4_byte_string_assign_8815F510(p, s);
        n--;
        s++;
        p++;
    }
    return p;
}
typedef struct Cx37Own244 { u8 pad[0x244]; Cx37V4c v; } Cx37Own244;
typedef struct Cx37Own238 { u8 pad[0x238]; Cx37V4c v; } Cx37Own238;
/* 0x88952D90 */
void ts4_clear_list_244_88952D90(Cx37Own244 *o)
{
    Cx37V4c *v = &o->v;
    Cx37E4c *p;
    u8 tmp[16];
    for (p = v->first; p != o->v.last; p++)
        fn_88950190(tmp, p->w0);
    v->last = cx37_copy4c(v->last, v->last, v->first);
}
/* 0x88952E10 */
void ts4_clear_list_238_88952E10(Cx37Own238 *o)
{
    Cx37V4c *v = &o->v;
    Cx37E4c *p;
    u8 tmp[16];
    for (p = v->first; p != o->v.last; p++)
        fn_88950190(tmp, p->w0);
    v->last = cx37_copy4c(v->last, v->last, v->first);
}
