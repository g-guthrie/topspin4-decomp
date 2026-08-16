typedef unsigned int u32;

extern void ts4_memset(void *destination, int value, u32 size);

/* Swing_DLL.xex 0x88151B08. */
void ts4_initialize_netdb_stat_record(void *record)
{
    char *bytes = (char *)record;

    ts4_memset(bytes, 0, 0x40);
    ts4_memset(bytes + 0x40, 0, 0x20);
    ts4_memset(bytes + 0x60, 0, 0x10);
    ts4_memset(bytes + 0x70, 0, 0x10);
    *(u32 *)(bytes + 0x80) = 0;
    *(u32 *)(bytes + 0x84) = 0;
    *(u32 *)(bytes + 0x88) = 0xF4DBDF21;
    *(u32 *)(bytes + 0x8C) = 0xF4DBDF21;
    *(u32 *)(bytes + 0x90) = 0;
    *(unsigned char *)(bytes + 0x94) = 0;
}
