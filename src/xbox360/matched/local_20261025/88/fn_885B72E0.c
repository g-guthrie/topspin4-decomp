#define TS4_ADJUST(object) ((void *)((char *)(object) - 4))
extern void fn_885B70F0(void *object, int a1);

void fn_885B72E0(void *o, int a1) { fn_885B70F0(TS4_ADJUST(o), a1); }