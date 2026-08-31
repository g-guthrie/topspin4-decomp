typedef unsigned char u8;

/* Swing_DLL.xex 0x88171C10. */
int ts4_parse_u8_decimal_if_changed(void *unused, u8 *output, const char *text)
{
    u8 value = 0;
    char current = *text;

    (void)unused;

    while (current != 0) {
        if (current < '0' || current > '9') {
            break;
        }
        value = (u8)(value * 10 + (u8)current - '0');
        text++;
        current = *text;
    }
    if (*output != value) {
        *output = value;
        return 1;
    }
    return 0;
}
