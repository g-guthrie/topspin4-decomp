extern int fn_8832F930(void *p1, void *p2);
extern void fn_88330258(int p1, void *p2);

void fn_88317E20(void *a, void *b)
{
    int result;
    int buffer;
    result = fn_8832F930(a, &buffer);
    if (result == 0) {
        fn_88330258(buffer, b);
    }
}