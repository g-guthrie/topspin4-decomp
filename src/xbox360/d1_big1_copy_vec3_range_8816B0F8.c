/* Swing_DLL.xex 0x8816B0F8-0x8816B1C8, executable version 0.0.0.3. */
typedef struct Ts4Vec3 {
    float x;
    float y;
    float z;
} Ts4Vec3;

Ts4Vec3 *ts4_copy_vec3_range_8816B0F8(
    const Ts4Vec3 *first,
    const Ts4Vec3 *last,
    Ts4Vec3 *destination
)
{
    int count = last - first;

    while (count > 0) {
        destination->x = first->x;
        destination->y = first->y;
        destination->z = first->z;
        first++;
        destination++;
        count--;
    }
    return destination;
}
