/* Swing_DLL.xex 0x8899E040: OR the source's 128-bit flags (src +0x24, placed at words 3-6 of a zeroed 256-bit value) into the holder mask (+0x90) via 88150CA8, then bump the source change count (+0x48).
 * /Oc. Read the four flag words into locals after zeroing words 0-2, then zero word 7, then store the locals: the target loads all four before any store. */
typedef struct Bits256 { unsigned int w[8]; } Bits256;
typedef struct FlagSource { char pad[0x24]; unsigned int flags[4]; char pad2[0x48 - 0x34]; int changeCount; } FlagSource;
typedef struct MaskHolder { char pad[0x2c]; FlagSource *src; char pad2[0x90 - 0x30]; Bits256 mask; } MaskHolder;
Bits256 *fn_88150CA8(Bits256 *out, const Bits256 *a, const Bits256 *b);

void fn_8899E040(MaskHolder *o)
{
    FlagSource *src = o->src;
    Bits256 add;
    Bits256 result;
    unsigned int f0, f1, f2, f3;
    add.w[0] = 0;
    add.w[1] = 0;
    add.w[2] = 0;
    f0 = src->flags[0];
    f1 = src->flags[1];
    f2 = src->flags[2];
    f3 = src->flags[3];
    add.w[7] = 0;
    add.w[3] = f0;
    add.w[4] = f1;
    add.w[5] = f2;
    add.w[6] = f3;
    o->mask = *fn_88150CA8(&result, &o->mask, &add);
    src->changeCount++;
}
