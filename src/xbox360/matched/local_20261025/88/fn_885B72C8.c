#define TS4_ADJUST(object) ((void *)((unsigned char *)(object) - 4))
extern void fn_885B7008(void *object, int a1);

void fn_885B72C8(void *o, int a1) { fn_885B7008(TS4_ADJUST(o), a1); }