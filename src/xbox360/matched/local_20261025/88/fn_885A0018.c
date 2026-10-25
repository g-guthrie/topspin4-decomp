#define TS4_ADJUST(object) ((void *)((char *)(object) - 4))
extern void fn_885A0298(void *object, int a1);

void fn_885A0018(void *o, int a1) { fn_885A0298(TS4_ADJUST(o), a1); }