#define TS4_ADJUST(object) ((void *)((unsigned char *)(object) - 4))
extern void fn_885A0290(void *object, int a1);

void fn_885A0040(void *o, int a1) { fn_885A0290(TS4_ADJUST(o), a1); }