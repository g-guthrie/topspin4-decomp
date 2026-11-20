/* Swing_DLL.xex 0x888C39A0: index of the 0x44-byte record whose word at +0x3c equals id in the self-relative table at
 * lbl_88D45908->+0x54 ({offset, count} header), or -1. agO: plain and LTCG. */
typedef struct Rec { char pad[0x3c]; unsigned id; char rest[4]; } Rec;
typedef struct Table { unsigned offset; unsigned count; } Table;
typedef struct Ts4Db { char pad[0x54]; Table *table; } Ts4Db;
extern Ts4Db *lbl_88D45908;

int fn_888C39A0(unsigned id)
{
    int r = -1;
    Table *t = lbl_88D45908->table;
    unsigned i;
    for (i = 0; i < t->count; i++) {
        if (((Rec *)((char *)t + t->offset))[i].id == id) {
            r = i;
            break;
        }
    }
    return r;
}
