/* Swing_DLL.xex family of tracked object factories, executable version 0.0.0.3. */
typedef struct Ts4AllocHeader {
    unsigned int reserved;
    unsigned short size;
} Ts4AllocHeader;

extern unsigned int lbl_88CACF08;
void *KeTlsGetValue(unsigned int index);
Ts4AllocHeader *fn_8841A510(void *allocator, int size, int kind);
void *ts4_call_seq_fn_884B70D0_884A98E8(void *header, void *argument);
void *fn_884A9FE0(void *header, void *argument);
void *fn_884AADD8(void *header, void *argument);
void *fn_884AB908(void *header, void *argument);
void *fn_884ACA78(void *header, void *argument);
void *fn_884ADDB0(void *header, void *argument);
void *ts4_call_seq_fn_884B70D0_884AE6A8(void *header, void *argument);
void *fn_884AF088(void *header, void *argument);
void *fn_884AFB70(void *header, void *argument);
void *ts4_call_seq_fn_884B96F0_884B00F0(void *header, void *argument);
void *ts4_call_seq_fn_884B96F0_884B0218(void *header, void *argument);
void *fn_884B06B0(void *header, void *argument);
void *fn_884B1450(void *header, void *argument);
void *fn_884B20B0(void *header, void *argument);
void *fn_884B23B0(void *header, void *argument);
void *fn_884B2ED8(void *header, void *argument);
void *fn_884EDA58(void *header, void *argument);
void *fn_884EE6A0(void *header, void *argument);

void *ts4_create_tracked_object_884A9950(void *argument)
{
    void *allocator = KeTlsGetValue(lbl_88CACF08);
    Ts4AllocHeader *header = fn_8841A510(allocator, 0x54, 53);
    char *object;
    header->size = 0x54;
    object = ts4_call_seq_fn_884B70D0_884A98E8(header, argument);
    return object != 0 ? object + 8 : 0;
}

void *ts4_create_tracked_object_884AA708(void *argument)
{
    void *allocator = KeTlsGetValue(lbl_88CACF08);
    Ts4AllocHeader *header = fn_8841A510(allocator, 0x3c, 53);
    char *object;
    header->size = 0x3c;
    object = fn_884A9FE0(header, argument);
    return object != 0 ? object + 8 : 0;
}

void *ts4_create_tracked_object_884AB258(void *argument)
{
    void *allocator = KeTlsGetValue(lbl_88CACF08);
    Ts4AllocHeader *header = fn_8841A510(allocator, 0x3c, 53);
    char *object;
    header->size = 0x3c;
    object = fn_884AADD8(header, argument);
    return object != 0 ? object + 8 : 0;
}

void *ts4_create_tracked_object_884ABB50(void *argument)
{
    void *allocator = KeTlsGetValue(lbl_88CACF08);
    Ts4AllocHeader *header = fn_8841A510(allocator, 0x48, 53);
    char *object;
    header->size = 0x48;
    object = fn_884AB908(header, argument);
    return object != 0 ? object + 8 : 0;
}

void *ts4_create_tracked_object_884ACBC8(void *argument)
{
    void *allocator = KeTlsGetValue(lbl_88CACF08);
    Ts4AllocHeader *header = fn_8841A510(allocator, 0x6c, 53);
    char *object;
    header->size = 0x6c;
    object = fn_884ACA78(header, argument);
    return object != 0 ? object + 8 : 0;
}

void *ts4_create_tracked_object_884AE1F8(void *argument)
{
    void *allocator = KeTlsGetValue(lbl_88CACF08);
    Ts4AllocHeader *header = fn_8841A510(allocator, 0x3c, 53);
    char *object;
    header->size = 0x3c;
    object = fn_884ADDB0(header, argument);
    return object != 0 ? object + 8 : 0;
}

void *ts4_create_tracked_object_884AE808(void *argument)
{
    void *allocator = KeTlsGetValue(lbl_88CACF08);
    Ts4AllocHeader *header = fn_8841A510(allocator, 0x34, 53);
    char *object;
    header->size = 0x34;
    object = ts4_call_seq_fn_884B70D0_884AE6A8(header, argument);
    return object != 0 ? object + 8 : 0;
}

