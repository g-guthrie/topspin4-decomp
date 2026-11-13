/* Derived from Expat (MIT license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
#ifndef R3_XMLPARSE_H
#define R3_XMLPARSE_H

struct ts4_xml_encoding;
/* Partial layout of the Expat parser object (Expat 1.95/2.0 style xmlparse.c) as used by R3 functions.
 * Offsets verified against Swing_DLL.xex machine code. */

typedef struct ts4_xml_content_scaffold {
    int type;          /* +0x00 */
    int quant;         /* +0x04 */
    const char *name;  /* +0x08 */
    int firstchild;    /* +0x0C */
    int lastchild;     /* +0x10 */
    int childcnt;      /* +0x14 */
    int nextsib;       /* +0x18 */
} ts4_xml_content_scaffold;

typedef struct ts4_xml_content {
    int type;                          /* +0x00 */
    int quant;                         /* +0x04 */
    char *name;                        /* +0x08 */
    unsigned int numchildren;          /* +0x0C */
    struct ts4_xml_content *children;  /* +0x10 */
} ts4_xml_content;

typedef struct ts4_xml_memory_suite {
    void *(*malloc_fcn)(unsigned int);
    void *(*realloc_fcn)(void *, unsigned int);
    void (*free_fcn)(void *);
} ts4_xml_memory_suite;

/* Expat string pool (xmlparse.c STRING_POOL / BLOCK). */
typedef struct ts4_xml_block {
    struct ts4_xml_block *next; /* +0x00 */
    int size;                   /* +0x04 */
    char s[1];                  /* +0x08 */
} ts4_xml_block;

typedef struct ts4_xml_string_pool {
    ts4_xml_block *blocks;       /* +0x00 */
    ts4_xml_block *free_blocks;  /* +0x04 */
    const char *end;             /* +0x08 */
    char *ptr;                   /* +0x0C */
    char *start;                 /* +0x10 */
    const ts4_xml_memory_suite *mem; /* +0x14 */
} ts4_xml_string_pool;

typedef struct ts4_xml_hash_table {
    void **v;              /* +0x00 */
    unsigned int size;     /* +0x04 */
    unsigned int used;     /* +0x08 */
    unsigned int used_lim; /* +0x0C */
    const ts4_xml_memory_suite *mem; /* +0x10 */
} ts4_xml_hash_table;

typedef struct ts4_xml_binding {
    const char *prefix;                 /* +0x00 */
    struct ts4_xml_binding *next_tag_binding; /* +0x04 */
    struct ts4_xml_binding *prev_prefix_binding; /* +0x08 */
    void *att_id;                       /* +0x0C */
    char *uri;                          /* +0x10 */
    int uri_len;                        /* +0x14 */
    int uri_alloc;                      /* +0x18 */
} ts4_xml_binding;

typedef struct ts4_xml_prefix {
    const char *name;                   /* +0x00 */
    ts4_xml_binding *binding;           /* +0x04 */
} ts4_xml_prefix;

typedef struct ts4_xml_entity {
    const char *name;                   /* +0x00 */
    unsigned char pad004[0x18];
    unsigned char open;                 /* +0x1C */
} ts4_xml_entity;

/* Expat DTD object (0xBC bytes). */
typedef struct ts4_xml_dtd {
    ts4_xml_hash_table general_entities;  /* +0x00 */
    ts4_xml_hash_table element_types;     /* +0x14 */
    ts4_xml_hash_table attribute_ids;     /* +0x28 */
    ts4_xml_hash_table prefixes;          /* +0x3C */
    ts4_xml_string_pool pool;             /* +0x50 */
    ts4_xml_string_pool entity_value_pool; /* +0x68 */
    unsigned char keep_processing;        /* +0x80 */
    unsigned char has_param_entity_refs;  /* +0x81 */
    unsigned char standalone;             /* +0x82 */
    unsigned char param_entity_read;      /* +0x83 */
    ts4_xml_hash_table param_entities;    /* +0x84 */
    ts4_xml_prefix default_prefix;        /* +0x98 */
    unsigned char in_eldecl;              /* +0xA0 */
    ts4_xml_content_scaffold *scaffold;   /* +0xA4 */
    unsigned int content_string_len;      /* +0xA8 */
    unsigned int scaff_size;              /* +0xAC */
    unsigned int scaff_count;             /* +0xB0 */
    int scaff_level;                      /* +0xB4 */
    int *scaff_index;                     /* +0xB8 */
} ts4_xml_dtd;

typedef struct ts4_xml_open_internal_entity {
    const char *internal_event_ptr;     /* +0x00 */
    const char *internal_event_end_ptr; /* +0x04 */
} ts4_xml_open_internal_entity;

