/* Derived from Expat 2.0 (MIT license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* Swing_DLL.xex 0x8889F878-0x8889FE20, executable version 0.0.0.3.
 * Family D6S: xmltok_impl.c scanLt for little-endian UTF-16 (one function per file; $LN labels repeat per function). */
#include "swb2_expat.h"

#define D6S_FN ts4_xml_scan_lt_little2_8889F878
#define D6S_TYPE(p) ((hi = (p)[1]) == 0 ? (enc)->type[(p)[0]] : ts4_xmltok_unicode_byte_type_888927A0(hi, (p)[0]))
#define D6S_HI(p) ((unsigned char)(p)[1])
#define D6S_LO(p) ((unsigned char)(p)[0])
#define D6S_MATCHES(p, c) ((p)[1] == 0 && (p)[0] == (c))
#define D6S_GAP 0xB88
#define D6S_CDATA lbl_880CFC48
#define D6S_ATTS fn_8889E498
#define D6S_COMMENT ts4_xml_scan_comment_16_88899140
#define D6S_PI ex5_xml_scan_pi_little2_88898CD8
#define D6S_END_TAG ex5_xml_scan_end_tag_little2_88898678

#include "d6s_xmltok_lt16.h"
