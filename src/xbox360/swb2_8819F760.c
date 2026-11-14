/* Family SWB2 (jump-table switch). */
extern float g_ts4_script_constants[];
int fn_885636E8(void);

int ts4_map_input_flag_8819F760(double value, int *out)
{
    int flag;
    int result;

    switch (fn_885636E8()) {
    case 1:
    case 2:
        result = 1; flag = 0; break;
    case 4:
        flag = 1; result = 0; break;
    case 16:
        flag = 1; result = 3; break;
    case 8:
        flag = 1; result = 2; break;
    case 32:
        flag = 1; result = 4; break;
    case 64:
        result = 4; flag = 0; break;
    case 128:
        result = 3; flag = 0; break;
    case 256:
        result = 2; flag = 0; break;
    case 512:
        result = 0; flag = 0; break;
    default:
        flag = value < *(const double *)((const char *)g_ts4_script_constants + 0x58);
        result = 2;
        break;
    }
    *out = flag;
    return result;
}
