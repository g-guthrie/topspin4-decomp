/* Derived from Expat (MIT license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* Family SWB2 (jump-table switch): expat sameName for little-endian UTF-16. One function per file (fn_check label names repeat). */
#include "swb2_expat.h"

/* Swing_DLL.xex 0x88897530: compares two names code unit by code unit; returns 1 when both end together. */
int ts4_same_name_little2_88897530(const unsigned char *encoding, const char *name1, const char *name2)
{
    for (;;) {
        int cls;
        unsigned int raw = (unsigned char)name1[1];

        cls = raw == 0 ? encoding[(unsigned char)name1[0] + 0x4c] : swb_little2_uni_inline(raw, (const unsigned char *)name1);
        switch (cls) {
        case 7:
            if (*name1++ != *name2++) {
                return 0;
            }
        case 6:
            if (*name1++ != *name2++) {
                return 0;
            }
        case 5:
            if (*name1++ != *name2++) {
                return 0;
            }
            if (*name1++ != *name2++) {
                return 0;
            }
            break;
        case 0x16: case 0x17: case 0x18: case 0x19: case 0x1a: case 0x1b: case 0x1d:
            if (*name2++ != *name1++) {
                return 0;
            }
            if (*name2++ != *name1++) {
                return 0;
            }
            break;
        default: {
            int cls2 = (unsigned char)name2[1] == 0 ? encoding[(unsigned char)name2[0] + 0x4c]
                                                    : ts4_xmltok_unicode_byte_type_888927A0(name2[1], name2[0]);
            switch (cls2) {
            case 5: case 6: case 7:
            case 0x16: case 0x17: case 0x18: case 0x19: case 0x1a: case 0x1b: case 0x1d:
                return 0;
            default:
                return 1;
            }
        }
        }
    }
}
