/* SM2: linear searches over pointer vectors and small float clamps. */
extern const float lbl_8814B440;
extern const float g_ts4_script_constants[];

/* find the element whose id (+4) equals key in a [begin, end) pointer vector */
#define FIND_BY_ID(NAME, BEGIN_OFF, END_OFF) \
    char *NAME(char *p, unsigned key) \
    { \
        char **end = *(char ***)(p + (END_OFF)); \
        char **it = *(char ***)(p + (BEGIN_OFF)); \
        for (; it != end; ++it) { \
            if (key == *(unsigned *)(*it + 4)) return *it; \
        } \
        return 0; \
    }
FIND_BY_ID(ts4_find_by_id_886F1738, 0x54, 0x58)
FIND_BY_ID(ts4_find_by_id_886F15B0, 0x64, 0x68)

char *ts4_find_by_id_886C3DC0(char *p, unsigned key)
{
    char **it = *(char ***)(p + 4);
    char **end = *(char ***)(p + 8);
    for (; it != end; ++it) {
        if (key == *(unsigned *)(*it + 4)) return *it;
    }
    return 0;
}
unsigned char ts4_is_default_value_886EEE98(int unused, const char *p)
{
    float v = *(const float *)(p + 0x54);
    (void)unused;
    return v == lbl_8814B440 || v == g_ts4_script_constants[0];
}
