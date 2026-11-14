/* Swing_DLL.xex 0x884273B8-0x88427538, executable version 0.0.0.3. */
typedef unsigned long long ts4_u64;

void fn_88426FF8(void *stream, const void *data, int size, int count);

void ts4_stream_write_i16_a_884273B8(void *stream, short value)
{
    fn_88426FF8(stream, &value, 2, 1);
}

void ts4_stream_write_i16_b_884273E8(void *stream, short value)
{
    fn_88426FF8(stream, &value, 2, 1);
}

void ts4_stream_write_i32_a_88427418(void *stream, int value)
{
    fn_88426FF8(stream, &value, 4, 1);
}

void ts4_stream_write_i32_b_88427448(void *stream, int value)
{
    fn_88426FF8(stream, &value, 4, 1);
}

void ts4_stream_write_i64_a_88427478(void *stream, ts4_u64 value)
{
    fn_88426FF8(stream, &value, 8, 1);
}

void ts4_stream_write_i64_b_884274A8(void *stream, ts4_u64 value)
{
    fn_88426FF8(stream, &value, 8, 1);
}

void ts4_stream_write_f32_884274D8(void *stream, float value)
{
    fn_88426FF8(stream, &value, 4, 1);
}

void ts4_stream_write_f64_88427508(void *stream, double value)
{
    fn_88426FF8(stream, &value, 8, 1);
}
