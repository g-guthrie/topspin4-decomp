/* Derived from Expat 2.0 (MIT license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* Swing_DLL.xex 0x8889F2B8-0x8889F878, executable version 0.0.0.3.
 * Family D6S: xmltok_impl.c scanLt for big-endian UTF-16 (one function per file; $LN labels repeat per function). */
#include "swb2_expat.h"

#define D6S_FN ts4_xml_scan_lt_big2_8889F2B8
#define D6S_TYPE(p) ((hi = (p)[0]) == 0 ? (enc)->type[(p)[1]] : ts4_xmltok_unicode_byte_type_888927A0(hi, (p)[1]))
#define D6S_HI(p) ((unsigned char)(p)[0])
#define D6S_LO(p) ((unsigned char)(p)[1])
#define D6S_MATCHES(p, c) ((p)[0] == 0 && (p)[1] == (c))
#define D6S_GAP 0xE70
#define D6S_CDATA lbl_880CFF30
#define D6S_ATTS fn_8889D890
#define D6S_COMMENT ex4_xml_scan_comment_big2_88897060
#define D6S_PI ex5_xml_scan_pi_big2_88896BE8
#define D6S_END_TAG ex5_xml_scan_end_tag_big2_88896578

#include "d6s_xmltok_lt16.h"
