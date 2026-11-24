/* Loader_DLL.xex 0x8316F5C8-0x83175108, executable version 0.0.0.3. */


unsigned ts4l_round_down_377_o1_8316F5C8(unsigned x)
{
    unsigned r = x % 0x177U;
    if (r == 0) {
        return x;
    }
    x -= r;
    if (x >= 0x7D00U) {
        return x;
    }
    return x + 0x177U;
}

unsigned ts4l_round_down_377_o1_83173BF8(unsigned x)
{
    unsigned r = x % 0x177U;
    if (r == 0) {
        return x;
    }
    x -= r;
    if (x >= 0x7D00U) {
        return x;
    }
    return x + 0x177U;
}

unsigned ts4l_round_down_377_o1_83175108(unsigned x)
{
    unsigned r = x % 0x177U;
    if (r == 0) {
        return x;
    }
    x -= r;
    if (x >= 0x7D00U) {
        return x;
    }
    return x + 0x177U;
}
