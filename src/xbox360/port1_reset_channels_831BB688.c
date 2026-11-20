/* Swing_DLL.xex functions whose code is identical (after masking relocations) to
   matched Loader_DLL.xex functions; source form ported from src/loader/l15_reset_channels_831BB688.c.
   Reconstructed from disassembly; no upstream source, no Microsoft source. */
typedef struct { char pad[0x22]; unsigned short n; } Ts4lStreamInfo;

/* Per-channel reset: walk every channel record of a stream (0x6f0 bytes each,
 * two or four 0x38-byte slots per channel) and reset each slot, then finish the stream. */
extern void ts4_noop_881B3360(void *);
extern void ts4_forward_with_const_248C8000_885BE200(void *);

/* Swing_DLL.xex 0x885BE518 */
void ts4_reset_channels_885BE518(Ts4lStreamInfo *c, char *o)
{
    short i;
    unsigned short j;
    char *b;

    if (o != 0 && c != 0) {
        if (c->n != 0) {
            i = 0;
            do {
                b = o + i * 0x6f0;
                j = 0;
                do {
                    ts4_noop_881B3360(b + j * 0x38 + 0xc8);
                    j++;
                } while (j < 2);
                i++;
            } while (i < c->n);
        }
        ts4_forward_with_const_248C8000_885BE200(o);
    }
}

