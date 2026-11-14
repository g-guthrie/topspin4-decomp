/* Swing_DLL.xex message-object family around 0x885F7BD8-0x885FF748.
   MSVC 16.00.10224.00 /O2 /Oi, C++.

   The callers keep a buffer pointer in r6 across the call to the
   message-pool singleton getter (0x8864DFF0): the compiler knows that the
   getter only touches r3 and r7-r11, which needs the getter defined in the
   same translation unit. The singleton pointer is file-static so that the
   compiler may schedule its store before the vtable store. */
typedef unsigned int u32;

struct Ts4BumpPool {
    char storage[0x400];
    char *cursor;   /* 0x400: next free byte */
    int remaining;  /* 0x404: bytes left */
};

static void *lbl_88D45B10; /* message-pool service singleton */

extern "C" {
extern Ts4BumpPool lbl_88D429F0;
extern char lbl_88D49304[]; /* service vtable */
void ts4_registry_dispatch_888860A0(void *block);
extern char lbl_880F93F8[];
extern char lbl_880F958C[];
extern char lbl_880F95C8[];
extern char lbl_880F9604[];
extern char lbl_880F9668[];
extern char lbl_880F96A4[];
extern char lbl_880F96CC[];
extern char lbl_880F96F4[];
extern char lbl_880F97D0[];
extern char lbl_880F97F8[];
extern char lbl_880F980C[];
extern char lbl_880F9834[];
extern char lbl_880F9848[];
extern char lbl_880F9870[];
extern char lbl_880F9884[];
extern char lbl_880F98AC[];
extern char lbl_880F98C0[];
extern char lbl_880F9924[];
extern char lbl_880F9938[];
extern char lbl_880F994C[];
extern char lbl_880F9960[];
extern char lbl_880F9974[];
extern char lbl_880F9988[];
extern char lbl_880F999C[];
extern char lbl_880F99B0[];
extern char lbl_880F99C4[];
extern char lbl_880F99D8[];
extern char lbl_880F99EC[];
extern char lbl_880F9A00[];
extern char lbl_880F9A14[];
extern char lbl_880F9A28[];
extern char lbl_880F9A64[];
extern char lbl_880F9A8C[];
extern char lbl_880F9AA0[];
}

/* 8-byte bump allocation from the static pool (header-less). */
inline void *operator new(unsigned, Ts4BumpPool &pool)
{
    char *block = pool.cursor;
    pool.cursor = block + 8;
    pool.remaining -= 8;
    return block;
}

struct Ts4MsgPoolService {
    void *vtbl;
    Ts4MsgPoolService() { vtbl = lbl_88D49304; }
};

/* Returns the message-pool service, creating it on first use. */
extern "C" __declspec(noinline) Ts4MsgPoolService *ts4_msg_pool_service_get_8864DFF0(void)
{
    Ts4MsgPoolService *service = (Ts4MsgPoolService *)lbl_88D45B10;
    if (!service) {
        service = new (lbl_88D429F0) Ts4MsgPoolService;
        lbl_88D45B10 = service;
    }
    return service;
}

/* Frees a pooled buffer: the block header sits 8 bytes before the data. */
static __forceinline void ts4_msg_buffer_free(char *data)
{
    if (data) {
        ts4_msg_pool_service_get_8864DFF0();
        ts4_registry_dispatch_888860A0(data - 8);
    }
}

#define FIELD(o, off) (*(char **)((char *)(o) + (off)))
#define FREE(off) ts4_msg_buffer_free(FIELD(self, off));
#define FREEZ(off) { char *data = FIELD(self, off); if (data) { ts4_msg_pool_service_get_8864DFF0(); \
    ts4_registry_dispatch_888860A0(data - 8); FIELD(self, off) = 0; } }

/* Message destructor: install the class vtable, free the pooled buffers held
   in the listed fields (FREEZ also clears the field), then fall back to the
   base message vtable. */
#define DTOR(A, VT, BASEVT, BODY) \
extern "C" void ts4_msg_dtor_##A(void **self) \
{ \
    self[0] = VT; \
    BODY \
    self[0] = BASEVT; \
}

