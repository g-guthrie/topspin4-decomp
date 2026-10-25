#define TS4_ADJUST(object) ((void *)((unsigned char *)(object) - 4))
extern void fn_885B93D0(void *object);

void fn_885B9100(void *o) { fn_885B93D0(TS4_ADJUST(o)); }