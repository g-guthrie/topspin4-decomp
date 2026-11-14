/* Swing_DLL.xex 0x881613A0-0x881AD868, executable version 0.0.0.3. */
typedef unsigned char u8;
typedef unsigned int u32;
#ifdef _MSC_VER
extern void *memcpy(void *, const void *, unsigned int);
#else
#include <string.h>
#endif

typedef struct Elem_881613A0 { u8 bytes[68]; } Elem_881613A0;
typedef struct Vec_881613A0 { u32 pad; Elem_881613A0 *end; Elem_881613A0 *capacity; } Vec_881613A0;
extern void fn_8817F148(Vec_881613A0 *v, Elem_881613A0 *where, const Elem_881613A0 *item);

/* Appends a 68-byte record by copy, using the generic insert when the vector is full. */
void ts4_vector_push_back_copy_881613A0(Vec_881613A0 *v, const Elem_881613A0 *item)
{
    if (v->end != v->capacity) {
        if (v->end) {
            memcpy(v->end, item, 68);
        }
        v->end++;
    } else {
        fn_8817F148(v, v->end, item);
    }
}

typedef struct Elem_8817E2E0 { u8 bytes[48]; } Elem_8817E2E0;
typedef struct Vec_8817E2E0 { u32 pad; Elem_8817E2E0 *end; Elem_8817E2E0 *capacity; } Vec_8817E2E0;
extern void fn_8817E7A0(Vec_8817E2E0 *v, Elem_8817E2E0 *where, const Elem_8817E2E0 *item);

/* Appends a 48-byte record by copy, using the generic insert when the vector is full. */
void ts4_vector_push_back_copy_8817E2E0(Vec_8817E2E0 *v, const Elem_8817E2E0 *item)
{
    if (v->end != v->capacity) {
        if (v->end) {
            memcpy(v->end, item, 48);
        }
        v->end++;
    } else {
        fn_8817E7A0(v, v->end, item);
    }
}

typedef struct Elem_881A58D0 { u8 bytes[268]; } Elem_881A58D0;
typedef struct Vec_881A58D0 { u32 pad; Elem_881A58D0 *end; Elem_881A58D0 *capacity; } Vec_881A58D0;
extern void fn_881A5948(Vec_881A58D0 *v, Elem_881A58D0 *where, const Elem_881A58D0 *item);

/* Appends a 268-byte record by copy, using the generic insert when the vector is full. */
void ts4_vector_push_back_copy_881A58D0(Vec_881A58D0 *v, const Elem_881A58D0 *item)
{
    if (v->end != v->capacity) {
        if (v->end) {
            memcpy(v->end, item, 268);
        }
        v->end++;
    } else {
        fn_881A5948(v, v->end, item);
    }
}

typedef struct Elem_881AB090 { u8 bytes[92]; } Elem_881AB090;
typedef struct Vec_881AB090 { u32 pad; Elem_881AB090 *end; Elem_881AB090 *capacity; } Vec_881AB090;
extern void fn_881AB408(Vec_881AB090 *v, Elem_881AB090 *where, const Elem_881AB090 *item);

/* Appends a 92-byte record by copy, using the generic insert when the vector is full. */
void ts4_vector_push_back_copy_881AB090(Vec_881AB090 *v, const Elem_881AB090 *item)
{
    if (v->end != v->capacity) {
        if (v->end) {
            memcpy(v->end, item, 92);
        }
        v->end++;
    } else {
        fn_881AB408(v, v->end, item);
    }
}

typedef struct Elem_881AD868 { u8 bytes[44]; } Elem_881AD868;
typedef struct Vec_881AD868 { u32 pad; Elem_881AD868 *end; Elem_881AD868 *capacity; } Vec_881AD868;
extern void fn_881ADBE8(Vec_881AD868 *v, Elem_881AD868 *where, const Elem_881AD868 *item);

/* Appends a 44-byte record by copy, using the generic insert when the vector is full. */
void ts4_vector_push_back_copy_881AD868(Vec_881AD868 *v, const Elem_881AD868 *item)
{
    if (v->end != v->capacity) {
        if (v->end) {
            memcpy(v->end, item, 44);
        }
        v->end++;
    } else {
        fn_881ADBE8(v, v->end, item);
    }
}
