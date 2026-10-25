extern int fn_88322CA8(void *p1, void *p2);
extern void fn_883252E8(int p1, void *p2);

void fn_88317420(void *a, void *b)
{
    int result;
    int buffer;
    result = fn_88322CA8(a, &buffer);
    if (result == 0) {
        fn_883252E8(buffer, b);
    }
}