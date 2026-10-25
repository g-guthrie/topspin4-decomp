#define TS4_ADJUST(object) ((void *)((unsigned char *)(object) - 4))
extern void fn_88598F70(void *object, int a1);

void fn_8859A0E8(void *o, int a1) { fn_88598F70(TS4_ADJUST(o), a1); }