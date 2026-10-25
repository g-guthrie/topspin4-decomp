extern int fn_88322CA8(void *p1, void *p2);
extern void fn_88328CA0(int p1, void *p2);

void fn_883178C8(void *a, void *b)
{
    int result;
    int buffer;
    result = fn_88322CA8(a, &buffer);
    if (result == 0) {
        fn_88328CA0(buffer, b);
    }
}