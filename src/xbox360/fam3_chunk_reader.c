/* Swing_DLL.xex chunk reader: typed fixed-size reads (FAM3).
   MSVC 16.00.10224.00 /O2.

   A chunk reader wraps a stream and tracks the bytes left in the current
   chunk. Each read<T> pulls sizeof(T) bytes, then skips the padding that
   keeps the chunk 4-byte aligned. When the chunk is used up it tells the
   stream's owner to close it. Instances differ only in sizeof(T). */
typedef unsigned int u32;

#ifndef _MSC_VER
#define __forceinline inline
#endif

typedef struct Ts4Stream Ts4Stream;
typedef struct Ts4StreamOwner Ts4StreamOwner;

typedef struct Ts4StreamVt {
    void *slot0;
    void *slot1;
    void *slot2;
    void *slot3;
    u32 (*read)(Ts4Stream *self, void *dst, u32 size);
} Ts4StreamVt;

typedef struct Ts4StreamOwnerVt {
    void *slots[22];
    void (*close_chunk)(Ts4StreamOwner *self, void *reader);
} Ts4StreamOwnerVt;

struct Ts4StreamOwner {
    Ts4StreamOwnerVt *vt;
};

struct Ts4Stream {
    Ts4StreamVt *vt;
    Ts4StreamOwner *owner;
};

typedef struct Ts4ChunkReader {
    Ts4Stream *stream;
    int remaining;
    int unk8;
    unsigned char open;
} Ts4ChunkReader;

static __forceinline void ts4_chunk_reader_skip(Ts4ChunkReader *self, u32 n)
{
    unsigned char zero = 0;
    u32 i;
    for (i = 0; i < n; ++i)
        self->stream->vt->read(self->stream, &zero, 1);
}

#define CHUNK_READER_READ(A, SIZE) \
u32 ts4_chunk_reader_read_##A(Ts4ChunkReader *self, void *dst) \
{ \
    u32 got; \
    int pad; \
    if (!self->open || self->remaining < (SIZE)) \
        return 0; \
    got = self->stream->vt->read(self->stream, dst, (SIZE)); \
    self->remaining -= (SIZE); \
    pad = self->remaining % 4; \
    if (pad) { \
        ts4_chunk_reader_skip(self, (u32)pad); \
        self->remaining -= pad; \
    } \
    if (self->remaining <= 0) { \
        self->stream->owner->vt->close_chunk(self->stream->owner, self); \
        self->open = 0; \
    } \
    return got; \
}

/* Swing_DLL.xex addresses */
CHUNK_READER_READ(88169C10, 0x14)
CHUNK_READER_READ(8816B4B8, 0x8)
CHUNK_READER_READ(8816B5A8, 0x4)
CHUNK_READER_READ(8816BAE8, 0xC)
