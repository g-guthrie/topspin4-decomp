/* CX33: slot report helper (Swing_DLL.xex 0x88908530). */
typedef unsigned char u8;
typedef unsigned int u32;
extern char lbl_880D9950[];
extern char lbl_880D996C[];
extern void fn_88907570(void *o, u32 handle, void *text, u32 value);

typedef struct I3Slot { u8 pad10[0x10]; u32 w10; u32 w14; u32 w18; u8 pad1c[0xc]; u8 b28; u8 pad29; u8 b2a; u8 pad2b[9]; u8 b34; u8 pad35[0x5c - 0x35]; u32 w5c; } I3Slot;
typedef struct I3Obj { u8 pad[0x2fc]; u8 b2fc; u8 pad2fd; u8 b2fe; } I3Obj;

static __inline u8 chk_a(I3Obj *o) { return o->b2fe && o->b2fc == 1; }
static __inline u8 chk_b(I3Slot *s) { return s->b2a && s->b28 == 1; }

void ts4_slot_report_88908530(I3Obj *o, I3Slot *s)
{
    if (chk_a(o) || chk_b(s)) {
        u32 v = s->w10;
        u32 h = s->w5c;
        void *text;
        if (s->b34)
            text = lbl_880D9950;
        else
            text = lbl_880D996C;
        fn_88907570(o, h, text, v);
        s->w18 = 6;
    }
}
