#define TS4_ADJUST(object) ((void *)((unsigned char *)(object) - 4))
extern void fn_885B71C0(void *object, int a1);

void fn_885B72D0(void *o, int a1) { fn_885B71C0(TS4_ADJUST(o), a1); }