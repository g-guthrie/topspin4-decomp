/* 0x8828E7D8: rebuilds a 0x600-byte blob, and when it differs from the copy at +0x3B70 flushes the old copy to the device (once) and stores the new one */
/* Matched on /O1 plain and LTCG (work/army/ME/v.py chk); sets bit 1 of the flags word at +0x421C. */
int memcmp(const void *a, const void *b, unsigned int n);
void *memcpy(void *d, const void *s, unsigned int n);
#pragma intrinsic(memcmp)
typedef struct T { char pad[0x3B70]; unsigned char blob[0x600]; char p2[0x421C - 0x4170]; unsigned int flags; char p3[0x5E6C - 0x4220]; void *dev; unsigned int st; } T;
void fn_8829C3F0(unsigned char *buf, int a, int b);
int KeGetCurrentProcessType(void);
int fn_8857ACB8(void *dev, unsigned char *blob, int n);
void ts4_blob_cache_refresh_8828E7D8(T *t, int a)
{
    unsigned char buf[0x600];
    fn_8829C3F0(buf, a, 0);
    if (memcmp(buf, t->blob, 0x600) != 0) {
        if (KeGetCurrentProcessType() != 2) {
            if (t->dev && !(t->st & 0x80000000))
                fn_8857ACB8(t->dev, t->blob, 0x600);
            t->st |= 0x80000000;
        }
        memcpy(t->blob, buf, 0x600);
        t->flags |= 2;
    }
}