/* Swing_DLL.xex addresses */
DTOR(885F7BD8, lbl_880F9AA0, lbl_880F93F8, FREE(0x18) FREE(0x1c))
DTOR(885F7C48, lbl_880F9A8C, lbl_880F93F8, FREE(0x18) FREE(0x1c))
DTOR(885F7CB8, lbl_880F9A64, lbl_880F93F8, FREEZ(0x4c))
DTOR(885F7DE0, lbl_880F9A28, lbl_880F93F8, FREEZ(0xc))
DTOR(885F7E40, lbl_880F9A14, lbl_880F93F8, FREEZ(0xc))
DTOR(885F7EA0, lbl_880F9A00, lbl_880F93F8, FREEZ(0xc))
DTOR(885F7F00, lbl_880F99EC, lbl_880F93F8, FREEZ(0xc))
DTOR(885F7F60, lbl_880F99D8, lbl_880F93F8, FREEZ(0xc))
DTOR(885F7FC0, lbl_880F99C4, lbl_880F93F8, FREEZ(0xc))
DTOR(885F8020, lbl_880F99B0, lbl_880F93F8, FREEZ(0xc))
DTOR(885F8080, lbl_880F999C, lbl_880F93F8, FREEZ(0xc))
DTOR(885F80E0, lbl_880F9988, lbl_880F93F8, FREEZ(0xc))
DTOR(885F8140, lbl_880F9974, lbl_880F93F8, FREEZ(0xc))
DTOR(885F81A0, lbl_880F9960, lbl_880F93F8, FREEZ(0xc))
DTOR(885F8200, lbl_880F994C, lbl_880F93F8, FREEZ(0xc))
DTOR(885F8260, lbl_880F9938, lbl_880F93F8, FREEZ(0xc))
DTOR(885FF038, lbl_880F9924, lbl_880F93F8, FREE(0xc))
DTOR(885FF090, lbl_880F98C0, lbl_880F93F8, FREE(0xc))
DTOR(885FF0E8, lbl_880F98AC, lbl_880F93F8, FREE(0xc))
DTOR(885FF140, lbl_880F9884, lbl_880F93F8, FREE(0xc))
DTOR(885FF198, lbl_880F9870, lbl_880F93F8, FREE(0xc))
DTOR(885FF1F0, lbl_880F9848, lbl_880F93F8, FREE(0x10) FREE(0x14))
DTOR(885FF260, lbl_880F9834, lbl_880F93F8, FREE(0x10) FREE(0x14) FREE(0x18))
DTOR(885FF2E8, lbl_880F980C, lbl_880F93F8, FREE(0x14))
DTOR(885FF340, lbl_880F97F8, lbl_880F93F8, FREE(0x10))
DTOR(885FF398, lbl_880F97D0, lbl_880F93F8, FREE(0xc))
DTOR(885FF3F0, lbl_880F96F4, lbl_880F93F8, FREE(0xc) FREE(0x10))
DTOR(885FF460, lbl_880F96CC, lbl_880F93F8, FREE(0xc))
DTOR(885FF4B8, lbl_880F96A4, lbl_880F93F8, FREE(0xc))
DTOR(885FF510, lbl_880F9668, lbl_880F93F8, FREE(0xc) FREE(0x14) FREE(0x1c) FREE(0x20))
DTOR(885FF5B0, lbl_880F9604, lbl_880F93F8, FREE(0x20) FREE(0x28) FREE(0x34) FREE(0x38))
DTOR(885FF650, lbl_880F95C8, lbl_880F93F8, FREE(0xc))
DTOR(885FF6A8, lbl_880F958C, lbl_880F93F8, FREE(0xc) FREE(0x10) FREE(0x14) FREE(0x18))

/* ---- other users of the message-pool service ---- */
extern "C" {
void *fn_8899F760(u32 size);
void fn_889BD8B0(void *item);
extern char lbl_880F90BC[];
extern char lbl_880F909C[];
extern char lbl_880F940C[];
}

/* Frees a pooled buffer given its data pointer (may be null). Swing_DLL.xex 0x88604250 */
extern "C" void ts4_msg_buffer_free_88604250(char *data) { ts4_msg_buffer_free(data); }
/* Swing_DLL.xex 0x88604288 (identical twin) */
extern "C" void ts4_msg_buffer_free_88604288(char *data) { ts4_msg_buffer_free(data); }

