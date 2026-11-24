/* 0x8843CA08: Stores 1 in *out if bit index is set in the packed bitset (31 bits per word, data words after a header word count at bits[0]), else 0. */
/* Matched on /Oc (agAH). Plain expression; /31 and %31 compile to divwu plus mulhwu. */
void fn_8843CA08(unsigned char *out, int unused, const unsigned int *bits, unsigned int index)
{
    *out = (bits[bits[0] + index / 31 + 1] & (1u << (index % 31))) != 0;
}
