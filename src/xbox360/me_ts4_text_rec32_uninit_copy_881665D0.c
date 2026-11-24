/* Swing_DLL.xex 0x881665D0: uninitialized_copy over 32-byte records {text string, five words}: the text is copy-constructed from its buffer (ts4_assign_formatted_text).
 * /Oc. Member-wise copy-constructor inline (same shape as 88166650). */
typedef struct Text { char *p; char *last; char *end; } Text;
typedef struct Rec32 { Text t00; unsigned int w0c; unsigned int w10; unsigned int w14; unsigned int w18; unsigned int w1c; } Rec;
void ts4_assign_formatted_text(void *dst, void *src);

static __inline void text_copy(Text *d, const Text *s) { ts4_assign_formatted_text(d, s->p); }

static __inline void rec_copy(Rec *d, const Rec *s)
{
    text_copy(&d->t00, &s->t00);
    d->w0c = s->w0c;
    d->w10 = s->w10;
    d->w14 = s->w14;
    d->w18 = s->w18;
    d->w1c = s->w1c;
}

Rec *fn_881665D0(const Rec *first, const Rec *last, Rec *dest)
{
    for (; first != last; ++dest, ++first)
        if (dest) rec_copy(dest, first);
    return dest;
}
