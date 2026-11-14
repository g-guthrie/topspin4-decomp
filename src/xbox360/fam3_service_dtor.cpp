/* Swing_DLL.xex singleton service destructors with member subobjects (FAM3).
   MSVC 16.00.10224.00 /O2.

   Each service class installs its vtable and clears its instance pointer in
   the destructor body. The compiler then runs the member destructors in
   reverse order (owned objects, heap buffers) and the base destructor.
   Writing the members as real C++ subobjects gives the original schedule,
   where the instance store sits after the first member's null test. */

extern "C" {
void ts4_destroy_owned_object(void *object);
void ts4_if_call_seq_fn_881F04B8_886131F0(void *heap, void *data, int size); /* heap free */
void fn_885651F8(void *data);                       /* free */
void ts4_tsu_cleanup_end(void *object);             /* operator delete */
extern void *lbl_88D45B38;                          /* game heap */
void fn_885E58B0(void *self);
void fn_8860BBD8(void *self);
void fn_8890F1E8(void *self);
void ts4_if_call_seq_lbl_880F21E8_88720080(void *self);
void ts4_if_call_seq_lbl_880F7908_8862C308(void *self);
void ts4_if_call_seq_lbl_880F7EE4_88617D28(void *self);
void ts4_if_call_seq_u32_off7c_881981E0(void *self);
void ts4_if_get_u32_lbl_88C32048_8857A1E0(void *self);
void ts4_loop_call_seq_u32_off4_88282DF0(void *self);
extern char lbl_880391E0[];
extern char lbl_88039C20[];
extern char lbl_88039C68[];
extern char lbl_8809602C[];
extern char lbl_88096058[];
extern char lbl_880BA498[];
extern char lbl_880D19F0[];
extern char lbl_880D4B20[];
extern char lbl_880D50A0[];
extern char lbl_880D50C8[];
extern char lbl_880D5118[];
extern char lbl_880D5140[];
extern char lbl_880D5694[];
extern char lbl_880D5E0C[];
extern char lbl_880D6B70[];
extern char lbl_880D7590[];
extern char lbl_880D75FC[];
extern char lbl_880D7600[];
extern char lbl_880D7604[];
extern char lbl_880DB490[];
extern char lbl_880DB4B8[];
extern char lbl_880DB508[];
extern char lbl_880DB8B4[];
extern char lbl_880DB904[];
extern char lbl_880DB92C[];
extern char lbl_880DBE20[];
extern char lbl_880DCF20[];
extern char lbl_880DD088[];
extern char lbl_880DD640[];
extern char lbl_880DF328[];
extern char lbl_880DF8B0[];
extern char lbl_880E0638[];
extern char lbl_880E165C[];
extern char lbl_880E16D4[];
extern char lbl_880E3710[];
extern char lbl_880E3AB4[];
extern char lbl_880E45B8[];
extern char lbl_880E4BA0[];
extern char lbl_880E7038[];
extern char lbl_880E7070[];
extern char lbl_880E70D8[];
extern char lbl_880EA63C[];
extern char lbl_880EF510[];
extern char lbl_880F2148[];
extern char lbl_880F2810[];
extern char lbl_880F285C[];
extern char lbl_880F2A08[];
extern char lbl_880F3388[];
extern char lbl_880F379C[];
extern char lbl_880F37A0[];
extern char lbl_880F37D0[];
extern char lbl_880F37D4[];
extern char lbl_880F37D8[];
extern char lbl_880F4314[];
extern char lbl_880F444C[];
extern char lbl_880F4850[];
extern char lbl_880F4E2C[];
extern char lbl_880F51C4[];
extern char lbl_880F7B28[];
extern char lbl_880F7C94[];
extern char lbl_880F7DEC[];
extern char lbl_880F7E00[];
extern char lbl_880F7E14[];
extern char lbl_880F7F90[];
extern char lbl_880F85DC[];
extern char lbl_880F9018[];
}

