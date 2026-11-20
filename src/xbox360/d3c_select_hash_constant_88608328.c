/* Swing_DLL.xex 0x88608328-0x886083B0, executable version 0.0.0.3. */
typedef unsigned int u32;

/* Store the type-hash constant selected by a small index (0..5; anything else selects the index 0 value). */
void ts4_select_hash_constant_88608328(u32 *out, u32 idx)
{
    switch (idx) {
    case 0: *out = 0x99f5620b; break;
    case 2: *out = 0x14588b45; break;
    case 3: *out = 0x93cae023; break;
    case 4: *out = 0xbc7c2723; break;
    case 5: *out = 0xc9a1c481; break;
    case 1: *out = 0x3f34a24d; break;
    default: *out = 0x99f5620b; break;
    }
}
