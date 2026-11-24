/* Swing_DLL.xex 0x888327C0-0x88832820, executable version 0.0.0.3. */
typedef unsigned int u32;

/* Text sink with a write method in virtual slot 3. */
struct Ts9Sink {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void write(const char *text);
};

/* Write n tab characters to a text sink. */
extern "C" void ts4_script_write_indent_888327C0(Ts9Sink *sink, u32 n)
{
    char buf[0x1F0];
    u32 i;
    for (i = 0; i < n; i++) buf[i] = 9;
    buf[i] = 0;
    sink->write(buf);
}
