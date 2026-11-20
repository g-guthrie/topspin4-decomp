/* CX33: small helper that only matches under the LTCG route (Swing_DLL.xex 0x889006A0). */
typedef unsigned char u8;

typedef struct Cx33Lua { u8 pad[0x70]; struct Cx33Holder *h70; } Cx33Lua;
struct Cx33Holder { u8 pad[0x30]; u8 b30; };
extern void *lbl_88D45A60;
extern Cx33Lua *lbl_88D41FC4;
extern void fn_88210B18(struct Cx33Holder *h);

/* 0x889006A0: store the flag in the holder, and notify if set */
void ts4_set_holder_flag_889006A0(u8 on)
{
    if (!lbl_88D45A60)
        return;
    lbl_88D41FC4->h70->b30 = on;
    if (on)
        fn_88210B18(lbl_88D41FC4->h70);
}
