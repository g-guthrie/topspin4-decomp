typedef unsigned char ts4_u8;
#define TS4_ADJUST(object) ((void *)((ts4_u8 *)(object) - 4))
extern void fn_8859EA70(void *object, int a1);

void fn_8859EA00(void *o, int a1) { fn_8859EA70(TS4_ADJUST(o), a1); }