static void *g_ts4_tsu_notification_object; /* instance pointer */
static void *lbl_88D45874; /* instance pointer */
static void *lbl_88D45894; /* instance pointer */
static void *lbl_88D45898; /* instance pointer */
static void *lbl_88D458CC; /* instance pointer */
static void *lbl_88D458D0; /* instance pointer */
static void *lbl_88D458F8; /* instance pointer */
static void *lbl_88D45930; /* instance pointer */
static void *lbl_88D45940; /* instance pointer */
static void *lbl_88D4594C; /* instance pointer */
static void *lbl_88D45950; /* instance pointer */
static void *lbl_88D45954; /* instance pointer */
static void *lbl_88D45958; /* instance pointer */
static void *lbl_88D4595C; /* instance pointer */
static void *lbl_88D459C4; /* instance pointer */
static void *lbl_88D459D4; /* instance pointer */
static void *lbl_88D459E8; /* instance pointer */
static void *lbl_88D459F4; /* instance pointer */
static void *lbl_88D459FC; /* instance pointer */
static void *lbl_88D45A00; /* instance pointer */
static void *lbl_88D45A20; /* instance pointer */
static void *lbl_88D45A24; /* instance pointer */
static void *lbl_88D45A48; /* instance pointer */
static void *lbl_88D45A78; /* instance pointer */
static void *lbl_88D45AB0; /* instance pointer */
static void *lbl_88D45AB4; /* instance pointer */
static void *lbl_88D45AC4; /* instance pointer */
static void *lbl_88D45AC8; /* instance pointer */
static void *lbl_88D45ACC; /* instance pointer */
static void *lbl_88D45AE0; /* instance pointer */
static void *lbl_88D45AF0; /* instance pointer */
static void *lbl_88D45B28; /* instance pointer */
static void *lbl_88D45B2C; /* instance pointer */
static void *lbl_88D45B30; /* instance pointer */
static void *lbl_88D45B40; /* instance pointer */

/* Owned object pointer, destroyed if set. */
struct Ts4OwnedRef {
    void *p;
    __forceinline ~Ts4OwnedRef() { if (p) ts4_destroy_owned_object(p); }
};

/* Owned object pointer, destroyed unconditionally. */
struct Ts4OwnedRaw {
    void *p;
    __forceinline ~Ts4OwnedRaw() { ts4_destroy_owned_object(*(void *volatile *)&p); }
};

/* Heap buffer returned to the game heap (or freed if there is none). */
struct Ts4HeapBuf {
    void *data;
    int unk4;
    int size;
    __forceinline ~Ts4HeapBuf()
    {
        if (data) {
            if (lbl_88D45B38)
                ts4_if_call_seq_fn_881F04B8_886131F0(lbl_88D45B38, data, size);
            else
                fn_885651F8(data);
        }
    }
};

/* Member subobject with an out-of-line destructor. */
template <void (*MEMBER_DTOR)(void *)>
struct Ts4ExtMember {
    void *unk0;
    __forceinline ~Ts4ExtMember() { MEMBER_DTOR(this); }
};

/* Member whose destructor only reinstalls its vtable. */
template <char *VT>
struct Ts4VtShell {
    void *vt;
    __forceinline ~Ts4VtShell() { *(void *volatile *)&vt = VT; }
};

struct Ts4NoBase {
};

template <void (*BASE_DTOR)(void *)>
struct Ts4Base1 {
    __forceinline ~Ts4Base1() { BASE_DTOR(this); }
};

template <void (*OUTER_DTOR)(void *), void (*INNER_DTOR)(void *)>
struct Ts4Base2 {
    __forceinline ~Ts4Base2() { OUTER_DTOR(this); INNER_DTOR(this); }
};

