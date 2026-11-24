/* Q5h1 clone: forward both halves of a self-relative record pair to fn_886DBF40 (gameplay, 0x886C4C60).
 * Clone of ts4_pair_forward_both_halves_886C4CB8 (q5_gameplay_pair_visit.cpp). The only difference in the
 * asm is the second sub-record offset: addi r31,r4,0xC here (template: 0x8). So the first base is 0xC bytes
 * and the record class derives from the 0xC-byte pair. The base-class conversion and __assume(record != 0)
 * are kept: a plain &t->second does not match. */
#ifndef _MSC_VER
#define __assume(cond) ((void)0)
#endif

struct Q5h1PairHeader { int offset; };    /* self-relative: record = (char *)hdr + hdr->offset */
struct Q5h1PairFirstC { char bytes[0xC]; };
struct Q5h1PairSecondC { char bytes[0xC]; };
struct Q5h1PairRecordC : Q5h1PairFirstC, Q5h1PairSecondC {};

extern "C" void fn_886DBF40(void *slot, void *record, void *defs, unsigned int style, int marker, unsigned int value);

/* Swing_DLL.xex 0x886C4C60: resolve the self-relative record, then forward its first and second (+0xC) halves */
extern "C" void ts4_pair_forward_both_halves_886C4C60(void *slot, Q5h1PairHeader *hdr, void *defs, unsigned int style,
                                                      int marker, unsigned int value)
{
    Q5h1PairRecordC *record = (Q5h1PairRecordC *)((char *)hdr + hdr->offset);
    __assume(record != 0);
    Q5h1PairSecondC *second = record;
    fn_886DBF40(slot, record, defs, style, marker, value);
    fn_886DBF40(slot, second, defs, style, marker, value);
}
