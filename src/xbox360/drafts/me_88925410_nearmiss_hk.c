/* nearmiss: 2 off (q5s batch 2); the target is subfe r11,r10,r11 / clrlwi r3,r11,24, and ours allocates r9. Tried: a C++ bool member, extern "C" bool, !!, a reference local, and unsigned char/int returns with casts. Only the & 0xff forms stay at 2. Blocker: register choice for the carry temp; likely needs the original Havok inline (hkBool or a similar wrapper type). */
typedef struct Obj { char pad[0x4]; void *ptr; } Obj;
int has_handle_88925410(Obj *o){ return (0 != o->ptr) & 0xff; }
