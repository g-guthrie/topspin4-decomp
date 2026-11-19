typedef struct Obj { char pad[0x9c]; void *ptr; } Obj;
int has_handle_8899CFF0(Obj *o){ return 0 != o->ptr; }
