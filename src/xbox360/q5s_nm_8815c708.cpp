/* Swing_DLL.xex 0x8815C708: vector<48-byte entry>::_M_insert_overflow (STLport-style grow path).
 * New length old_size + max(old_size, fill_len); allocate, move the prefix, construct fill_len copies of x
 * (one copy through the copy-construct helper, which does its own null test), move the suffix, destroy and free the old block.
 * Matched on /Oc as a C++ member. The `old_size + max(...)` add takes old_size first only with the STLport
 * tag temporaries at the call sites (_TrivialUCopy()/_Movable() per move, __false_type() for the fill):
 * call-site temporaries count as function locals for the operand-order rule (docs/agents/regalloc.md C1). */
extern "C" {
extern void *lbl_88D45B38;
void *ts4_if_call_seq_fn_88883CD0_8860D250(void *heap);
void *fn_88613570(void *alloc, unsigned int size, unsigned int align, void *owner);
}

struct Entry48 { unsigned int w[12]; };

extern "C" {
Entry48 *fn_8815CFA8(const Entry48 *first, const Entry48 *last, Entry48 *dest);
Entry48 *fn_8815D388(Entry48 *dest, unsigned int count, const Entry48 *val);
void ts4_if_call_seq_fn_88159180_8815D328(Entry48 *dest, const Entry48 *val);
void fn_8815DEA0(Entry48 *first, Entry48 *last);
void ts4_destroy_owned_object(void *obj);
}

struct __true_type {};
struct __false_type {};

template <class T> inline const T &ts4_max(const T &a, const T &b) { return a < b ? b : a; }

static inline Entry48 *__uninitialized_move(const Entry48 *first, const Entry48 *last, Entry48 *dest,
                                            const __true_type &, const __false_type &)
{
    return fn_8815CFA8(first, last, dest);
}

static inline Entry48 *__uninitialized_fill_n(Entry48 *dest, unsigned int n, const Entry48 &x, const __false_type &)
{
    return fn_8815D388(dest, n, &x);
}

struct Entry48Vector {
    Entry48 *_M_start;
    Entry48 *_M_finish;
    Entry48 *_M_end_of_storage;

    unsigned int size() const { return (unsigned int)(_M_finish - _M_start); }
    void _M_set(Entry48 *s, Entry48 *f, Entry48 *e) { _M_start = s; _M_finish = f; _M_end_of_storage = e; }
    void _M_insert_overflow(Entry48 *pos, const Entry48 &x, unsigned int fill_len);
};

void Entry48Vector::_M_insert_overflow(Entry48 *pos, const Entry48 &x, unsigned int fill_len)
{
    const unsigned int old_size = size();
    unsigned int len = old_size + ts4_max(old_size, fill_len);
    Entry48 *new_start = 0;
    if (len != 0)
        new_start = (Entry48 *)fn_88613570(lbl_88D45B38 ? ts4_if_call_seq_fn_88883CD0_8860D250(lbl_88D45B38) : 0,
                                       len * sizeof(Entry48), 4, &_M_end_of_storage);
    Entry48 *new_finish = __uninitialized_move(_M_start, pos, new_start, __true_type(), __false_type());
    if (fill_len == 1) {
        ts4_if_call_seq_fn_88159180_8815D328(new_finish, &x);
        ++new_finish;
    } else {
        new_finish = __uninitialized_fill_n(new_finish, fill_len, x, __false_type());
    }
    new_finish = __uninitialized_move(pos, _M_finish, new_finish, __true_type(), __false_type());
    fn_8815DEA0(_M_start, _M_finish);
    ts4_destroy_owned_object(_M_start);
    _M_set(new_start, new_finish, new_start + len);
}
