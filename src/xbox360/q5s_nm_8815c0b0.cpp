/* Swing_DLL.xex 0x8815C0B0: vector<32-byte entry>::_M_insert_overflow (STLport-style grow path).
 * New length old_size + max(old_size, fill_len); allocate, move the prefix, construct fill_len copies of x
 * (one copy through the null-tested copy constructor), move the suffix, destroy and free the old block.
 * Matched on /Oc as a C++ member. The `old_size + max(...)` add takes old_size first only with the STLport
 * tag temporaries at the call sites (_TrivialUCopy()/_Movable() per move, __false_type() for the fill):
 * call-site temporaries count as function locals for the operand-order rule (docs/agents/regalloc.md C1). */
extern "C" {
extern void *lbl_88D45B38;
void *ts4_if_call_seq_fn_88883CD0_8860D250(void *heap);
void *fn_88613570(void *alloc, unsigned int size, unsigned int align, void *owner);
}

struct Entry32 { unsigned int w[8]; };

extern "C" {
Entry32 *fn_8815CAD0(const Entry32 *first, const Entry32 *last, Entry32 *dest);
Entry32 *fn_8815D230(Entry32 *dest, unsigned int count, const Entry32 *val);
void ts4_call_seq_u32_off0_8815BBD0(Entry32 *dest, const Entry32 *val);
void fn_8815DB40(Entry32 *first, Entry32 *last);
void ts4_destroy_owned_object(void *obj);
}

struct __true_type {};
struct __false_type {};

template <class T> inline const T &ts4_max(const T &a, const T &b) { return a < b ? b : a; }

static inline Entry32 *__uninitialized_move(const Entry32 *first, const Entry32 *last, Entry32 *dest,
                                            const __true_type &, const __false_type &)
{
    return fn_8815CAD0(first, last, dest);
}

static inline Entry32 *__uninitialized_fill_n(Entry32 *dest, unsigned int n, const Entry32 &x, const __false_type &)
{
    return fn_8815D230(dest, n, &x);
}

struct Entry32Vector {
    Entry32 *_M_start;
    Entry32 *_M_finish;
    Entry32 *_M_end_of_storage;

    unsigned int size() const { return (unsigned int)(_M_finish - _M_start); }
    void _M_set(Entry32 *s, Entry32 *f, Entry32 *e) { _M_start = s; _M_finish = f; _M_end_of_storage = e; }
    void _M_insert_overflow(Entry32 *pos, const Entry32 &x, unsigned int fill_len);
};

void Entry32Vector::_M_insert_overflow(Entry32 *pos, const Entry32 &x, unsigned int fill_len)
{
    const unsigned int old_size = size();
    unsigned int len = old_size + ts4_max(old_size, fill_len);
    Entry32 *new_start = 0;
    if (len != 0)
        new_start = (Entry32 *)fn_88613570(lbl_88D45B38 ? ts4_if_call_seq_fn_88883CD0_8860D250(lbl_88D45B38) : 0,
                                       len * sizeof(Entry32), 4, &_M_end_of_storage);
    Entry32 *new_finish = __uninitialized_move(_M_start, pos, new_start, __true_type(), __false_type());
    if (fill_len == 1) {
        if (new_finish)
            ts4_call_seq_u32_off0_8815BBD0(new_finish, &x);
        ++new_finish;
    } else {
        new_finish = __uninitialized_fill_n(new_finish, fill_len, x, __false_type());
    }
    new_finish = __uninitialized_move(pos, _M_finish, new_finish, __true_type(), __false_type());
    fn_8815DB40(_M_start, _M_finish);
    ts4_destroy_owned_object(_M_start);
    _M_set(new_start, new_finish, new_start + len);
}
