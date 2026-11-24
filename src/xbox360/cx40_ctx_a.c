/* CW40 LTCG context: leaf that does not touch r4-r7, so callers keep arguments live across the call. */
typedef unsigned int u32;
typedef unsigned char u8;
#ifdef _MSC_VER
__declspec(noinline)
#endif
u8 ts4_check_hash_pair_887CE408(char *self)
{
    char *a = *(char **)(self + 0x38);
    if (*(u32 *)(a + 0x2c) == 0x1DCA7285u && *(u8 *)(*(char **)(self + 0x34) + 0x1c) != 0)
        return *(u32 *)(*(char **)(self + 0x3c) + 0x2cc) == 0x99F8C8F0u;
    return 0;
}
