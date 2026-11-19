/* 0x88286428: uninitialized_fill_n of 0x201-byte name records (0x1FF-char bounded string copy plus a trailing flag byte), skipping null slots */
/* Matched on /Oc (agAL). Plain route; first try with an inline bounded copy indexed as s->text[p - d->text]. */
typedef unsigned char u8;
typedef struct Name201 { char text[0x200]; u8 flag; } Name201;

static void name_copy(Name201 *d, const Name201 *s)
{
    char *end = d->text + 0x1ff;
    char *p = d->text;
    while (p != end) {
        u8 c = s->text[p - d->text];
        if (c == 0) break;
        *p = c;
        p++;
    }
    *p = 0;
    d->flag = s->flag;
}

void ts4_name201_uninit_fill_n_88286428(Name201 *dest, unsigned int count, const Name201 *val)
{
    for (; count != 0; --count, ++dest)
        if (dest) name_copy(dest, val);
}
