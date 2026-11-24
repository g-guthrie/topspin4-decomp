/* Swing_DLL.xex 0x8815C0B0: vector<32-byte keyed string pair>::_Insert_n grow path: new length size + max(size, n), copy the prefix, construct n copies, copy the suffix, destroy and free the old block.
 * /Oc near miss, 1 off: add. operand order of size + max(size, n) (target size first). C++ refs, a size() inline and statement splits all give max first. Sibling 8815C708 (48-byte elements) has the same issue. */
typedef struct Entry32 { unsigned int w[8]; } Entry;
typedef struct EntryVec { Entry *first; Entry *last; Entry *end; } EntryVec;
extern void *lbl_88D45B38;
void *ts4_if_call_seq_fn_88883CD0_8860D250(void *heap);
void *fn_88613570(void *alloc, unsigned int size, unsigned int align, void *owner);
Entry *fn_8815CAD0(const Entry *first, const Entry *last, Entry *dest);
Entry *fn_8815D230(Entry *dest, unsigned int count, const Entry *val);
void ts4_call_seq_u32_off0_8815BBD0(Entry *dest, const Entry *val);
void fn_8815DB40(Entry *first, Entry *last);
void ts4_destroy_owned_object(void *obj);

static __inline const unsigned int *max_ref(const unsigned int *a, const unsigned int *b)
{
    return *a < *b ? b : a;
}

void fn_8815C0B0(EntryVec *v, Entry *where, const Entry *val, unsigned int n)
{
    unsigned int size = v->last - v->first;
    unsigned int len = size + *max_ref(&size, &n);
    Entry *start = 0;
    Entry *finish;
    if (len != 0)
        start = (Entry *)fn_88613570(lbl_88D45B38 ? ts4_if_call_seq_fn_88883CD0_8860D250(lbl_88D45B38) : 0, len * sizeof(Entry), 4, &v->end);
    finish = fn_8815CAD0(v->first, where, start);
    if (n == 1) {
        if (finish) ts4_call_seq_u32_off0_8815BBD0(finish, val);
        ++finish;
    } else {
        finish = fn_8815D230(finish, n, val);
    }
    finish = fn_8815CAD0(where, v->last, finish);
    fn_8815DB40(v->first, v->last);
    ts4_destroy_owned_object(v->first);
    v->first = start;
    v->last = finish;
    v->end = start + len;
}
