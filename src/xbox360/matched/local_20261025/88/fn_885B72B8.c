#define TS4_ADJUST(object) ((void *)((unsigned char *)(object) - 4))
extern void fn_885B7080(void *object, int a1);

void fn_885B72B8(void *o, int a1) { fn_885B7080(TS4_ADJUST(o), a1); }