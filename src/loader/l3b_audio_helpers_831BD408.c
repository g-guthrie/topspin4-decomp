/* Loader_DLL.xex 0x831BD408-0x8326C710, executable version 0.0.0.3.
 * Sample conversion helpers (scale an integer sample to float). */

extern float lbl_83027058;

void ts4l_store_scaled_sample_831BD408(int a, float *out, char *o, int idx)
{
    out[idx] = (float)a / (float)(1 << (*(unsigned short *)(o + 0x6e) - 1));
}

void ts4l_store_scaled_sample_83254950(int a, float *out, char *o, int idx)
{
    out[idx] = (float)a / (float)(1 << (*(unsigned short *)(o + 0x6e) - 1));
}

void ts4l_store_mixed_sample_831FA7D8(int i, int j, int a, int *tbl, float *out, float s)
{
    out[i] = ((float)a * lbl_83027058 + (float)tbl[j]) * s;
}

void ts4l_store_mixed_sample_8326C710(int i, int j, int a, int *tbl, float *out, float s)
{
    out[i] = ((float)a * lbl_83027058 + (float)tbl[j]) * s;
}
