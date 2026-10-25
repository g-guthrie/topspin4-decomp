extern int fn_8832BFC0(void *p1, void *p2);
extern void fn_8832CC38(int p1, void *p2);

void fn_88318420(void *a, void *b)
{
    int result;
    int buffer;
    result = fn_8832BFC0(a, &buffer);
    if (result == 0) {
        fn_8832CC38(buffer, b);
    }
}