/* Loader_DLL.xex 0x8343F658-0x8343F6B0, executable version 0.0.0.3. */
typedef unsigned long u32;
extern int ts4l_if_call_seq_fn_8340D710_8343F408(void *o, u32 n);
typedef struct { char p0[8]; u32 n; unsigned char *cur; } Arena;
void ts4l_arena_align_8343F658(Arena *a, u32 n)
{
    int r;
    a->n = n;
    r = ts4l_if_call_seq_fn_8340D710_8343F408(a, n + 16);
    if (r >= 0) {
        unsigned char pad = 16 - ((u32)a->cur & 15); a->cur = &a->cur[pad];
        a->cur[-1] = pad;
    }
}
