/* Swing_DLL.xex 0x885938B0: free every chunk list (fn_88593688) and its header, last first, then the set array
 * /O1; the context argument is passed through to fn_88593688 */
typedef unsigned int u32;
typedef struct ChunkList ChunkList;
typedef struct ChunkSet { ChunkList *list; u32 key; } ChunkSet;
typedef struct ChunkTable { ChunkSet *sets; u32 capacity; u32 count; } ChunkTable;

void fn_88593688(ChunkList *l, u32 context);
void ts4_if_call_seq_u32_lbl_88D45B38_88884DE0(void *p, u32 tag);

/* Free every chunk list (fn_88593688), last first, then the set array. */
void fn_885938B0(ChunkTable *t, u32 context)
{
    if (t->sets == 0)
        return;
    while (t->count-- != 0) {
        fn_88593688(t->sets[t->count].list, context);
        ts4_if_call_seq_u32_lbl_88D45B38_88884DE0(t->sets[t->count].list, 0x24970000);
    }
    ts4_if_call_seq_u32_lbl_88D45B38_88884DE0(t->sets, 0x24970000);
    t->sets = 0;
}
