typedef unsigned int ts4_size_t;

/* Swing_DLL.xex 0x8857CB70. */
int ts4_consume_to_delimiter(
    char **cursor,
    ts4_size_t *remaining,
    char delimiter
)
{
    char *current = *cursor;
    ts4_size_t count = *remaining;

    while (count != 0) {
        char value = *current++;

        --count;
        if (value == delimiter) {
            *cursor = current;
            *remaining = count;
            return 1;
        }
    }
    return 0;
}
