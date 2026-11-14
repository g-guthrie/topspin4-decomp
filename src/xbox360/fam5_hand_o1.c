/* FAM5 hand-written matches built with /O1 (Swing_DLL.xex, Xbox 360,
   MSVC 16.00.10224.00), each verified byte-for-byte with tools/fn_check.py.
   The original address is in the comment above each definition; fields are
   accessed by byte offset. */
typedef unsigned long ts4_word;

extern char lbl_8803964C[];
extern char lbl_88B3302C[];
extern char lbl_88D3CAF4[];
ts4_word fn_88315F10();
int fn_883FB528();
int ts4_if_call_seq_fn_883FB3E8_883FB4B8();

/* Swing_DLL.xex 0x883E40F8: free the buffer at +0x10 (fn_88315F10: heap,
   block, source-file string, line 454), then, if there is a handle at +0x8,
   try fn_883FB528 and ts4_if_call_seq_fn_883FB3E8_883FB4B8 on it in turn and
   return the first non-zero result.  When both return 0 the handle is
   cleared.  Returns 0 when there is no handle. */
int ts4_release_buffer_and_handle_883E40F8(ts4_word a0)
{
    ts4_word t1;
    int r;

    t1 = *(ts4_word *)(a0 + 16);
    if (t1 != 0) {
        fn_88315F10(*(ts4_word *)(*(ts4_word *)lbl_88B3302C + 4), t1, (ts4_word)lbl_8803964C, 454);
        *(ts4_word *)(a0 + 16) = 0;
    }
    if (*(ts4_word *)(a0 + 8) == 0)
        return 0;
    r = fn_883FB528(*(ts4_word *)(a0 + 8));
    if (r != 0)
        return r;
    r = ts4_if_call_seq_fn_883FB3E8_883FB4B8(*(ts4_word *)(a0 + 8));
    if (r != 0)
        return r;
    *(ts4_word *)(a0 + 8) = 0;
    return 0;
}

/* Swing_DLL.xex 0x885E7300: if bit 7 of the word at a1+0xe4 is set, map the
   index at a1+0x38 through the table that lbl_88D3CAF4 points to; otherwise
   return the index unchanged.  The bit test is a byte-sized (bool) value. */
ts4_word ts4_map_index_885E7300(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t2;

    (void)a0;
    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 228);
    t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 56);
    if ((unsigned char)((t1 >> 7) & 0x1) != 0) {
        return (*(ts4_word *)((char *)(ts4_word)((t2 << 2)) + (*(ts4_word *)lbl_88D3CAF4)));
    }
    return t2;
}
