/* CX44 LTCG part a: callers of leaf helpers (callee keeps r9/r10 untouched), Pam Display renderer. */
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned short u16;
extern u8 ts4_hex_digit_value_886EBCE8(u16 c);

/* 0x886ED168: combine two nibble codes from two halfwords */
u8 ts4_combine_nibbles_886ED168(u16 *p)
{
    u8 lo = ts4_hex_digit_value_886EBCE8(p[1]);
    u8 hi = ts4_hex_digit_value_886EBCE8(p[0]);
    return lo | (hi << 4);
}
