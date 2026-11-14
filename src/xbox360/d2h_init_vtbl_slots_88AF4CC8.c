/* Swing_DLL.xex 0x88AF5B60-0x88AF8E50, executable version 0.0.0.3. */

struct ts4_vtbl_slot { void *vtbl; void *destroy; void *thunk; unsigned first_word; };

extern char lbl_88045420[];
extern char lbl_88045430[];
extern char lbl_880454AC[];
extern char lbl_88045568[];
extern char lbl_88045654[];
extern char lbl_880456FC[];
extern char lbl_880457B0[];
extern char lbl_88045818[];
extern char lbl_880458FC[];
extern char lbl_8804592C[];
extern char lbl_88045958[];
extern char lbl_88045990[];
extern char lbl_8804653C[];
extern char lbl_88046560[];
extern char lbl_88046588[];
extern char lbl_880465E8[];
extern char lbl_88046618[];
extern char lbl_88046798[];
extern char lbl_880467A8[];
extern char lbl_880467EC[];
extern char lbl_8804683C[];
extern struct ts4_vtbl_slot lbl_88D23444;
extern struct ts4_vtbl_slot lbl_88D23544;
extern struct ts4_vtbl_slot lbl_88D23634;
extern struct ts4_vtbl_slot lbl_88D236A4;
extern struct ts4_vtbl_slot lbl_88D23964;
extern struct ts4_vtbl_slot lbl_88D239A4;
extern struct ts4_vtbl_slot lbl_88D239E4;
extern struct ts4_vtbl_slot lbl_88D23A24;
extern struct ts4_vtbl_slot lbl_88D23A64;
extern struct ts4_vtbl_slot lbl_88D242B0;
extern struct ts4_vtbl_slot lbl_88D24380;
extern struct ts4_vtbl_slot lbl_88D243F0;
extern struct ts4_vtbl_slot lbl_88D24430;
extern struct ts4_vtbl_slot lbl_88D245F0;
extern struct ts4_vtbl_slot lbl_88D24690;
extern struct ts4_vtbl_slot lbl_88D24880;
extern struct ts4_vtbl_slot lbl_88D249F0;
extern struct ts4_vtbl_slot lbl_88D24C80;
extern struct ts4_vtbl_slot lbl_88D24E40;
extern struct ts4_vtbl_slot lbl_88D24FA0;
extern struct ts4_vtbl_slot lbl_88D24FE0;
extern void fn_88437950(void);
extern void fn_884379F0(void);
extern void fn_88437DB8(void);
extern void fn_88437E08(void);
extern void fn_88438668(void);
extern void fn_884386C8(void);
extern void fn_88438728(void);
extern void fn_88438788(void);
extern void fn_884387E8(void);
extern void fn_8843FFA0(unsigned *, int);
extern void fn_88441FF8(unsigned *, int);
extern void fn_884430E8(unsigned *, int);
extern void fn_88446CE8(unsigned *, int);
extern void fn_88448290(unsigned *, int);
extern void fn_88448BB8(unsigned *, int);
extern void fn_88468460(void);
extern void fn_884685D8(unsigned *, int);
extern void fn_88468768(void);
extern void fn_88468888(void);
extern void fn_884688E8(void);
extern void fn_88468998(unsigned *, int);
extern void fn_88468D28(void);
extern void fn_88468F58(void);
extern void fn_884692E0(void);
extern void fn_88469570(void);
extern void fn_88469A70(void);
extern void fn_88469AB8(unsigned *, int);
extern void fn_88469E10(void);
extern void fn_8846A010(void);
extern void fn_8846A070(void);
extern void fn_8846D5E0(unsigned *, int);
extern void fn_884748C0(unsigned *, int);
extern void ts4_if_addr_lbl_88086ED0_88475A78(unsigned *, int);
extern void ts4_call_seq_lbl_88086FCC_88478CE8(unsigned *, int);
extern void ts4_call_seq_lbl_88087004_884796F8(unsigned *, int);
extern void ts4_call_seq_lbl_88087078_8847B788(unsigned *, int);
extern void ts4_call_seq_lbl_880870F4_8847E988(unsigned *, int);
extern void ts4_call_seq_lbl_88087154_88481278(unsigned *, int);
extern void fn_88486018(unsigned *, int);
extern void ts4_addr_lbl_88081E00_88446CB8(unsigned *, int);
extern void ts4_addr_lbl_88081E10_88446CD0(unsigned *, int);
extern void ts4_init_object_88444740(unsigned *, int);
extern void ts4_vcall0_thunk_88437938(void);
extern void ts4_vcall0_thunk_88437A08(void);
extern void ts4_vcall0_thunk_88437DA0(void);
extern void ts4_vcall0_thunk_88437E20(void);
extern void ts4_vcall0_thunk_88438680(void);
extern void ts4_vcall0_thunk_884386E0(void);
extern void ts4_vcall0_thunk_88438740(void);
extern void ts4_vcall0_thunk_884387A0(void);
extern void ts4_vcall0_thunk_88438800(void);
extern void ts4_vcall0_thunk_88468448(void);
extern void ts4_vcall0_thunk_88468780(void);
extern void ts4_vcall0_thunk_88468870(void);
extern void ts4_vcall0_thunk_884688D0(void);
extern void ts4_vcall0_thunk_88468D10(void);
extern void ts4_vcall0_thunk_88468F40(void);
extern void ts4_vcall0_thunk_884692C8(void);
extern void ts4_vcall0_thunk_88469588(void);
extern void ts4_vcall0_thunk_88469A58(void);
extern void ts4_vcall0_thunk_88469E28(void);
extern void ts4_vcall0_thunk_8846A028(void);
extern void ts4_vcall0_thunk_8846A088(void);

