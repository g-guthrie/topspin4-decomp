extern void ts4_object_finalize(int);

void fn_88614EE0(unsigned char *a)
{
    unsigned char *ptr = a;
    ptr[148] = 0;
    ts4_object_finalize((int)(a + 136));
}