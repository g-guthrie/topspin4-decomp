/* Family SWB2 (jump-table switch). */
unsigned int ts4_mask_for_index_88884040(unsigned int kind, unsigned int idx)
{
    unsigned int r = 0x10;

    if (kind == 1) {
        switch (idx) {
        case 0:  r = 0x1000; break;
        case 2:  r = 4; break;
        case 3:  r = 8; break;
        case 4:  r = 0x10; break;
        case 5:  r = 0x20; break;
        case 6:  r = 0x40; break;
        case 7:  r = 0x80; break;
        case 8:  r = 0x100; break;
        case 9:  r = 0x200; break;
        case 10: r = 0x400; break;
        case 11: r = 0x800; break;
        case 12: r = 0x1000; break;
        case 13: r = 0x2000; break;
        case 14: r = 0x4000; break;
        case 15: r = 0x8000; break;
        }
    } else {
        switch (idx) {
        case 0: r = 0x10; break;
        case 1: r = 4; break;
        case 2: r = 8; break;
        case 4: r = 0x10; break;
        }
    }
    return r;
}
