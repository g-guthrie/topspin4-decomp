/* Loader_DLL.xex 0x8346D4C0-0x8346D548, executable version 0.0.0.3. */
typedef unsigned long u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef struct { u16 Year, Month, Day, Hour, Minute, Second, Milliseconds, Weekday; } Tf;
typedef struct { u32 lo; u32 hi; } Ts4lTime;
extern void ts4l_import_RtlTimeToTimeFields_83517DE8(Ts4lTime *t, Tf *f);
int ts4l_time_to_fields_8346D4C0(Ts4lTime *t, u16 *out)
{
    Ts4lTime tt;
    Tf f;
    tt.hi = t->hi;
    tt.lo = t->lo;
    ts4l_import_RtlTimeToTimeFields_83517DE8(&tt, &f);
    out[0] = f.Year;
    out[1] = f.Month;
    out[3] = f.Day;
    out[2] = f.Weekday;
    out[4] = f.Hour;
    out[5] = f.Minute;
    out[6] = f.Second;
    out[7] = f.Milliseconds;
    return 1;
}
