/* Family SWA: switch jump-table function. One function per file: fn_check resolves $LN labels by name and they repeat per function. */

extern double g_ts4_script_constants[];
double fn_8819F650(void);
double fn_8819F6A0(void);
double fn_885640B0(double value);

/* Swing_DLL.xex 0x8819CF40: returns a table constant for a few radix values (2, 8, 10, 16); otherwise computes
 * from the value by comparing it against a threshold constant, falling back to log(value) / log(base). */
double ts4_radix_constant_8819CF40(int radix)
{
    switch (radix) {
    case 2:
        return g_ts4_script_constants[15];
    case 8:
        return g_ts4_script_constants[1];
    case 10:
        return g_ts4_script_constants[137];
    case 16:
        return g_ts4_script_constants[138];
    default: {
        double value = (double)radix;
        if (value <= g_ts4_script_constants[11]) {
            if (value == g_ts4_script_constants[11]) {
                return fn_8819F650();
            }
            return fn_8819F6A0();
        }
        return fn_885640B0(value) / fn_885640B0(g_ts4_script_constants[46]);
    }
    }
}
