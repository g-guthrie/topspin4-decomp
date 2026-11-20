/* Swing_DLL.xex 0x88614030-0x886140B8, executable version 0.0.0.3. */
typedef unsigned int u32;
extern void ts4_normalize_dir_path_88606978(void *buf);
extern u32 fn_88608590(u32 a, void *buf);

typedef struct { u32 val; u32 key; } ts4_pair;

u32 ts4_find_value_by_key_88614030(char *self)
{
    char buf[0x200];
    u32 key;
    u32 r;
    int i;

    ts4_normalize_dir_path_88606978(buf);
    key = fn_88608590(0, buf);
    r = (u32)-1;
    for (i = 0; i < 0x8c; i++) {
        if (((ts4_pair *)(self + 0x30))[i].key == key) {
            r = ((ts4_pair *)(self + 0x30))[i].val;
            break;
        }
    }
    return r;
}
