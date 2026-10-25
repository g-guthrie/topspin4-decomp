#define TS4_ADJUST(object) ((void *)((char *)(object) - 4))
extern void fn_8859CC38(void *object, int a1);

void fn_8859CBB8(void *o, int a1) { fn_8859CC38(TS4_ADJUST(o), a1); }