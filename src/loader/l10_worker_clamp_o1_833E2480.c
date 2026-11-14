/* Loader_DLL.xex 0x833E2480-0x833E5DE0, executable version 0.0.0.3.
   Formatted-output front ends: forward the caller's arguments, with a
   callback address in front, to a shared worker and normalise any
   negative result to -1. */
typedef long ts4l_word;

ts4l_word fn_833E2360();
ts4l_word fn_833E5990();
ts4l_word fn_833E92C0();
ts4l_word fn_833EA5D8();
ts4l_word fn_833EEC88();
ts4l_word fn_833F6388();

ts4l_word ts4l_call_worker_clamp_833E2480(ts4l_word p0, ts4l_word p1, ts4l_word p2, ts4l_word p3)
{
    ts4l_word r = fn_833E2360((ts4l_word)fn_833EA5D8, p0, p1, p2, 0, p3);
    return r < 0 ? -1 : r;
}

ts4l_word ts4l_call_worker_clamp_833E24C8(ts4l_word p0, ts4l_word p1, ts4l_word p2, ts4l_word p3, ts4l_word p4)
{
    ts4l_word r = fn_833E2360((ts4l_word)fn_833EA5D8, p0, p1, p2, p3, p4);
    return r < 0 ? -1 : r;
}

ts4l_word ts4l_call_worker_clamp_833E2718(ts4l_word p0, ts4l_word p1, ts4l_word p2, ts4l_word p3)
{
    ts4l_word r = fn_833E2360((ts4l_word)fn_833EEC88, p0, p1, p2, 0, p3);
    return r < 0 ? -1 : r;
}

ts4l_word ts4l_call_worker_clamp_833E2760(ts4l_word p0, ts4l_word p1, ts4l_word p2, ts4l_word p3, ts4l_word p4)
{
    ts4l_word r = fn_833E2360((ts4l_word)fn_833EEC88, p0, p1, p2, p3, p4);
    return r < 0 ? -1 : r;
}

ts4l_word ts4l_call_worker_clamp_833E5B00(ts4l_word p0, ts4l_word p1, ts4l_word p2, ts4l_word p3)
{
    ts4l_word r = fn_833E5990((ts4l_word)fn_833E92C0, p0, p1, p2, 0, p3);
    return r < 0 ? -1 : r;
}

ts4l_word ts4l_call_worker_clamp_833E5B48(ts4l_word p0, ts4l_word p1, ts4l_word p2, ts4l_word p3, ts4l_word p4)
{
    ts4l_word r = fn_833E5990((ts4l_word)fn_833E92C0, p0, p1, p2, p3, p4);
    return r < 0 ? -1 : r;
}

ts4l_word ts4l_call_worker_clamp_833E5D98(ts4l_word p0, ts4l_word p1, ts4l_word p2, ts4l_word p3)
{
    ts4l_word r = fn_833E5990((ts4l_word)fn_833F6388, p0, p1, p2, 0, p3);
    return r < 0 ? -1 : r;
}

ts4l_word ts4l_call_worker_clamp_833E5DE0(ts4l_word p0, ts4l_word p1, ts4l_word p2, ts4l_word p3, ts4l_word p4)
{
    ts4l_word r = fn_833E5990((ts4l_word)fn_833F6388, p0, p1, p2, p3, p4);
    return r < 0 ? -1 : r;
}
