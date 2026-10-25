#define TS4_ADJUST(object) ((void *)((char *)(object) - 4))
extern void fn_885B89A0(void *object, int a1);

void fn_885B8A48(void *o, int a1) { fn_885B89A0(TS4_ADJUST(o), a1); }