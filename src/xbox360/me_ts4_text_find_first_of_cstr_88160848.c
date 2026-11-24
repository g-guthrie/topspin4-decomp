/* Swing_DLL.xex 0x88160848: string::find_first_of(const char *set): index of the first character that is in set, or -1 (also for an empty string).
 * /Oc. `(int)strlen(set)` gives the clrrwi; the find_first_of inline must end with `return last;` (not `first`) to get the target's mr of last. */
typedef struct Text { char *p; char *last; char *end; } Text;
unsigned int strlen(const char *s);

static __inline const char *find_first_of(const char *first, const char *last, const char *set, const char *set_end)
{
    for (; first != last; ++first) {
        const char *s;
        for (s = set; s != set_end; ++s)
            if (*first == *s)
                return first;
    }
    return last;
}

int fn_88160848(const Text *t, const char *set)
{
    unsigned int n = (int)strlen(set);
    if (t->last - t->p != 0) {
        const char *it = find_first_of(t->p, t->last, set, set + n);
        if (it != t->last)
            return it - t->p;
    }
    return -1;
}
