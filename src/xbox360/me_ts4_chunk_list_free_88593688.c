/* Swing_DLL.xex 0x88593688: free every chunk's data and the chunk itself (tag 0x24970000), last first, then the chunk array
 * /O1; while (l->count-- != 0) with the index re-read for the second free. The caller (885938B0) passes a second argument, unused here. */
typedef unsigned int u32;
typedef struct Chunk { void *data; } Chunk;
typedef struct ChunkList { Chunk **chunks; u32 count; } ChunkList;

void ts4_if_call_seq_u32_lbl_88D45B38_88884DE0(void *p, u32 tag);

/* Free every chunk's data and the chunk, newest first, then the chunk array. */
void fn_88593688(ChunkList *l, u32 context)
{
    while (l->count-- != 0) {
        Chunk *c = l->chunks[l->count];
        ts4_if_call_seq_u32_lbl_88D45B38_88884DE0(c->data, 0x24970000);
        c->data = 0;
        ts4_if_call_seq_u32_lbl_88D45B38_88884DE0(l->chunks[l->count], 0x24970000);
    }
    ts4_if_call_seq_u32_lbl_88D45B38_88884DE0(l->chunks, 0x24970000);
    l->chunks = 0;
}
