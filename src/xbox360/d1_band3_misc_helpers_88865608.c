/* Swing_DLL.xex band3 miscellaneous helpers, executable version 0.0.0.3. */
struct TS4Reader {
    char reserved[0x42C];
    unsigned int value;
};
struct TS4DispObj;
struct TS4DispTable {
    void *slots[10];
    void (*slot10)(void *self, struct TS4DispObj *object, unsigned int value);
};
struct TS4DispObj {
    struct TS4DispTable *vtable;
};
extern void *lbl_88D459DC;
void fn_88865388(void *object, int a, void *b, unsigned char *flag);
void ts4_object_finalize(void *object);
void fn_889395D8(void *stream, unsigned int *value);

void ts4_call_with_false_flag_88865608(void *arg)
{
    unsigned char flag = 0;
    fn_88865388(lbl_88D459DC, 0, arg, &flag);
}

void ts4_call_with_false_flag_88865688(void *arg)
{
    unsigned char flag = 0;
    fn_88865388(lbl_88D459DC, 0, arg, &flag);
}

void ts4_finalize_both_886C91F0(char *self)
{
    ts4_object_finalize(self + 0x2C);
    ts4_object_finalize(self);
}



void *ts4_dispatch_slot10_88884698(void *self, struct TS4DispObj *object, unsigned int *value)
{
    object->vtable->slot10(self, object, *value);
    return self;
}

void *ts4_dispatch_slot10_88884980(void *self, struct TS4DispObj *object, unsigned int *value)
{
    object->vtable->slot10(self, object, *value);
    return self;
}
