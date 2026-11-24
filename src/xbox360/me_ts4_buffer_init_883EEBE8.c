/* 0x883EEBE8: stores size and buffer, allocating size bytes from the lbl_88B3302C heap (file lbl_88039C34, line 0x28) when none is given */
/* Matched on /O1 plain and LTCG (work/army/ME/v.py chk); sets cur to the buffer; returns 0 on allocation failure. */
typedef struct Ctx { int a; void *heap; } Ctx;
extern Ctx *lbl_88B3302C;
extern const char lbl_88039C34[];
void *fn_88315C60(void *heap, unsigned size, const char *file, int line, int a, int b);
typedef struct T { int f0; unsigned size; void *buf; void *cur; } T;
unsigned char ts4_buffer_init_883EEBE8(T *t, unsigned size, void *buf)
{
    t->size = size;
    t->buf = buf;
    if (!t->buf) {
        t->buf = fn_88315C60(lbl_88B3302C->heap, size, lbl_88039C34, 0x28, 0, 0);
        if (!t->buf)
            return 0;
    }
    t->cur = t->buf;
    return 1;
}
