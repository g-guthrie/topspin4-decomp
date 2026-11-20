/* Derived from Expat 2.0 (MIT license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* Family OS2: Expat xmltok.c XmlParseXmlDecl for the plain (0x8889B480) and namespace (0x8889B4F0) encoding tables:
 * both pass their own findEncoding to the shared doParseXmlDecl. */
#include "r3_xmltok.h"

typedef const struct ts4_xml_encoding *(*os2_encoding_finder)(const struct ts4_xml_encoding *, const char *,
                                                              const char *);

const struct ts4_xml_encoding *ex5_xmltok_find_encoding_888999E0(const struct ts4_xml_encoding *, const char *,
                                                                 const char *);
const struct ts4_xml_encoding *ex5_xmltok_find_encoding_88899B28(const struct ts4_xml_encoding *, const char *,
                                                                 const char *);
int fn_88899F70(os2_encoding_finder encoding_finder, int is_general_text_entity, const struct ts4_xml_encoding *enc,
                const char *ptr, const char *end, const char **bad_ptr, const char **version_ptr,
                const char **version_end_ptr, const char **encoding_name, const struct ts4_xml_encoding **encoding,
                int *standalone);

#define OS2_DEFINE_PARSE_XML_DECL(name, finder)                                                            \
int name(int is_general_text_entity, const struct ts4_xml_encoding *enc, const char *ptr, const char *end, \
         const char **bad_ptr, const char **version_ptr, const char **version_end_ptr,                     \
         const char **encoding_name, const struct ts4_xml_encoding **encoding, int *standalone)            \
{                                                                                                          \
    return fn_88899F70(finder, is_general_text_entity, enc, ptr, end, bad_ptr, version_ptr,                \
                       version_end_ptr, encoding_name, encoding, standalone);                              \
}

/* Swing_DLL.xex 0x8889B480 */
OS2_DEFINE_PARSE_XML_DECL(os2_xmltok_parse_xml_decl_8889B480, ex5_xmltok_find_encoding_888999E0)
/* Swing_DLL.xex 0x8889B4F0 */
OS2_DEFINE_PARSE_XML_DECL(os2_xmltok_parse_xml_decl_ns_8889B4F0, ex5_xmltok_find_encoding_88899B28)
