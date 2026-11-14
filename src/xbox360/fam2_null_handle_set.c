/* Family FAM2: typed value setters through a handle-resolved slot (Swing_DLL.xex 0x881BBE70..0x881BBF98).
   Each resolves the value slot of OBJ with the null handle {0, 0xFFFFF, 0} (ts4_if_call_seq_fn_8892EE88_8817F5E0, or
   ts4_if_call_seq_fn_8892EE88_88165000 with an extra 0) and, when a slot comes back, copies *src of the given type into it.
   Always returns 1. */
typedef unsigned int u32;
typedef unsigned char u8;
typedef struct Ts4Handle12 { u32 a, b, c; } Ts4Handle12;
extern void *ts4_if_call_seq_fn_8892EE88_8817F5E0(void *obj, Ts4Handle12 h);
extern void *ts4_if_call_seq_fn_8892EE88_88165000(void *obj, Ts4Handle12 h, u32 z);

#define TS4_NULL_HANDLE_SET(A, T) \
u32 ts4_null_handle_set_##A(void *obj, const T *src); \
u32 ts4_null_handle_set_##A(void *obj, const T *src) \
{ \
    Ts4Handle12 h; \
    T *slot; \
    h.a = 0; \
    h.b = 0xFFFFF; \
    h.c = 0; \
    slot = (T *)ts4_if_call_seq_fn_8892EE88_8817F5E0(obj, h); \
    if (slot) \
        *slot = *src; \
    return 1; \
}

#define TS4_NULL_HANDLE_SET_EX(A, T) \
u32 ts4_null_handle_set_ex_##A(void *obj, const T *src); \
u32 ts4_null_handle_set_ex_##A(void *obj, const T *src) \
{ \
    Ts4Handle12 h; \
    T *slot; \
    h.a = 0; \
    h.b = 0xFFFFF; \
    h.c = 0; \
    slot = (T *)ts4_if_call_seq_fn_8892EE88_88165000(obj, h, 0); \
    if (slot) \
        *slot = *src; \
    return 1; \
}

/* Swing_DLL.xex addresses */
TS4_NULL_HANDLE_SET(881BBE70, u8)
TS4_NULL_HANDLE_SET(881BBF38, float)
TS4_NULL_HANDLE_SET(881BBF98, u32)
TS4_NULL_HANDLE_SET_EX(881BBED0, u32)
