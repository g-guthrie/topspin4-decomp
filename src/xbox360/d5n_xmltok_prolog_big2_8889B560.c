/* Derived from Expat (MIT license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* Family D5N: xmltok_impl.c prologTok for big-endian UTF-16 (Swing_DLL.xex 0x8889B560-0x8889BDB4). */
#include "swb2_expat.h"

#define D5N_FN ts4_xml_prolog_tok_big2_8889B560
#define D5N_TYPE(p) ((hi = (p)[0]) == 0 ? (enc)->type[(p)[1]] : ts4_xmltok_unicode_byte_type_888927A0(hi, (p)[1]))
#define D5N_HI(p) ((unsigned char)(p)[0])
#define D5N_LO(p) ((unsigned char)(p)[1])
#define D5N_MATCHES(p, c) ((p)[0] == 0 && (p)[1] == (c))
#define D5N_NOT_LAST(p, e) ((p) + 2 != (e))
#define D5N_SCAN_LIT ex4_xml_scan_lit_big2_88895D28
#define D5N_SCAN_DECL ex5_xml_scan_decl_big2_8889A3B8
#define D5N_SCAN_PI ex5_xml_scan_pi_big2_88896BE8
#define D5N_SCAN_PERCENT ex5_xml_scan_percent_big2_888961E0
#define D5N_SCAN_POUND ex5_xml_scan_pound_name_big2_88895F30

#include "d5n_xmltok_prolog16.h"
