extern int fn_8832F930(void *p1, void *p2);
extern void fn_883304F8(int p1, void *p2);

void fn_88317D38(void *a, void *b)
{
    int result;
    int buffer;
    result = fn_8832F930(a, &buffer);
    if (result == 0) {
        fn_883304F8(buffer, b);
    }
}