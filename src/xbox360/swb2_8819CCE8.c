/* Family SWB2 (jump-table switch). */
extern float g_ts4_script_constants[];
double fn_88563A38(double x, double y);

#define K(off) (*(const double *)((const char *)g_ts4_script_constants + (off)))

double ts4_pow_small_8819CCE8(int base, int exponent)
{
    if (base == 10) {
        switch (exponent) {
        case 0: return K(0x78);
        case 1: return K(0x88);
        case 2: return K(0x90);
        case 3: return K(0x98);
        case 4: return K(0xa0);
        case 5: return K(0xa8);
        case 6: return K(0xb0);
        case 7: return K(0xb8);
        case 8: return K(0xc0);
        case 9: return K(0xc8);
        default:
            return fn_88563A38(K(0x88), (double)exponent);
        }
    }
    return fn_88563A38((double)base, (double)exponent);
}