void ts4_init_vtbl_slot_88AF5B60(void)
{
    unsigned local[20];

    ts4_addr_lbl_88081E00_88446CB8(local, 0);
    lbl_88D23964.vtbl = lbl_880465E8;
    lbl_88D23964.destroy = (void *)fn_88438668;
    lbl_88D23964.thunk = (void *)ts4_vcall0_thunk_88438680;
    lbl_88D23964.first_word = local[0];
}

void ts4_init_vtbl_slot_88AF5C38(void)
{
    unsigned local[16];

    ts4_addr_lbl_88081E10_88446CD0(local, 0);
    lbl_88D239A4.vtbl = lbl_88046588;
    lbl_88D239A4.destroy = (void *)fn_884386C8;
    lbl_88D239A4.thunk = (void *)ts4_vcall0_thunk_884386E0;
    lbl_88D239A4.first_word = local[0];
}

void ts4_init_vtbl_slot_88AF5D10(void)
{
    unsigned local[56];

    fn_88446CE8(local, 0);
    lbl_88D239E4.vtbl = lbl_88046618;
    lbl_88D239E4.destroy = (void *)fn_88438728;
    lbl_88D239E4.thunk = (void *)ts4_vcall0_thunk_88438740;
    lbl_88D239E4.first_word = local[0];
}

void ts4_init_vtbl_slot_88AF5DE8(void)
{
    unsigned local[20];

    fn_88448290(local, 0);
    lbl_88D23A24.vtbl = lbl_8804653C;
    lbl_88D23A24.destroy = (void *)fn_88438788;
    lbl_88D23A24.thunk = (void *)ts4_vcall0_thunk_884387A0;
    lbl_88D23A24.first_word = local[0];
}

void ts4_init_vtbl_slot_88AF5EC0(void)
{
    unsigned local[28];

    fn_88448BB8(local, 0);
    lbl_88D23A64.vtbl = lbl_88046560;
    lbl_88D23A64.destroy = (void *)fn_884387E8;
    lbl_88D23A64.thunk = (void *)ts4_vcall0_thunk_88438800;
    lbl_88D23A64.first_word = local[0];
}

void ts4_init_vtbl_slot_88AF6B20(void)
{
    unsigned local[52];

    fn_884685D8(local, 0);
    lbl_88D242B0.vtbl = lbl_88045990;
    lbl_88D242B0.destroy = (void *)fn_88468460;
    lbl_88D242B0.thunk = (void *)ts4_vcall0_thunk_88468448;
    lbl_88D242B0.first_word = local[0];
}

void ts4_init_vtbl_slot_88AF6D50(void)
{
    unsigned local[16];

    ts4_call_seq_lbl_88086FCC_88478CE8(local, 0);
    lbl_88D24380.vtbl = lbl_88045958;
    lbl_88D24380.destroy = (void *)fn_88468768;
    lbl_88D24380.thunk = (void *)ts4_vcall0_thunk_88468780;
    lbl_88D24380.first_word = local[0];
}

void ts4_init_vtbl_slot_88AF6E90(void)
{
    unsigned local[12];

    ts4_call_seq_lbl_88087004_884796F8(local, 0);
    lbl_88D243F0.vtbl = lbl_8804592C;
    lbl_88D243F0.destroy = (void *)fn_88468888;
    lbl_88D243F0.thunk = (void *)ts4_vcall0_thunk_88468870;
    lbl_88D243F0.first_word = local[0];
}

void ts4_init_vtbl_slot_88AF6F68(void)
{
    unsigned local[88];

    fn_88468998(local, 0);
    lbl_88D24430.vtbl = lbl_880458FC;
    lbl_88D24430.destroy = (void *)fn_884688E8;
    lbl_88D24430.thunk = (void *)ts4_vcall0_thunk_884688D0;
    lbl_88D24430.first_word = local[0];
}

void ts4_init_vtbl_slot_88AF7408(void)
{
    unsigned local[128];

    fn_884748C0(local, 0);
    lbl_88D245F0.vtbl = lbl_88045818;
    lbl_88D245F0.destroy = (void *)fn_88468D28;
    lbl_88D245F0.thunk = (void *)ts4_vcall0_thunk_88468D10;
    lbl_88D245F0.first_word = local[0];
}

