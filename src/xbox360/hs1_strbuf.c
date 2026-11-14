/* HS1 matching batch strbuf: inline-buffer string constructors.
   MSVC 16.00.10224.00 /O2 /Oi, verified with tools/fn_check.py. */

/* Swing_DLL.xex 0x88163990 */
typedef struct TS4Buf64 { char d[64]; } TS4Buf64;
typedef struct TS4SmallString64 {
    char * volatile begin;
    char * volatile end;
    TS4Buf64 buf;
    char * volatile limit;
} TS4SmallString64;
void *ts4_sbuf_shrink_88169260(void *self);
/* construct an empty inline-buffer string (64 byte buffer) */
TS4SmallString64 *ts4_small_string64_ctor_88163990(TS4SmallString64 *self)
{
    TS4Buf64 tmp;
    char *b = self->buf.d;
    self->buf = tmp;
    self->limit = 0;
    self->begin = b;
    self->end = b;
    self->limit = b + 8;
    self->buf.d[0] = 0;
    ts4_sbuf_shrink_88169260(self);
    return self;
}

/* Swing_DLL.xex 0x88163B90 */
typedef struct TS4Buf256 { char d[256]; } TS4Buf256;
typedef struct TS4SmallString256 {
    char * volatile begin;
    char * volatile end;
    TS4Buf256 buf;
    char * volatile limit;
} TS4SmallString256;
void *ts4_sbuf_shrink_881692D8(void *self);
/* construct an empty inline-buffer string (256 byte buffer) */
TS4SmallString256 *ts4_small_string256_ctor_88163B90(TS4SmallString256 *self)
{
    TS4Buf256 tmp;
    char *b = self->buf.d;
    self->buf = tmp;
    self->limit = 0;
    self->begin = b;
    self->end = b;
    self->limit = b + 8;
    self->buf.d[0] = 0;
    ts4_sbuf_shrink_881692D8(self);
    return self;
}

/* Swing_DLL.xex 0x881A50F0 */
typedef struct TS4Buf512 { char d[0x200]; } TS4Buf512;
typedef struct TS4SmallString512 {
    char * volatile begin;
    char * volatile end;
    TS4Buf512 buf;
    char * volatile limit;
} TS4SmallString512;
void *ts4_sbuf_shrink_88185660(void *self);
/* construct an empty inline-buffer string (512 byte buffer) */
TS4SmallString512 *ts4_small_string512_ctor_881A50F0(TS4SmallString512 *self)
{
    TS4Buf512 tmp;
    char *b = self->buf.d;
    self->buf = tmp;
    self->limit = 0;
    self->begin = b;
    self->end = b;
    self->limit = b + 8;
    self->buf.d[0] = 0;
    ts4_sbuf_shrink_88185660(self);
    return self;
}

/* Swing_DLL.xex 0x88180070 */
void *ts4_sbuf_shrink_88185660(void *self);
void *ts4_byte_string_assign_cstr_88181EF8(void *self, const char *s);
/* construct an inline-buffer string (512 byte buffer) from a C string */
TS4SmallString512 *ts4_small_string512_from_cstr_88180070(TS4SmallString512 *self, const char *s)
{
    TS4Buf512 tmp;
    char *b = self->buf.d;
    self->buf = tmp;
    self->limit = 0;
    self->begin = b;
    self->end = b;
    self->limit = b + 8;
    self->buf.d[0] = 0;
    ts4_sbuf_shrink_88185660(self);
    ts4_byte_string_assign_cstr_88181EF8(self, s);
    return self;
}

/* Swing_DLL.xex 0x881A5020 */
void *ts4_sbuf_shrink_881692D8(void *self);
void *ts4_byte_string_assign_cstr_88182330(void *self, const char *s);
/* construct an inline-buffer string (256 byte buffer) from a C string */
TS4SmallString256 *ts4_small_string256_from_cstr_881A5020(TS4SmallString256 *self, const char *s)
{
    TS4Buf256 tmp;
    char *b = self->buf.d;
    self->buf = tmp;
    self->limit = 0;
    self->begin = b;
    self->end = b;
    self->limit = b + 8;
    self->buf.d[0] = 0;
    ts4_sbuf_shrink_881692D8(self);
    ts4_byte_string_assign_cstr_88182330(self, s);
    return self;
}

/* Swing_DLL.xex 0x8822AE40 */
void *ts4_sbuf_shrink_881692D8(void *self);
void *ts4_byte_string_assign_cstr_88182330(void *self, const char *s);
/* construct an inline-buffer string (256 byte buffer) from the C string held in *src */
TS4SmallString256 *ts4_small_string256_from_cstr_ptr_8822AE40(TS4SmallString256 *self, const char **src)
{
    TS4Buf256 tmp;
    char *b = self->buf.d;
    self->buf = tmp;
    self->limit = 0;
    self->begin = b;
    self->end = b;
    self->limit = b + 8;
    self->buf.d[0] = 0;
    ts4_sbuf_shrink_881692D8(self);
    ts4_byte_string_assign_cstr_88182330(self, *src);
    return self;
}
