/* 0x88554468: appends a 0x70-byte record: flag, optional value, tag byte, 0x68-byte template copy, then advances the cursor */
/* Matched on /Oc (agAH). Cursor advanced with w->cur++ re-read from memory. */
typedef unsigned int size_t;
void *memcpy(void *d, const void *s, size_t n);
typedef struct Rec { char body[0x68]; int value; unsigned char tag; signed char has; char pad[2]; } Rec;
typedef struct W { char pad[0x40]; Rec *cur; char tmpl[0x68]; int tag; } W;
void fn_88554468(W *w, signed char has, int value)
{
    Rec *r = w->cur;
    r->has = has;
    if (has)
        r->value = value;
    r->tag = (unsigned char)w->tag;
    memcpy(r, w->tmpl, 0x68);
    w->cur++;
}
