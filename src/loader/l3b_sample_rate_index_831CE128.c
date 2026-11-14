/* Loader_DLL.xex 0x831CE128-0x831CE128, executable version 0.0.0.3.
 * Map a sample rate in Hz to its table index (0xFF when unsupported). */

int ts4l_sample_rate_index_831CE128(unsigned rate)
{
    switch (rate) {
    case 44100: return 0;
    case 48000: return 1;
    case 88200: return 2;
    case 96000: return 3;
    case 176400: return 6;
    case 192000: return 7;
    }
    return 0xff;
}
