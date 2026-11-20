/* SM4: message senders (stack message object with a vtable pointer) whose argument order differs from the d1_band2 senders. */
typedef struct Ts4ByteMsg { void *vtable; unsigned char flag; int value; } Ts4ByteMsg;
typedef struct Ts4FloatMsg { void *vtable; float number; int value; } Ts4FloatMsg;
extern char lbl_88081FB0[];
extern char lbl_88081F98[];
extern float lbl_8803A3B0;

#define DECL_BYTE(CALLEE) extern void CALLEE(void *, void *, void *, Ts4ByteMsg *);
#define DECL_BYTE2(CALLEE) extern void CALLEE(void *, void *, void *, void *, Ts4ByteMsg *);
#define DECL_FLOAT(CALLEE) extern void CALLEE(void *, void *, void *, Ts4FloatMsg *);

/* callee(p3, p2, p4, &msg) with a byte message carrying value in field 8 */
#define SEND_BYTE_A(NAME, CALLEE) \
    void NAME(void *p1, void *p2, void *p3, void *p4, int value) \
    { \
        Ts4ByteMsg message; \
        (void)p1; \
        message.vtable = lbl_88081FB0; \
        message.flag = 0; \
        message.value = value; \
        CALLEE(p3, p2, p4, &message); \
    }
/* callee(p1, p3, p2, p4, &msg) */
#define SEND_BYTE_B(NAME, CALLEE) \
    void NAME(void *p1, void *p2, void *p3, void *p4, int value) \
    { \
        Ts4ByteMsg message; \
        message.vtable = lbl_88081FB0; \
        message.flag = 0; \
        message.value = value; \
        CALLEE(p1, p3, p2, p4, &message); \
    }
/* callee(p3, p2, p4, &msg) with a float message */
#define SEND_FLOAT_A(NAME, CALLEE) \
    void NAME(void *p1, void *p2, void *p3, void *p4, int value) \
    { \
        Ts4FloatMsg message; \
        (void)p1; \
        message.vtable = lbl_88081F98; \
        message.number = lbl_8803A3B0; \
        message.value = value; \
        CALLEE(p3, p2, p4, &message); \
    }
DECL_BYTE(fn_88450CD0) DECL_BYTE(fn_88452DD0) DECL_BYTE(fn_88454800) DECL_BYTE(fn_88461C60) DECL_BYTE(fn_884572B8) DECL_BYTE(fn_8845B5E8) DECL_BYTE(fn_8845D5B8)
DECL_BYTE2(fn_88461B30) DECL_BYTE2(ts4_call_88450CD0_88451170) DECL_BYTE2(fn_88457E88) DECL_BYTE2(fn_884599A8) DECL_BYTE2(fn_8845C630) DECL_BYTE2(fn_88462A30) DECL_BYTE2(fn_88464138)
DECL_FLOAT(fn_88450A70) DECL_FLOAT(fn_884530E8) DECL_FLOAT(fn_88454588) DECL_FLOAT(fn_884616C0)
SEND_BYTE_A(ts4_send_byte_msg_a_8844DFE0, fn_88450CD0) /* Swing_DLL.xex 0x8844DFE0 */
SEND_BYTE_A(ts4_send_byte_msg_a_88454168, fn_88452DD0) /* Swing_DLL.xex 0x88454168 */
SEND_BYTE_A(ts4_send_byte_msg_a_88455FD0, fn_88454800) /* Swing_DLL.xex 0x88455FD0 */
SEND_BYTE_A(ts4_send_byte_msg_a_88456660, fn_88461C60) /* Swing_DLL.xex 0x88456660 */
SEND_BYTE_A(ts4_send_byte_msg_a_88457A90, fn_884572B8) /* Swing_DLL.xex 0x88457A90 */
SEND_BYTE_A(ts4_send_byte_msg_a_8845C2E0, fn_8845B5E8) /* Swing_DLL.xex 0x8845C2E0 */
SEND_BYTE_A(ts4_send_byte_msg_a_8845E0C8, fn_8845D5B8) /* Swing_DLL.xex 0x8845E0C8 */
SEND_BYTE_B(ts4_send_byte_msg_b_8844E150, fn_88461B30) /* Swing_DLL.xex 0x8844E150 */
SEND_BYTE_B(ts4_send_byte_msg_b_8844E888, ts4_call_88450CD0_88451170) /* Swing_DLL.xex 0x8844E888 */
SEND_BYTE_B(ts4_send_byte_msg_b_88458980, fn_88457E88) /* Swing_DLL.xex 0x88458980 */
SEND_BYTE_B(ts4_send_byte_msg_b_8845A3B8, fn_884599A8) /* Swing_DLL.xex 0x8845A3B8 */
SEND_BYTE_B(ts4_send_byte_msg_b_8845D030, fn_8845C630) /* Swing_DLL.xex 0x8845D030 */
SEND_BYTE_B(ts4_send_byte_msg_b_88463160, fn_88462A30) /* Swing_DLL.xex 0x88463160 */
SEND_BYTE_B(ts4_send_byte_msg_b_88464790, fn_88464138) /* Swing_DLL.xex 0x88464790 */
SEND_FLOAT_A(ts4_send_float_msg_8844E028, fn_88450A70) /* Swing_DLL.xex 0x8844E028 */
SEND_FLOAT_A(ts4_send_float_msg_884541B0, fn_884530E8) /* Swing_DLL.xex 0x884541B0 */
SEND_FLOAT_A(ts4_send_float_msg_88456018, fn_88454588) /* Swing_DLL.xex 0x88456018 */
SEND_FLOAT_A(ts4_send_float_msg_884563E8, fn_884616C0) /* Swing_DLL.xex 0x884563E8 */
