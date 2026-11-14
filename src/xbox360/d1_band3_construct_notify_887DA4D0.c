/* Swing_DLL.xex band3 notification constructors, executable version 0.0.0.3. */
struct TS4Triple {
    unsigned int first;
    unsigned int second;
    unsigned int third;
};
struct TS4NotifyObject {
    char reserved[0x1C];
    void *notification;
};
void *fn_88627EC0(void *object, struct TS4Triple value);
extern void *g_ts4_tsu_notification_object;


void ts4_construct_notify_887DA4D0(struct TS4NotifyObject *self, struct TS4Triple value)
{
    fn_88627EC0(self, value);
    self->notification = g_ts4_tsu_notification_object;
}

void ts4_construct_notify_887DA518(struct TS4NotifyObject *self, struct TS4Triple value)
{
    fn_88627EC0(self, value);
    self->notification = g_ts4_tsu_notification_object;
}

void ts4_construct_notify_887DA560(struct TS4NotifyObject *self, struct TS4Triple value)
{
    fn_88627EC0(self, value);
    self->notification = g_ts4_tsu_notification_object;
}

void ts4_construct_notify_887DA5A8(struct TS4NotifyObject *self, struct TS4Triple value)
{
    fn_88627EC0(self, value);
    self->notification = g_ts4_tsu_notification_object;
}

void ts4_construct_notify_887DA5F0(struct TS4NotifyObject *self, struct TS4Triple value)
{
    fn_88627EC0(self, value);
    self->notification = g_ts4_tsu_notification_object;
}

void ts4_construct_notify_887DA638(struct TS4NotifyObject *self, struct TS4Triple value)
{
    fn_88627EC0(self, value);
    self->notification = g_ts4_tsu_notification_object;
}

void ts4_construct_notify_887DA680(struct TS4NotifyObject *self, struct TS4Triple value)
{
    fn_88627EC0(self, value);
    self->notification = g_ts4_tsu_notification_object;
}

void ts4_construct_notify_887DA6C8(struct TS4NotifyObject *self, struct TS4Triple value)
{
    fn_88627EC0(self, value);
    self->notification = g_ts4_tsu_notification_object;
}
