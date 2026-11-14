/* Swing_DLL.xex 0x88160EB8-0x88220128, executable version 0.0.0.3. */
typedef unsigned char u8;
typedef unsigned int u32;
extern void fn_88161A18(void *v, void *where, const void *item);
extern void fn_88162688(void *v, void *where, const void *item);
extern void fn_88166938(void *dst, const void *src);
extern void fn_88166AF8(void *dst, const void *src);
extern void fn_88214708(void *v, void *where, const void *item);
extern void fn_88225880(void *v, void *where, const void *item);
extern void fn_88225990(void *v, void *where, const void *item);
extern void fn_8822A4A0(void *dst, const void *src);
extern void ts4_call_seq_u32_off0_88212FD0(void *dst, const void *src);

typedef struct Elem_88160EB8 { u8 bytes[48]; } Elem_88160EB8;
typedef struct Vec_88160EB8 { u32 pad; Elem_88160EB8 *end; Elem_88160EB8 *capacity; } Vec_88160EB8;

/* Appends a copy of item, using the generic insert when the vector is full. */
void ts4_vector_push_back_construct_88160EB8(Vec_88160EB8 *v, const Elem_88160EB8 *item)
{
    if (v->end != v->capacity) {
        if (v->end) {
            fn_88166938(v->end, item);
        }
        v->end++;
    } else {
        fn_88161A18(v, v->end, item);
    }
}

typedef struct Elem_881614C8 { u8 bytes[76]; } Elem_881614C8;
typedef struct Vec_881614C8 { u32 pad; Elem_881614C8 *end; Elem_881614C8 *capacity; } Vec_881614C8;

/* Appends a copy of item, using the generic insert when the vector is full. */
void ts4_vector_push_back_construct_881614C8(Vec_881614C8 *v, const Elem_881614C8 *item)
{
    if (v->end != v->capacity) {
        if (v->end) {
            fn_88166AF8(v->end, item);
        }
        v->end++;
    } else {
        fn_88162688(v, v->end, item);
    }
}

typedef struct Elem_88213DB0 { u8 bytes[92]; } Elem_88213DB0;
typedef struct Vec_88213DB0 { u32 pad; Elem_88213DB0 *end; Elem_88213DB0 *capacity; } Vec_88213DB0;

/* Appends a copy of item, using the generic insert when the vector is full. */
void ts4_vector_push_back_construct_88213DB0(Vec_88213DB0 *v, const Elem_88213DB0 *item)
{
    if (v->end != v->capacity) {
        if (v->end) {
            ts4_call_seq_u32_off0_88212FD0(v->end, item);
        }
        v->end++;
    } else {
        fn_88214708(v, v->end, item);
    }
}

typedef struct Elem_88220060 { u8 bytes[268]; } Elem_88220060;
typedef struct Vec_88220060 { u32 pad; Elem_88220060 *end; u32 pad2; Elem_88220060 *capacity; } Vec_88220060;

/* Appends a copy of item, using the generic insert when the vector is full. */
void ts4_vector_push_back_construct_88220060(Vec_88220060 *v, const Elem_88220060 *item)
{
    if (v->end != v->capacity) {
        if (v->end) {
            fn_8822A4A0(v->end, item);
        }
        v->end++;
    } else {
        fn_88225880(v, v->end, item);
    }
}

typedef struct Elem_88220128 { u8 bytes[76]; } Elem_88220128;
typedef struct Vec_88220128 { u32 pad; Elem_88220128 *end; u32 pad2; Elem_88220128 *capacity; } Vec_88220128;

/* Appends a copy of item, using the generic insert when the vector is full. */
void ts4_vector_push_back_construct_88220128(Vec_88220128 *v, const Elem_88220128 *item)
{
    if (v->end != v->capacity) {
        if (v->end) {
            fn_88166AF8(v->end, item);
        }
        v->end++;
    } else {
        fn_88225990(v, v->end, item);
    }
}
