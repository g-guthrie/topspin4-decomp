/* Q5S swan: shot record copy (Swing_DLL.xex). */

typedef unsigned int u32;

/* 0x90-byte shot record: a 0x84-byte base copied by 0x886C4AF0, then a word
 * and two floats. */
typedef struct Q5sShotRec {
    char base[0x84];    /* +0x00: copied by ts4_record_copy_886C4AF0 */
    u32 w84;            /* +0x84 */
    float f88;          /* +0x88 */
    float f8c;          /* +0x8c */
} Q5sShotRec;

extern void ts4_record_copy_886C4AF0(Q5sShotRec *d, const Q5sShotRec *s);

/* Swing_DLL.xex 0x886C6660: copy a shot record (base, then the tail fields).
 * The callee leaves r3/r4 intact under LTCG, so the tail reuses them. */
void ts4_shot_rec_copy_886C6660(Q5sShotRec *d, const Q5sShotRec *s)
{
    ts4_record_copy_886C4AF0(d, s);
    d->w84 = s->w84;
    d->f88 = s->f88;
    d->f8c = s->f8c;
}
