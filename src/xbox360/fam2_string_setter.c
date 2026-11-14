/* FAM2: record string setters.  Each duplicates a C string into a fresh
 * ts4_msg_buffer_alloc_88278620 allocation stored at OFF and returns 1. */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

extern char *ts4_msg_buffer_alloc_88278620(u32 size);
unsigned long strlen(const char *s);

#define TS4_FIELD_SET_STRING(A, OFF) \
int ts4_field_set_string_##A(char *self, const char *s) \
{ \
    char *d = ts4_msg_buffer_alloc_88278620((u32)strlen(s) + 1); \
    *(char **)(self + OFF) = d; \
    { \
        const char *q = s - 1; \
        char c; \
        --d; \
        do { \
            c = *++q; \
            *++d = c; \
        } while (c); \
    } \
    return 1; \
}


TS4_FIELD_SET_STRING(885F8540, 0x2c)
TS4_FIELD_SET_STRING(885FF840, 0xc)
TS4_FIELD_SET_STRING(885FFA88, 0xc)
TS4_FIELD_SET_STRING(885FFC30, 0x14)
TS4_FIELD_SET_STRING(885FFCB0, 0x10)
TS4_FIELD_SET_STRING(88600210, 0xc)
TS4_FIELD_SET_STRING(886004B8, 0x20)
TS4_FIELD_SET_STRING(88600538, 0x1c)
