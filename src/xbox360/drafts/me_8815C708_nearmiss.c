/* Swing_DLL.xex 0x8815C708: vector<48-byte Mat/string entry>::_Insert_n grow path (sibling of 8815C0B0).
 * /Oc near miss, 1 off: add. operand order of size + max(size, n). The single-element construct helper (fn_8815D328) does its own null test. */
typedef struct Entry48 { unsigned int w[12]; } Entry;
typedef struct EntryVec { Entry *first; Entry *last; Entry *end; } EntryVec;
extern void *lbl_88D45B38;
void *ts4_if_call_seq_fn_88883CD0_8860D250(void *heap);
void *fn_88613570(void *alloc, unsigned int size, unsigned int align, void *owner);
Entry *fn_8815CFA8(const Entry *first, const Entry *last, Entry *dest);
Entry *fn_8815D388(Entry *dest, unsigned int count, const Entry *val);
void ts4_if_call_seq_fn_88159180_8815D328(Entry *dest, const Entry *val);
void fn_8815DEA0(Entry *first, Entry *last);
void ts4_destroy_owned_object(void *obj);

static __inline const unsigned int *max_ref(const unsigned int *a, const unsigned int *b)
{
    return *a < *b ? b : a;
}

void fn_8815C708(EntryVec *v, Entry *where, const Entry *val, unsigned int n)
{
    unsigned int size = v->last - v->first;
    unsigned int len = size + *max_ref(&size, &n);
    Entry *start = 0;
    Entry *finish;
    if (len != 0)
        start = (Entry *)fn_88613570(lbl_88D45B38 ? ts4_if_call_seq_fn_88883CD0_8860D250(lbl_88D45B38) : 0, len * sizeof(Entry), 4, &v->end);
    finish = fn_8815CFA8(v->first, where, start);
    if (n == 1) {
        ts4_if_call_seq_fn_88159180_8815D328(finish, val);
        ++finish;
    } else {
        finish = fn_8815D388(finish, n, val);
    }
    finish = fn_8815CFA8(where, v->last, finish);
    fn_8815DEA0(v->first, v->last);
    ts4_destroy_owned_object(v->first);
    v->first = start;
    v->last = finish;
    v->end = start + len;
}
