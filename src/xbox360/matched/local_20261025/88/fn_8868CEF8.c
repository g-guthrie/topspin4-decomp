extern void fn_881B9148(void *p);

void fn_8868CEF8(unsigned char *ptr)
{
    unsigned char *arg = ptr + 0x10;
    ptr[8] = 0;
    fn_881B9148(arg);
    *(unsigned int *)(ptr + 28) = 0;
}