/* Swing_DLL.xex 0x881B4590 ts4_object_finalize: empties the byte vector at +0 (erase(begin, end) through the fn_88562DC0 memmove copy idiom).
 * /Oc; same template as 88176A28 in cw4_core_a.c. Name kept from symbols.txt (callers use it). */
typedef struct ByteVec { char *first; char *last; } ByteVec;
void *fn_88562DC0(void *dst, const void *src, unsigned int n);

static __forceinline char *copy_bytes(char *first, char *last, char *dest)
{
    if (first == last) {
        return dest;
    } else {
        unsigned int n = (unsigned int)(last - first);
        dest = (char *)fn_88562DC0(dest, first, n);
        return dest + n;
    }
}

void ts4_object_finalize(ByteVec *v)
{
    v->last = copy_bytes(v->last, v->last, v->first);
}
