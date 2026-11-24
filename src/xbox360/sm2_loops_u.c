/* SM2: CRC32 variants and float-array finite checks. */
extern char lbl_880C84C0[];
extern char lbl_880C8B18[];

/* CRC32 with a null-data / empty-length guard: null data gives 0 */
#define CRC32_GUARDED(NAME, TABLE) \
    unsigned NAME(const unsigned char *data, unsigned len) \
    { \
        unsigned crc = 0; \
        if (data != 0) { \
            crc = 0xffffffffu; \
            if (len != 0) { \
                const unsigned *table = (const unsigned *)(TABLE); \
                while (len--) crc = table[(crc ^ *data++) & 0xff] ^ (crc >> 8); \
            } \
        } \
        return ~crc; \
    }
CRC32_GUARDED(ts4_crc32_guarded_88608540, lbl_880C84C0)
CRC32_GUARDED(ts4_crc32_guarded_8864B2C8, lbl_880C8B18)


/* *out = 1 when none of the first N floats has an all-ones exponent (inf/nan) */
#define ALL_FINITE(NAME, N) \
    void NAME(unsigned char *out, const float *a) \
    { \
        int i; \
        for (i = 0; i < (N); i++) { \
            float f = a[i]; \
            unsigned bits = *(unsigned *)&f; \
            if ((bits & 0x7f800000u) == 0x7f800000u) { *out = 0; return; } \
        } \
        *out = 1; \
    }
ALL_FINITE(ts4_all_finite_16_8841C878, 16)
ALL_FINITE(ts4_all_finite_3_88420C80, 3)
ALL_FINITE(ts4_all_finite_4_88420CD0, 4)
ALL_FINITE(ts4_all_finite_12_884255D8, 12)

void ts4_all_finite_n_88420C28(unsigned char *out, const float *a, int n)
{
    int i;
    for (i = 0; i < n; i++) {
        float f = a[i];
        unsigned bits = *(unsigned *)&f;
        if ((bits & 0x7f800000u) == 0x7f800000u) { *out = 0; return; }
    }
    *out = 1;
}
