/* Swing_DLL.xex family of float message senders, executable version 0.0.0.3. */
typedef struct Ts4FloatMessage {
    void *vtable;
    float number;
    int value;
} Ts4FloatMessage;

extern float lbl_8803A3B0;
extern char lbl_88081F98[];
void fn_88451158(void *a, void *c, void *b, int d, Ts4FloatMessage *message);
void fn_88456D98(void *a, void *c, void *b, int d, Ts4FloatMessage *message);
void fn_884582F0(void *a, void *c, void *b, int d, Ts4FloatMessage *message);
void fn_88459450(void *a, void *c, void *b, int d, Ts4FloatMessage *message);
void fn_8845BAF8(void *a, void *c, void *b, int d, Ts4FloatMessage *message);
void fn_8845CA20(void *a, void *c, void *b, int d, Ts4FloatMessage *message);
void fn_8845D9F8(void *a, void *c, void *b, int d, Ts4FloatMessage *message);
void fn_884615A0(void *a, void *c, void *b, int d, Ts4FloatMessage *message);
void fn_884625C8(void *a, void *c, void *b, int d, Ts4FloatMessage *message);
void fn_88463DA0(void *a, void *c, void *b, int d, Ts4FloatMessage *message);

void ts4_send_float_message5_8844E198(void *a, void *b, void *c, int d, int value)
{
    Ts4FloatMessage message;
    message.vtable = lbl_88081F98;
    message.number = lbl_8803A3B0;
    message.value = value;
    fn_884615A0(a, c, b, d, &message);
}

void ts4_send_float_message5_8844E8D0(void *a, void *b, void *c, int d, int value)
{
    Ts4FloatMessage message;
    message.vtable = lbl_88081F98;
    message.number = lbl_8803A3B0;
    message.value = value;
    fn_88451158(a, c, b, d, &message);
}

void ts4_send_float_message5_88457A40(void *a, void *b, void *c, int d, int value)
{
    Ts4FloatMessage message;
    message.vtable = lbl_88081F98;
    message.number = lbl_8803A3B0;
    message.value = value;
    fn_88456D98(a, c, b, d, &message);
}

void ts4_send_float_message5_88458D80(void *a, void *b, void *c, int d, int value)
{
    Ts4FloatMessage message;
    message.vtable = lbl_88081F98;
    message.number = lbl_8803A3B0;
    message.value = value;
    fn_884582F0(a, c, b, d, &message);
}

void ts4_send_float_message5_8845A448(void *a, void *b, void *c, int d, int value)
{
    Ts4FloatMessage message;
    message.vtable = lbl_88081F98;
    message.number = lbl_8803A3B0;
    message.value = value;
    fn_88459450(a, c, b, d, &message);
}

void ts4_send_float_message5_8845C370(void *a, void *b, void *c, int d, int value)
{
    Ts4FloatMessage message;
    message.vtable = lbl_88081F98;
    message.number = lbl_8803A3B0;
    message.value = value;
    fn_8845BAF8(a, c, b, d, &message);
}

void ts4_send_float_message5_8845D320(void *a, void *b, void *c, int d, int value)
{
    Ts4FloatMessage message;
    message.vtable = lbl_88081F98;
    message.number = lbl_8803A3B0;
    message.value = value;
    fn_8845CA20(a, c, b, d, &message);
}

void ts4_send_float_message5_8845E4B8(void *a, void *b, void *c, int d, int value)
{
    Ts4FloatMessage message;
    message.vtable = lbl_88081F98;
    message.number = lbl_8803A3B0;
    message.value = value;
    fn_8845D9F8(a, c, b, d, &message);
}

void ts4_send_float_message5_884631A8(void *a, void *b, void *c, int d, int value)
{
    Ts4FloatMessage message;
    message.vtable = lbl_88081F98;
    message.number = lbl_8803A3B0;
    message.value = value;
    fn_884625C8(a, c, b, d, &message);
}

void ts4_send_float_message5_884647D8(void *a, void *b, void *c, int d, int value)
{
    Ts4FloatMessage message;
    message.vtable = lbl_88081F98;
    message.number = lbl_8803A3B0;
    message.value = value;
    fn_88463DA0(a, c, b, d, &message);
}
