/* Swing_DLL.xex 0x8834B260-0x8841B1B4, executable version 0.0.0.3. */
typedef unsigned int u32;
typedef unsigned char u8;

typedef u32 (*ts4_vfn1)(void *);

/* Reads a word at +0x31c of the containing object (this - 0x1c) into *out. */
u32 ts4_get_word_31c_883A3828(char *obj, u32 *out)
{
    char *base = obj ? obj - 0x1c : 0;
    if (!out) {
        return 0x25;
    }
    *out = *(u32 *)(base + 0x31c);
    return 0;
}

/* Stores a value into the sub-record at +0x190 and bumps its counter. */
u32 ts4_set_sub_record_value_883832D8(char *obj, u32 value)
{
    char *base = obj ? obj - 0x1c : 0;
    *(u32 *)(*(char **)(base + 0x190) + 0x30) = value;
    (*(u32 **)(base + 0x190))[0x34 / 4]++;
    return 0;
}

/* Size of a block with a 16-aligned row area, 0x60 bytes per entry and a 0x40 header. */
u32 ts4_block_size_8840D7B8(char *obj)
{
    u32 a = *(u32 *)(obj + 0x10);
    u32 b = *(u32 *)(obj + 0x14);
    return ((b * 8 + 0x1f) & ~0xfu) + a * 0x60 + 0x40;
}

/* Clears fields, then forwards to virtual slot 10 of the owner at +8. */
u32 ts4_reset_and_forward_8841B188(char *obj)
{
    void *owner;
    *(int *)(obj + 0x1c) = -1;
    *(int *)(obj + 0x20) = -1;
    *(u32 *)(obj + 0x10) = 0;
    *(u32 *)(obj + 0x14) = 0;
    owner = *(void **)(obj + 8);
    return ((ts4_vfn1)(*(void ***)owner)[10])(owner);
}
