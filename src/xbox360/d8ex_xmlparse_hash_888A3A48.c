/* Swing_DLL.xex 0x888A3A48-0x888A3A7C, executable version 0.0.0.3. */

/* Expat hash(): h = h * 33 + c over the key bytes. */
unsigned long ts4_xml_hash_888A3A48(const char *s)
{
    unsigned long h = 0;
    while (*s)
        h = h * 33 + (unsigned char)*s++;
    return h;
}
