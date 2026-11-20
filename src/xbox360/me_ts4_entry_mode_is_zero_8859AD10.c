/* 0x8859AD10: tests whether the 2-bit mode field (bits 20-21) of entry i (0x60-byte entries at +8) is 0, read from the entry itself when flag 0x20000 is set at +4, else through its pointer at +0x40. */
/* Matched on /O1 (agAB). The field is a 2-bit bitfield after 10 bits (extrwi 2,10), read in each arm; 0 == m gives the addi 0 before cntlzw. */
typedef struct W { unsigned int hi : 10; unsigned int mode : 2; unsigned int lo : 20; } W;
typedef struct Ent { W w0; char p4[0x40 - 4]; W *p40; char p44[0x60 - 0x44]; } Ent;
typedef struct S { int p0; unsigned int flags; Ent *arr; } S;
unsigned char fn_8859AD10(S *s, int i)
{
    unsigned int m;
    if (s->flags & 0x20000)
        m = s->arr[i].w0.mode;
    else
        m = s->arr[i].p40->mode;
    return 0 == m;
}
