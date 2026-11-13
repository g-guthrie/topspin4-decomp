/* R6: net message factory (Swing_DLL.xex 0x889BF980). */
typedef unsigned int u32;
typedef unsigned char u8;

typedef struct Ts4NetMessageSource {
    u8 pad[0xA];
    u8 kind;
} Ts4NetMessageSource;

typedef struct Ts4NetMessageObject {
    u32 pad[2];
} Ts4NetMessageObject;

void fn_8864DFF0(void);
void fn_888860A0(void *block);
Ts4NetMessageObject *fn_8899F760(u32 size);
u8 fn_889BE7B0(Ts4NetMessageObject *object, Ts4NetMessageSource *source);
u8 fn_889BE3A8(Ts4NetMessageObject *object, Ts4NetMessageSource *source);
u8 fn_889BE1E8(Ts4NetMessageObject *object, Ts4NetMessageSource *source);
u8 fn_889BDBC8(Ts4NetMessageObject *object, Ts4NetMessageSource *source);

/* Swing_DLL.xex 0x889BF980: allocate a message object and parse it by source kind; NULL on failure. */
Ts4NetMessageObject *ts4_net_create_message_889BF980(Ts4NetMessageSource *source)
{
    Ts4NetMessageObject *object;

    fn_8864DFF0();
    object = fn_8899F760(8);
    if (object != 0) {
        switch (source->kind) {
        case 0:
            if (fn_889BE7B0(object, source)) {
                return object;
            }
            break;
        case 1:
            if (fn_889BE3A8(object, source)) {
                return object;
            }
            break;
        case 4:
            if (fn_889BE1E8(object, source)) {
                return object;
            }
            break;
        case 6:
            if (fn_889BDBC8(object, source)) {
                return object;
            }
            break;
        default:
            break;
        }
        fn_8864DFF0();
        fn_888860A0(object);
    }
    return 0;
}
