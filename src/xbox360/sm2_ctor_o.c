/* SM2: derived-object constructors: call the base initializer, install the vtable, clear fields. */
extern void *fn_88617D88(void *p);
extern void *fn_8861B128(void *p);
extern void *fn_8861E530(void *p);
extern void *fn_885E5BC8(void *p);
extern void fn_886CF940(void *p);
extern void fn_881705B0(void *p, int n);
extern char lbl_880F6400[];
extern char lbl_880F7B80[];
extern char lbl_880F8C78[];
extern char lbl_880BD6C8[];

void ts4_init_with_buffer_886D3860(char *p)
{
    fn_886CF940(p);
    *(int *)(p + 0x20) = 0;
    *(int *)(p + 0x24) = 0;
    *(int *)(p + 0x28) = 0;
    p[0x1c] = 0;
    fn_881705B0(p + 0x2c, 0x10);
}
