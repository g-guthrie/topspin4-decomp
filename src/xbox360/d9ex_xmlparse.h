/* Swing_DLL.xex expat xmlparse.c parser object (full layout for the D9EX files). */
#ifndef D9EX_XMLPARSE_H
#define D9EX_XMLPARSE_H
#include "r3_xmlparse.h"
#include "r3_xmltok.h"
#include "r3_xmlrole.h"

#ifdef _MSC_VER
#define D9_INLINE __forceinline
#else
#define D9_INLINE inline
#endif

struct d9_xml_parser;
typedef int (*d9_xml_processor)(struct d9_xml_parser *parser, const char *s, const char *end, const char **next_ptr);

typedef struct d9_open_entity {
    const char *internal_event_ptr;     /* +0x00 */
    const char *internal_event_end_ptr; /* +0x04 */
    struct d9_open_entity *next;        /* +0x08 */
    void *entity;                       /* +0x0C */
} d9_open_entity;

typedef struct d9_entity {
    const char *name;        /* +0x00 */
    const char *text_ptr;    /* +0x04 */
    int text_len;            /* +0x08 */
    const char *system_id;   /* +0x0C */
    const char *base;        /* +0x10 */
    const char *public_id;   /* +0x14 */
    const char *notation;    /* +0x18 */
    unsigned char open;      /* +0x1C */
    unsigned char is_param;  /* +0x1D */
    unsigned char is_internal; /* +0x1E */
} d9_entity;

typedef struct d9_tag {
    struct d9_tag *parent;   /* +0x00 */
    const char *raw_name;    /* +0x04 */
    int raw_name_length;     /* +0x08 */
    char *name_str;          /* +0x0C */
    char *name_local_part;   /* +0x10 */
    char *name_prefix;       /* +0x14 */
    int name_str_len;        /* +0x18 */
    int name_uri_len;        /* +0x1C */
    int name_prefix_len;     /* +0x20 */
    char *buf;               /* +0x24 */
    char *buf_end;           /* +0x28 */
    ts4_xml_binding *bindings; /* +0x2C */
} d9_tag;

