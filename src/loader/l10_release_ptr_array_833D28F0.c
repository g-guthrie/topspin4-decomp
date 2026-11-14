/* Loader_DLL.xex 0x833D28F0-0x833DBCE0, executable version 0.0.0.3.
   Release helpers: walk a fixed-size array of object pointers and release
   every non-null entry. */
extern void fn_830AF1B8();

void ts4l_release_ptr_array5_833D28F0(void **p)
{
    int i;
    for (i = 5; i != 0; i--) {
        if (*p) fn_830AF1B8(*p);
        p++;
    }
}

void ts4l_release_ptr_array4_833D3840(void **p)
{
    int i;
    for (i = 4; i != 0; i--) {
        if (*p) fn_830AF1B8(*p);
        p++;
    }
}

void ts4l_release_ptr_array7_833D54A0(void **p)
{
    int i;
    for (i = 7; i != 0; i--) {
        if (*p) fn_830AF1B8(*p);
        p++;
    }
}

void ts4l_release_ptr_array33_833DA808(void **p)
{
    int i;
    for (i = 33; i != 0; i--) {
        if (*p) fn_830AF1B8(*p);
        p++;
    }
}

void ts4l_release_ptr_array2_833DBCE0(void **p)
{
    int i;
    for (i = 2; i != 0; i--) {
        if (*p) fn_830AF1B8(*p);
        p++;
    }
}
