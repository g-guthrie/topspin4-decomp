/* 0x886ED860: Maps one of five 32-bit name hashes to a kind code (0, 2, 1, 6, 3); anything else gives 0. */
/* Matched on /Oc (agAH). A result local with an else-if chain; early returns and switch both miss. */
int fn_886ED860(unsigned int hash)
{
    int kind = 0;
    if (hash == 0x9AAF3D69u) kind = 0;
    else if (hash == 0x5757B54Au) kind = 2;
    else if (hash == 0xAB5FDCCCu) kind = 1;
    else if (hash == 0x370DACF1u) kind = 6;
    else if (hash == 0x81FA3875u) kind = 3;
    return kind;
}