typedef struct d9_xml_parser {
    void *user_data;                              /* +0x00 */
    void *handler_arg;                            /* +0x04 */
    char *buffer;                                 /* +0x08 */
    void *(*malloc_fcn)(unsigned int);            /* +0x0C */
    void *(*realloc_fcn)(void *, unsigned int);   /* +0x10 */
    void (*free_fcn)(void *);                     /* +0x14 */
    const char *buffer_ptr;                       /* +0x18 */
    char *buffer_end;                             /* +0x1C */
    const char *buffer_lim;                       /* +0x20 */
    long parse_end_byte_index;                    /* +0x24 */
    const char *parse_end_ptr;                    /* +0x28 */
    char *data_buf;                               /* +0x2C */
    char *data_buf_end;                           /* +0x30 */
    void *start_element_handler;                  /* +0x34 */
    void *end_element_handler;                    /* +0x38 */
    void (*character_data_handler)(void *, const char *, int); /* +0x3C */
    void (*processing_instruction_handler)(void *, const char *, const char *); /* +0x40 */
    void (*comment_handler_fn)(void *, const char *); /* +0x44 */
    void *start_cdata_section_handler;            /* +0x48 */
    void (*end_cdata_section_handler)(void *);    /* +0x4C */
    void (*default_handler)(void *, const char *, int); /* +0x50 */
    void *start_doctype_decl_handler;             /* +0x54 */
    void *end_doctype_decl_handler;               /* +0x58 */
    void *unparsed_entity_decl_handler;           /* +0x5C */
    void *notation_decl_handler;                  /* +0x60 */
    void *start_namespace_decl_handler;           /* +0x64 */
    void *end_namespace_decl_handler;             /* +0x68 */
    void *not_standalone_handler;                 /* +0x6C */
    void *external_entity_ref_handler;            /* +0x70 */
    void *external_entity_ref_handler_arg;        /* +0x74 */
    void *skipped_entity_handler;                 /* +0x78 */
    void *unknown_encoding_handler;               /* +0x7C */
    void *element_decl_handler;                   /* +0x80 */
    void *attlist_decl_handler;                   /* +0x84 */
    void *entity_decl_handler;                    /* +0x88 */
    void *xml_decl_handler;                       /* +0x8C */
    const struct ts4_xml_encoding *encoding;      /* +0x90 */
    unsigned char init_encoding[0x50];            /* +0x94 */
    const struct ts4_xml_encoding *internal_encoding; /* +0xE4 */
    const char *protocol_encoding_name;           /* +0xE8 */
    unsigned char ns;                             /* +0xEC */
    unsigned char ns_triplets;                    /* +0xED */
    unsigned char pad_ee[2];
    void *unknown_encoding_mem;                   /* +0xF0 */
    void *unknown_encoding_data;                  /* +0xF4 */
    void *unknown_encoding_handler_data;          /* +0xF8 */
    void (*unknown_encoding_release)(void *);     /* +0xFC */
    struct ts4_prolog_state prolog_state;         /* +0x100 */
    d9_xml_processor processor;                   /* +0x118 */
    int error_code;                               /* +0x11C */
    const char *event_ptr;                        /* +0x120 */
    const char *event_end_ptr;                    /* +0x124 */
    const char *position_ptr;                     /* +0x128 */
    d9_open_entity *open_internal_entities;       /* +0x12C */
    unsigned char default_expand_internal_entities; /* +0x130 */
    unsigned char pad131[3];
    int tag_level;                                /* +0x134 */
    d9_entity *decl_entity;                       /* +0x138 */
    const char *doctype_name;                     /* +0x13C */
    const char *doctype_sysid;                    /* +0x140 */
    const char *doctype_pubid;                    /* +0x144 */
    const char *decl_attribute_type;              /* +0x148 */
    const char *decl_notation_name;               /* +0x14C */
    const char *decl_notation_public_id;          /* +0x150 */
    ts4_xml_element_type *decl_element_type;      /* +0x154 */
    ts4_xml_attribute_id *decl_attribute_id;      /* +0x158 */
    unsigned char decl_attribute_is_cdata;        /* +0x15C */
    unsigned char decl_attribute_is_id;           /* +0x15D */
    unsigned char pad15e[2];
    ts4_xml_dtd *dtd;                             /* +0x160 */
    const char *cur_base;                         /* +0x164 */
    d9_tag *tag_stack;                            /* +0x168 */
    d9_tag *free_tag_list;                        /* +0x16C */
    ts4_xml_binding *inherited_bindings;          /* +0x170 */
    ts4_xml_binding *free_binding_list;           /* +0x174 */
    int atts_size;                                /* +0x178 */
    int n_specified_atts;                         /* +0x17C */
    int id_att_index;                             /* +0x180 */
    void *atts;                                   /* +0x184 */
    unsigned int line_number;                     /* +0x188 */
    unsigned int column_number;                   /* +0x18C */
    ts4_xml_string_pool temp_pool;                /* +0x190 */
    ts4_xml_string_pool temp2_pool;               /* +0x1A8 */
    void *group_connector;                        /* +0x1C0 */
    unsigned int group_size;                      /* +0x1C4 */
    char namespace_separator;                     /* +0x1C8 */
    char pad1c9[3];
    struct d9_xml_parser *parent_parser;          /* +0x1CC */
    unsigned char is_param_entity;                /* +0x1D0 */
    unsigned char use_foreign_dtd;                /* +0x1D1 */
    unsigned char pad1d2[2];
    int param_entity_parsing;                     /* +0x1D4 */
} d9_xml_parser;

typedef struct d9_hash_iter {
    void **p;
    void **end;
} d9_hash_iter;

static D9_INLINE void *d9_hash_iter_next(d9_hash_iter *iter)
{
    while (iter->p != iter->end) {
        void *tem = *(iter->p)++;
        if (tem)
            return tem;
    }
    return 0;
}
#endif
