/* 0x882911D0: ensures room for n words between +0x30 cur and +0x34 end: flushes (fn_88292598), then grows (fn_88291960, an unsigned/pointer result) and returns cur, or that 0 result */
/* Matched on /O1 plain and LTCG (agT, v.py chk). */
typedef struct Buf { char pad[0x30]; char *cur; char *end; } Buf;
void fn_88292598(Buf *b);
char *fn_88291960(Buf *b, unsigned int words);
char *ts4_buf_reserve_words_882911D0(Buf *b, unsigned int words)
{
    char *p;
    if (b->cur + words * 4 > b->end) {
        fn_88292598(b);
        if (b->cur + words * 4 > b->end) {
            p = fn_88291960(b, words);
            if (!p && b->cur + words * 4 > b->end)
                return p;
        }
    }
    return b->cur;
}
