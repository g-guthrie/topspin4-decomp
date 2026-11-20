/* Loader_DLL.xex 0x830A6130-0x830A9F88, executable version 0.0.0.3. */
extern void ts4l_if_call_seq_KeGetCurrentProcessType_830BBB98(void *p);

void ts4l_tail_if_set_830A6130(void **p)
{
    if (p[3] != 0) {
        ts4l_if_call_seq_KeGetCurrentProcessType_830BBB98(p[3]);
    }
}

void ts4l_tail_if_set_830A9F88(void **p)
{
    if (p[3] != 0) {
        ts4l_if_call_seq_KeGetCurrentProcessType_830BBB98(p[3]);
    }
}
