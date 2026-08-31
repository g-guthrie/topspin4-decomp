typedef struct Ts4NetDbOwnedRecord {
    unsigned char reserved[0xDB8];
    void *owned;
} Ts4NetDbOwnedRecord;

extern void fn_888860A0(void *owned);

/* Swing_DLL.xex 0x881515B8. */
void ts4_clear_netdb_owned_record(Ts4NetDbOwnedRecord *object)
{
    if ((long)object->owned != 0) {
        fn_888860A0(object->owned);
        object->owned = 0;
    }
}
