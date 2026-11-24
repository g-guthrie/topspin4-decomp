/* CW11 LTCG route, context: src/xbox360/fam3_msg_dtor.cpp (message-pool service getter, buffer alloc). Built with /Oc. */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef unsigned long long u64;
#ifdef _MSC_VER
extern void *memset(void *, int, unsigned int);
extern void *memcpy(void *, const void *, unsigned int);
#else
#include <string.h>
#endif

extern char lbl_880F9A3C[];
extern char lbl_880F93F8[];
extern void ts4_msg_pool_service_get_8864DFF0(void);
extern void ts4_registry_dispatch_888860A0(void *p);
extern char *ts4_msg_buffer_alloc_88278620(u32 size);

/* 0x885F7D18: message destructor: frees the pooled buffers at 0x24, 0x2c, 0x30 and destroys + frees the child at 0x28 */
typedef struct Cx11VtSlot { void (*dtor)(void *self, u32 flags); } Cx11VtSlot;
typedef struct Cx11Child { Cx11VtSlot *vt; } Cx11Child;
typedef struct Cx11Msg2 { void *vt; u8 pad[0x20]; char *f24; Cx11Child *f28; char *f2c; char *f30; } Cx11Msg2;
void ts4_msg_dtor_885F7D18(Cx11Msg2 *m)
{
    Cx11Child *s;
    char *t;
    m->vt = lbl_880F9A3C;
    t = m->f24;
    if (t != 0) {
        ts4_msg_pool_service_get_8864DFF0();
        ts4_registry_dispatch_888860A0(t - 8);
    }
    s = m->f28;
    if (s != 0) {
        s->vt->dtor(s, 0);
        ts4_msg_pool_service_get_8864DFF0();
        ts4_registry_dispatch_888860A0(s);
        m->f28 = 0;
    }
    t = m->f2c;
    if (t != 0) {
        ts4_msg_pool_service_get_8864DFF0();
        ts4_registry_dispatch_888860A0(t - 8);
    }
    t = m->f30;
    if (t != 0) {
        ts4_msg_pool_service_get_8864DFF0();
        ts4_registry_dispatch_888860A0(t - 8);
    }
    m->vt = lbl_880F93F8;
}

/* 0x88604080: grow the u32 element array (data at 0x14, capacity at 0x10, count at 0xc) to at least n elements */
extern void *fn_8899F760(u32 size);
#ifdef _MSC_VER
#define CX11_INL static __forceinline
#else
#define CX11_INL static inline
#endif
/* pooled allocation with an 8-byte size header (inline copy of ts4_msg_buffer_alloc_88278620) */
CX11_INL u32 *cx11_pool_alloc(u32 size)
{
    u32 total;
    u32 *block;
    ts4_msg_pool_service_get_8864DFF0();
    total = size + 8;
    block = (u32 *)fn_8899F760(total);
    if (block) {
        block[0] = total;
        return block + 2;
    }
    return 0;
}
typedef struct Cx11U32Vec { u8 pad[0xc]; u32 count; u32 capacity; u32 *data; } Cx11U32Vec;
u32 ts4_u32vec_reserve_88604080(Cx11U32Vec *v, u32 n)
{
    if (n > v->capacity) {
        u32 *arr = cx11_pool_alloc(n * 4);
        if (arr == 0) return 0;
        memset(arr, 0, n * 4);
        if (v->count != 0 && v->data != 0 && v->count <= v->capacity)
            memcpy(arr, v->data, v->count * 4);
        if (v->capacity != 0 && v->data != 0) {
            char *old = (char *)v->data;
            ts4_msg_pool_service_get_8864DFF0();
            ts4_registry_dispatch_888860A0(old - 8);
        }
        v->data = arr;
        v->capacity = n;
    }
    return 1;
}
