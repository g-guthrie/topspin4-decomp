/* 0x884B9770: passes every item of the source list at +0x1C (items +0x6C, count +0x70) to vtable slot 1 of the embedded sink at +0x18, re-checking the source each pass. */
/* Matched on /Oc (agAF). Same source as 0x884AFBE0. */
typedef struct Sink Sink;
typedef struct SinkVt { void *f0; void (*add)(Sink *s, void *item); } SinkVt;
struct Sink { SinkVt *vt; };
typedef struct Src { char p[0x6c]; void **items; int count; } Src;
typedef struct T { char p[0x18]; Sink sink; Src *src; } T;
void fn_884B9770(T *t)
{
    int i;
    for (i = 0; t->src && i < t->src->count; i++)
        t->sink.vt->add(&t->sink, t->src->items[i]);
}