typedef Ts4Base2<ts4_if_call_seq_u32_off7c_881981E0, ts4_if_get_u32_lbl_88C32048_8857A1E0> Ts4Base_881981E0_8857A1E0;
typedef Ts4Base2<ts4_loop_call_seq_u32_off4_88282DF0, ts4_if_call_seq_lbl_880F7EE4_88617D28> Ts4Base_88282DF0_88617D28;
typedef Ts4Base1<fn_885E58B0> Ts4Base_885E58B0;
typedef Ts4Base1<fn_8860BBD8> Ts4Base_8860BBD8;
typedef Ts4Base1<ts4_if_call_seq_lbl_880F7EE4_88617D28> Ts4Base_88617D28;
typedef Ts4Base1<ts4_if_call_seq_lbl_880F21E8_88720080> Ts4Base_88720080;

#define SERVICE_DTOR(A, VT, INSTANCE, BASE, MEMBERS) \
struct Ts4Service##A : BASE { \
    void *vt; \
    MEMBERS \
    __forceinline ~Ts4Service##A() \
    { \
        *(void *volatile *)&vt = VT; \
        INSTANCE = 0; \
    } \
}; \
extern "C" void ts4_service_dtor_##A(Ts4Service##A *self) \
{ \
    self->Ts4Service##A::~Ts4Service##A(); \
}

/* Scalar deleting destructor: destroy, then free when bit 0 of flags is set. */
#define SERVICE_DELETING_DTOR(A, VT, INSTANCE, BASE, MEMBERS) \
struct Ts4Service##A : BASE { \
    void *vt; \
    MEMBERS \
    __forceinline ~Ts4Service##A() \
    { \
        *(void *volatile *)&vt = VT; \
        INSTANCE = 0; \
    } \
}; \
extern "C" Ts4Service##A *ts4_service_deleting_dtor_##A(Ts4Service##A *self, unsigned int flags) \
{ \
    self->Ts4Service##A::~Ts4Service##A(); \
    if (flags & 1) \
        ts4_tsu_cleanup_end(self); \
    return self; \
}

/* The same without a class instance pointer. */
#define OBJECT_CLASS(A, VT, BASE, MEMBERS) \
struct Ts4Object##A : BASE { \
    void *vt; \
    MEMBERS \
    __forceinline ~Ts4Object##A() { *(void *volatile *)&vt = VT; } \
};

#define OBJECT_DTOR(A, VT, BASE, MEMBERS) \
OBJECT_CLASS(A, VT, BASE, MEMBERS) \
extern "C" void ts4_object_dtor_##A(Ts4Object##A *self) \
{ \
    self->Ts4Object##A::~Ts4Object##A(); \
}

#define OBJECT_DELETING_DTOR(A, VT, BASE, MEMBERS) \
OBJECT_CLASS(A, VT, BASE, MEMBERS) \
extern "C" Ts4Object##A *ts4_object_deleting_dtor_##A(Ts4Object##A *self, unsigned int flags) \
{ \
    self->Ts4Object##A::~Ts4Object##A(); \
    if (flags & 1) \
        ts4_tsu_cleanup_end(self); \
    return self; \
}

/* A class whose base class also has a vtable: the base destructor
   reinstalls the base vtable after the members are gone. */
#define VT_OBJECT_CLASS(A, VT, BASE_VT, BASE, MEMBERS) \
struct Ts4ObjectBase##A : BASE { \
    void *vt; \
    __forceinline ~Ts4ObjectBase##A() { *(void *volatile *)&vt = BASE_VT; } \
}; \
struct Ts4Object##A : Ts4ObjectBase##A { \
    MEMBERS \
    __forceinline ~Ts4Object##A() { *(void *volatile *)&vt = VT; } \
};

#define VT_OBJECT_DTOR(A, VT, BASE_VT, BASE, MEMBERS) \
VT_OBJECT_CLASS(A, VT, BASE_VT, BASE, MEMBERS) \
extern "C" void ts4_object_dtor_##A(Ts4Object##A *self) \
{ \
    self->Ts4Object##A::~Ts4Object##A(); \
}

