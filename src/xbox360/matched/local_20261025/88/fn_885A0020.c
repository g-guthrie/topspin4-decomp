typedef unsigned char ts4_u8;
#define TS4_ADJUST(object) ((void *)((ts4_u8 *)(object) - 4))
extern void fn_885A02A0(void *object, int a1);

void fn_885A0020(void *o, int a1) { fn_885A02A0(TS4_ADJUST(o), a1); }