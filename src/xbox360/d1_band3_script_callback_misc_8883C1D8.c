/* Swing_DLL.xex band3 script callbacks with service and manager lookups, executable version 0.0.0.3. */
struct TS4ArgList { void *list; };
struct TS4CallState { char reserved[0x6C]; struct TS4ArgList *args; };
struct TS4CallContext { struct TS4CallState *state; };
struct TS4ServiceInner { char reserved[0x18]; unsigned int value; };
struct TS4Service { char reserved[0x4C]; struct TS4ServiceInner *inner; };
struct TS4Record { char reserved[0x60]; unsigned int first; unsigned int second; };
struct TS4Inner24 { char reserved[8]; unsigned int word8; };
struct TS4Mgr { char reserved[0x24]; struct TS4Inner24 *inner; };
double fn_88822420(void *list, int index);
struct TS4Service *ts4_find_service(unsigned int service_id);
extern void *lbl_88D459E0;
extern struct TS4Mgr *lbl_88D459E8;
void fn_88857B48(void *object, int first, unsigned int second, int flag, unsigned int key);
unsigned int ts4_member_field_get_or0_88838C40(void *object, int value);
void fn_88858098(void *object, int value, unsigned int *result);
struct TS4Record *ts4_member_field_addr_8883B318(void *object, int value);
void fn_8885E268(void *object, unsigned int first, unsigned int second, struct TS4Record *record, int flag);
void fn_8883F0C0(void *object);
void fn_8883EF20(void *object, unsigned int key);

unsigned int ts4_script_callback_8883C1D8(void *unused, struct TS4CallContext *context)
{
    unsigned int value = (unsigned int)fn_88822420(context->state->args->list, 1);
    struct TS4Service *service = ts4_find_service(0xCD365085U);
    service->inner->value = value;
    (void)unused;
    return 0;
}

unsigned int ts4_script_callback_8883C238(void *unused, struct TS4CallContext *context)
{
    unsigned int value = (unsigned int)fn_88822420(context->state->args->list, 1);
    struct TS4Service *service = ts4_find_service(0xD5D7F07CU);
    service->inner->value = value;
    (void)unused;
    return 0;
}



