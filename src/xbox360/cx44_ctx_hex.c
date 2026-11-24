/* CX44 LTCG context: hex digit helper, exact callee name used by the callers. */
typedef unsigned short u16;
typedef unsigned char u8;
#ifdef _MSC_VER
__declspec(noinline)
#endif
u8 ts4_hex_digit_value_886EBCE8(u16 c)
{
    if (c >= '0' && c <= '9') return (u8)(c - '0');
    if (c >= 'A' && c <= 'F') return (u8)(c - 'A' + 10);
    if (c >= 'a' && c <= 'f') return (u8)(c - 'a' + 10);
    return 0;
}
