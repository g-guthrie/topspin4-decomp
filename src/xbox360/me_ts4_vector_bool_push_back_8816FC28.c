/* Swing_DLL.xex 0x8816FC28: std::vector<bool>::push_back: sets or clears the bit at end() and advances it, or calls insert(end(), value) (fn_881700D0) when the storage is full.
 * /Oc. 'VbIter *it = &v->last' before the capacity test; the insert iterator is passed by address from a stack copy. */
typedef struct VbIter { unsigned int *word; unsigned int bit; } VbIter;
typedef struct VecBool {
    unsigned char pad[8];
    VbIter last;               /* 0x8 */
    unsigned int *storage_end; /* 0x10 */
} VecBool;

void fn_881700D0(VecBool *v, const VbIter *where, unsigned char value);

void fn_8816FC28(VecBool *v, unsigned char value)
{
    VbIter *it = &v->last;
    if (it->word != v->storage_end) {
        unsigned int mask = 1u << it->bit;
        if (value) *it->word |= mask;
        else *it->word &= ~mask;
        if (it->bit++ == 31) {
            it->bit = 0;
            ++it->word;
        }
    } else {
        VbIter where = v->last;
        fn_881700D0(v, &where, value);
    }
}
