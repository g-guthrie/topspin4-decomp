/* SM6 batch d: calendar helper (Swing_DLL.xex). */
typedef unsigned int u32;
typedef unsigned char u8;
typedef struct { u32 year; u32 month; } ts4_date;

/* Swing_DLL.xex 0x88150AB0: days in the month (1..12) of a year/month pair; 0 when the month is out of range */
u8 ts4_days_in_month_88150AB0(ts4_date *d)
{
    u32 m = d->month;
    if (m < 1 || m > 12) return 0;
    if (m != 2) {
        u8 days[12] = { 31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        return days[m - 1];
    }
    {
        u32 y = d->year;
        if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) return 29;
        return 28;
    }
}
