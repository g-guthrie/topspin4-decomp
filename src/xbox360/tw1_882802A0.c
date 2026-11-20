/* Swing_DLL.xex 0x882802A0: append one u32 to a vector at +0x1c, generic insert when full */
typedef unsigned int u32;
extern void ts4_vector_realloc_insert_8817F4E8(void *vec, void *where, void *item, u32 count);

typedef struct VecU32 { u32 *begin; u32 *end; u32 *capacity; } VecU32;
typedef struct VecU32Holder { u32 pad[7]; VecU32 vec; } VecU32Holder;

void ts4_vector_push_back_u32_882802A0(VecU32Holder *self, u32 value)
{
    VecU32 *v = &self->vec;
    if (v->end != v->capacity) {
        if (v->end) {
            *v->end = value;
        }
        v->end++;
        return;
    }
    ts4_vector_realloc_insert_8817F4E8(v, v->end, &value, 1);
}
