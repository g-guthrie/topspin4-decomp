/* Swing_DLL.xex 0x886FCB48: bind a source descriptor to a renderer binding, then copy two descriptor words. */
typedef unsigned int u32;
typedef struct Ts4BindSrc Ts4BindSrc;
typedef struct Ts4Bind Ts4Bind;
extern void fn_886F3798(Ts4Bind *o, Ts4BindSrc *s);
typedef struct Ts4BindHost { char pad[0x18]; u32 f18; u32 f1c; } Ts4BindHost;
typedef struct Ts4BindDesc { char pad[0x30]; u32 f30; u32 f34; } Ts4BindDesc;
void ts4_bind_attach_886FCB48(Ts4BindHost *h, Ts4BindDesc *d)
{
    fn_886F3798((Ts4Bind *)h, (Ts4BindSrc *)d);
    h->f1c = d->f30;
    h->f18 = d->f34;
}
