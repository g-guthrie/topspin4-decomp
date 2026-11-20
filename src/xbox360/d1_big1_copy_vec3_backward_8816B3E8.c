/* Swing_DLL.xex 0x8816B3E8-0x8816B4B8, executable version 0.0.0.3. */
typedef struct Ts4Vec3 {
    float x;
    float y;
    float z;
} Ts4Vec3;

Ts4Vec3 *ts4_copy_vec3_backward_8816B3E8(
    const Ts4Vec3 *first,
    const Ts4Vec3 *last,
    Ts4Vec3 *destination_end
)
{
    int count = last - first;

    while (count > 0) {
        last--;
        destination_end--;
        destination_end->x = last->x;
        destination_end->y = last->y;
        destination_end->z = last->z;
        count--;
    }
    return destination_end;
}
