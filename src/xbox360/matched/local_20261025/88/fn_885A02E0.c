#define TS4_ADJUST(object) ((void *)((char *)(object) - 4))
extern void fn_885A02B0(void *object, int a1);

void fn_885A02E0(void *o, int a1) { fn_885A02B0(TS4_ADJUST(o), a1); }