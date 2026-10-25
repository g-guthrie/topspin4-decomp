typedef unsigned char ts4_u8;
#define TS4_ADJUST(object) ((void *)((ts4_u8 *)(object) - 4))
extern void fn_885B6C50(void *object, int a1);

void fn_885B6D40(void *o, int a1) { fn_885B6C50(TS4_ADJUST(o), a1); }