extern int fn_8832F930(void *p1, void *p2);
extern void fn_8832FE00(int p1, void *p2);

void fn_88317C68(void *a, void *b)
{
    int result;
    int buffer;
    result = fn_8832F930(a, &buffer);
    if (result == 0) {
        fn_8832FE00(buffer, b);
    }
}