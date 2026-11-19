/* Swing_DLL.xex 0x88166650: uninitialized_copy over 0x84-byte records of nine text strings (ts4_assign_formatted_text from each source text), a 12-byte member (fn_88166BC0), a flag byte and two words.
 * /Oc. Plain member-wise copy-constructor inline; the compiler picks the +0x18 induction base itself. */
typedef struct Text { char *p; char *last; char *end; } Text;
typedef struct Sub12 { unsigned int w[3]; } Sub12;
typedef struct Profile {
    Text t00; Text t0c; Text t18;
    Sub12 tags;
    unsigned char flag;
    Text t34; Text t40; Text t4c; Text t58;
    unsigned int a; unsigned int b;
    Text t6c; Text t78;
} Profile;
void ts4_assign_formatted_text(void *dst, void *src);
void fn_88166BC0(Sub12 *dst, const Sub12 *src);

static __inline void text_copy(Text *d, const Text *s) { ts4_assign_formatted_text(d, s->p); }

static __inline void profile_copy(Profile *d, const Profile *s)
{
    text_copy(&d->t00, &s->t00);
    text_copy(&d->t0c, &s->t0c);
    text_copy(&d->t18, &s->t18);
    fn_88166BC0(&d->tags, &s->tags);
    d->flag = s->flag;
    text_copy(&d->t34, &s->t34);
    text_copy(&d->t40, &s->t40);
    text_copy(&d->t4c, &s->t4c);
    text_copy(&d->t58, &s->t58);
    d->a = s->a;
    d->b = s->b;
    text_copy(&d->t6c, &s->t6c);
    text_copy(&d->t78, &s->t78);
}

Profile *fn_88166650(const Profile *first, const Profile *last, Profile *dest)
{
    for (; first != last; ++dest, ++first)
        if (dest) profile_copy(dest, first);
    return dest;
}
