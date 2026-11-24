/* 0x884EC070: under the writer lock, writes the array count and then each item to the stream at +0xC, clears the lock owner and leaves */
/* Near miss (agAH): /Oc, 1 off at +0x44: the item lwzx wants base-first; chain, element local, i[a], accessor and stream-local forms all give index-first. */
typedef struct Lock { char cs[0x20]; __int64 owner; } Lock;
typedef struct Stream Stream;
typedef struct W { char p[0xc]; Stream *stream; Lock *lock; } W;
typedef struct Arr { void **items; int count; } Arr;
extern void fn_88472530(Lock *l);
extern void ts4_stream_write_i32_a_88427418(Stream *s, int v);
extern void fn_884ED278(Stream *s, void *item);
extern void RtlLeaveCriticalSection(void *cs);
void fn_884EC070(W *w, Arr *a)
{
    int i;
    fn_88472530(w->lock);
    ts4_stream_write_i32_a_88427418(w->stream, a->count);
    for (i = 0; i < a->count; i++)
        fn_884ED278(w->stream, a->items[i]);
    {
        Lock *l = w->lock;
        l->owner = -1;
        RtlLeaveCriticalSection(l);
    }
}
