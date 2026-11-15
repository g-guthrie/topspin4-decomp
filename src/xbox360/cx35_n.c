/* CW35 part n: small helper in 0x88790000-0x887B0000. */
typedef unsigned int u32;
typedef unsigned char u8;

extern u8 ts4_loop_get_u32_off10_882109B8(void *);
extern void ts4_if_set_u32_off0_8862BE08(void *out, const void *k);
extern void ts4_get_u32_off0_8822AFE8(void *a, void *b);
extern u8 lbl_880D41AC[];
typedef struct R70 { u8 pad[0x70]; void *f70; } R70;
extern R70 *lbl_88D41FC4;
extern void *lbl_88D45B1C;
typedef struct G274 { u8 pad[0x274]; u8 b274; } G274;

u32 ts4_check_set_887915F0(void *self)
{
    volatile u8 o50;
    u32 t58[3];
    if (ts4_loop_get_u32_off10_882109B8(lbl_88D41FC4->f70)) {
        return 1;
    }
    ts4_if_set_u32_off0_8862BE08(t58, lbl_880D41AC);
    ts4_get_u32_off0_8822AFE8(t58, self);
    o50 = 1;
    ((G274 *)lbl_88D45B1C)->b274 = o50;
    return 0;
}
