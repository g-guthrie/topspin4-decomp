typedef unsigned int u32;

extern void *fn_881519D0(void);
extern void fn_8819B060(
    void *destination,
    const char *source,
    u32 length,
    void *allocator
);

/* Swing_DLL.xex 0x88152E70. */
void *ts4_assign_text_from_c_string(void *destination, const char *source)
{
    const char *cursor;
    u32 length;

    if (source != 0) {
        char character;

        cursor = source;
        do {
            character = *cursor;
            cursor++;
        } while (character != '\0');
        length = (u32)(cursor - source - 1);
    } else {
        length = 0;
    }
    fn_8819B060(destination, source, length, fn_881519D0());
    return destination;
}
