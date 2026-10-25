#define TS4_ADJUST(object) ((void *)((unsigned char *)(object) - 4))
extern void fn_885A0098(void *object, int a1);

void fn_885A0028(void *o, int a1) { fn_885A0098(TS4_ADJUST(o), a1); }