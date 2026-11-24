/* Loader_DLL.xex 0x831808A8-0x831A2178, executable version 0.0.0.3. */
extern int ts4l_import_KeSetEvent_835174E8(void *ev, int inc, int wait);

int ts4l_event_set_ok_831808A8(void *ev)
{
    return ts4l_import_KeSetEvent_835174E8(ev, 1, 0) >= 0;
}

int ts4l_event_set_ok_8319DA18(void *ev)
{
    return ts4l_import_KeSetEvent_835174E8(ev, 1, 0) >= 0;
}

int ts4l_event_set_ok_831A2178(void *ev)
{
    return ts4l_import_KeSetEvent_835174E8(ev, 1, 0) >= 0;
}
