#define TS4_ADJUST(object) ((void *)((unsigned char *)(object) - 4))
extern void fn_885B6B10(void *object, int a1);

void fn_885B6D48(void *o, int a1) { fn_885B6B10(TS4_ADJUST(o), a1); }