/* Returns a raw pooled block. Swing_DLL.xex 0x889BDB40 */
extern "C" void ts4_msg_block_release_889BDB40(void *block)
{
    ts4_msg_pool_service_get_8864DFF0();
    ts4_registry_dispatch_888860A0(block);
}

/* Releases the block referenced by a holder, then the holder itself. Swing_DLL.xex 0x8864B1A0 */
extern "C" void ts4_msg_holder_release_8864B1A0(void **holder)
{
    void *block = *holder;
    ts4_msg_pool_service_get_8864DFF0();
    ts4_registry_dispatch_888860A0(block);
    ts4_msg_pool_service_get_8864DFF0();
    ts4_registry_dispatch_888860A0(holder);
}

/* Allocates size bytes behind an 8-byte header holding the total size. Swing_DLL.xex 0x88278620 */
extern "C" __declspec(noinline) void *ts4_msg_buffer_alloc_88278620(u32 size)
{
    ts4_msg_pool_service_get_8864DFF0();
    u32 total = size + 8;
    u32 *block = (u32 *)fn_8899F760(total);
    if (block) {
        block[0] = total;
        return block + 2;
    }
    return 0;
}

/* Allocates count 8-byte elements behind an 8-byte size header. Swing_DLL.xex 0x88278680 */
extern "C" void *ts4_msg_buffer_alloc_array8_88278680(u32 count)
{
    ts4_msg_pool_service_get_8864DFF0();
    u32 total = (count + 1) * 8;
    u32 *block = (u32 *)fn_8899F760(total);
    if (block) {
        block[0] = total;
        return block + 2;
    }
    return 0;
}

/* Destructor: frees the buffer at +4 unless the not-owned flag at +0x18 is set. Swing_DLL.xex 0x886047F8 */
struct Ts4MsgView { void *vtbl; char *data; char pad8[0x10]; unsigned char borrowed; };
extern "C" void ts4_msg_view_dtor_886047F8(Ts4MsgView *self)
{
    self->vtbl = lbl_880F90BC;
    if (!self->borrowed)
        ts4_msg_buffer_free(self->data);
    self->vtbl = lbl_880F909C;
}

/* Destructor: releases every item, then frees the item array if it was allocated. Swing_DLL.xex 0x88603FF8 */
struct Ts4MsgItemList { void *vtbl; char pad4[8]; u32 count; u32 capacity; void **items; };
extern "C" void ts4_msg_item_list_dtor_88603FF8(Ts4MsgItemList *self)
{
    u32 i;
    self->vtbl = lbl_880F940C;
    for (i = 0; i < self->count; i++)
        fn_889BD8B0(self->items[i]);
    if (self->capacity)
        ts4_msg_buffer_free((char *)self->items);
    self->vtbl = lbl_880F93F8;
}

/* Pops the head node of a singly linked list {count, head, tail}. Swing_DLL.xex 0x882784F0 */
struct Ts4MsgNode { u32 unused; Ts4MsgNode *next; };
struct Ts4MsgList { int count; Ts4MsgNode *head; Ts4MsgNode *tail; };
extern "C" void ts4_msg_list_pop_882784F0(Ts4MsgList *list)
{
    if (list->count > 0) {
        Ts4MsgNode *node = list->head;
        Ts4MsgNode *next = node->next;
        ts4_msg_pool_service_get_8864DFF0();
        ts4_registry_dispatch_888860A0(node);
        list->head = next;
        list->count--;
    }
    if (list->count == 0)
        list->tail = 0;
}

extern "C" void RtlInitializeCriticalSection(void *cs);

/* Creates a critical section (0x1C bytes) and a 4-byte handle that owns it. Swing_DLL.xex 0x8864B1E8 */
extern "C" void **ts4_msg_lock_create_8864B1E8(void)
{
    ts4_msg_pool_service_get_8864DFF0();
    void *cs = fn_8899F760(0x1c);
    if (cs) {
        RtlInitializeCriticalSection(cs);
        ts4_msg_pool_service_get_8864DFF0();
        void **handle = (void **)fn_8899F760(4);
        if (handle) {
            *handle = cs;
            return handle;
        }
        ts4_msg_pool_service_get_8864DFF0();
        ts4_registry_dispatch_888860A0(cs);
    }
    return 0;
}