#define VT_OBJECT_DELETING_DTOR(A, VT, BASE_VT, BASE, MEMBERS) \
VT_OBJECT_CLASS(A, VT, BASE_VT, BASE, MEMBERS) \
extern "C" Ts4Object##A *ts4_object_deleting_dtor_##A(Ts4Object##A *self, unsigned int flags) \
{ \
    self->Ts4Object##A::~Ts4Object##A(); \
    if (flags & 1) \
        ts4_tsu_cleanup_end(self); \
    return self; \
}

/* A class derived from a service base: the base destructor reinstalls the
   base vtable and clears the service instance pointer. */
#define VT_SERVICE_CLASS(A, VT, BASE_VT, INSTANCE, BASE, MEMBERS) \
struct Ts4ServiceBase##A : BASE { \
    void *vt; \
    __forceinline ~Ts4ServiceBase##A() \
    { \
        *(void *volatile *)&vt = BASE_VT; \
        INSTANCE = 0; \
    } \
}; \
struct Ts4Service##A : Ts4ServiceBase##A { \
    MEMBERS \
    __forceinline ~Ts4Service##A() { *(void *volatile *)&vt = VT; } \
};

#define VT_SERVICE_DTOR(A, VT, BASE_VT, INSTANCE, BASE, MEMBERS) \
VT_SERVICE_CLASS(A, VT, BASE_VT, INSTANCE, BASE, MEMBERS) \
extern "C" void ts4_service_dtor_##A(Ts4Service##A *self) \
{ \
    self->Ts4Service##A::~Ts4Service##A(); \
}

#define VT_SERVICE_DELETING_DTOR(A, VT, BASE_VT, INSTANCE, BASE, MEMBERS) \
VT_SERVICE_CLASS(A, VT, BASE_VT, INSTANCE, BASE, MEMBERS) \
extern "C" Ts4Service##A *ts4_service_deleting_dtor_##A(Ts4Service##A *self, unsigned int flags) \
{ \
    self->Ts4Service##A::~Ts4Service##A(); \
    if (flags & 1) \
        ts4_tsu_cleanup_end(self); \
    return self; \
}

/* Member holders: a vtable and an owned pointer. */
struct Ts4Holder8826A020_24 {
    void *vt;
    char pad4[0x10];
    Ts4OwnedRaw owned;
    __forceinline ~Ts4Holder8826A020_24() { *(void *volatile *)&vt = lbl_880D7604; }
};

struct Ts4Holder8861F380_4 {
    void *vt;
    char pad4[0x18];
    Ts4OwnedRef owned;
    __forceinline ~Ts4Holder8861F380_4() { *(void *volatile *)&vt = lbl_880F7E14; }
};

struct Ts4Holder8869CD68_144 {
    void *vt;
    Ts4OwnedRef owned;
    __forceinline ~Ts4Holder8869CD68_144() { *(void *volatile *)&vt = lbl_880D75FC; }
};

struct Ts4Holder886AD128_24 {
    void *vt;
    char pad4[0x10];
    Ts4OwnedRef owned;
    __forceinline ~Ts4Holder886AD128_24() { *(void *volatile *)&vt = lbl_880D7604; }
};

struct Ts4Holder8887DB70_24 {
    void *vt;
    Ts4OwnedRef owned;
    __forceinline ~Ts4Holder8887DB70_24() { *(void *volatile *)&vt = lbl_880D75FC; }
};

