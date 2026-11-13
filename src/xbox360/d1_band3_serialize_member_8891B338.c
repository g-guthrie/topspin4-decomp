/* Swing_DLL.xex band3 serialization helpers, executable version 0.0.0.3. */
struct TS4SerObj;
struct TS4SerVTable {
    void *slot0;
    void *slot1;
    void *slot2;
    void *(*slot3)(struct TS4SerObj *self);
};
struct TS4SerObj {
    struct TS4SerVTable *vtable;
};
extern void *lbl_88C6B4AC;
void fn_889393C0(void *stream, void *value, void *tag);


void ts4_serialize_member_8891B338(struct TS4SerObj *self, void *stream)
{
    fn_889393C0(stream, self->vtable->slot3(self), lbl_88C6B4AC);
}

void ts4_serialize_member_8891B3F0(struct TS4SerObj *self, void *stream)
{
    fn_889393C0(stream, self->vtable->slot3(self), lbl_88C6B4AC);
}

void ts4_serialize_member_8891B448(struct TS4SerObj *self, void *stream)
{
    fn_889393C0(stream, self->vtable->slot3(self), lbl_88C6B4AC);
}

void ts4_serialize_member_8891F730(struct TS4SerObj *self, void *stream)
{
    fn_889393C0(stream, self->vtable->slot3(self), lbl_88C6B4AC);
}

void ts4_serialize_member_8891F7D8(struct TS4SerObj *self, void *stream)
{
    fn_889393C0(stream, self->vtable->slot3(self), lbl_88C6B4AC);
}

void ts4_serialize_member_8893B868(struct TS4SerObj *self, void *stream)
{
    fn_889393C0(stream, self->vtable->slot3(self), lbl_88C6B4AC);
}

void ts4_serialize_member_8893BB10(struct TS4SerObj *self, void *stream)
{
    fn_889393C0(stream, self->vtable->slot3(self), lbl_88C6B4AC);
}

void ts4_serialize_member_8893BD88(struct TS4SerObj *self, void *stream)
{
    fn_889393C0(stream, self->vtable->slot3(self), lbl_88C6B4AC);
}

void ts4_serialize_member_889AF6E0(struct TS4SerObj *self, void *stream)
{
    fn_889393C0(stream, self->vtable->slot3(self), lbl_88C6B4AC);
}

void ts4_serialize_member_889AFD98(struct TS4SerObj *self, void *stream)
{
    fn_889393C0(stream, self->vtable->slot3(self), lbl_88C6B4AC);
}

void ts4_serialize_member_889AFDF0(struct TS4SerObj *self, void *stream)
{
    fn_889393C0(stream, self->vtable->slot3(self), lbl_88C6B4AC);
}
