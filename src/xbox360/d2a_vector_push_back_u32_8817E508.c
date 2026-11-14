/* Swing_DLL.xex 0x8817E508-0x8817E508, executable version 0.0.0.3. */
typedef unsigned int u32;
extern void fn_8817F4E8(void *vec, void *where, void *item, u32 count);

typedef struct VecU32 { u32 *begin; u32 *end; u32 *capacity; } VecU32;
typedef struct VecU32Holder { u32 pad[0x1d]; VecU32 vec; } VecU32Holder;

/* Appends one value, falling back to the generic insert when the vector is full. */
void ts4_vector_push_back_u32_8817E508(VecU32Holder *self, u32 value)
{
    VecU32 *v = &self->vec;
    if (v->end != v->capacity) {
        if (v->end) {
            *v->end = value;
        }
        v->end++;
        return;
    }
    fn_8817F4E8(v, v->end, &value, 1);
}
