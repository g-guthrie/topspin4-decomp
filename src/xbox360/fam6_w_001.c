/* Small functions produced by the asm2c translator (FAM4/FAM5 fork) and verified
   byte-for-byte with tools/fn_check.py (Swing_DLL.xex, Xbox 360, MSVC 16.00.10224.00).
   FAM6: FAM5 near misses fixed by a per-function hill climb over source-level
   variants. Besides FAM5's mutations (operand order, retyped locals, volatile
   reloads, statement swaps, if/else inversion, members for `this`), it uses:
   a ||/&& condition kept in an unsigned char/int temporary; compound
   assignment; resized/reordered stack arrays; a load hoisted out of both
   branches or above a store; strlen() instead of an inline byte scan (the
   intrinsic returns through `clrrwi`); a one-word struct argument read from
   memory (also `clrrwi`). Callers and callees sit in different files.
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
typedef struct ts4_args3 { ts4_word w[3]; } ts4_args3;

extern char lbl_880C1320[];
ts4_word fn_881506A0();
ts4_word fn_88169D00();
ts4_word ts4_if_get_fn_88150770_886F7C08();
ts4_word ts4_assign_formatted_text();
ts4_word ts4_destroy_owned_object();
ts4_word ts4_handle_forward0_88610948();
ts4_word ts4_handle_forward0_88610AC8();
ts4_word ts4_if_call_seq_u32_off8_88160D30();

/* Swing_DLL.xex 0x8895A1E8: loop_call_seq ts4_handle_forward0_88610AC8, lbl_880C1320, fn_881506A0, u32@0x0, ts4_if_get_fn_88150770_886F7C08, u32@0x4 */
void ts4_loop_call_seq_fn_88610AC8_8895A1E8(ts4_args3 sp0, ts4_word a2)
{
    unsigned char b80;
    unsigned char b81;
    ts4_word p4;
    ts4_word lv8;
    ts4_word lv9;
    ts4_word p12;
    ts4_word p30;
    ts4_word p31;
    ts4_word loc58[3];
    ts4_word loc54[1];
    ts4_word loc50[1];
    ts4_word loc68[3];
    ts4_word loc78[3];
    ts4_word t1;
    ts4_word t6;
    ts4_word t7;
    ts4_word t13;
    ts4_word t14;
    ts4_word t16;
    ts4_word t17;
    ts4_word t19;
    ts4_word t22;
    ts4_word t26;
    ts4_word t27;
    ts4_word t28;
    ts4_word t29;

    t1 = sp0.w[0];
    b80 = !((ts4_word)t1 != 0) || ((ts4_word)(sp0.w[1]) == (ts4_word)((983040) | 65535));
    p4 = (ts4_word)b80;
    if ((ts4_word)(p4 & 0xff) == 0) {
        ts4_handle_forward0_88610AC8((ts4_word)(ts4_word)&loc58[0], (ts4_word)(ts4_word)&sp0);
        t6 = loc58[1];
        t7 = loc58[0];
        lv8 = (ts4_word)t6;
        lv9 = (ts4_word)t7;
        do {
            b81 = !((ts4_word)lv9 != 0) || ((ts4_word)lv8 == (ts4_word)((983040) | 65535));
            p12 = (ts4_word)b81;
            if ((ts4_word)(p12 & 0xff) != 0) {
                return;
            }
            t13 = fn_881506A0((ts4_word)(ts4_word)&loc54[0], (ts4_word)(ts4_word)&loc58[0]);
            t14 = *(ts4_word *)((char *)(ts4_word)(t13) + 0);
            if ((ts4_word)t14 == (ts4_word)((147062784) | 9629)) {
                (void)loc58[2];
                t16 = ts4_if_get_fn_88150770_886F7C08(*(ts4_args3 *)&loc58[0], (ts4_word)((4262526976) | 53560), (ts4_word)(ts4_word)lbl_880C1320);
                loc50[0] = (ts4_word)t16;
                t17 = *(ts4_word *)((char *)(ts4_word)(a2) + 4);
                t19 = fn_88169D00((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a2) + 0)), (ts4_word)t17, (ts4_word)(ts4_word)&loc50[0]);
                if ((ts4_word)t17 == (ts4_word)t19) {
                    ts4_assign_formatted_text((ts4_word)(ts4_word)&loc68[0], (ts4_word)t16);
                    ts4_if_call_seq_u32_off8_88160D30((ts4_word)a2, (ts4_word)(ts4_word)&loc68[0]);
                    t22 = loc68[0];
                    ts4_destroy_owned_object((ts4_word)t22);
                }
            }
            t26 = ts4_handle_forward0_88610948((ts4_word)(ts4_word)&loc78[0], (ts4_word)(ts4_word)&loc58[0]);
            t27 = *(ts4_word *)((char *)(ts4_word)(t26) + 0);
            t28 = *(ts4_word *)((char *)(ts4_word)(t26) + 4);
            t29 = *(ts4_word *)((char *)(ts4_word)(t26) + 8);
            loc58[0] = (ts4_word)t27;
            loc58[1] = (ts4_word)t28;
            loc58[2] = (ts4_word)t29;
            p30 = (ts4_word)t28;
            p31 = (ts4_word)t27;
            lv8 = p30;
            lv9 = p31;
        } while (1);
    }
    return;
}
