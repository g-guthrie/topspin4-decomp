/* Loader_DLL.xex 0x830B3540-0x8314C780, executable version 0.0.0.3. */
/* Struct assignments of this size are lowered by the compiler to memcpy (fn_833E3AD0). */
typedef struct B1C { int a[7]; } B1C;
typedef struct B40 { int a[16]; } B40;
void ts4l_copy_state_830B3540(char *dev, B1C *dst)
{
    *dst = *(B1C *)(dev + 0x3218);
}

int ts4l_copy_block_8314C780(char *o, B40 *dst, int *out)
{
    *out = *(int *)(o + 0x18c);
    *dst = *(B40 *)(o + 0x190);
    return 0;
}

typedef unsigned int u32;
typedef struct B100 { int a[64]; } B100;
typedef struct B7C { int a[31]; } B7C;
#define GETBLK(NAME, OFF) \
int NAME(char *o, B100 *dst) \
{ \
    int r = 0; \
    if (o != 0 && dst != 0) { \
        if (*(int *)(o + 0x10) == 0) { \
            r = -1; \
        } else { \
            *dst = *(B100 *)(o + (OFF)); \
        } \
    } else { \
        r = (int)0x80000006u; \
    } \
    return r; \
}
GETBLK(ts4l_get_block_831618C8, 0x30)
GETBLK(ts4l_get_block_83161938, 0x150)

int ts4l_set_entry_83149F28(char *o, u32 key, B7C *src)
{
    char *e;
    if (*(int *)(o + 0x1c) != 0) {
        e = *(char **)(o + 8);
        if (e != 0 && *(u32 *)(e + 0xc) == key) {
            *(B7C *)(e + 0x10) = *src;
            return 0;
        }
    }
    return 1;
}
