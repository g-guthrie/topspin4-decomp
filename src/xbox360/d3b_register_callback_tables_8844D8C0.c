/* Swing_DLL.xex 0x8844D8C0-0x88464600, executable version 0.0.0.3. */
typedef void (*Fn)(void);
typedef struct Slots { Fn f[4]; unsigned char a, b; } Slots;
extern void fn_8844D720(void);
extern void fn_8844DA60(void);
extern void fn_8844DCC8(void);
extern void fn_88450820(void);
extern void fn_88450A70(void);
extern void fn_88450CD0(void);
extern void fn_88452DD0(void);
extern void fn_884530E8(void);
extern void fn_88453520(void);
extern void fn_88453FD0(void);
extern void fn_884557F8(void);
extern void fn_88456710(void);
extern void fn_884567D8(void);
extern void fn_88457028(void);
extern void fn_884572B8(void);
extern void fn_88457CF0(void);
extern void fn_88457DF0(void);
extern void fn_884580B8(void);
extern void fn_884585D0(void);
extern void fn_884596F8(void);
extern void fn_88459C18(void);
extern void fn_8845B5E8(void);
extern void fn_8845BE18(void);
extern void fn_8845C208(void);
extern void fn_8845C768(void);
extern void fn_8845CC10(void);
extern void fn_8845D5B8(void);
extern void fn_8845DCF8(void);
extern void fn_884603F0(void);
extern void fn_884607A8(void);
extern void fn_884608D0(void);
extern void fn_884609F0(void);
extern void fn_88460B10(void);
extern void fn_88460E98(void);
extern void fn_884616C0(void);
extern void fn_88461988(void);
extern void fn_88461C60(void);
extern void fn_884626D0(void);
extern void fn_88462900(void);
extern void fn_88462B40(void);
extern void fn_88463088(void);
extern void fn_88463BC8(void);
extern void fn_88463F80(void);
extern void fn_88464318(void);
extern void fn_884646A8(void);
extern void fn_88467F60(void);
extern void ts4_call_seq_u32_lbl_88CACF08_8844D0E8(void);
extern void ts4_call_seq_u32_lbl_88CACF08_8844D850(void);
extern void ts4_call_seq_u32_lbl_88CACF08_88452D78(void);
extern void ts4_call_seq_u32_lbl_88CACF08_884538D0(void);
extern void ts4_call_seq_u32_lbl_88CACF08_88457540(void);
extern void ts4_call_seq_u32_lbl_88CACF08_88457598(void);
extern void ts4_call_seq_u32_lbl_88CACF08_88458EE0(void);
extern void ts4_call_seq_u32_lbl_88CACF08_88458FD8(void);
extern void ts4_call_seq_u32_lbl_88CACF08_8845B518(void);
extern void ts4_call_seq_u32_lbl_88CACF08_8845B580(void);
extern void ts4_call_seq_u32_lbl_88CACF08_8845C4D0(void);
extern void ts4_call_seq_u32_lbl_88CACF08_8845C5B0(void);
extern void ts4_call_seq_u32_lbl_88CACF08_8845D480(void);
extern void ts4_call_seq_u32_lbl_88CACF08_8845D550(void);
extern void ts4_call_seq_u32_lbl_88CACF08_88462280(void);
extern void ts4_call_seq_u32_lbl_88CACF08_884622D8(void);
extern void ts4_call_seq_u32_lbl_88CACF08_88462E58(void);
extern void ts4_call_seq_u32_lbl_88CACF08_88462EB0(void);
extern void ts4_call_seq_u32_lbl_88CACF08_88463780(void);
extern void ts4_call_seq_u32_lbl_88CACF08_884644D0(void);
extern void ts4_send_byte_message_8844DC80(void);
extern void ts4_send_byte_message_88453F38(void);
extern void ts4_send_byte_message_88455760(void);
extern void ts4_send_byte_message_884576D8(void);
extern void ts4_send_byte_message_884589C8(void);
extern void ts4_send_byte_message_8845A400(void);
extern void ts4_send_byte_message_8845C328(void);
extern void ts4_send_byte_message_8845D078(void);
extern void ts4_send_byte_message_8845E110(void);
extern void ts4_send_byte_message_88460E00(void);
extern void ts4_send_byte_message_88462FF0(void);
extern void ts4_send_byte_message_88464610(void);
extern void ts4_send_float_message_8844CAA0(void);
extern void ts4_send_float_message_88453F80(void);
extern void ts4_send_float_message_884557A8(void);
extern void ts4_send_float_message_88457720(void);
extern void ts4_send_float_message_88458DD0(void);
extern void ts4_send_float_message_8845A498(void);
extern void ts4_send_float_message_8845C3C0(void);
extern void ts4_send_float_message_8845D370(void);
extern void ts4_send_float_message_8845E508(void);
extern void ts4_send_float_message_88460E48(void);
extern void ts4_send_float_message_88463038(void);
extern void ts4_send_float_message_88464658(void);
void fn_88451F18(void *self, Slots *s, int n, int m);
void fn_88452028(void *self, Slots *s, int n, int m);

