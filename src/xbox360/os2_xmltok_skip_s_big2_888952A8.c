/* Derived from Expat 2.0 (MIT license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* Family OS2: Expat xmltok_impl.c skipS for the big-endian UTF-16 encoding. */
#include "swb2_expat.h"

/* Expat unicode_byte_type, static in xmltok.c so the compiler folds it into callers */
static int unicode_byte_type(char hi, char lo)
{
    switch ((unsigned char)hi) {
    case 0xD8: case 0xD9: case 0xDA: case 0xDB:
        return SWB_BT_LEAD4;
    case 0xDC: case 0xDD: case 0xDE: case 0xDF:
        return SWB_BT_TRAIL;
    case 0xFF:
        switch ((unsigned char)lo) {
        case 0xFF:
        case 0xFE:
            return SWB_BT_NONXML;
        }
        break;
    }
    return SWB_BT_NONASCII;
}

/* Swing_DLL.xex 0x888952A8 (big2), 0x888973C8 (little2) */
const char *os2_xmltok_big2_skip_s_888952A8(const SwbEnc *enc, const char *ptr)
{
    for (;;) {
        switch ((ptr[0] == 0) ? enc->type[(unsigned char)ptr[1]]
                              : unicode_byte_type(ptr[0], ptr[1])) {
        case SWB_BT_LF:
        case SWB_BT_CR:
        case SWB_BT_S:
            ptr += 2;
            break;
        default:
            return ptr;
        }
    }
}
