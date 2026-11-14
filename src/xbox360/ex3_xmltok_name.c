/* Derived from Expat (MIT license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* Family EX3: Expat xmltok name-class predicates (namingBitmap / nmstrtPages / namePages tables).
 *
 * The original addresses the three tables from one base register: the compiler anchors the page table that
 * the function reads and reaches namingBitmap at a constant negative offset (-0x600 from namePages,
 * -0x500 from nmstrtPages). That only happens when the tables are statics of the same translation unit, so
 * the tables are declared here as statics under the placeholder names of the real tables (0x880CE9C0,
 * 0x880CEEC0, 0x880CEFC0). The contents below are NOT the real tables; they only fix the object layout
 * (bitmap 0x500 bytes, nmstrt 0x100, name 0x100, contiguous) so the generated code matches. The leading
 * dummy array shifts the anchor choice to the page tables, as in the original code. */
#include "r3_xmltok.h"

#ifdef _MSC_VER
#define EX3_UNUSED_DATA
#else
#define EX3_UNUSED_DATA __attribute__((unused))
#endif
static const unsigned char ex3_layout_pad[16] EX3_UNUSED_DATA = {1};
static const unsigned int lbl_880CE9C0[320] = {1};      /* namingBitmap */
static const unsigned char lbl_880CEEC0[256] = {1};     /* nmstrtPages */
static const unsigned char lbl_880CEFC0[256] = {1};     /* namePages */

#define EX3_UCS2_NAMING(bitmap, pages, hi, lo) \
    ((bitmap)[((pages)[hi] << 3) + ((lo) >> 5)] & (1u << ((lo) & 0x1F)))
#define EX3_UTF8_NAMING2(bitmap, pages, b) \
    ((bitmap)[((pages)[(((b)[0]) >> 2) & 7] << 3) + ((((b)[0]) & 3) << 1) + ((((b)[1]) >> 5) & 1)] & \
     (1u << (((b)[1]) & 0x1F)))
#define EX3_UTF8_NAMING3(bitmap, pages, b) \
    ((bitmap)[((pages)[((((b)[0]) & 0xF) << 4) + ((((b)[1]) >> 2) & 0xF)] << 3) + ((((b)[1]) & 3) << 1) + \
              ((((b)[2]) >> 5) & 1)] & \
     (1u << (((b)[2]) & 0x1F)))

struct ex3_unknown_encoding {
    struct ts4_xml_normal_encoding normal;           /* +0x000 */
    int (*convert)(void *user_data, const char *p);  /* +0x170 */
    void *user_data;                                 /* +0x174 */
};

/* Name-start test for an application-converted character (Expat unknown_isNmstrt).
 * Swing_DLL.xex 0x88891678; also referenced by family LG1 as fn_88891678, so the placeholder name stays. */
int fn_88891678(const struct ts4_xml_encoding *enc, const char *p)
{
    int c = ((const struct ex3_unknown_encoding *)enc)->convert(((const struct ex3_unknown_encoding *)enc)->user_data, p);
    if (c & ~0xFFFF)
        return 0;
    return EX3_UCS2_NAMING(lbl_880CE9C0, lbl_880CEEC0, c >> 8, c & 0xFF);
}

/* Name-character test for an application-converted character (Expat unknown_isName).
 * Swing_DLL.xex 0x88891700; also referenced by family LG1 as fn_88891700. */
int fn_88891700(const struct ts4_xml_encoding *enc, const char *p)
{
    int c = ((const struct ex3_unknown_encoding *)enc)->convert(((const struct ex3_unknown_encoding *)enc)->user_data, p);
    if (c & ~0xFFFF)
        return 0;
    return EX3_UCS2_NAMING(lbl_880CE9C0, lbl_880CEFC0, c >> 8, c & 0xFF);
}

/* Name-start test for a 3-byte UTF-8 sequence (Expat utf8_isNmstrt3). Swing_DLL.xex 0x888949A0 */
int ts4_xmltok_utf8_is_nmstrt3_888949A0(const struct ts4_xml_encoding *enc, const char *p)
{
    (void)enc;
    return EX3_UTF8_NAMING3(lbl_880CE9C0, lbl_880CEEC0, (const unsigned char *)p);
}

/* Name-start test for a 2-byte UTF-8 sequence (Expat utf8_isNmstrt2). Swing_DLL.xex 0x88894A00 */
int ts4_xmltok_utf8_is_nmstrt2_88894A00(const struct ts4_xml_encoding *enc, const char *p)
{
    (void)enc;
    return EX3_UTF8_NAMING2(lbl_880CE9C0, lbl_880CEEC0, (const unsigned char *)p);
}

/* Name-character test for a 3-byte UTF-8 sequence (Expat utf8_isName3). Swing_DLL.xex 0x88894A50 */
int ts4_xmltok_utf8_is_name3_88894A50(const struct ts4_xml_encoding *enc, const char *p)
{
    (void)enc;
    return EX3_UTF8_NAMING3(lbl_880CE9C0, lbl_880CEFC0, (const unsigned char *)p);
}

/* Name-character test for a 2-byte UTF-8 sequence (Expat utf8_isName2). Swing_DLL.xex 0x88894AB0 */
int ts4_xmltok_utf8_is_name2_88894AB0(const struct ts4_xml_encoding *enc, const char *p)
{
    (void)enc;
    return EX3_UTF8_NAMING2(lbl_880CE9C0, lbl_880CEFC0, (const unsigned char *)p);
}
