#define TS4_ADJUST(object) ((void *)((ts4_u8 *)(object) - 4))
typedef unsigned char ts4_u8;
extern void fn_885B8DF8(void *object, int a1);

void fn_885B8DF0(void *o, int a1) { fn_885B8DF8(TS4_ADJUST(o), a1); }