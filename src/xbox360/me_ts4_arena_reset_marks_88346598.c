/* Swing_DLL.xex 0x88346598: recomputes the 16 mark offsets (+0x214.., 0 for an unset mark, else top - mark) with used[0] = 0,
 * then clears the arena buffer (+0x200, size +0x208) with ts4_memset. agAE: /Oc. */
typedef struct Arena {
    char pad[0x1c0]; int marks[16]; void *buf; char pad204[4]; unsigned int size; int top; int used[17];
} Arena;
void *ts4_memset(void *p, int v, unsigned int n);
int fn_88346598(Arena *a)
{
    int i;
    a->used[0] = 0;
    for (i = 0; i < 16; i++)
        a->used[i + 1] = a->marks[i] == 0 ? 0 : a->top - a->marks[i];
    if (a->buf) ts4_memset(a->buf, 0, a->size);
    return 0;
}
