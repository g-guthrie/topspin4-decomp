typedef unsigned int u32;

extern void *__imp_ExLoadedCommandLine;
extern void fn_8857A1E0(void);
extern void fn_88582890(int, int, int, int, int, int, int);
extern void fn_88582610(void);

typedef struct Ts4FourWordRecord {
    u32 first;
    u32 second;
    u32 third;
    u32 fourth;
} Ts4FourWordRecord;

void *ts4_get_loaded_command_line(void) { return __imp_ExLoadedCommandLine; }
void ts4_call_runtime_a1e0(void) { fn_8857A1E0(); }
void ts4_call_runtime_2890(int a, int b, int c, int d, int e, int f)
{
    fn_88582890(a, b, c, d, e, -1, f);
}
int ts4_set_four_word_record(Ts4FourWordRecord *record, u32 first, u32 second,
    u32 third, u32 fourth)
{
    record->first = first;
    record->second = second;
    record->third = third;
    record->fourth = fourth;
    return 1;
}
void ts4_call_runtime_2610(void) { fn_88582610(); }
