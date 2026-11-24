/* Q5: forward both halves of a self-relative record pair to fn_886DBF40 (gameplay, 0x886C4C60-0x886C4D10).
 * Plain route, no flags. The incoming header word is a byte offset from itself to a record made of two
 * sub-records; the second sub-record starts 8 (0x886C4CB8) or 0xC (0x886C4C60) bytes in.
 *
 * Codegen note: the target computes the second sub-record address before the first call and keeps it in a
 * saved register. A plain `&t->second` is rematerialised after the call instead. Writing the record as a
 * class with two bases and converting to the second base (a this-adjust), with __assume(t != 0) to drop the
 * null test of the conversion, gives the target's early `addi r31,r4,K`. */
#ifndef _MSC_VER
#define __assume(cond) ((void)0)
#endif

struct Q5PairHeader { int offset; };    /* self-relative: record = (char *)hdr + hdr->offset */
struct Q5PairFirst8 { char bytes[0x8]; };
struct Q5PairSecond8 { char bytes[0x8]; };
struct Q5PairRecord8 : Q5PairFirst8, Q5PairSecond8 {};

extern "C" void fn_886DBF40(void *slot, void *record, void *defs, unsigned int style, int marker, unsigned int value);

/* Swing_DLL.xex 0x886C4CB8: resolve the self-relative record, then forward its first and second (+8) halves */
extern "C" void ts4_pair_forward_both_halves_886C4CB8(void *slot, Q5PairHeader *hdr, void *defs, unsigned int style,
                                                      int marker, unsigned int value)
{
    Q5PairRecord8 *record = (Q5PairRecord8 *)((char *)hdr + hdr->offset);
    __assume(record != 0);
    Q5PairSecond8 *second = record;
    fn_886DBF40(slot, record, defs, style, marker, value);
    fn_886DBF40(slot, second, defs, style, marker, value);
}