void *ts4_create_tracked_object_884AF270(void *argument)
{
    void *allocator = KeTlsGetValue(lbl_88CACF08);
    Ts4AllocHeader *header = fn_8841A510(allocator, 0x48, 53);
    char *object;
    header->size = 0x48;
    object = fn_884AF088(header, argument);
    return object != 0 ? object + 8 : 0;
}

void *ts4_create_tracked_object_884AFF80(void *argument)
{
    void *allocator = KeTlsGetValue(lbl_88CACF08);
    Ts4AllocHeader *header = fn_8841A510(allocator, 0x2c, 53);
    char *object;
    header->size = 0x2c;
    object = fn_884AFB70(header, argument);
    return object != 0 ? object + 8 : 0;
}

void *ts4_create_tracked_object_884B0160(void *argument)
{
    void *allocator = KeTlsGetValue(lbl_88CACF08);
    Ts4AllocHeader *header = fn_8841A510(allocator, 0x30, 53);
    char *object;
    header->size = 0x30;
    object = ts4_call_seq_fn_884B96F0_884B00F0(header, argument);
    return object != 0 ? object + 8 : 0;
}

void *ts4_create_tracked_object_884B0288(void *argument)
{
    void *allocator = KeTlsGetValue(lbl_88CACF08);
    Ts4AllocHeader *header = fn_8841A510(allocator, 0x30, 53);
    char *object;
    header->size = 0x30;
    object = ts4_call_seq_fn_884B96F0_884B0218(header, argument);
    return object != 0 ? object + 8 : 0;
}

void *ts4_create_tracked_object_884B09F8(void *argument)
{
    void *allocator = KeTlsGetValue(lbl_88CACF08);
    Ts4AllocHeader *header = fn_8841A510(allocator, 0x3c, 53);
    char *object;
    header->size = 0x3c;
    object = fn_884B06B0(header, argument);
    return object != 0 ? object + 8 : 0;
}

void *ts4_create_tracked_object_884B17D8(void *argument)
{
    void *allocator = KeTlsGetValue(lbl_88CACF08);
    Ts4AllocHeader *header = fn_8841A510(allocator, 0x38, 17);
    char *object;
    header->size = 0x38;
    object = fn_884B1450(header, argument);
    return object != 0 ? object + 8 : 0;
}

void *ts4_create_tracked_object_884B2238(void *argument)
{
    void *allocator = KeTlsGetValue(lbl_88CACF08);
    Ts4AllocHeader *header = fn_8841A510(allocator, 0x3c, 53);
    char *object;
    header->size = 0x3c;
    object = fn_884B20B0(header, argument);
    return object != 0 ? object + 8 : 0;
}

void *ts4_create_tracked_object_884B2580(void *argument)
{
    void *allocator = KeTlsGetValue(lbl_88CACF08);
    Ts4AllocHeader *header = fn_8841A510(allocator, 0x38, 17);
    char *object;
    header->size = 0x38;
    object = fn_884B23B0(header, argument);
    return object != 0 ? object + 8 : 0;
}

void *ts4_create_tracked_object_884B30A8(void *argument)
{
    void *allocator = KeTlsGetValue(lbl_88CACF08);
    Ts4AllocHeader *header = fn_8841A510(allocator, 0x38, 17);
    char *object;
    header->size = 0x38;
    object = fn_884B2ED8(header, argument);
    return object != 0 ? object + 8 : 0;
}

void *ts4_create_tracked_object_884EDC20(void *argument)
{
    void *allocator = KeTlsGetValue(lbl_88CACF08);
    Ts4AllocHeader *header = fn_8841A510(allocator, 0x30, 53);
    char *object;
    header->size = 0x30;
    object = fn_884EDA58(header, argument);
    return object != 0 ? object + 8 : 0;
}

void *ts4_create_tracked_object_884EEF90(void *argument)
{
    void *allocator = KeTlsGetValue(lbl_88CACF08);
    Ts4AllocHeader *header = fn_8841A510(allocator, 0x44, 53);
    char *object;
    header->size = 0x44;
    object = fn_884EE6A0(header, argument);
    return object != 0 ? object + 8 : 0;
}
