/* Swing_DLL.xex 0x8833BA38-0x883703A8, executable version 0.0.0.3. */
typedef struct Ts4Obj8833BA38 { char pad[0x134]; unsigned char on; } Ts4Obj8833BA38;
extern int fn_8833B258(Ts4Obj8833BA38 *o, unsigned enable);
typedef struct Ts4Obj8833D818 { char pad[0x134]; unsigned char on; } Ts4Obj8833D818;
extern int fn_8833D6D8(Ts4Obj8833D818 *o, unsigned enable);
typedef struct Ts4Obj88370328 { char pad[0x110]; unsigned char on; } Ts4Obj88370328;
extern int ts4_loop_call_seq_u32_off14c_8836F668(Ts4Obj88370328 *o, unsigned enable);
int ts4_set_enabled_88370328(void *sub, unsigned enable)
{
    Ts4Obj88370328 *o = sub ? (Ts4Obj88370328 *)((char *)sub - 0x1c) : 0;
    int r;
    if (enable) {
        if (o->on != 0) { return 0; }
        r = ts4_loop_call_seq_u32_off14c_8836F668(o, enable);
        if (r != 0) { return r; }
        o->on = 1;
    } else {
        r = ts4_loop_call_seq_u32_off14c_8836F668(o, 0);
        if (r != 0) { return r; }
        o->on = 0;
    }
    return 0;
}
