/* Swing_DLL.xex singleton service destructors (FAM3).
   MSVC 16.00.10224.00 /O2 /Oi.

   Each destructor installs the class vtable, clears the class's instance
   pointer, destroys the owned object held in a member and runs the service
   base destructor. The vtable store and the member load are volatile so they
   keep their order; the instance pointer is file-static, which lets the
   compiler treat it as not aliasing the object. */

void ts4_destroy_owned_object(void *object);
void ts4_if_call_seq_lbl_880F7EE4_88617D28(void *self);
void ts4_if_call_seq_lbl_880F21E8_88720080(void *self);

extern char lbl_880F285C[];
extern char lbl_880F2A08[];
extern char lbl_880D5140[];
extern char lbl_880D5694[];

static void *lbl_88D45AE0; /* instance pointers */
static void *lbl_88D45ACC;
static void *lbl_88D458D0;
static void *lbl_88D45894;

#define SINGLETON_DTOR(A, VT, INSTANCE, OWNED_INDEX, BASE_DTOR) \
void ts4_singleton_service_dtor_##A(void **self) \
{ \
    *(void *volatile *)self = VT; \
    INSTANCE = 0; \
    ts4_destroy_owned_object(*(void *volatile *)&self[OWNED_INDEX]); \
    BASE_DTOR(self); \
}

/* Swing_DLL.xex addresses */
SINGLETON_DTOR(8871A6F0, lbl_880F285C, lbl_88D45AE0, 10, ts4_if_call_seq_lbl_880F7EE4_88617D28)
SINGLETON_DTOR(88720380, lbl_880F2A08, lbl_88D45ACC, 85, ts4_if_call_seq_lbl_880F21E8_88720080)
SINGLETON_DTOR(88723070, lbl_880F2A08, lbl_88D45ACC, 85, ts4_if_call_seq_lbl_880F21E8_88720080)
SINGLETON_DTOR(88955D28, lbl_880D5140, lbl_88D458D0, 7, ts4_if_call_seq_lbl_880F7EE4_88617D28)
SINGLETON_DTOR(88956448, lbl_880D5694, lbl_88D45894, 10, ts4_if_call_seq_lbl_880F7EE4_88617D28)
