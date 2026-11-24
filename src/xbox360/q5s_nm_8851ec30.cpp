// Swing_DLL.xex 0x8851EC30: Ts4FloatMatrix::Sub(o): element-wise this -= o over rows * cols
// floats (count re-read every pass). Caller: 8851F5B8. Matched /Oc as a C++ member: as a C
// function the destination address add takes `add r9,r9(data),r11(offset)` instead of the
// target's offset-first order (`this` is numbered differently from a first parameter).
struct Ts4FloatMatrix {
    float *data; // +0x00
    int f_04;
    int f_08;
    int rows;    // +0x0C
    int cols;    // +0x10
    void Sub(const Ts4FloatMatrix &o);
};

void Ts4FloatMatrix::Sub(const Ts4FloatMatrix &o)
{
    for (int i = 0; i < rows * cols; i++)
        data[i] -= o.data[i];
}
