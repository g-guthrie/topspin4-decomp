/* Swing_DLL.xex 0x8861B800: splits a path into components at separators (88605B58 / 88605AB8) and appends each one, NUL-terminated in a 256-byte stack buffer, to the pool (88280110).
 * /Oc. Two function-scope 256-byte buffers (frame 0x290); the last component's length is `(int)strlen(path) - start` (the clrrwi). */
typedef struct Pool Pool;
unsigned int strlen(const char *s);
void *memcpy(void *dst, const void *src, unsigned int n);
int ts4_find_first_sep_88605AB8(const char *base, int off);
int ts4_find_first_nonsep_88605B58(const char *base, int off);
void ts4_pool_append_cstr_88280110(Pool *self, const char *s);

void fn_8861B800(const char *path, Pool *parts)
{
    char part[256];
    char last[256];
    int start = ts4_find_first_nonsep_88605B58(path, 0);
    while (start != -1) {
        int end = ts4_find_first_sep_88605AB8(path, start + 1);
        if (end == -1) {
            int n = (int)strlen(path) - start;
            memcpy(last, path + start, n);
            last[n] = 0;
            ts4_pool_append_cstr_88280110(parts, last);
            return;
        } else {
            int n = end - start;
            memcpy(part, path + start, n);
            part[n] = 0;
            ts4_pool_append_cstr_88280110(parts, part);
        }
        start = ts4_find_first_nonsep_88605B58(path, end);
    }
}
