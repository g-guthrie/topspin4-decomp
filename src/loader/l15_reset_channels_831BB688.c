/* Loader_DLL.xex 0x831BB688-0x8325273C, executable version 0.0.0.3. */
/* Per-channel reset: walk every channel record of a stream (0x6f0 bytes each,
 * two or four 0x38-byte slots per channel) and reset each slot, then finish the stream. */
extern void ts4_fn_831FA2C0(void *);
extern void ts4_tailcall_fn_8340D830_831BB278(void *);
extern void ts4l_call_seq_u32_off30_8326B428(void *);
extern void ts4_tailcall_fn_8340D830_832522A8(void *);
typedef struct { char pad[0x22]; unsigned short n; } Ts4lStreamInfo;

void ts4l_reset_channels_831BB688(Ts4lStreamInfo *c, char *o)
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
                    ts4_fn_831FA2C0(b + j * 0x38 + 0xc8);
                    j++;
                } while (j < 2);
                i++;
            } while (i < c->n);
        }
        ts4_tailcall_fn_8340D830_831BB278(o);
    }
}

void ts4l_reset_channels_832526B8(Ts4lStreamInfo *c, char *o)
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
                    ts4l_call_seq_u32_off30_8326B428(b + j * 0x38 + 0xc8);
                    j++;
                } while (j < 4);
                i++;
            } while (i < c->n);
        }
        ts4_tailcall_fn_8340D830_832522A8(o);
    }
}