typedef struct ts4_xml_attribute_id {
    char *name;                         /* +0x00 */
    ts4_xml_prefix *prefix;             /* +0x04 */
    unsigned char maybe_tokenized;      /* +0x08 */
    unsigned char xmlns;                /* +0x09 */
} ts4_xml_attribute_id;

typedef struct ts4_xml_default_attribute {
    ts4_xml_attribute_id *id;           /* +0x00 */
    unsigned char is_cdata;             /* +0x04 */
    const char *value;                  /* +0x08 */
} ts4_xml_default_attribute;

typedef struct ts4_xml_element_type {
    const char *name;                   /* +0x00 */
    ts4_xml_prefix *prefix;             /* +0x04 */
    ts4_xml_attribute_id *id_att;       /* +0x08 */
    int n_default_atts;                 /* +0x0C */
    int alloc_default_atts;             /* +0x10 */
    ts4_xml_default_attribute *default_atts; /* +0x14 */
} ts4_xml_element_type;

typedef struct ts4_xml_tag {
    struct ts4_xml_tag *parent;         /* +0x00 */
    unsigned char pad004[0x20];
    char *buf;                          /* +0x24 */
    char *buf_end;                      /* +0x28 */
    ts4_xml_binding *bindings;          /* +0x2C */
} ts4_xml_tag;

typedef struct ts4_xml_parser {
    void *user_data; /* +0x0 */
    void *handler_arg; /* +0x4 */
    char *buffer; /* +0x8 */
    void *(*malloc_fcn)(unsigned int); /* +0xC */
    void *(*realloc_fcn)(void *, unsigned int); /* +0x10 */
    void (*free_fcn)(void *); /* +0x14 */
    char *buffer_ptr; /* +0x18 */
    char *buffer_end; /* +0x1C */
    char *buffer_lim; /* +0x20 */
    unsigned char pad024[0x8];
    char *data_buf; /* +0x2C */
    char *data_buf_end; /* +0x30 */
    unsigned char pad034[0xC];
    void (*processing_instruction_handler)(void *, const char *, const char *); /* +0x40 */
    unsigned char pad044[0xC];
    void (*default_handler)(void *, const char *, int); /* +0x50 */
    unsigned char pad054[0x10];
    void (*start_namespace_decl_handler)(void *, const char *, const char *); /* +0x64 */
    unsigned char pad068[0x14];
    int (*unknown_encoding_handler)(void *, const char *, void *); /* +0x7C */
    unsigned char pad080[0xC];
    void (*xml_decl_handler)(void *, const char *, const char *, int); /* +0x8C */
    const struct ts4_xml_encoding *encoding; /* +0x90 */
    unsigned char pad094[0x54];
    const char *protocol_encoding_name; /* +0xE8 */
    unsigned char ns; /* +0xEC */
    unsigned char pad0ED[0x3];
    void *unknown_encoding_mem; /* +0xF0 */
    void *unknown_encoding_data; /* +0xF4 */
    void *unknown_encoding_handler_data; /* +0xF8 */
    void (*unknown_encoding_release)(void *); /* +0xFC */
    unsigned char pad100[0x1C];
    int error_code; /* +0x11C */
    const char *event_ptr; /* +0x120 */
    const char *event_end_ptr; /* +0x124 */
    unsigned char pad128[0x4];
    ts4_xml_open_internal_entity *open_internal_entities; /* +0x12C */
    unsigned char pad130[0x30];
    ts4_xml_dtd *dtd; /* +0x160 */
    unsigned char pad164[0x4];
    ts4_xml_tag *tag_stack; /* +0x168 */
    ts4_xml_tag *free_tag_stack; /* +0x16C */
    ts4_xml_binding *inherited_bindings; /* +0x170 */
    ts4_xml_binding *free_binding_list; /* +0x174 */
    unsigned char pad178[0xC];
    void *atts; /* +0x184 */
    unsigned char pad188[0x8];
    ts4_xml_string_pool temp_pool; /* +0x190 */
    ts4_xml_string_pool temp2_pool; /* +0x1A8 */
    void *group_connector; /* +0x1C0 */
    unsigned int group_size; /* +0x1C4 */
    char namespace_separator; /* +0x1C8 */
    unsigned char pad1C9[0x3];
    void *parent_parser; /* +0x1CC */
    unsigned char is_param_entity; /* +0x1D0 */
    unsigned char pad1D1[0x3];
    int param_entity_parsing; /* +0x1D4 */
} ts4_xml_parser;

#endif