/* Registers two four-callback tables with the dispatcher, each with two flag bytes and a (count, limit) pair. */
#define REG_TABLES(NAME, REG, A0, B0, N0, M0, A1, B1, N1, M1, F0, F1, F2, F3, G0, G1, G2, G3) \
void NAME(void *self) \
{ \
    Slots s0, s1; \
    s0.f[0] = F0; s0.f[1] = F1; s0.f[2] = F2; s0.f[3] = F3; \
    s0.a = A0; s0.b = B0; \
    REG(self, &s0, N0, M0); \
    s1.f[0] = G0; s1.f[1] = G1; s1.f[2] = G2; s1.f[3] = G3; \
    s1.a = A1; s1.b = B1; \
    REG(self, &s1, N1, M1); \
}

REG_TABLES(ts4_register_callback_tables_8844D8C0, fn_88451F18, 1, 1, 9, 1, 0, 1, 1, 9, ts4_call_seq_u32_lbl_88CACF08_8844D850, ts4_send_byte_message_8844DC80, ts4_send_float_message_8844CAA0, fn_8844DCC8, ts4_call_seq_u32_lbl_88CACF08_8844D0E8, fn_88450CD0, fn_88450A70, fn_88450820)
REG_TABLES(ts4_register_callback_tables_8844D990, fn_88451F18, 1, 1, 9, 23, 0, 1, 23, 9, ts4_call_seq_u32_lbl_88CACF08_8844D850, ts4_send_byte_message_8844DC80, ts4_send_float_message_8844CAA0, fn_8844DCC8, ts4_call_seq_u32_lbl_88CACF08_8844D0E8, fn_88450CD0, fn_88450A70, fn_88450820)
REG_TABLES(ts4_register_callback_tables_8844DBB0, fn_88451F18, 1, 1, 9, 21, 0, 1, 21, 9, fn_8844DA60, ts4_send_byte_message_8844DC80, ts4_send_float_message_8844CAA0, fn_8844DCC8, fn_8844D720, fn_88450CD0, fn_88450A70, fn_88450820)
REG_TABLES(ts4_register_callback_tables_88453940, fn_88451F18, 1, 1, 24, 25, 0, 1, 25, 24, ts4_call_seq_u32_lbl_88CACF08_884538D0, ts4_send_byte_message_88453F38, ts4_send_float_message_88453F80, fn_88453FD0, ts4_call_seq_u32_lbl_88CACF08_88452D78, fn_88452DD0, fn_884530E8, fn_88453520)
REG_TABLES(ts4_register_callback_tables_884568A8, fn_88451F18, 1, 1, 10, -1, 0, 1, -1, 10, fn_884567D8, fn_88461C60, fn_884616C0, fn_88461988, fn_88456710, ts4_send_byte_message_88455760, ts4_send_float_message_884557A8, fn_884557F8)
REG_TABLES(ts4_register_callback_tables_88457608, fn_88451F18, 1, 1, 1, 23, 0, 1, 23, 1, ts4_call_seq_u32_lbl_88CACF08_88457598, ts4_send_byte_message_884576D8, ts4_send_float_message_88457720, fn_8845C208, ts4_call_seq_u32_lbl_88CACF08_88457540, fn_884572B8, fn_88457028, fn_88467F60)
REG_TABLES(ts4_register_callback_tables_884588B0, fn_88451F18, 1, 0, 4, 20, 0, 0, 20, 4, fn_88457DF0, ts4_send_byte_message_884589C8, ts4_send_float_message_88458DD0, fn_8845C208, fn_88457CF0, fn_884580B8, fn_884585D0, fn_88467F60)
REG_TABLES(ts4_register_callback_tables_88459F18, fn_88451F18, 1, 0, 4, 6, 0, 0, 6, 4, ts4_call_seq_u32_lbl_88CACF08_88458FD8, ts4_send_byte_message_8845A400, ts4_send_float_message_8845A498, fn_8845C208, ts4_call_seq_u32_lbl_88CACF08_88458EE0, fn_88459C18, fn_884596F8, fn_88467F60)
REG_TABLES(ts4_register_callback_tables_88459FE8, fn_88452028, 1, 0, 4, 6, 0, 0, 6, 4, ts4_call_seq_u32_lbl_88CACF08_88458FD8, ts4_send_byte_message_8845A400, ts4_send_float_message_8845A498, fn_8845C208, ts4_call_seq_u32_lbl_88CACF08_88458EE0, fn_88459C18, fn_884596F8, fn_88467F60)
REG_TABLES(ts4_register_callback_tables_8845C138, fn_88451F18, 1, 0, 5, 2, 0, 0, 2, 5, ts4_call_seq_u32_lbl_88CACF08_8845B518, ts4_send_byte_message_8845C328, ts4_send_float_message_8845C3C0, fn_8845C208, ts4_call_seq_u32_lbl_88CACF08_8845B580, fn_8845B5E8, fn_8845BE18, fn_88467F60)
REG_TABLES(ts4_register_callback_tables_8845CE90, fn_88451F18, 1, 0, 4, 2, 0, 0, 2, 4, ts4_call_seq_u32_lbl_88CACF08_8845C5B0, ts4_send_byte_message_8845D078, ts4_send_float_message_8845D370, fn_8845C208, ts4_call_seq_u32_lbl_88CACF08_8845C4D0, fn_8845C768, fn_8845CC10, fn_88467F60)
REG_TABLES(ts4_register_callback_tables_8845CF60, fn_88452028, 1, 0, 4, 2, 0, 0, 2, 4, ts4_call_seq_u32_lbl_88CACF08_8845C5B0, ts4_send_byte_message_8845D078, ts4_send_float_message_8845D370, fn_8845C208, ts4_call_seq_u32_lbl_88CACF08_8845C4D0, fn_8845C768, fn_8845CC10, fn_88467F60)
REG_TABLES(ts4_register_callback_tables_8845DFF8, fn_88451F18, 1, 0, 6, 2, 0, 0, 2, 6, ts4_call_seq_u32_lbl_88CACF08_8845D550, ts4_send_byte_message_8845E110, ts4_send_float_message_8845E508, fn_8845C208, ts4_call_seq_u32_lbl_88CACF08_8845D480, fn_8845D5B8, fn_8845DCF8, fn_88467F60)
REG_TABLES(ts4_register_callback_tables_88460C20, fn_88451F18, 1, 1, -1, 28, 0, 1, 28, -1, fn_88460B10, ts4_send_byte_message_88460E00, ts4_send_float_message_88460E48, fn_88460E98, fn_884603F0, fn_884609F0, fn_884608D0, fn_884607A8)
REG_TABLES(ts4_register_callback_tables_88462348, fn_88451F18, 1, 1, -1, 8, 0, 1, 8, -1, ts4_call_seq_u32_lbl_88CACF08_884622D8, ts4_send_byte_message_88455760, ts4_send_float_message_884557A8, fn_884557F8, ts4_call_seq_u32_lbl_88CACF08_88462280, fn_88461C60, fn_884616C0, fn_88461988)
REG_TABLES(ts4_register_callback_tables_88462F20, fn_88451F18, 1, 1, -1, 20, 0, 1, 20, -1, ts4_call_seq_u32_lbl_88CACF08_88462EB0, ts4_send_byte_message_88462FF0, ts4_send_float_message_88463038, fn_88463088, ts4_call_seq_u32_lbl_88CACF08_88462E58, fn_88462B40, fn_884626D0, fn_88462900)
REG_TABLES(ts4_register_callback_tables_88464540, fn_88451F18, 1, 1, -1, 26, 0, 1, 26, -1, ts4_call_seq_u32_lbl_88CACF08_884644D0, ts4_send_byte_message_88464610, ts4_send_float_message_88464658, fn_884646A8, ts4_call_seq_u32_lbl_88CACF08_88463780, fn_88464318, fn_88463F80, fn_88463BC8)
