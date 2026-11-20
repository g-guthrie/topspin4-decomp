/* Swing_DLL.xex 0x884FF7F0-0x884FFA60, executable version 0.0.0.3. */
int ts4_sample_rate_lookup_884FF7F0(int kind, unsigned index, int *rate)
{
    int v;
    switch (kind) {
    case 1:
        switch (index) {
        case 1: v = 16000; break;
        case 2: v = 24000; break;
        case 3: v = 32000; break;
        default: return 5;
        }
        break;
    case 2:
        switch (index) {
        case 1: v = 24000; break;
        case 2: v = 32000; break;
        case 3: v = 48000; break;
        default: return 5;
        }
        break;
    case 3:
        switch (index) {
        case 59: v = 8800; break;
        case 1: v = 9600; break;
        case 12: v = 10000; break;
        case 13: v = 10400; break;
        case 14: v = 10800; break;
        case 15: v = 11200; break;
        case 16: v = 11600; break;
        case 2: v = 12000; break;
        case 17: v = 12400; break;
        case 18: v = 12800; break;
        case 19: v = 13200; break;
        case 20: v = 13600; break;
        case 21: v = 14000; break;
        case 3: v = 14400; break;
        case 22: v = 14800; break;
        case 23: v = 15200; break;
        case 24: v = 15600; break;
        case 25: v = 16000; break;
        case 26: v = 16400; break;
        case 4: v = 16800; break;
        case 27: v = 17200; break;
        case 28: v = 17600; break;
        case 29: v = 18000; break;
        case 30: v = 18400; break;
        case 31: v = 18800; break;
        case 5: v = 19200; break;
        case 32: v = 19600; break;
        case 33: v = 20000; break;
        case 34: v = 20400; break;
        case 35: v = 20800; break;
        case 36: v = 21200; break;
        case 6: v = 21600; break;
        case 37: v = 22000; break;
        case 38: v = 22400; break;
        case 39: v = 22800; break;
        case 40: v = 23200; break;
        case 41: v = 23600; break;
        case 7: v = 24000; break;
        case 42: v = 24400; break;
        case 43: v = 24800; break;
        case 44: v = 25200; break;
        case 45: v = 25600; break;
        case 46: v = 26000; break;
        case 8: v = 26400; break;
        case 47: v = 26800; break;
        case 48: v = 27200; break;
        case 49: v = 27600; break;
        case 50: v = 28000; break;
        case 51: v = 28400; break;
        case 9: v = 28800; break;
        case 52: v = 29200; break;
        case 53: v = 29600; break;
        case 54: v = 30000; break;
        case 55: v = 30400; break;
        case 56: v = 30800; break;
        case 10: v = 31200; break;
        case 57: v = 31600; break;
        case 58: v = 32000; break;
        default: return 5;
        }
        break;
    default:
        return 6;
    }
    *rate = v;
    return 0;
}
