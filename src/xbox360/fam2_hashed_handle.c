/* Family FAM2: users of the 12-byte hashed handle (Swing_DLL.xex). The handle arrives by value (r4/r5, the
   second register spilled to the stack) and is resolved with fn_88923530(handle.c, handle, type_hash), which
   returns the referenced object. Signature as in d3c_hashed_node_factories_886F9CF8.c. */
typedef unsigned int u32;
typedef unsigned char u8;
typedef struct Ts4Handle12 { u32 a, b, c; } Ts4Handle12;
typedef struct Ts4Obj Ts4Obj;
typedef struct Ts4ObjVt {
    void *s0, *s1, *s2;
    void (*set_target)(Ts4Obj *, void *);       /* +0xc */
    void *s4, *s5, *s6, *s7, *s8, *s9, *s10, *s11;
    void (*set_target2)(Ts4Obj *, void *, int); /* +0x30 */
} Ts4ObjVt;
struct Ts4Obj { Ts4ObjVt *vt; };
typedef struct Ts4Res { char pad[0x1c]; void *service_key; } Ts4Res;
typedef struct Ts4ServiceRef { char pad[0x1c]; void *service; } Ts4ServiceRef;
extern void *fn_88923530(u32 pool, Ts4Handle12 h, u32 hash);
extern void fn_88627EC0(void *object, Ts4Handle12 h);
extern void fn_88628D48(void *object, Ts4Handle12 h);
extern void *ts4_find_service(void *key);
extern void fn_88888F90(void *self, void *target);

/* Resolve the handle and pass the object to the virtual setter at vtable offset SLOT. */
#define TS4_HANDLE_VSET(A, HASH, SLOT) \
void ts4_handle_set_target_##A(Ts4Obj *self, Ts4Handle12 h); \
void ts4_handle_set_target_##A(Ts4Obj *self, Ts4Handle12 h) \
{ \
    void *r = fn_88923530(h.c, h, HASH); \
    (*(void (**)(Ts4Obj *, void *))((char *)self->vt + (SLOT)))(self, r); \
}

/* Resolve the handle and pass the object to virtual slot 12 (+0x30) with a zero flag. */
#define TS4_HANDLE_VSET2(A, HASH) \
void ts4_handle_set_target2_##A(Ts4Obj *self, Ts4Handle12 h); \
void ts4_handle_set_target2_##A(Ts4Obj *self, Ts4Handle12 h) \
{ \
    void *r = fn_88923530(h.c, h, HASH); \
    self->vt->set_target2(self, r, 0); \
}

/* Read the base part, then resolve the handle and look up the service named by the object's +0x1c. */
#define TS4_HANDLE_READ_SERVICE(A, BASE, HASH) \
void ts4_handle_read_service_##A(Ts4ServiceRef *self, Ts4Handle12 h); \
void ts4_handle_read_service_##A(Ts4ServiceRef *self, Ts4Handle12 h) \
{ \
    Ts4Res *r; \
    BASE(self, h); \
    r = (Ts4Res *)fn_88923530(h.c, h, HASH); \
    self->service = ts4_find_service(r->service_key); \
}

/* Read the base part, then resolve the handle and hand the object to CALLEE. */
#define TS4_HANDLE_READ_CALL(A, BASE, HASH, CALLEE) \
void ts4_handle_read_call_##A(void *self, Ts4Handle12 h); \
void ts4_handle_read_call_##A(void *self, Ts4Handle12 h) \
{ \
    void *r; \
    BASE(self, h); \
    r = fn_88923530(h.c, h, HASH); \
    CALLEE(self, r); \
}

/* Resolve the handle and store the address its self-relative first word designates at +8. */
#define TS4_HANDLE_STORE_RELATIVE(A, HASH) \
void ts4_handle_store_relative_##A(char *self, Ts4Handle12 h); \
void ts4_handle_store_relative_##A(char *self, Ts4Handle12 h) \
{ \
    int *r = (int *)fn_88923530(h.c, h, HASH); \
    *(char **)(self + 8) = (char *)r + *r; \
}

/* Swing_DLL.xex addresses */
TS4_HANDLE_VSET(88611708, 0x42E59AD9, 0xc)
TS4_HANDLE_VSET(88612B18, 0xAB6ABB47, 0x28)
TS4_HANDLE_VSET(88612D08, 0x54D3196C, 0x28)
TS4_HANDLE_VSET(88612FC8, 0x53FA9145, 0x28)
TS4_HANDLE_VSET(886130C0, 0x0DF4117B, 0x28)
TS4_HANDLE_VSET(88613180, 0xD11869DE, 0x28)
TS4_HANDLE_VSET(88613A50, 0x8D9F61A4, 0x28)
TS4_HANDLE_VSET(88613AD0, 0xA52FDC6D, 0x28)
TS4_HANDLE_VSET(88614718, 0x0E1A69FB, 0x2c)
TS4_HANDLE_VSET(888C3AD8, 0x967033F7, 0xc)
TS4_HANDLE_VSET(88925428, 0xF35EC927, 0xc)
TS4_HANDLE_VSET2(886148A0, 0xF529BE15)
TS4_HANDLE_READ_SERVICE(88219C20, fn_88627EC0, 0x85EA561D)
TS4_HANDLE_READ_SERVICE(8893D738, fn_88627EC0, 0x210D0583)
TS4_HANDLE_READ_SERVICE(8899B610, fn_88627EC0, 0x210D0583)
TS4_HANDLE_READ_SERVICE(889B13B0, fn_88627EC0, 0x210D0583)
TS4_HANDLE_READ_CALL(88889080, fn_88627EC0, 0xEF231875, fn_88888F90)
TS4_HANDLE_STORE_RELATIVE(88662F10, 0xA4FFC421)
