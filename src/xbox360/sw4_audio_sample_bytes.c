/* Family SW4: audio sample/byte conversion helpers (FMOD-style sound formats).
 *
 * The format codes match the FMOD Ex FMOD_SOUND_FORMAT order: 0 none, 1 PCM8,
 * 2 PCM16, 3 PCM24, 4 PCM32, 5 PCM float, 6 GC ADPCM (14 samples per 8 bytes),
 * 7 IMA ADPCM (64 samples per 36 bytes), 8 VAG (28 samples per 16 bytes),
 * 9..11 compressed formats (XMA, MPEG, CELT) that report bytes unchanged.
 *
 * Winning shape: two force-inlined helpers. The bit-width helper has its own
 * 12-slot switch; the conversion helper tests `bits` and, when it is zero,
 * switches on the format again with case 0 written AFTER cases 6..11. MSVC
 * then threads the first table straight into the second (slots 0 and 6..11),
 * removes the `if (bits)` test, and keeps the channel divide as one shared
 * tail. Writing `case 0` first makes the compiler tail-duplicate that divide.
 */

#ifdef _MSC_VER
#define SW4_INLINE __forceinline
#else
#define SW4_INLINE inline
#endif

typedef unsigned long long sw4_u64;

/* Bits per sample of a PCM format code; 0 for non-PCM codes 0 and 6..11. */
static SW4_INLINE int sw4_bits_from_format(unsigned int format, int *bits)
{
    switch (format) {
    case 1: *bits = 8; break;
    case 2: *bits = 16; break;
    case 3: *bits = 24; break;
    case 4:
    case 5: *bits = 32; break;
    case 0:
    case 6: case 7: case 8: case 9: case 10: case 11:
        *bits = 0; break;
    default:
        return 19; /* unsupported format */
    }
    return 0;
}

/* Byte count -> per-channel sample count for a format code. */
static SW4_INLINE int sw4_samples_from_bytes(unsigned int bytes, unsigned int *samples,
                                             int channels, unsigned int format)
{
    int bits;
    int result;

    if (!channels)
        return 31; /* invalid parameter */
    result = sw4_bits_from_format(format, &bits);
    if (result != 0)
        return result;
    if (bits) {
        *samples = (unsigned int)(((sw4_u64)bytes * 8) / bits);
    } else {
        switch (format) {
        case 6: *samples = bytes * 14 / 8; break;
        case 7: *samples = bytes * 64 / 36; break;
        case 8: *samples = bytes * 28 / 16; break;
        case 9: case 10: case 11:
            *samples = bytes;
            return 0;
        case 0: *samples = 0; break;
        default:
            return 19;
        }
    }
    *samples /= channels;
    return 0;
}

struct sw4_sound_desc {
    char pad0[0x48];
    int channels; /* +0x48 */
};

struct sw4_subsound {
    char pad0[0xc];
    int index;                   /* +0x0C entry index into the owner's length table */
    char pad1[0x30 - 0x10];
    unsigned int format;         /* +0x30 format code (see top of file) */
    char pad2[0x3c - 0x34];
    struct sw4_sound_desc *desc; /* +0x3C */
};

/* Swing_DLL.xex 0x88382580: converts the stored byte length of entry
 * `sound->index` (owner word table at +0x2EC) into a per-channel sample count
 * written to *out. The conversion status is ignored; always returns 0.
 * Reached through a this-adjusting thunk (ts4_forward_adjusted_or_null_m1c_88382738). */
int ts4_audio_entry_length_samples_88382580(unsigned int *owner, struct sw4_subsound *sound,
                                            unsigned int *out)
{
    sw4_samples_from_bytes(owner[sound->index + 0xbb], out, sound->desc->channels, sound->format);
    return 0;
}
