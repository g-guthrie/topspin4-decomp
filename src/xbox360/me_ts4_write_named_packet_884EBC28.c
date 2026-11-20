/* 0x884EBC28: Serialises a packet: opens a writer over a temporary pool byte buffer, writes tag byte 0x90, the two ints lbl_88C2688C and lbl_88C26888, and the string lbl_8808D470 as a u16 length (clamped to 0xFFFF) plus bytes; then opens a second writer on target and writes the buffer length and contents. Destroys both writers, frees the buffer (kind 0x17) and returns 0. */
/* Matched on /Oc (agAH). The u16 length goes to the _b writer as unsigned short (clrlwi 16); the _a sibling is the signed overload. */
extern unsigned int lbl_88CACF08;
void *KeTlsGetValue(unsigned int index);
void fn_8841A590(void *allocator, void *object, unsigned int size, int kind);
typedef struct ByteBuf { unsigned char *data; int count; int capFlags; } ByteBuf;
typedef struct Stream { void *impl; int pos; int a; int b; } Stream;
extern int lbl_88C2688C;
extern int lbl_88C26888;
extern const char lbl_8808D470[];
void fn_884ECF18(Stream *s, ByteBuf *out);
void fn_884ED1C8(Stream *s, void *target);
void ts4_call_slot4_one_byte_88426FA0(Stream *s, unsigned char b);
void ts4_stream_write_i32_a_88427418(Stream *s, int value);
void ts4_stream_write_i16_b_884273E8(Stream *s, unsigned short value);
void ts4_get_u32_off8_88427198(Stream *s, const void *data, int size);
void ts4_ref_holder_dtor_88427338(Stream *s);
unsigned int fn_88421338(const char *s);

static __forceinline void ByteBuf_Free(ByteBuf *b)
{
    if ((b->capFlags & (int)0x80000000) == 0) {
        unsigned int cap = b->capFlags & 0x3FFFFFFF;
        void *alloc = KeTlsGetValue(lbl_88CACF08);
        fn_8841A590(alloc, b->data, cap, 0x17);
    }
}

int fn_884EBC28(void *target)
{
    ByteBuf payload;
    Stream header;
    Stream body;
    const char *name;
    int len;
    payload.data = 0;
    payload.count = 0;
    payload.capFlags = (int)0x80000000;
    fn_884ECF18(&header, &payload);
    ts4_call_slot4_one_byte_88426FA0(&header, 0x90);
    ts4_stream_write_i32_a_88427418(&header, lbl_88C2688C);
    ts4_stream_write_i32_a_88427418(&header, lbl_88C26888);
    name = lbl_8808D470;
    len = fn_88421338(name);
    if (len > 0xFFFF)
        len = 0xFFFF;
    ts4_stream_write_i16_b_884273E8(&header, (unsigned short)len);
    ts4_get_u32_off8_88427198(&header, name, len);
    fn_884ED1C8(&body, target);
    ts4_stream_write_i32_a_88427418(&body, payload.count);
    ts4_get_u32_off8_88427198(&body, payload.data, payload.count);
    ts4_ref_holder_dtor_88427338(&body);
    ts4_ref_holder_dtor_88427338(&header);
    ByteBuf_Free(&payload);
    return 0;
}
