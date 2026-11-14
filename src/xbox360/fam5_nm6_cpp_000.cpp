/* Small functions produced by the asm2c translator (FAM4 fork) and verified
   byte-for-byte with tools/fn_check.py (Swing_DLL.xex, Xbox 360, MSVC 16.00.10224.00).
   FAM5: near misses of the translator fixed by a per-function search over
   source-level variants (commutative operand order, int-widened byte/half
   locals, address of a parameter instead of a stack copy, a named pointer
   for a repeated base+offset, ||/&& conditions kept in a bool temporary,
   ...).  In .cpp files a function whose first argument is `this` is a member
   of a one-function struct ts4_obj_<ADDR>: MSVC orders the operands of
   commutative instructions differently for `this` than for a plain argument.
   The original address is in the comment above each definition. Parameters
   are untyped words (a0 = this/first argument); field accesses are by byte
   offset. */
#ifdef _MSC_VER
typedef unsigned __int64 ts4_u64;
typedef __int64 ts4_s64;
#else
typedef unsigned long long ts4_u64;
typedef long long ts4_s64;
#endif
typedef unsigned long ts4_word;

extern "C" {
extern char lbl_8802B898[];
extern char lbl_88B3302C[];
ts4_word fn_88315C60(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word);
ts4_word fn_884DADB0(ts4_word);
ts4_word fn_88692468(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word);
ts4_word ts4_call_seq_u32_off0_88627AD0(ts4_word);
ts4_word ts4_destroy_owned_object(ts4_word);
ts4_word ts4_if_call_seq_u32_off10_8861C5C8(ts4_word, ts4_word);
ts4_word ts4_if_get_u32_off0_8841AD18(ts4_word);
ts4_word ts4_object_finalize(ts4_word);

}
/* Swing_DLL.xex 0x88443530: get u32@0x18, u32@0x4 */
struct ts4_obj_88443530 { void ts4_get_u32_off18_88443530(ts4_word a1, ts4_word a2); };
void ts4_obj_88443530::ts4_get_u32_off18_88443530(ts4_word a1, ts4_word a2)
{
    ts4_word a0 = (ts4_word)this;
    *(ts4_word *)((char *)(ts4_word)(((a1 << 4) + (*(ts4_word *)((char *)(ts4_word)(a0) + 24)))) + 4) = (ts4_word)a2;
    return;
}

/* Swing_DLL.xex 0x884739D8: if_get u32@0x10, u8@0xd8, u32@0xc, u32@0x0, u32@0x14, vcall */
struct ts4_obj_884739D8 { void ts4_if_get_u32_off10_884739D8(); };
void ts4_obj_884739D8::ts4_if_get_u32_off10_884739D8()
{
    ts4_word a0 = (ts4_word)this;
    unsigned char b70;
    ts4_word p5;
    ts4_word t1;
    unsigned char t2;
    int t3;
    ts4_word t8;
    ts4_word t18;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    if ((ts4_word)t1 != 0) {
        t2 = *(unsigned char *)((char *)(ts4_word)(a0) + 216);
        t3 = *(ts4_word *)((char *)(ts4_word)(t1) + 12);
        b70 = !((ts4_word)t2 != 7) || ((ts4_word)t2 == 6);
        p5 = (ts4_word)b70;
        if ((int)((signed char)p5) == 0) {
            if ((int)t3 == 11 || (int)t3 == 9) {
                t8 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 20))))((ts4_word)t1);
                ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t8) + 0))) + 4))))((ts4_word)t8);
            }
        }
        if ((int)t3 == 8) {
            t18 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
            ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t18) + 16))) + 4))))((ts4_word)(t18 + 16));
            return;
        }
        if ((int)t3 == 10) {
            ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 16))) + 4))))((ts4_word)(t1 + 16));
        }
        return;
    }
    return;
}

/* Swing_DLL.xex 0x8849AA90: if_get u32@0x28, u32@0x20, u32@0x20, u8@0x12, u8@0x12 */
struct ts4_obj_8849AA90 { void ts4_if_get_u32_off28_8849AA90(ts4_word a1, ts4_word a2); };
void ts4_obj_8849AA90::ts4_if_get_u32_off28_8849AA90(ts4_word a1, ts4_word a2)
{
    ts4_word a0 = (ts4_word)this;
    if ((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 40)) != 0) {
        *(unsigned char *)((char *)(ts4_word)(((*(ts4_word *)((char *)(ts4_word)(a1) + 40)) & 0xffffffff)) + 18) = (unsigned char)((*(unsigned char *)((char *)(ts4_word)(((*(ts4_word *)((char *)(ts4_word)(a1) + 40)) & 0xffffffff)) + 18)) | a2);
        return;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 32)) | a2);
    return;
}

/* Swing_DLL.xex 0x88516D70: get  */
struct ts4_obj_88516D70 { void ts4_get_88516D70(ts4_word a1); };
void ts4_obj_88516D70::ts4_get_88516D70(ts4_word a1)
{
    ts4_word a0 = (ts4_word)this;
    float t1;
    float t2;
    float t3;
    float t4;
    float t5;
    float t6;
    float t7;

    t1 = *(float *)((char *)(ts4_word)(a1) + 0);
    t2 = *(float *)((char *)(ts4_word)(a0) + 0);
    t3 = *(float *)((char *)(ts4_word)(a0) + 4);
    *(float *)((char *)(ts4_word)(a0) + 0) = (t1 + t2);
    t4 = *(float *)((char *)(ts4_word)(a1) + 4);
    t5 = *(float *)((char *)(ts4_word)(a0) + 8);
    *(float *)((char *)(ts4_word)(a0) + 4) = (t4 + t3);
    t6 = *(float *)((char *)(ts4_word)(a1) + 8);
    t7 = *(float *)((char *)(ts4_word)(a0) + 12);
    *(float *)((char *)(ts4_word)(a0) + 8) = (t6 + t5);
    *(float *)((char *)(ts4_word)(a0) + 12) = ((*(float *)((char *)(ts4_word)(a1) + 12)) + t7);
    return;
}

/* Swing_DLL.xex 0x88606DE0: set u8@0x60 */
struct ts4_obj_88606DE0 { void ts4_set_u8_off60_88606DE0(ts4_word a1, ts4_word a2); };
void ts4_obj_88606DE0::ts4_set_u8_off60_88606DE0(ts4_word a1, ts4_word a2)
{
    ts4_word a0 = (ts4_word)this;
    *(unsigned char *)((char *)(ts4_word)((a1 + a0)) + 96) = (unsigned char)a2;
    return;
}

/* Swing_DLL.xex 0x88778728: set u8@0x26 */
struct ts4_obj_88778728 { void ts4_set_u8_off26_88778728(ts4_word a1); };
void ts4_obj_88778728::ts4_set_u8_off26_88778728(ts4_word a1)
{
    ts4_word a0 = (ts4_word)this;
    *(unsigned char *)((char *)(ts4_word)((a1 + a0)) + 38) = (unsigned char)1;
    return;
}

/* Swing_DLL.xex 0x887F73D8: get u32@0x14 */
struct ts4_obj_887F73D8 { void ts4_get_u32_off14_887F73D8(ts4_word a1); };
void ts4_obj_887F73D8::ts4_get_u32_off14_887F73D8(ts4_word a1)
{
    ts4_word a0 = (ts4_word)this;
    *(ts4_word *)((char *)(ts4_word)((a1 << 2)) + (*(ts4_word *)((char *)(ts4_word)(a0) + 20))) = (ts4_word)1;
    return;
}
