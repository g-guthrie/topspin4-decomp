/* Family FAM2: singleton service constructors (Swing_DLL.xex 0x8861DD58..0x888CCF98).
   The constructors run the service base constructor (fn_88617D88), install the class vtable, clear
   the three words of the embedded vector at VEC and publish the object in its INSTANCE global. */
typedef unsigned int u32;
extern void fn_88617D88(void *self);
extern char lbl_880F8D00[], lbl_880F85DC[], lbl_880EF370[], lbl_880E3AB4[], lbl_880E0728[], lbl_880DB370[];
extern void *lbl_88D45B4C, *lbl_88D45B30, *lbl_88D45A64, *lbl_88D459FC, *lbl_88D459D8, *lbl_88D4592C;

typedef struct Ts4SvcVec { u32 first, last, end; } Ts4SvcVec;
static __inline Ts4SvcVec *vec_init(Ts4SvcVec *v) { v->first = 0; v->last = 0; v->end = 0; return v; }

#define TS4_SINGLETON_SERVICE_CTOR(A, VT, VEC, INSTANCE) \
void *ts4_singleton_service_ctor_##A(void **self); \
void *ts4_singleton_service_ctor_##A(void **self) \
{ \
    fn_88617D88(self); \
    *(void *volatile *)self = VT; \
    vec_init((Ts4SvcVec *)((char *)self + VEC)); \
    INSTANCE = self; \
    return self; \
}

/* Same with the vtable installed after the vector is cleared. */
#define TS4_SINGLETON_SERVICE_CTOR_PLAIN(A, VT, VEC, INSTANCE) \
void *ts4_singleton_service_ctor_##A(void **self); \
void *ts4_singleton_service_ctor_##A(void **self) \
{ \
    fn_88617D88(self); \
    vec_init((Ts4SvcVec *)((char *)self + VEC)); \
    self[0] = VT; \
    INSTANCE = self; \
    return self; \
}

/* Plain derived-service constructors: base constructor, cleared vector at
   VEC, class vtable; no singleton registration. */
#define TS4_SERVICE_CTOR_VEC(A, BASE, VT, VEC) \
extern void BASE(void *self); \
extern char VT[]; \
void *ts4_service_ctor_vec_##A(void **self); \
void *ts4_service_ctor_vec_##A(void **self) \
{ \
    BASE(self); \
    vec_init((Ts4SvcVec *)((char *)self + VEC)); \
    self[0] = VT; \
    return self; \
}

/* Constructors that register the new service in the global service table
   (lbl_88D45B1C) at SLOT. */
extern char *lbl_88D45B1C;

/* Constructors holding a null handle {0, 0xFFFFF, 0} at H. */
typedef struct Ts4SvcHandle { u32 obj, id, extra; } Ts4SvcHandle;
#define TS4_SERVICE_CTOR_HANDLE(A, BASE, VT, H) \
extern void BASE(void *self); \
extern char VT[]; \
void *ts4_service_ctor_handle_##A(void **self); \
void *ts4_service_ctor_handle_##A(void **self) \
{ \
    Ts4SvcHandle *h = (Ts4SvcHandle *)((char *)self + H); \
    BASE(self); \
    self[0] = VT; \
    h->obj = 0; \
    h->extra = 0; \
    h->id = 0xFFFFF; \
    return self; \
}

/* Same with the vtable installed last. */
#define TS4_SERVICE_CTOR_HANDLE_LATE(A, BASE, VT, H) \
extern void BASE(void *self); \
extern char VT[]; \
void *ts4_service_ctor_handle_##A(void **self); \
void *ts4_service_ctor_handle_##A(void **self) \
{ \
    Ts4SvcHandle *h = (Ts4SvcHandle *)((char *)self + H); \
    BASE(self); \
    h->obj = 0; \
    h->extra = 0; \
    h->id = 0xFFFFF; \
    self[0] = VT; \
    return self; \
}

/* Swing_DLL.xex addresses */
TS4_SINGLETON_SERVICE_CTOR(8861DD58, lbl_880F8D00, 0x1c, lbl_88D45B4C)
TS4_SINGLETON_SERVICE_CTOR(88621250, lbl_880F85DC, 0x1c, lbl_88D45B30)
TS4_SINGLETON_SERVICE_CTOR_PLAIN(8878BE98, lbl_880EF370, 0x1c, lbl_88D45A64)
TS4_SINGLETON_SERVICE_CTOR(888006F0, lbl_880E3AB4, 0x1c, lbl_88D459FC)
TS4_SINGLETON_SERVICE_CTOR(888662C8, lbl_880E0728, 0x24, lbl_88D459D8)
TS4_SINGLETON_SERVICE_CTOR(888CCF98, lbl_880DB370, 0x1c, lbl_88D4592C)
TS4_SERVICE_CTOR_VEC(88622D18, fn_8861B128, lbl_880F7B80, 0x24)
TS4_SERVICE_CTOR_VEC(886258A0, fn_8861E530, lbl_880F8C78, 0x74)
TS4_SERVICE_CTOR_VEC(88639080, fn_88617D88, lbl_880F6400, 0x1c)
TS4_SERVICE_CTOR_VEC(887CBE90, fn_88617D88, lbl_880EA38C, 0x1c)
TS4_SERVICE_CTOR_HANDLE(8861D130, fn_88617D88, lbl_880F7C54, 0x1c)
TS4_SERVICE_CTOR_HANDLE_LATE(886256D0, fn_88617D88, lbl_880F8DA0, 0x1c)
