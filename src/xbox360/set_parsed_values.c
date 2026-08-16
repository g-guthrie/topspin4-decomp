typedef long long s64;
typedef unsigned int u32;

extern s64 fn_88564780(void *input);
extern u32 fn_88564B08(void *input, u32 unused_4, u32 unused_5);

int ts4_set_parsed_i64_if_changed(void *unused, s64 *value, void *input)
{
    s64 parsed = fn_88564780(input);
    (void)unused;

    if (*value != parsed) {
        *value = parsed;
        return 1;
    }
    return 0;
}

int ts4_set_parsed_u32_if_changed(void *unused, u32 *value, void *input)
{
    u32 parsed = fn_88564B08(input, 0, 0);
    (void)unused;

    if (*value != parsed) {
        *value = parsed;
        return 1;
    }
    return 0;
}
