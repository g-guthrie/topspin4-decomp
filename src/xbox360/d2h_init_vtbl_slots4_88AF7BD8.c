/* Swing_DLL.xex 0x88AF7BD8-0x88AFB8C8, executable version 0.0.0.3. */

struct ts4_vtbl_slot2 { void *vtbl; void *destroy; void *thunk; void *data; };
struct ts4_tmp_88AFB860 { char *vt; unsigned short s0; unsigned short s1; unsigned pad[3]; unsigned sub[7]; };
struct ts4_tmp_88AFB0F0 { char *vt; unsigned short s0; unsigned short s1; unsigned pad[6]; unsigned sub[0x40]; };
struct ts4_tmp_88AF7BD8 { char *vt; unsigned short s0; unsigned short s1; unsigned pad; unsigned sub[0xa4 / 4]; };

extern void ts4_set_wrap_byte_8847FBC8(void *, int);
extern char lbl_88088130[];
extern char lbl_88044CA0[];
extern void fn_884A1C40(void);
extern void ts4_vcall0_thunk_884A1C08(void);
extern struct ts4_vtbl_slot2 lbl_88D25D84;
extern void ts4_set_u32_off8_8847FA60(unsigned *, unsigned);
extern char lbl_880842B8[];
extern char lbl_880456A4[];
extern void fn_884693F0(void);
extern void ts4_vcall0_thunk_884693D8(void);
extern struct ts4_vtbl_slot2 lbl_88D248F0;

void ts4_init_object_884BF7C0(void *);
extern char lbl_880897EC[];
extern char lbl_880444AC[];
extern void fn_884BEC88(void);
extern void ts4_vcall0_thunk_884BEC28(void);
extern struct ts4_vtbl_slot2 lbl_88D26044;
void ts4_init_vtbl_slot4_88AFB860(void)
{
    struct ts4_tmp_88AFB860 local;
    local.vt = lbl_880897EC;
    local.s1 = 1;
    ts4_init_object_884BF7C0(local.sub);
    lbl_88D26044.vtbl = lbl_880444AC;
    lbl_88D26044.destroy = (void *)fn_884BEC88;
    lbl_88D26044.thunk = (void *)ts4_vcall0_thunk_884BEC28;
    lbl_88D26044.data = local.vt;
}

void ts4_init_vtbl_slot4_88AFB0F0(void)
{
    struct ts4_tmp_88AFB0F0 local;
    local.vt = lbl_88088130;
    local.s1 = 1;
    ts4_set_wrap_byte_8847FBC8(local.sub, 0);
    lbl_88D25D84.vtbl = lbl_88044CA0;
    lbl_88D25D84.destroy = (void *)fn_884A1C40;
    lbl_88D25D84.thunk = (void *)ts4_vcall0_thunk_884A1C08;
    lbl_88D25D84.data = local.vt;
}

void ts4_init_vtbl_slot4_88AF7BD8(void)
{
    struct ts4_tmp_88AF7BD8 local;
    local.vt = lbl_880842B8;
    local.s1 = 1;
    ts4_set_u32_off8_8847FA60(local.sub, local.sub[2]);
    lbl_88D248F0.vtbl = lbl_880456A4;
    lbl_88D248F0.destroy = (void *)fn_884693F0;
    lbl_88D248F0.thunk = (void *)ts4_vcall0_thunk_884693D8;
    lbl_88D248F0.data = local.vt;
}
