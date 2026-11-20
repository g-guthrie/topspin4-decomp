/* 0x88606108: copies the NUL-terminated UTF-16 string src into the 64-byte buffer dst, replacing characters above 0xFF with an underscore; returns 1 when the copy was lossless and terminated, 0 otherwise (dst[63] is then cleared). */
/* Matched on /Oc (agAF). 0 == lossy gives the addi 0 before cntlzw (agAB 8859AD10 rule). */
unsigned char fn_88606108(const unsigned short *src, char *dst)
{
    unsigned char lossy = 0;
    unsigned int i;
    for (i = 0; i < 0x40; i++) {
        unsigned short c = src[i];
        char ch;
        if (c > 0xff) {
            ch = '_';
            lossy = 1;
        } else
            ch = (char)c;
        dst[i] = ch;
        if (!ch)
            return 0 == lossy;
    }
    dst[0x3f] = 0;
    return 0;
}
