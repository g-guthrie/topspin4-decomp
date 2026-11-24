/* Swing_DLL.xex 0x885F66D8-0x885F6AE0, executable version 0.0.0.3. */
typedef unsigned int u32;
typedef unsigned short u16;
#ifdef _MSC_VER
extern void *memcpy(void *, const void *, unsigned int);
#else
#include <string.h>
#endif

/* Serializable record: a length-prefixed byte block followed by small fixed fields. */
typedef struct Ts4Record {
    char pad[0xc];
    char *data;
    u32 length;
    u16 first;
    u16 second;
    u32 third;
    u16 fourth;
    u16 fifth;
} Ts4Record;

/* Returns the writer's current offset for the record. */
extern u32 fn_88603F38(Ts4Record *self);

/* Length-prefixed block followed by one 32-bit field. */
u32 ts4_write_block_u32_885F6758(Ts4Record *self, char *buffer)
{
    u32 offset = fn_88603F38(self);
    char *cursor = buffer + offset;
    char *body;
    u32 length;
    *(u32 *)cursor = self->length;
    body = cursor + 4;
    length = self->length;
    if (length) memcpy(body, self->data, length);
    body += length;
    *(u32 *)body = *(u32 *)&self->first;
    return (u32)(body + 4 - buffer);
}

u32 ts4_write_block_u32_885F67B8(Ts4Record *self, char *buffer)
{
    u32 offset = fn_88603F38(self);
    char *cursor = buffer + offset;
    char *body;
    u32 length;
    *(u32 *)cursor = self->length;
    body = cursor + 4;
    length = self->length;
    if (length) memcpy(body, self->data, length);
    body += length;
    *(u32 *)body = *(u32 *)&self->first;
    return (u32)(body + 4 - buffer);
}

/* Length-prefixed block followed by one 16-bit field. */
u32 ts4_write_block_u16_885F6818(Ts4Record *self, char *buffer)
{
    u32 offset = fn_88603F38(self);
    char *cursor = buffer + offset;
    char *body;
    u32 length;
    *(u32 *)cursor = self->length;
    body = cursor + 4;
    length = self->length;
    if (length) memcpy(body, self->data, length);
    body += length;
    *(u16 *)body = self->first;
    return (u32)(body + 2 - buffer);
}

u32 ts4_write_block_u16_885F6878(Ts4Record *self, char *buffer)
{
    u32 offset = fn_88603F38(self);
    char *cursor = buffer + offset;
    char *body;
    u32 length;
    *(u32 *)cursor = self->length;
    body = cursor + 4;
    length = self->length;
    if (length) memcpy(body, self->data, length);
    body += length;
    *(u16 *)body = self->first;
    return (u32)(body + 2 - buffer);
}

/* Length-prefixed block followed by the second 16-bit field. */
u32 ts4_write_block_u16_second_885F6AE0(Ts4Record *self, char *buffer)
{
    u32 offset = fn_88603F38(self);
    char *cursor = buffer + offset;
    char *body;
    u32 length;
    *(u32 *)cursor = self->length;
    body = cursor + 4;
    length = self->length;
    if (length) memcpy(body, self->data, length);
    body += length;
    *(u16 *)body = self->second;
    return (u32)(body + 2 - buffer);
}

/* Length-prefixed block followed by five fixed fields. */
u32 ts4_write_block_fields_885F66D8(Ts4Record *self, char *buffer)
{
    u32 offset = fn_88603F38(self);
    char *cursor = buffer + offset;
    char *body;
    u32 length;
    *(u32 *)cursor = self->length;
    body = cursor + 4;
    length = self->length;
    if (length) memcpy(body, self->data, length);
    body += length;
    *(u16 *)body = self->first;
    body += 2;
    *(u16 *)body = self->second;
    body += 2;
    *(u32 *)body = self->third;
    body += 4;
    *(u16 *)body = self->fourth;
    body += 2;
    *(u16 *)body = self->fifth;
    return (u32)(body + 2 - buffer);
}
