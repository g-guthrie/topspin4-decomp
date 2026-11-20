/* 0x885B42B0: Gets the block size for bytes at the format rate (fn_885CD120; 0 means 0). Unless exact is set and bytes/(channels*size) drops below the minimum (3 below rate 32000, else 5), it returns bytes/(size*min); otherwise it returns the channel byte. */
/* Matched on /Oc (agAH). Ternary minimum and a combined && test. */
typedef struct Format { unsigned int rate; char p4[3]; unsigned char channels; } Format;
extern unsigned int fn_885CD120(unsigned int bytes, unsigned int rate, void *a, void *b);
unsigned int fn_885B42B0(unsigned int bytes, int unused, const Format *f, int exact, void *a, void *b)
{
    unsigned int min_frames = f->rate < 32000 ? 3 : 5;
    unsigned int size = fn_885CD120(bytes, f->rate, a, b);
    if (size == 0)
        return 0;
    if (exact == 0 && bytes / (f->channels * size) < min_frames)
        return bytes / (size * min_frames);
    return f->channels;
}
