/* Loader_DLL.xex 0x83228A88-0x83228CE4, executable version 0.0.0.3. */
int ts4l_map_status_code_83228A88(int code)
{
    switch (code) {
    case (int)0x8007000e: return 3;
    case (int)0x80070057: return 4;
    case (int)0x80500000: return 0x1e;
    case (int)0x80004005:
    case (int)0x80500002:
    case (int)0x80500003: return 0x1d;
    case (int)0x80500006: return 0x1e;
    case (int)0x8050000c: return 1;
    case (int)0x8050000d: return 0x1c;
    case (int)0x8050000e: case (int)0x8050000f: case (int)0x80500010: case (int)0x80500011:
    case (int)0x80500012: case (int)0x80500013: case (int)0x80500014: case (int)0x80500015:
        return 0x1b;
    case (int)0x80500017:
    case (int)0x80500018: return 2;
    case (int)0x805000a7:
    case (int)0x805000a8: return 7;
    case (int)0x805000b7: return 0x12;
    case (int)0x805000ba: return 5;
    case (int)0x80600000: return 0xf;
    case (int)0x80600003: return 0x10;
    case (int)0x80600004: return 0x17;
    case (int)0x80600005: return 0x18;
    case (int)0x80600006: return 0x11;
    case (int)0x80600007: return 0xf;
    case (int)0x80600008: return 0x15;
    default: return code < 0 ? 0x1d : 0;
    case 0x500004: return 0x21;
    case 0x600000: return 0x16;
    case 0: case 0x500000: case 0x500001: case 0x500002: case 0x500003: case 0x500005: case 0x500006: return 0;
    }
}
