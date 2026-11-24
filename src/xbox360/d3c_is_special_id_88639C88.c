/* Swing_DLL.xex 0x88639C88-0x88639D0C, executable version 0.0.0.3. */
typedef struct Ts4IdHolder {
    char pad[0x54];
    int id;
} Ts4IdHolder;

/* True when the holder's id is one of seven fixed id constants. */
unsigned char ts4_is_special_id_88639C88(Ts4IdHolder *p)
{
    int v = p->id;
    return v == 0x18280186 || v == 0x1a200152 || v == 0x1a200153 || v == 0x1a200154 ||
           v == 0x1a200052 || v == 0x1a200053 || v == 0x1a200054;
}
