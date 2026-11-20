/* Swing_DLL.xex family of byte message senders, executable version 0.0.0.3. */
typedef struct Ts4ByteMessage {
    void *vtable;
    unsigned char flag;
    int value;
} Ts4ByteMessage;

extern char lbl_88081FB0[];
void fn_88450CD0(void *target, void *source, int extra, Ts4ByteMessage *message);
void fn_88452DD0(void *target, void *source, int extra, Ts4ByteMessage *message);
void fn_88454800(void *target, void *source, int extra, Ts4ByteMessage *message);
void fn_884572B8(void *target, void *source, int extra, Ts4ByteMessage *message);
void fn_884580B8(void *target, void *source, int extra, Ts4ByteMessage *message);
void fn_88459C18(void *target, void *source, int extra, Ts4ByteMessage *message);
void fn_8845B5E8(void *target, void *source, int extra, Ts4ByteMessage *message);
void fn_8845C768(void *target, void *source, int extra, Ts4ByteMessage *message);
void fn_8845D5B8(void *target, void *source, int extra, Ts4ByteMessage *message);
void fn_884609F0(void *target, void *source, int extra, Ts4ByteMessage *message);
void fn_88461C60(void *target, void *source, int extra, Ts4ByteMessage *message);
void fn_88462B40(void *target, void *source, int extra, Ts4ByteMessage *message);
void fn_88464318(void *target, void *source, int extra, Ts4ByteMessage *message);

void ts4_send_byte_message_8844DC80(void *source, void *target, int extra, int value)
{
    Ts4ByteMessage message;
    message.vtable = lbl_88081FB0;
    message.flag = 0;
    message.value = value;
    fn_88450CD0(target, source, extra, &message);
}

void ts4_send_byte_message_88453F38(void *source, void *target, int extra, int value)
{
    Ts4ByteMessage message;
    message.vtable = lbl_88081FB0;
    message.flag = 0;
    message.value = value;
    fn_88452DD0(target, source, extra, &message);
}

void ts4_send_byte_message_88455760(void *source, void *target, int extra, int value)
{
    Ts4ByteMessage message;
    message.vtable = lbl_88081FB0;
    message.flag = 0;
    message.value = value;
    fn_88461C60(target, source, extra, &message);
}

void ts4_send_byte_message_88455DF0(void *source, void *target, int extra, int value)
{
    Ts4ByteMessage message;
    message.vtable = lbl_88081FB0;
    message.flag = 0;
    message.value = value;
    fn_88454800(target, source, extra, &message);
}

void ts4_send_byte_message_88456438(void *source, void *target, int extra, int value)
{
    Ts4ByteMessage message;
    message.vtable = lbl_88081FB0;
    message.flag = 0;
    message.value = value;
    fn_88461C60(target, source, extra, &message);
}

void ts4_send_byte_message_884576D8(void *source, void *target, int extra, int value)
{
    Ts4ByteMessage message;
    message.vtable = lbl_88081FB0;
    message.flag = 0;
    message.value = value;
    fn_884572B8(target, source, extra, &message);
}

void ts4_send_byte_message_884589C8(void *source, void *target, int extra, int value)
{
    Ts4ByteMessage message;
    message.vtable = lbl_88081FB0;
    message.flag = 0;
    message.value = value;
    fn_884580B8(target, source, extra, &message);
}

void ts4_send_byte_message_8845A400(void *source, void *target, int extra, int value)
{
    Ts4ByteMessage message;
    message.vtable = lbl_88081FB0;
    message.flag = 0;
    message.value = value;
    fn_88459C18(target, source, extra, &message);
}

void ts4_send_byte_message_8845C328(void *source, void *target, int extra, int value)
{
    Ts4ByteMessage message;
    message.vtable = lbl_88081FB0;
    message.flag = 0;
    message.value = value;
    fn_8845B5E8(target, source, extra, &message);
}

void ts4_send_byte_message_8845D078(void *source, void *target, int extra, int value)
{
    Ts4ByteMessage message;
    message.vtable = lbl_88081FB0;
    message.flag = 0;
    message.value = value;
    fn_8845C768(target, source, extra, &message);
}

void ts4_send_byte_message_8845E110(void *source, void *target, int extra, int value)
{
    Ts4ByteMessage message;
    message.vtable = lbl_88081FB0;
    message.flag = 0;
    message.value = value;
    fn_8845D5B8(target, source, extra, &message);
}

void ts4_send_byte_message_88460E00(void *source, void *target, int extra, int value)
{
    Ts4ByteMessage message;
    message.vtable = lbl_88081FB0;
    message.flag = 0;
    message.value = value;
    fn_884609F0(target, source, extra, &message);
}

void ts4_send_byte_message_88462FF0(void *source, void *target, int extra, int value)
{
    Ts4ByteMessage message;
    message.vtable = lbl_88081FB0;
    message.flag = 0;
    message.value = value;
    fn_88462B40(target, source, extra, &message);
}

void ts4_send_byte_message_88464610(void *source, void *target, int extra, int value)
{
    Ts4ByteMessage message;
    message.vtable = lbl_88081FB0;
    message.flag = 0;
    message.value = value;
    fn_88464318(target, source, extra, &message);
}
