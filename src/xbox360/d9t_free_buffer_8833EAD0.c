/* Swing_DLL.xex 0x8833EAD0-0x8836F028, executable version 0.0.0.3. */
typedef struct Ts4Heap { int pad; void *impl; } Ts4Heap;
extern Ts4Heap *lbl_88B3302C;
extern char lbl_88029DF0[];
extern char lbl_8802A690[];
extern char lbl_8802B928[];
extern void fn_88315F10(void *impl, void *p, const char *file, int line);
typedef struct Ts4Obj8833EAD0 { char pad[0x158]; void *buf; } Ts4Obj8833EAD0;
int ts4_free_buffer_8833EAD0(void *sub)
{
    Ts4Obj8833EAD0 *o = sub ? (Ts4Obj8833EAD0 *)((char *)sub - 0x1c) : 0;
    if (o->buf != 0) {
        fn_88315F10(lbl_88B3302C->impl, o->buf, lbl_88029DF0, 0xee);
        o->buf = 0;
    }
    return 0;
}
typedef struct Ts4Obj88346080 { char pad[0x158]; void *buf; } Ts4Obj88346080;
int ts4_free_buffer_88346080(void *sub)
{
    Ts4Obj88346080 *o = sub ? (Ts4Obj88346080 *)((char *)sub - 0x1c) : 0;
    if (o->buf != 0) {
        fn_88315F10(lbl_88B3302C->impl, o->buf, lbl_8802A690, 0x128);
        o->buf = 0;
    }
    return 0;
}
typedef struct Ts4Obj8836EFC0 { char pad[0x40]; void *buf; } Ts4Obj8836EFC0;
int ts4_free_buffer_8836EFC0(void *sub)
{
    Ts4Obj8836EFC0 *o = sub ? (Ts4Obj8836EFC0 *)((char *)sub - 0x1c) : 0;
    if (o->buf != 0) {
        fn_88315F10(lbl_88B3302C->impl, o->buf, lbl_8802B928, 0xad);
        o->buf = 0;
    }
    return 0;
}
