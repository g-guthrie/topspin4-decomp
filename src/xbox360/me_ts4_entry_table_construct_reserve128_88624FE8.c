/* Swing_DLL.xex 0x88624FE8: constructor: zero the 12-byte entry vector, construct the text owner at +0xC (8827FFB8), clear count/cursor, set enabled, reserve 128 entries.
 * /Oc. Same end-slot vector init as 8827FFB8; allocate and reserve are __forceinline. */
typedef struct UVec { unsigned int *first; unsigned int *last; unsigned int *end; } UVec;
typedef struct TextOwner { char text[0x800]; UVec items; struct TextOwner *self; } TextOwner;
typedef struct Entry12 { unsigned int a; unsigned int b; unsigned int c; } Entry12;
typedef struct Entry12Vec { Entry12 *first; Entry12 *last; Entry12 *end; } Entry12Vec;
typedef struct EntryTable { Entry12Vec entries; TextOwner names; unsigned int count; unsigned int cursor; unsigned char enabled; } EntryTable;
extern void *lbl_88D45B38;
void *ts4_if_call_seq_fn_88883CD0_8860D250(void *heap);
void *fn_88613570(void *alloc, unsigned int size, unsigned int align, void *owner);
void *fn_88562DC0(void *dst, const void *src, unsigned int n);
void ts4_destroy_owned_object(void *obj);
TextOwner *fn_8827FFB8(TextOwner *o);

static __forceinline Entry12 *allocate(Entry12Vec *v, unsigned int n)
{
    return (Entry12 *)fn_88613570(lbl_88D45B38 ? ts4_if_call_seq_fn_88883CD0_8860D250(lbl_88D45B38) : 0, n * sizeof(Entry12), 4, &v->end);
}

static __inline void copy_elems(Entry12 *first, Entry12 *last, Entry12 *dest)
{
    if (last != first) fn_88562DC0(dest, first, (char *)last - (char *)first);
}

static __forceinline void reserve(Entry12Vec *v, unsigned int n)
{
    Entry12 *first = v->first;
    if ((unsigned int)(v->end - first) < n) {
        Entry12 *last = v->last;
        int size = v->last - v->first;
        if (first != 0) {
            Entry12 *buffer = allocate(v, n);
            copy_elems(first, last, buffer);
            first = buffer;
            ts4_destroy_owned_object(v->first);
        } else {
            first = allocate(v, n);
        }
        v->first = first;
        v->last = first + size;
        v->end = first + n;
    }
}

static __inline void entry12_vec_init(Entry12Vec *v)
{
    Entry12 **end_slot = &v->end;
    v->first = 0;
    v->last = 0;
    *end_slot = 0;
}

EntryTable *fn_88624FE8(EntryTable *t)
{
    entry12_vec_init(&t->entries);
    fn_8827FFB8(&t->names);
    t->count = 0;
    t->cursor = 0;
    t->enabled = 1;
    reserve(&t->entries, 128);
    return t;
}
