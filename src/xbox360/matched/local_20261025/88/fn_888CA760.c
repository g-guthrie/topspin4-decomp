extern void ts4_object_finalize(int);

void fn_888CA760(unsigned char *a)
{
    unsigned char *ptr = a;
    ptr[56] = 0;
    ts4_object_finalize((int)(a + 32));
}