/* FAM5 hand-written matches (Swing_DLL.xex, Xbox 360, MSVC 16.00.10224.00),
   each verified byte-for-byte with tools/fn_check.py.  The original address is
   in the comment above each definition; fields are accessed by byte offset. */
typedef unsigned long ts4_word;

/* Swing_DLL.xex 0x88885130: seek-like position update of the object at a0
   (position word at +0x24c).  mode 0: relative, 1: take the value of virtual
   slot 5, 2: absolute.  Written as an if-chain the add operands come out
   swapped; the original is a switch. */
ts4_word ts4_stream_seek_88885130(ts4_word a0, ts4_word a1, int mode)
{
    switch (mode) {
    case 0:
        *(ts4_word *)(a0 + 588) += a1;
        break;
    case 1:
        *(ts4_word *)(a0 + 588) = ((ts4_word (*)(ts4_word))(*(ts4_word *)(*(ts4_word *)a0 + 20)))(a0);
        break;
    case 2:
        *(ts4_word *)(a0 + 588) = a1;
        break;
    }
    return *(ts4_word *)(a0 + 588);
}

extern char lbl_88028C78[];
extern char lbl_88B3302C[];
ts4_word fn_88315F10();
int fn_8830F378();
ts4_word ts4_call_seq_fn_8832E690_8832E878();

/* Swing_DLL.xex 0x883142A8: shut down and free the object at a0.  If the
   byte at +0x15 is set, fn_8830F378(a0, 0) runs first and a non-zero result
   is returned unchanged.  Then the object at +0x498 is released through
   virtual slot 0, the member at +0x5ffc is cleaned up, the list node at
   +0x8 is unlinked and reset to point at itself, and a0 goes back to the
   heap (fn_88315F10 takes the heap, the block, a source-file string and the
   line number 4455).  Returns 0. */
int ts4_close_and_free_883142A8(ts4_word a0)
{
    ts4_word p;
    int r;

    if (*(unsigned char *)(a0 + 21) != 0) {
        r = fn_8830F378(a0, 0);
        if (r != 0)
            return r;
    }
    p = *(ts4_word *)(a0 + 1176);
    if (p != 0) {
        ((void (*)(ts4_word))(*(ts4_word *)(*(ts4_word *)p)))(p);
        *(ts4_word *)(a0 + 1176) = 0;
    }
    ts4_call_seq_fn_8832E690_8832E878(a0 + 24572);
    *(ts4_word *)(*(ts4_word *)(a0 + 12) + 0) = *(ts4_word *)(a0 + 8);
    *(ts4_word *)(*(ts4_word *)(a0 + 8) + 4) = *(ts4_word *)(a0 + 12);
    *(ts4_word *)(a0 + 12) = a0 + 8;
    *(ts4_word *)(a0 + 8) = a0 + 8;
    *(ts4_word *)(a0 + 16) = 0;
    fn_88315F10(*(ts4_word *)(*(ts4_word *)lbl_88B3302C + 4), a0, (ts4_word)lbl_88028C78, 4455);
    return 0;
}
