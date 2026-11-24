/* Swing_DLL.xex 0x885A9A08: last frame of block `index`: start = index * frames per block
 * (fn_885BDF00(channels, rate)), result = start + frames - 1.
 * Matched /Oc. The named `start` product is what gives `mullw (index+1), frames`: written as one
 * expression, (index + 1) * frames - 1 or index * frames + frames - 1, the factored multiply takes
 * the operands the other way round (see regalloc.md C1). */
typedef struct Ts4AudioTrack {
    int unk0;
    unsigned short rate;     /* +0x4 */
    unsigned short channels; /* +0x6 */
} Ts4AudioTrack;

unsigned short fn_885BDF00(unsigned short a, unsigned short b);

unsigned int ts4_audio_block_last_frame_885A9A08(Ts4AudioTrack *t, unsigned int index)
{
    unsigned int frames = fn_885BDF00(t->channels, t->rate);
    unsigned int start = index * frames;
    return start + frames - 1;
}
