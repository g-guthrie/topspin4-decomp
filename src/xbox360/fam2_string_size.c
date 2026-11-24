/* FAM2: serialized-size helpers for records holding an optional C string at
 * +0xc.  The string contributes strlen + 2 bytes (or 2 when absent) on top of
 * a fixed record size. */
typedef unsigned int u32;

typedef struct Ts4NamedRecord {
    u32 f00, f04, f08;
    const char *name;
} Ts4NamedRecord;

unsigned long strlen(const char *s);

#define TS4_NAMED_RECORD_SIZE(A, FIXED) \
u32 ts4_named_record_size_##A(const Ts4NamedRecord *self) \
{ \
    u32 n; \
    if (self->name) \
        n = (u32)strlen(self->name) + 2; \
    else \
        n = 2; \
    return n + FIXED; \
}

TS4_NAMED_RECORD_SIZE(885F9D10, 0x12)
TS4_NAMED_RECORD_SIZE(885F9D90, 0xa)
TS4_NAMED_RECORD_SIZE(885F9F10, 0xe)
TS4_NAMED_RECORD_SIZE(885F9F88, 0x2c)
TS4_NAMED_RECORD_SIZE(885FA450, 0x8)
TS4_NAMED_RECORD_SIZE(885FACC0, 0xa)
TS4_NAMED_RECORD_SIZE(885FADA8, 0xa)
TS4_NAMED_RECORD_SIZE(885FB708, 0x8)
