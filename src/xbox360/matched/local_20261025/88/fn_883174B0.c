extern int fn_88322CA8(void *p1, void *p2);
extern void fn_88325810(int p1, void *p2);

void fn_883174B0(void *a, void *b)
{
    int result;
    int buffer;
    result = fn_88322CA8(a, &buffer);
    if (result == 0) {
        fn_88325810(buffer, b);
    }
}