/* Loader_DLL.xex 0x83228758-0x8322887C, executable version 0.0.0.3. */

typedef struct ts4l_fmt_obj {
    unsigned char pad[0x228];
    unsigned int format;
} ts4l_fmt_obj;

int ts4l_format_info_83228758(ts4l_fmt_obj *o, unsigned int *code, unsigned short *bits)
{
    unsigned short b;
    unsigned int c;
    int hr = 0;

    switch (o->format) {
    case 9: c = 0x56555949; b = 12; break;
    case 10: c = 0x30323449; b = 12; break;
    case 12: c = 0x32315659; b = 12; break;
    case 1: c = 0x32595559; b = 16; break;
    case 2: c = 0x59565955; b = 16; break;
    case 3: c = 0x55595659; b = 16; break;
    case 4: c = 0; b = 24; break;
    case 5: c = 0; b = 16; break;
    case 6: c = 3; b = 16; break;
    case 11: c = 3; b = 12; break;
    case 7: c = 0; b = 32; break;
    case 8: c = 0; b = 8; break;
    default: hr = (int)0x80070057; break;
    }
    if (hr == 0) {
        if (code) *code = c;
        if (bits) *bits = b;
    }
    return hr;
}
