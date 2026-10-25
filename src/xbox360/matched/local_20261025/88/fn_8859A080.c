#define TS4_ADJUST(object) ((void *)((ts4_u8 *)(object) - 4))
typedef unsigned char ts4_u8;
extern void fn_88599FD0(void *object, int a1);

void fn_8859A080(void *o, int a1) { fn_88599FD0(TS4_ADJUST(o), a1); }