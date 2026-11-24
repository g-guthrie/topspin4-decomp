/* Swing_DLL.xex 0x8816BA20: Equality of a {first,last} string and *p (a c_str pointer) through the inline compare of 882348F0.
 * Leaf; returns compare == 0 as a byte. */
#pragma intrinsic(memcmp, strlen)
int memcmp(const void *, const void *, unsigned int);
unsigned int strlen(const char *);
typedef struct String { char *first; char *last; } String;
static __inline const int *min_ref(const int *a, const int *b) { return *a < *b ? a : b; }
static __inline int string_compare(const String *s, const char *p)
{
    int n2 = strlen(p);
    int n1 = s->last - s->first;
    int r = memcmp(s->first, p, *min_ref(&n2, &n1));
    if (r != 0) return r;
    if (n1 < n2) return -1;
    return n2 < n1;
}
unsigned char fn_8816BA20(const String *s, const char *const *p)
{
    return string_compare(s, *p) == 0;
}
