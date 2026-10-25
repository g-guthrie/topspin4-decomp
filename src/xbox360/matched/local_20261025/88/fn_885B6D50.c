#define TS4_ADJUST(object) ((void *)((char *)(object) - 4))
extern void fn_885B6DC0(void *object, int a1);

void fn_885B6D50(void *o, int a1) { fn_885B6DC0(TS4_ADJUST(o), a1); }