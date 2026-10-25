#define TS4_ADJUST(object) ((void *)((unsigned char *)(object) - 4))
extern void fn_885B6F90(void *object, int a1);

void fn_885B72C0(void *o, int a1) { fn_885B6F90(TS4_ADJUST(o), a1); }