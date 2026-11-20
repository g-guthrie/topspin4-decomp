/* Swing_DLL.xex band3 forwarding of a 12-byte by-value argument plus an address-taken word, executable version 0.0.0.3. */
struct TS4Triple {
    unsigned int first;
    unsigned int second;
    unsigned int third;
};
void fn_886F7CD8(struct TS4Triple value, unsigned int *extra);
void ts4_if_call_seq_u32_off0_886F7DA0(struct TS4Triple value, unsigned int *extra);
void fn_886F7E68(struct TS4Triple value, unsigned int *extra);
void ts4_if_call_seq_u32_off0_88714908(struct TS4Triple value, unsigned int *extra);

void ts4_forward_triple_extra_88945B38(struct TS4Triple value, unsigned int extra)
{
    fn_886F7CD8(value, &extra);
}

void ts4_forward_triple_extra_88945B70(struct TS4Triple value, unsigned int extra)
{
    ts4_if_call_seq_u32_off0_886F7DA0(value, &extra);
}

void ts4_forward_triple_extra_88945BA8(struct TS4Triple value, unsigned int extra)
{
    fn_886F7E68(value, &extra);
}

void ts4_forward_triple_extra_88952D58(struct TS4Triple value, unsigned int extra)
{
    ts4_if_call_seq_u32_off0_88714908(value, &extra);
}
