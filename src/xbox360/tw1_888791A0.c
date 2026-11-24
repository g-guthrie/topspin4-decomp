/* Swing_DLL.xex 0x888791A0: if field@0x10 != 0, tail-call fn_8846ACB0(field, a1, 1) */
extern void fn_8846ACB0(char *a0, int a1, int a2);

void ts4_call_if_field1c_888791A0(char *p, int a1)
{
    int v = *(int *)(p + 0x10);
    if (v != 0) {
        fn_8846ACB0((char *)(long)v, a1, 1);
    }
}
