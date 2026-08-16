typedef unsigned int u32;

extern void ts4_memset(void *destination, int value, u32 size);

/* Swing_DLL.xex 0x88151C70. */
void ts4_initialize_netdb_extended_record(void *record)
{
    char *bytes = (char *)record;

    ts4_memset(bytes, 0, 0x40);
    ts4_memset(bytes + 0x40, 0, 0x80);
    *(u32 *)(bytes + 0xC0) = 0;
    *(u32 *)(bytes + 0xC4) = 0;
    *(u32 *)(bytes + 0xC8) = 0xF4DBDF21;
    *(unsigned char *)(bytes + 0xCC) = 0;
}
