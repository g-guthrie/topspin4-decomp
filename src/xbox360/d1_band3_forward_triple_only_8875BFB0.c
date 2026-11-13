/* Swing_DLL.xex band3 forwarding of a 12-byte by-value argument, executable version 0.0.0.3. */
struct TS4Triple {
    unsigned int first;
    unsigned int second;
    unsigned int third;
};
void fn_8875B8D8(struct TS4Triple value);
void fn_88707908(struct TS4Triple value);
void fn_886F7C08(struct TS4Triple value);

void ts4_forward_triple_8875BFB0(struct TS4Triple value)
{
    fn_8875B8D8(value);
}

void ts4_forward_triple_8876FF18(struct TS4Triple value)
{
    fn_88707908(value);
}

void ts4_forward_triple_888B1D98(struct TS4Triple value)
{
    fn_88707908(value);
}

void ts4_forward_triple_88945B08(struct TS4Triple value)
{
    fn_886F7C08(value);
}
