/* CW40 LTCG context: hash selector leaf (writes one of seven hashes through r3, returns r3, uses only r10/r11). */
typedef unsigned int u32;
typedef unsigned char u8;
#ifdef _MSC_VER
__declspec(noinline)
#endif
u32 *ts4_set_u32_off0_887F7B18(u32 *p, u8 k)
{
    switch (k) {
    case 0: *p = 0xCD0B222Fu; break;
    case 1: *p = 0x95B29297u; break;
    case 2: *p = 0x4538B1F4u; break;
    case 3: *p = 0xC05FA6A6u; break;
    case 4: *p = 0xE5791C94u; break;
    case 5: *p = 0x11223344u; break;
    case 6: *p = 0x55667788u; break;
    default: *p = 0; break;
    }
    return p;
}
