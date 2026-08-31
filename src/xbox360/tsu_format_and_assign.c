typedef unsigned int u32;

extern char g_ts4_tsu_format[];
extern void ts4_format_text(
    char *buffer, u32 size, const char *format, const char *text, u32 value
);
extern void ts4_assign_formatted_text(void *object, const char *text);

typedef struct Ts4FormatScratch {
    char reserved[0x30];
    char buffer[0x20];
} Ts4FormatScratch;

/* Swing_DLL.xex 0x8878C388; callback registration name remains under review. */
void *ts4_tsu_format_and_assign(void *object, const char *text, u32 value)
{
    Ts4FormatScratch scratch;

    ts4_format_text(
        scratch.buffer, sizeof(scratch.buffer), g_ts4_tsu_format, text + 1, value
    );
    ts4_assign_formatted_text(object, scratch.buffer);
    return object;
}
