/* CX39 LTCG context only: ts4_index_to_name_hash_887F7BC8 returning its out pointer (r3 survives for the caller). */
typedef unsigned int u32;
typedef unsigned char u8;
typedef struct Globals { u8 reserved[0x27C]; u32 default_hash; } Globals;
extern Globals *lbl_88D45B1C;

/* Maps a small index to a 32-bit name hash, storing the result through out;
   unknown indices store the default hash. Swing_DLL.xex 0x887F7BC8. */
u32 *ts4_index_to_name_hash_887F7BC8(u32 *out, u8 index)
{
    switch (index) {
    case 0: *out = 0xB2FD713Eu; return out;
    case 1: *out = 0x686DDB10u; return out;
    case 2: *out = 0x83848D0Au; return out;
    case 3: *out = 0x962BD533u; return out;
    case 4: *out = 0x6D44B7DBu; return out;
    case 5: *out = 0x6A99BB54u; return out;
    case 6: *out = 0xEF0273B7u; return out;
    case 7: *out = 0x4902E8CAu; return out;
    case 8: *out = 0xCA3E2850u; return out;
    case 9: *out = 0xF68009FBu; return out;
    case 10: *out = 0x5A3B585Eu; return out;
    case 11: *out = 0x5611B5B5u; return out;
    case 12: *out = 0x69638443u; return out;
    case 13: *out = 0x9F448218u; return out;
    case 14: *out = 0x41CF1210u; return out;
    case 15: *out = 0xC0EB0F74u; return out;
    case 16: *out = 0xF4C5BD9Du; return out;
    case 17: *out = 0xEE581D0Eu; return out;
    case 18: *out = 0xD01BE30Fu; return out;
    case 19: *out = 0xFF49FD70u; return out;
    case 20: *out = 0x776299C3u; return out;
    case 21: *out = 0x3C1C6CB0u; return out;
    case 22: *out = 0x19C4AA83u; return out;
    case 23: *out = 0xAD4F7020u; return out;
    case 24: *out = 0x843EE2A8u; return out;
    case 25: *out = 0x079E4085u; return out;
    case 26: *out = 0x372DE1B5u; return out;
    case 27: *out = 0xF01117BFu; return out;
    case 28: *out = 0x5CC6E901u; return out;
    case 29: *out = 0xAC43EA94u; return out;
    case 30: *out = 0xC4719ADEu; return out;
    case 31: *out = 0xE1FEEF64u; return out;
    case 32: *out = 0x8C4054FAu; return out;
    case 33: *out = 0x35AE9337u; return out;
    case 34: *out = 0xC88D4316u; return out;
    case 35: *out = 0x810B530Au; return out;
    case 36: *out = 0xFF795B6Bu; return out;
    case 37: *out = 0x31363E2Au; return out;
    case 38: *out = 0xD75691CBu; return out;
    case 39: *out = 0x7763D605u; return out;
    case 40: *out = 0xA8AB6AF1u; return out;
    case 41: *out = 0x933E4E52u; return out;
    case 42: *out = 0x7E72B5A9u; return out;
    case 43: *out = 0x843FAD6Eu; return out;
    case 44: *out = 0x38DA1840u; return out;
    case 45: *out = 0x6577AE58u; return out;
    case 46: *out = 0xF09A0436u; return out;
    case 47: *out = 0xF20C12D0u; return out;
    case 48: *out = 0x1EC93F7Bu; return out;
    case 49: *out = 0x574302A1u; return out;
    case 50: *out = 0xB123AD40u; return out;
    case 51: *out = 0x7002928Eu; return out;
    case 52: *out = 0xE5AC034Bu; return out;
    case 53: *out = 0xC2141BF8u; return out;
    case 54: *out = 0x43E99C5Fu; return out;
    case 55: *out = 0xC4A4CD46u; return out;
    case 56: *out = 0xDF4EA92Du; return out;
    case 57: *out = 0x5B56094Bu; return out;
    case 58: *out = 0x8DA3BFCCu; return out;
    case 59: *out = 0xB3702A7Du; return out;
    case 60: *out = 0x93EADE2Cu; return out;
    case 61: *out = 0x63537641u; return out;
    case 62: *out = 0x82681FF6u; return out;
    case 63: *out = 0x478236C4u; return out;
    case 64: *out = 0x134E0D97u; return out;
    case 65: *out = 0xF59526D0u; return out;
    case 66: *out = 0xFF3A7B97u; return out;
    case 67: *out = 0x1ED23847u; return out;
    case 68: *out = 0x51621014u; return out;
    case 69: *out = 0xF40584B2u; return out;
    case 70: *out = 0x206C90B5u; return out;
    default: *out = lbl_88D45B1C->default_hash; return out;
    }
}
