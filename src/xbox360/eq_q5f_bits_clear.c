/* Top Spin 4 (Xbox 360, Swing_DLL.xex) 0x888C15A0 - EQUIVALENT tier, not byte-matched.
 * fn_check: not matched (the target stages the iterator pair through the stack).
 * fn_equiv/4 evidence: work/q5/evidence/eq_q5f_bits_clear.equiv.json (flags /Oc) */
typedef unsigned int u32;

/* ---- 0x888C15A0: clear bit `idx` of the bit vector at +0x8 when it is in range.
 * Not byte-matched: the iterator pair is staged through the stack in the target. */
typedef struct Q5BitIt { u32 *word; u32 bit; } Q5BitIt;
typedef struct Q5BitVec { Q5BitIt first; Q5BitIt last; } Q5BitVec;
typedef struct Q5BitRef { u32 *word; u32 mask; } Q5BitRef;
typedef struct Q5BitOwner { char pad[8]; Q5BitVec bits; } Q5BitOwner;
extern Q5BitRef *fn_8817E150(Q5BitRef *out, Q5BitVec *v, u32 idx);
static __inline u32 q5_bits_size(const Q5BitVec *v)
{
    return (u32)((v->last.word - v->first.word) * 32) - v->first.bit + v->last.bit;
}

/* Swing_DLL.xex 0x888C15A0 */
void ts4_bits_clear_888C15A0(Q5BitOwner *self, u32 idx)
{
    if (idx < q5_bits_size(&self->bits)) {
        Q5BitRef t;
        Q5BitRef *r = fn_8817E150(&t, &self->bits, idx);
        *r->word &= ~r->mask;
    }
}

