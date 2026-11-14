/* Loader_DLL.xex 0x833CD390-0x833CD6B8, executable version 0.0.0.3. */

typedef void (*ts4l_gcopy_fn)(void *dst, unsigned int a, unsigned int b, unsigned int n);

extern ts4l_gcopy_fn lbl_83542B2C;

#define COPY(p, n) lbl_83542B2C((p), a, b, (n))

void ts4l_copy_strided_833CD390(void *unused, unsigned int *p, unsigned char kind, unsigned int a, unsigned int b)
{
    (void)unused;
    switch (kind) {
    case 1: COPY(p + 3 * a, 4); break;
    case 2: COPY(p + 2 * a, 4); break;
    case 3: COPY(p + 2 * a, 8); break;
    case 4: COPY(p + a, 4); break;
    case 5: COPY(p + a, 4); COPY(p + 3 * a, 4); break;
    case 6: COPY(p + a, 8); break;
    case 7: COPY(p + a, 12); break;
    case 8: COPY(p, 4); break;
    case 9: COPY(p, 4); COPY(p + 3 * a, 4); break;
    case 10: COPY(p, 4); COPY(p + 2 * a, 4); break;
    case 11: COPY(p, 4); COPY(p + 2 * a, 8); break;
    case 12: COPY(p, 8); break;
    case 13: COPY(p, 8); COPY(p + 3 * a, 4); break;
    case 14: COPY(p, 12); break;
    case 15: COPY(p, 16); break;
    default: break;
    }
}
