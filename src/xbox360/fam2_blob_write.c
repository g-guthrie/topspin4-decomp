/* FAM2: serializers for records carrying a length-prefixed blob followed by
 * two u16 fields.  fn_88603F38 writes the common header and returns the
 * buffer base; each helper returns the new write offset. */
typedef unsigned int u32;
typedef unsigned short u16;

typedef struct Ts4BlobRecord {
    u32 f00, f04, f08;
    const void *data;
    u32 len;
    u16 f14, f16;
} Ts4BlobRecord;

extern char *fn_88603F38(Ts4BlobRecord *o, u32 off);
extern void *memcpy(void *dst, const void *src, unsigned long size);

#define TS4_BLOB_RECORD_WRITE(A) \
u32 ts4_blob_record_write_##A(Ts4BlobRecord *o, u32 off) \
{ \
    char *p = fn_88603F38(o, off) + off; \
    u32 len; \
    *(u32 *)p = o->len; \
    p += 4; \
    len = o->len; \
    if (len) \
        memcpy(p, o->data, len); \
    p += len; \
    *(u16 *)p = o->f14; \
    p += 2; \
    *(u16 *)p = o->f16; \
    p += 2; \
    return (u32)(unsigned long)(p - off); \
}

TS4_BLOB_RECORD_WRITE(885F68D8)
TS4_BLOB_RECORD_WRITE(885F6940)
TS4_BLOB_RECORD_WRITE(885F69A8)
TS4_BLOB_RECORD_WRITE(885F6A10)
TS4_BLOB_RECORD_WRITE(885F6A78)
