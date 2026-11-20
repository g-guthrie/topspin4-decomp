/* 0x88574C30: CRT _unlock_fh: leaves the lock at +0xc of the 0x48-byte ioinfo entry for fh */
/* Matched on /Os plain and LTCG (work/army/ME/v.py chk). */
typedef struct { int a, b, c; int cs[15]; } IoInfo;
extern IoInfo *lbl_88D4E000[];
void RtlLeaveCriticalSection(void *cs);
void ts4_unlock_fh_88574C30(int fh)
{
    RtlLeaveCriticalSection(&lbl_88D4E000[fh >> 5][fh & 0x1f].cs);
}
