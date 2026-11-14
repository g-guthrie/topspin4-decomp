/* Derived from Expat (MIT license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
#ifndef R3_XMLTOK_H
#define R3_XMLTOK_H
/* Expat-style XML tokenizer support types (the game links an Expat 1.95/2.0 style xmltok).
 * Byte type codes follow the public Expat enumeration (xmltok.h / xmltok_impl.h). */

enum {
    TS4_BT_NONXML, TS4_BT_MALFORM, TS4_BT_LT, TS4_BT_AMP, TS4_BT_RSQB,
    TS4_BT_LEAD2, TS4_BT_LEAD3, TS4_BT_LEAD4, TS4_BT_TRAIL, TS4_BT_CR,
    TS4_BT_LF, TS4_BT_GT, TS4_BT_QUOT, TS4_BT_APOS, TS4_BT_EQUALS,
    TS4_BT_QUEST, TS4_BT_EXCL, TS4_BT_SOL, TS4_BT_SEMI, TS4_BT_NUM,
    TS4_BT_LSQB, TS4_BT_S, TS4_BT_NMSTRT, TS4_BT_COLON, TS4_BT_HEX,
    TS4_BT_DIGIT, TS4_BT_NAME, TS4_BT_MINUS, TS4_BT_OTHER, TS4_BT_NONASCII,
    TS4_BT_PERCNT, TS4_BT_LPAR, TS4_BT_RPAR, TS4_BT_AST, TS4_BT_PLUS,
    TS4_BT_COMMA, TS4_BT_VERBAR
};

struct ts4_xml_encoding;
typedef int (*ts4_xml_scanner)(const struct ts4_xml_encoding *enc, const char *ptr,
                               const char *end, const char **next_tok_ptr);

/* Layout of Expat's ENCODING (0x4C bytes) followed by the byte-type table. */
struct ts4_xml_encoding {
    ts4_xml_scanner scanners[4];
    ts4_xml_scanner literal_scanners[2];
    int (*same_name)(const struct ts4_xml_encoding *, const char *, const char *);
    int (*name_matches_ascii)(const struct ts4_xml_encoding *, const char *, const char *, const char *);
    int (*name_length)(const struct ts4_xml_encoding *, const char *);
    const char *(*skip_s)(const struct ts4_xml_encoding *, const char *);
    int (*get_atts)(const struct ts4_xml_encoding *, const char *, int, void *);
    int (*char_ref_number)(const struct ts4_xml_encoding *, const char *);
    int (*predefined_entity_name)(const struct ts4_xml_encoding *, const char *, const char *);
    void (*update_position)(const struct ts4_xml_encoding *, const char *, const char *, void *);
    int (*is_public_id)(const struct ts4_xml_encoding *, const char *, const char *, const char **);
    void (*utf8_convert)(const struct ts4_xml_encoding *, const char **, const char *, char **, const char *);
    void (*utf16_convert)(const struct ts4_xml_encoding *, const char **, const char *, unsigned short **, const unsigned short *);
    int min_bytes_per_char;
    char is_utf8;
    char is_utf16;
};

typedef int (*ts4_xml_char_predicate)(const struct ts4_xml_encoding *enc, const char *p);

struct ts4_xml_normal_encoding {
    struct ts4_xml_encoding enc;
    unsigned char type[256];
    ts4_xml_char_predicate is_name2;     /* +0x14C */
    ts4_xml_char_predicate is_name3;     /* +0x150 */
    ts4_xml_char_predicate is_name4;     /* +0x154 */
    ts4_xml_char_predicate is_nmstrt2;   /* +0x158 */
    ts4_xml_char_predicate is_nmstrt3;   /* +0x15C */
    ts4_xml_char_predicate is_nmstrt4;   /* +0x160 */
    ts4_xml_char_predicate is_invalid2;  /* +0x164 */
    ts4_xml_char_predicate is_invalid3;  /* +0x168 */
    ts4_xml_char_predicate is_invalid4;  /* +0x16C */
};

#endif
