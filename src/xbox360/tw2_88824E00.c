/* Twin of 0x8881C800 (lua2_doswap_8881C800 in src/xbox360/lua2_ldump.c). */
int ts4_lua2_doswap_88824E00(int c)
{
    if (c == '<') return 1;
    else if (c == '>') return 0;
    else if (c == '=') return 0;
    return 0;
}
