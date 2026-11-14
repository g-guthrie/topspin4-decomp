/* Swing_DLL.xex 0x8819B308-0x8819C360, executable version 0.0.0.3. */
typedef unsigned char u8;
typedef unsigned short u16;
struct owner;
struct ownervt { void *s[4]; void *(*alloc)(struct owner *self); };
struct owner { struct ownervt *vt; };
struct rep { struct owner *owner; int refs; int pad; int len; };
extern void fn_88151988(struct rep *r);
void ts4_string_unshare_8819B308(u8 **self)
{
    u8 *p = *self;
    struct rep *r = (struct rep *)(p - 0x10);
    struct owner *o = *(struct owner **)(p - 0x10);
    if (*(int *)(p - 0xc) != 0) {
        if (r->len < 0) {
            *(int *)(p - 0xc) = 0;
            **self = 0;
        } else {
            fn_88151988(r);
            *self = (u8 *)o->vt->alloc(o) + 0x10;
        }
    }
}

void ts4_wstring_unshare_8819C2D8(u16 **self)
{
    u8 *p = (u8 *)*self;
    struct rep *r = (struct rep *)(p - 0x10);
    struct owner *o = *(struct owner **)(p - 0x10);
    if (*(int *)(p - 0xc) != 0) {
        if (r->len < 0) {
            *(int *)(p - 0xc) = 0;
            **self = 0;
        } else {
            fn_88151988(r);
            *self = (u16 *)((u8 *)o->vt->alloc(o) + 0x10);
        }
    }
}
