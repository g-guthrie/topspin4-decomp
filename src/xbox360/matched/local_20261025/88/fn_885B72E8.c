#define TS4_ADJUST(object) ((void *)((unsigned char *)(object) - 4))
extern void fn_885B73E8(void *object, int a1);

void fn_885B72E8(void *o, int a1) { fn_885B73E8(TS4_ADJUST(o), a1); }