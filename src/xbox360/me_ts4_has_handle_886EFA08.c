typedef struct Obj { char pad[0x38]; void *handle; } Obj;
int has_handle_886EFA08(Obj *o){ return 0 != o->handle; }
