#define TS4_ADJUST(object) ((void *)((unsigned char *)(object) - 4))
extern void fn_885B7158(void *object);

void fn_885B72D8(void *o) { fn_885B7158(TS4_ADJUST(o)); }