void ts4_init_vtbl_slot_88AF75B0(void)
{
    unsigned local[24];

    ts4_call_seq_lbl_88087078_8847B788(local, 0);
    lbl_88D24690.vtbl = lbl_880457B0;
    lbl_88D24690.destroy = (void *)fn_88468F58;
    lbl_88D24690.thunk = (void *)ts4_vcall0_thunk_88468F40;
    lbl_88D24690.first_word = local[0];
}

void ts4_init_vtbl_slot_88AF7A88(void)
{
    unsigned local[8];

    ts4_call_seq_lbl_880870F4_8847E988(local, 0);
    lbl_88D24880.vtbl = lbl_880456FC;
    lbl_88D24880.destroy = (void *)fn_884692E0;
    lbl_88D24880.thunk = (void *)ts4_vcall0_thunk_884692C8;
    lbl_88D24880.first_word = local[0];
}

void ts4_init_vtbl_slot_88AF7EA8(void)
{
    unsigned local[16];

    ts4_call_seq_lbl_88087154_88481278(local, 0);
    lbl_88D249F0.vtbl = lbl_88045654;
    lbl_88D249F0.destroy = (void *)fn_88469570;
    lbl_88D249F0.thunk = (void *)ts4_vcall0_thunk_88469588;
    lbl_88D249F0.first_word = local[0];
}

void ts4_init_vtbl_slot_88AF8538(void)
{
    unsigned local[88];

    fn_88469AB8(local, 0);
    lbl_88D24C80.vtbl = lbl_88045568;
    lbl_88D24C80.destroy = (void *)fn_88469A70;
    lbl_88D24C80.thunk = (void *)ts4_vcall0_thunk_88469A58;
    lbl_88D24C80.first_word = local[0];
}

void ts4_init_vtbl_slot_88AF89A8(void)
{
    unsigned local[12];

    fn_88486018(local, 0);
    lbl_88D24E40.vtbl = lbl_880454AC;
    lbl_88D24E40.destroy = (void *)fn_88469E10;
    lbl_88D24E40.thunk = (void *)ts4_vcall0_thunk_88469E28;
    lbl_88D24E40.first_word = local[0];
}

void ts4_init_vtbl_slot_88AF8D30(void)
{
    unsigned local[196];

    fn_8846D5E0(local, 0);
    lbl_88D24FA0.vtbl = lbl_88045430;
    lbl_88D24FA0.destroy = (void *)fn_8846A010;
    lbl_88D24FA0.thunk = (void *)ts4_vcall0_thunk_8846A028;
    lbl_88D24FA0.first_word = local[0];
}

void ts4_init_vtbl_slot_88AF8E08(void)
{
    unsigned local[52];

    ts4_if_addr_lbl_88086ED0_88475A78(local, 0);
    lbl_88D24FE0.vtbl = lbl_88045420;
    lbl_88D24FE0.destroy = (void *)fn_8846A070;
    lbl_88D24FE0.thunk = (void *)ts4_vcall0_thunk_8846A088;
    lbl_88D24FE0.first_word = local[0];
}

void ts4_init_vtbl_slot_88AF4CC8(void)
{
    unsigned local[24];

    fn_8843FFA0(local, 0);
    lbl_88D23444.vtbl = lbl_8804683C;
    lbl_88D23444.destroy = (void *)fn_88437950;
    lbl_88D23444.thunk = (void *)ts4_vcall0_thunk_88437938;
    lbl_88D23444.first_word = local[0];
}

void ts4_init_vtbl_slot_88AF4FA8(void)
{
    unsigned local[48];

    fn_88441FF8(local, 0);
    lbl_88D23544.vtbl = lbl_880467EC;
    lbl_88D23544.destroy = (void *)fn_884379F0;
    lbl_88D23544.thunk = (void *)ts4_vcall0_thunk_88437A08;
    lbl_88D23544.first_word = local[0];
}

void ts4_init_vtbl_slot_88AF52A8(void)
{
    unsigned local[28];

    ts4_init_object_88444740(local, 0);
    lbl_88D23634.vtbl = lbl_880467A8;
    lbl_88D23634.destroy = (void *)fn_88437DB8;
    lbl_88D23634.thunk = (void *)ts4_vcall0_thunk_88437DA0;
    lbl_88D23634.first_word = local[0];
}

void ts4_init_vtbl_slot_88AF5418(void)
{
    unsigned local[24];

    fn_884430E8(local, 0);
    lbl_88D236A4.vtbl = lbl_88046798;
    lbl_88D236A4.destroy = (void *)fn_88437E08;
    lbl_88D236A4.thunk = (void *)ts4_vcall0_thunk_88437E20;
    lbl_88D236A4.first_word = local[0];
}
