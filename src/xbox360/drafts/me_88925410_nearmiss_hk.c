typedef struct Obj { char pad[0x4]; void *ptr; } Obj;
int has_handle_88925410(Obj *o){ return (0 != o->ptr) & 0xff; }
