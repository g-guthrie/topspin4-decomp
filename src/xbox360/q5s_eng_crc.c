/* Engine core (eng): CRC32 helpers. LTCG route, /Oc, context src/xbox360/pp1_pool_primer.c. */
typedef unsigned int u32;
typedef unsigned char u8;

extern u32 lbl_880C84C0[];                         /* zlib CRC32 table (also used by ts4_crc32_88606410) */

/* Swing_DLL.xex 0x88608590: CRC32 of a C string continuing from `crc` (callers pass 0 for a fresh hash);
 * a null string returns ~crc. Copying the pointer into a local at the top and testing the copy coalesces
 * the copy (no `mr`) but makes the allocator give the running CRC r11 and the byte r10, as in the target;
 * testing the parameter itself swaps the two. */
u32 ts4_crc32_cstr_seed_88608590(u32 crc, const u8 *s)
{
    const u8 *p = s;
    if (p != 0) {
        crc = ~crc;
        for (; *p; p++)
            crc = lbl_880C84C0[(crc ^ *p) & 0xff] ^ (crc >> 8);
    }
    return ~crc;
}
