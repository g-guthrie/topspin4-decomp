/* 0x88867310: true when the pad's profile record exists, is signed in (+0x1a) and
   fn_888CDF68(pad) reports false. */
typedef unsigned int u32;
typedef unsigned char u8;
typedef struct PadObj { u8 pad[0x1a]; u8 b1a; } PadObj;
typedef struct ModList ModList;
typedef struct Engine { u8 pad[0x234]; ModList *modules; } Engine;
extern Engine *lbl_88D45B1C;
extern PadObj *ts4_pad_record_find_88614938(ModList *m, int pad);
extern u8 fn_888CDF68(int pad);
u8 ts4_pad_signed_in_not_flagged_88867310(int pad)
{
    PadObj *p = ts4_pad_record_find_88614938(lbl_88D45B1C->modules, pad);
    if (p)
        return p->b1a && !fn_888CDF68(pad);
    return 0;
}
