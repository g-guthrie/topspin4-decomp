/* Swing_DLL.xex 0x888A3CF0-0x888A3D84, executable version 0.0.0.3. */

/* Expat normalizePublicId: collapse white space runs to single spaces, trim the ends. */
void ts4_xml_normalize_public_id_888A3CF0(char *publicId)
{
    char *p = publicId;
    char *s = publicId;
    for (; *s; s++) {
        switch (*s) {
        case 0x20:
        case 0xD:
        case 0xA:
            if (p != publicId && p[-1] != 0x20)
                *p++ = 0x20;
            break;
        default:
            *p++ = *s;
        }
    }
    if (p != publicId && p[-1] == 0x20)
        --p;
    *p = 0;
}
