/* Loader_DLL.xex 0x8327EF18-0x8327F174, executable version 0.0.0.3. */
typedef struct ts4l_format_request {
    unsigned reserved0;
    unsigned flags;
    int format;
    unsigned char pad0c[0x10];
    unsigned handle;
} ts4l_format_request;

int fn_83233A38(unsigned a, unsigned handle, unsigned mode, int format);

/* Finds the first supported surface format (the request's own format when flag 1 is set, then the
   candidate list) and reports its FourCC code (0 for plain RGB) and bits per pixel. */
int ts4l_query_pixel_format_8327EF18(ts4l_format_request *req, unsigned a, int *list, signed char count,
                                     unsigned *fourcc, int *bits, int *unsupported)
{
    unsigned flags = req->flags;
    unsigned handle = req->handle;
    int fmt = req->format;
    int result = 0;
    int i;
    int n;

    if ((flags & 1) != 0 && fmt != 0) {
        result = fn_83233A38(a, handle, 0x90080, fmt);
        if (result >= 0)
            goto dispatch;
        if ((unsigned)result != 0x805000B7u)
            return result;
        *unsupported = 1;
    }
    n = count;
    i = 0;
    if (n > 0) {
        do {
            fmt = *list;
            result = fn_83233A38(a, handle, 0x90080, fmt);
            if (result >= 0)
                break;
            if ((unsigned)result != 0x805000B7u)
                return result;
            i++;
            list++;
        } while (i < n);
    }
dispatch:
    switch (fmt) {
    case 12: *fourcc = 0x32315659; *bits = 12; break;
    case 9: *fourcc = 0x56555949; *bits = 12; break;
    case 10: *fourcc = 0x30323449; *bits = 12; break;
    case 1: *fourcc = 0x32595559; *bits = 16; break;
    case 2: *fourcc = 0x59565955; *bits = 16; break;
    case 3: *fourcc = 0x55595659; *bits = 16; break;
    case 4: *fourcc = 0; *bits = 24; break;
    case 5: *fourcc = 0; *bits = 16; break;
    case 6: *fourcc = 3; *bits = 16; break;
    case 11: *fourcc = 3; *bits = 12; break;
    case 7: *fourcc = 0; *bits = 32; break;
    case 8: *fourcc = 0; *bits = 8; break;
    default: return (int)0x805000B7;
    }
    return result;
}
