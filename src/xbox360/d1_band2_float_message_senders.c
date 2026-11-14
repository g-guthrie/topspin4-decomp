/* Swing_DLL.xex family of float message senders, executable version 0.0.0.3. */
typedef struct Ts4FloatMessage {
    void *vtable;
    float number;
    int value;
} Ts4FloatMessage;

extern float lbl_8803A3B0;
extern char lbl_88081F98[];
void fn_88450A70(void *target, void *source, int extra, Ts4FloatMessage *message);
void fn_884530E8(void *target, void *source, int extra, Ts4FloatMessage *message);
void fn_88454588(void *target, void *source, int extra, Ts4FloatMessage *message);
void fn_88457028(void *target, void *source, int extra, Ts4FloatMessage *message);
void fn_884585D0(void *target, void *source, int extra, Ts4FloatMessage *message);
void fn_884596F8(void *target, void *source, int extra, Ts4FloatMessage *message);
void fn_8845BE18(void *target, void *source, int extra, Ts4FloatMessage *message);
void fn_8845CC10(void *target, void *source, int extra, Ts4FloatMessage *message);
void fn_8845DCF8(void *target, void *source, int extra, Ts4FloatMessage *message);
void fn_884608D0(void *target, void *source, int extra, Ts4FloatMessage *message);
void fn_884616C0(void *target, void *source, int extra, Ts4FloatMessage *message);
void fn_884626D0(void *target, void *source, int extra, Ts4FloatMessage *message);
void fn_88463F80(void *target, void *source, int extra, Ts4FloatMessage *message);

void ts4_send_float_message_8844CAA0(void *source, void *target, int extra, int value)
{
    Ts4FloatMessage message;
    message.vtable = lbl_88081F98;
    message.number = lbl_8803A3B0;
    message.value = value;
    fn_88450A70(target, source, extra, &message);
}

void ts4_send_float_message_88453F80(void *source, void *target, int extra, int value)
{
    Ts4FloatMessage message;
    message.vtable = lbl_88081F98;
    message.number = lbl_8803A3B0;
    message.value = value;
    fn_884530E8(target, source, extra, &message);
}

void ts4_send_float_message_884557A8(void *source, void *target, int extra, int value)
{
    Ts4FloatMessage message;
    message.vtable = lbl_88081F98;
    message.number = lbl_8803A3B0;
    message.value = value;
    fn_884616C0(target, source, extra, &message);
}

void ts4_send_float_message_88455E38(void *source, void *target, int extra, int value)
{
    Ts4FloatMessage message;
    message.vtable = lbl_88081F98;
    message.number = lbl_8803A3B0;
    message.value = value;
    fn_88454588(target, source, extra, &message);
}

void ts4_send_float_message_88456398(void *source, void *target, int extra, int value)
{
    Ts4FloatMessage message;
    message.vtable = lbl_88081F98;
    message.number = lbl_8803A3B0;
    message.value = value;
    fn_884616C0(target, source, extra, &message);
}

void ts4_send_float_message_88457720(void *source, void *target, int extra, int value)
{
    Ts4FloatMessage message;
    message.vtable = lbl_88081F98;
    message.number = lbl_8803A3B0;
    message.value = value;
    fn_88457028(target, source, extra, &message);
}

void ts4_send_float_message_88458DD0(void *source, void *target, int extra, int value)
{
    Ts4FloatMessage message;
    message.vtable = lbl_88081F98;
    message.number = lbl_8803A3B0;
    message.value = value;
    fn_884585D0(target, source, extra, &message);
}

void ts4_send_float_message_8845A498(void *source, void *target, int extra, int value)
{
    Ts4FloatMessage message;
    message.vtable = lbl_88081F98;
    message.number = lbl_8803A3B0;
    message.value = value;
    fn_884596F8(target, source, extra, &message);
}

void ts4_send_float_message_8845C3C0(void *source, void *target, int extra, int value)
{
    Ts4FloatMessage message;
    message.vtable = lbl_88081F98;
    message.number = lbl_8803A3B0;
    message.value = value;
    fn_8845BE18(target, source, extra, &message);
}

void ts4_send_float_message_8845D370(void *source, void *target, int extra, int value)
{
    Ts4FloatMessage message;
    message.vtable = lbl_88081F98;
    message.number = lbl_8803A3B0;
    message.value = value;
    fn_8845CC10(target, source, extra, &message);
}

void ts4_send_float_message_8845E508(void *source, void *target, int extra, int value)
{
    Ts4FloatMessage message;
    message.vtable = lbl_88081F98;
    message.number = lbl_8803A3B0;
    message.value = value;
    fn_8845DCF8(target, source, extra, &message);
}

void ts4_send_float_message_88460E48(void *source, void *target, int extra, int value)
{
    Ts4FloatMessage message;
    message.vtable = lbl_88081F98;
    message.number = lbl_8803A3B0;
    message.value = value;
    fn_884608D0(target, source, extra, &message);
}

void ts4_send_float_message_88463038(void *source, void *target, int extra, int value)
{
    Ts4FloatMessage message;
    message.vtable = lbl_88081F98;
    message.number = lbl_8803A3B0;
    message.value = value;
    fn_884626D0(target, source, extra, &message);
}

void ts4_send_float_message_88464658(void *source, void *target, int extra, int value)
{
    Ts4FloatMessage message;
    message.vtable = lbl_88081F98;
    message.number = lbl_8803A3B0;
    message.value = value;
    fn_88463F80(target, source, extra, &message);
}
