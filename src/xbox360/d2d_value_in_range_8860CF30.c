/* Swing_DLL.xex 0x8860CF30-0x8860D990, executable version 0.0.0.3. */
typedef unsigned int u32;
typedef struct { char p0[0x24]; u32 count; char p1[0x178-0x28]; u32 start; } Range;



unsigned char ts4_value_in_range_8860CF30(Range *o, u32 v)
{
    return o->start <= v && v < o->start + o->count;
}

unsigned char ts4_value_in_range_8860D8A8(Range *o, u32 v)
{
    return o->start <= v && v < o->start + o->count;
}

unsigned char ts4_value_in_range_8860D990(Range *o, u32 v)
{
    return o->start <= v && v < o->start + o->count;
}
