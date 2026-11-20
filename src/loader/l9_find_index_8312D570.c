/* Loader_DLL.xex 0x8312D570-0x83143938, executable version 0.0.0.3. */

typedef struct ts4l_u32_vec_a {
    unsigned *data;
    int count;
} ts4l_u32_vec_a;

typedef struct ts4l_u32_vec_b {
    unsigned *data;
    int reserved;
    int count;
} ts4l_u32_vec_b;

/* Linear search of a 32-bit value array; returns the index or -1. */
int ts4l_u32_vec_find_8312D570(ts4l_u32_vec_a *v, unsigned *key)
{
    int i;
    for (i = 0; i < v->count; i++) {
        if (v->data[i] == *key) {
            return i;
        }
    }
    return -1;
}

int ts4l_u32_vec_find_831438F8(ts4l_u32_vec_b *v, unsigned *key)
{
    int i;
    for (i = 0; i < v->count; i++) {
        if (v->data[i] == *key) {
            return i;
        }
    }
    return -1;
}
