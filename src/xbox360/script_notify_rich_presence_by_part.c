typedef unsigned char ts4_u8;
typedef unsigned int ts4_u32;

extern void *lbl_88D45960;
void *ts4_find_service(ts4_u32 service_id);
void fn_888E8A80(void *object, ts4_u32 *value);

struct TS4PresenceResult {
    ts4_u8 reserved[0x2C];
    ts4_u32 value;
};

struct TS4PresenceServiceVTable {
    ts4_u8 reserved[0x4C];
    struct TS4PresenceResult *(*get_result)(void *service, int index);
};

struct TS4PresenceService {
    struct TS4PresenceServiceVTable *vtable;
};

/* Registered as NotifyRichPresenceByPart. */
ts4_u32 ts4_script_notify_rich_presence_by_part(void)
{
    struct TS4PresenceService *service = ts4_find_service(0xC24FECAC);
    struct TS4PresenceResult *result;
    ts4_u32 value;

    if (service == 0) {
        return 0;
    }
    result = service->vtable->get_result(service, 0);
    value = result->value;
    if (lbl_88D45960 != 0) {
        fn_888E8A80(lbl_88D45960, &value);
    }
    return 1;
}
