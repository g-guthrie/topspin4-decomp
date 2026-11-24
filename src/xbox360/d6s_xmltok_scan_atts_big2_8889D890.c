/* Derived from Expat 2.0 (MIT license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* Swing_DLL.xex 0x8889D890-0x8889E008, executable version 0.0.0.3.
 * Family D6S: xmltok_impl.c scanAtts for big-endian UTF-16 (one function per file; $LN labels repeat per function). */
#include "swb2_expat.h"

/* Expat unicode_byte_type expanded in place (the compiler inlined it at some call sites). */
SWB_INLINE int d6s_unicode_byte_type_inline(char hi, char lo)
{
    switch ((unsigned char)hi) {
    case 0xD8: case 0xD9: case 0xDA: case 0xDB:
        return SWB_BT_LEAD4;
    case 0xDC: case 0xDD: case 0xDE: case 0xDF:
        return SWB_BT_TRAIL;
    case 0xFF:
        switch ((unsigned char)lo) {
        case 0xFF: case 0xFE:
            return SWB_BT_NONXML;
        }
        break;
    }
    return SWB_BT_NONASCII;
}

#define D6S_FN ts4_xml_scan_atts_big2_8889D890
#define D6S_REF ex5_xml_scan_ref_big2_8889BDB8
#define D6S_CREF ex5_xml_scan_char_ref_big2_8889A2A8
#define D6S_HREF ex5_xml_scan_hex_char_ref_big2_88896488
#define D6S_TYPE(p) ((hi = (p)[0]) == 0 ? (enc)->type[(p)[1]] : ts4_xmltok_unicode_byte_type_888927A0(hi, (p)[1]))
#define D6S_TYPE_INL(p) ((hi2 = (p)[0]) == 0 ? (enc)->type[(p)[1]] : d6s_unicode_byte_type_inline(hi2, (p)[1]))
#define D6S_TYPE_INL1(p) ((hi5 = (p)[0]) == 0 ? (enc)->type[(p)[1]] : d6s_unicode_byte_type_inline(hi5, (p)[1]))
#define D6S_HI(p) ((unsigned char)(p)[0])
#define D6S_LO(p) ((unsigned char)(p)[1])
#define D6S_MATCHES(p, c) ((p)[0] == 0 && (p)[1] == (c))

#include "d6s_xmltok_atts16.h"