/* Swing_DLL.xex addresses */
OBJECT_DELETING_DTOR(8815F4B0, lbl_880D4B20, Ts4NoBase, char pad4[0xC]; Ts4OwnedRaw m10;)
SERVICE_DELETING_DTOR(88160278, lbl_880D5694, lbl_88D45894, Ts4Base_88617D28, char pad4[0x24]; Ts4OwnedRaw m28;)
SERVICE_DELETING_DTOR(881606B8, lbl_880D5140, lbl_88D458D0, Ts4Base_88617D28, char pad4[0x18]; Ts4OwnedRaw m1C;)
OBJECT_DELETING_DTOR(8816D3A8, lbl_880D5E0C, Ts4NoBase, char pad4[0x4]; Ts4OwnedRaw m8;)
SERVICE_DELETING_DTOR(8817D2A0, lbl_880DB4B8, lbl_88D45940, Ts4Base_88617D28, char pad4[0x28]; Ts4VtShell<lbl_880D6B70> m2C;)
SERVICE_DELETING_DTOR(88212040, lbl_880EA63C, lbl_88D45A48, Ts4Base_88617D28, char pad4[0x20]; Ts4VtShell<lbl_880D6B70> m24; char pad28[0xC]; Ts4VtShell<lbl_880D6B70> m34; char pad38[0xC]; Ts4VtShell<lbl_880D6B70> m44; char pad48[0xC]; Ts4VtShell<lbl_880D6B70> m54;)
VT_OBJECT_DELETING_DTOR(88212B10, lbl_880EF510, lbl_880E4BA0, Ts4Base_8860BBD8, char pad4[0x24]; Ts4OwnedRaw m28;)
OBJECT_DELETING_DTOR(8821AE48, lbl_880F2148, Ts4NoBase, char pad4[0x4]; Ts4OwnedRaw m8;)
SERVICE_DELETING_DTOR(8821D3C8, lbl_880F2A08, lbl_88D45ACC, Ts4Base_88720080, char pad4[0x150]; Ts4OwnedRaw m154;)
SERVICE_DELETING_DTOR(8821D888, lbl_880F285C, lbl_88D45AE0, Ts4Base_88617D28, char pad4[0x24]; Ts4OwnedRaw m28;)
VT_OBJECT_DELETING_DTOR(882737A0, lbl_880F51C4, lbl_880F9018, Ts4NoBase, Ts4OwnedRaw m4;)
SERVICE_DTOR(886211F8, lbl_880F85DC, lbl_88D45B30, Ts4Base_88617D28, char pad4[0x18]; Ts4OwnedRef m1C;)
OBJECT_DTOR(8869CD68, lbl_880F4314, Ts4NoBase, char pad4[0xC]; Ts4OwnedRef m10; char pad14[0x20]; Ts4ExtMember<fn_8890F1E8> m34; char pad38[0x40]; Ts4ExtMember<fn_8890F1E8> m78; char pad7C[0x40]; Ts4ExtMember<fn_8890F1E8> mBC; char padC0[0x40]; Ts4ExtMember<fn_8890F1E8> m100; char pad104[0x40]; Ts4Holder8869CD68_144 m144;)
OBJECT_DTOR(886AD128, lbl_880F4850, Ts4NoBase, char pad4[0x20]; Ts4Holder886AD128_24 m24;)
OBJECT_DTOR(886CA260, lbl_880F37D0, Ts4NoBase, char pad4[0x4]; Ts4OwnedRef m8; char padC[0x8]; Ts4OwnedRef m14; char pad18[0x8]; Ts4OwnedRef m20; char pad24[0x8]; Ts4OwnedRef m2C;)
OBJECT_DTOR(886CEF70, lbl_880F37D8, Ts4NoBase, char pad4[0x4]; Ts4OwnedRef m8; char padC[0x8]; Ts4OwnedRef m14; char pad18[0x8]; Ts4OwnedRef m20;)
OBJECT_DTOR(886CF858, lbl_880F37D4, Ts4NoBase, char pad4[0x4]; Ts4OwnedRef m8; char padC[0x8]; Ts4OwnedRef m14; char pad18[0x8]; Ts4OwnedRef m20; char pad24[0x8]; Ts4OwnedRef m2C; char pad30[0xC]; Ts4OwnedRef m3C;)
SERVICE_DTOR(886D3230, lbl_880F37A0, lbl_88D45AF0, Ts4NoBase, Ts4OwnedRef m4; char pad8[0x8]; Ts4OwnedRef m10; char pad14[0x8]; Ts4OwnedRef m1C;)
OBJECT_DTOR(886DABD0, lbl_880F379C, Ts4NoBase, char pad4[0x38]; Ts4OwnedRef m3C; char pad40[0x8]; Ts4OwnedRef m48; char pad4C[0x8]; Ts4OwnedRef m54; char pad58[0x8]; Ts4OwnedRef m60;)
SERVICE_DTOR(8871E3F8, lbl_880F2810, lbl_88D45A78, Ts4Base_88617D28, char pad4[0x48]; Ts4OwnedRaw m4C; char pad50[0x8]; Ts4OwnedRaw m58;)
SERVICE_DTOR(887203D0, lbl_880F3388, lbl_88D45AC8, Ts4NoBase, char pad4[0x20]; Ts4HeapBuf m24;)
SERVICE_DTOR(88720420, lbl_880F3388, lbl_88D45AC4, Ts4NoBase, char pad4[0x20]; Ts4HeapBuf m24;)
OBJECT_DTOR(887205B0, lbl_880F3388, Ts4NoBase, char pad4[0x20]; Ts4HeapBuf m24;)
SERVICE_DTOR(88720D00, lbl_880F3388, lbl_88D45AB4, Ts4NoBase, char pad4[0x20]; Ts4HeapBuf m24;)
SERVICE_DTOR(88720D50, lbl_880F3388, lbl_88D45AB0, Ts4NoBase, char pad4[0x20]; Ts4HeapBuf m24;)
VT_OBJECT_DTOR(8877DEB0, lbl_880EF510, lbl_880E4BA0, Ts4Base_8860BBD8, char pad4[0x24]; Ts4OwnedRaw m28;)
SERVICE_DTOR(887C7C58, lbl_880EA63C, lbl_88D45A48, Ts4Base_88617D28, char pad4[0x20]; Ts4VtShell<lbl_880D6B70> m24; char pad28[0xC]; Ts4VtShell<lbl_880D6B70> m34; char pad38[0xC]; Ts4VtShell<lbl_880D6B70> m44; char pad48[0xC]; Ts4VtShell<lbl_880D6B70> m54;)
SERVICE_DTOR(887D2AE8, lbl_880E70D8, lbl_88D45A24, Ts4Base_88617D28, char pad4[0x3C]; Ts4OwnedRef m40;)
SERVICE_DTOR(887D2F40, lbl_880E7070, lbl_88D45A20, Ts4Base_8860BBD8, char pad4[0x4]; Ts4OwnedRef m8;)
SERVICE_DTOR(887DB5E8, lbl_880E7038, g_ts4_tsu_notification_object, Ts4Base_88617D28, char pad4[0x68]; Ts4OwnedRaw m6C; char pad70[0x8]; Ts4OwnedRaw m78; char pad7C[0x8]; Ts4OwnedRaw m84; char pad88[0x2B8]; Ts4OwnedRaw m340; char pad344[0x20]; Ts4OwnedRef m364; char pad368[0x18]; Ts4OwnedRef m380;)
SERVICE_DTOR(887F1330, lbl_880E45B8, lbl_88D45A00, Ts4Base_88617D28, char pad4[0x74]; Ts4OwnedRef m78; char pad7C[0x8]; Ts4OwnedRef m84; char pad88[0x8]; Ts4OwnedRef m90; char pad94[0x8]; Ts4OwnedRef m9C;)
SERVICE_DTOR(88800698, lbl_880E3AB4, lbl_88D459FC, Ts4Base_88617D28, char pad4[0x18]; Ts4OwnedRef m1C;)
SERVICE_DTOR(88804160, lbl_880E3710, lbl_88D459F4, Ts4Base_88617D28, char pad4[0x18]; Ts4ExtMember<ts4_if_call_seq_lbl_880F7908_8862C308> m1C; char pad20[0x70]; Ts4OwnedRef m90;)
SERVICE_DTOR(88866368, lbl_880E0638, lbl_88D459D4, Ts4Base_88617D28, char pad4[0x1C]; Ts4OwnedRef m20; char pad24[0x8]; Ts4OwnedRef m2C;)
SERVICE_DTOR(8887DB70, lbl_880DF8B0, lbl_88D459C4, Ts4Base_88617D28, char pad4[0x20]; Ts4Holder8887DB70_24 m24; char pad2C[0x14]; Ts4OwnedRef m40; char pad44[0x18]; Ts4VtShell<lbl_880D19F0> m5C;)
VT_SERVICE_DTOR(888888D0, lbl_880DF328, lbl_880F7B28, lbl_88D45B2C, Ts4Base_88617D28, char pad4[0x24]; Ts4OwnedRaw m28; char pad2C[0x8]; Ts4OwnedRaw m34;)
SERVICE_DTOR(888C8048, lbl_880DB92C, lbl_88D4595C, Ts4Base_88617D28, char pad4[0x38]; Ts4OwnedRef m3C;)
SERVICE_DTOR(888CAD28, lbl_880DB4B8, lbl_88D45940, Ts4Base_88617D28, char pad4[0x28]; Ts4VtShell<lbl_880D6B70> m2C;)
SERVICE_DTOR(888D0348, lbl_880DB904, lbl_88D45958, Ts4Base_88617D28, char pad4[0x30]; Ts4OwnedRef m34;)
SERVICE_DTOR(888D1A78, lbl_880DB490, lbl_88D45954, Ts4Base_88617D28, char pad4[0x1C]; Ts4OwnedRef m20; char pad24[0x8]; Ts4OwnedRef m2C;)
SERVICE_DTOR(888D7428, lbl_880DBE20, lbl_88D45930, Ts4Base_88617D28, char pad4[0x15C]; Ts4OwnedRef m160;)
SERVICE_DTOR(888DC3D8, lbl_880DB8B4, lbl_88D45950, Ts4Base_88617D28, char pad4[0x38]; Ts4OwnedRaw m3C; char pad40[0x8]; Ts4OwnedRaw m48; char pad4C[0x8]; Ts4OwnedRaw m54; char pad58[0x8]; Ts4OwnedRaw m60; char pad64[0x8]; Ts4OwnedRaw m6C; char pad70[0x8]; Ts4OwnedRaw m78; char pad7C[0x8]; Ts4OwnedRaw m84; char pad88[0x7C]; Ts4OwnedRaw m104;)
SERVICE_DTOR(888DE298, lbl_880DB508, lbl_88D4594C, Ts4Base_88617D28, char pad4[0x1C]; Ts4OwnedRef m20; char pad24[0x8]; Ts4OwnedRef m2C;)
SERVICE_DTOR(8894C130, lbl_880D50A0, lbl_88D458CC, Ts4Base_88617D28, char pad4[0x21C]; Ts4OwnedRef m220; char pad224[0x8]; Ts4OwnedRef m22C; char pad230[0x8]; Ts4OwnedRef m238; char pad23C[0x8]; Ts4OwnedRef m244;)
SERVICE_DTOR(889563E0, lbl_880D5118, lbl_88D45898, Ts4Base_88617D28, char pad4[0x28]; Ts4OwnedRaw m2C; char pad30[0x8]; Ts4OwnedRaw m38; char pad3C[0x8]; Ts4OwnedRaw m44; char pad48[0x14]; Ts4OwnedRaw m5C;)
SERVICE_DTOR(88956C60, lbl_880D50C8, lbl_88D45874, Ts4Base_88617D28, char pad4[0x18]; Ts4OwnedRaw m1C; char pad20[0x8]; Ts4OwnedRaw m28; char pad2C[0x8]; Ts4OwnedRaw m34; char pad38[0x8]; Ts4OwnedRaw m40;)
SERVICE_DTOR(889C7118, lbl_880D7590, lbl_88D458F8, Ts4Base_88617D28, char pad4[0x20]; Ts4OwnedRef m24; char pad28[0x8]; Ts4OwnedRef m30;)
