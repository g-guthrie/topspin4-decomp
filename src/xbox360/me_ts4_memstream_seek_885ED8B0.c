/* 0x885ED8B0: Seeks a memory stream {pos +8, size +0xc}: whence 0 sets pos, 1 adds, 2 sets size - offset; size becomes max(pos, size); returns 0. */
/* Matched on /Oc (agAH). switch on whence; max written as a ternary assignment (stores size in both arms). */
typedef struct MemStream { int unk0, unk4; int pos; int size; } MemStream;
int fn_885ED8B0(MemStream *s, int offset, unsigned int whence)
{
    switch (whence) {
    case 0: s->pos = offset; break;
    case 1: s->pos += offset; break;
    case 2: s->pos = s->size - offset; break;
    }
    s->size = s->pos > s->size ? s->pos : s->size;
    return 0;
}
