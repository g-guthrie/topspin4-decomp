extern int fn_88309DB8(void *p1, void *p2);
extern void fn_8830B178(int p1, void *p2);

void fn_88308C80(void *a, void *b)
{
    int result;
    int buffer;
    result = fn_88309DB8(a, &buffer);
    if (result == 0) {
        fn_8830B178(buffer, b);
    }
}