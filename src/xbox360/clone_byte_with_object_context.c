typedef unsigned char u8;
typedef void *(*Ts4Clone)(void *owner, void *source, void *data, int mode);

typedef struct Ts4CloneVtable {
    unsigned char padding[0x28];
    Ts4Clone clone;
} Ts4CloneVtable;

typedef struct Ts4CloneObject {
    Ts4CloneVtable *vtable;
} Ts4CloneObject;

typedef struct Ts4CloneWrapper {
    Ts4CloneObject *object;
    void *data;
} Ts4CloneWrapper;

/* Swing_DLL.xex 0x88153620. */
void ts4_clone_byte_with_object_context(Ts4CloneWrapper *wrapper, const u8 *value)
{
    Ts4CloneObject *object = wrapper->object;
    u8 *result = object->vtable->clone(object, wrapper, wrapper->data, 1);

    *result = *value;
}
