/* Swing_DLL.xex 0x884C1520: constructor of the default vehicle brake (vtable 0x88089E2C, RTTI
 * hkpVehicleDefaultBrake : hkpVehicleBrake : hkReferencedObject; Havok 5.5 physics range).
 * Reference-counted base (vptr, 16-bit size/flags, 16-bit count = 1), an empty growable array of
 * per-wheel braking properties ({data, size, capacity|0x80000000 "don't deallocate"}) and a float
 * (minimum time to block the wheels) = 0.
 * Matches only as a real polymorphic class: the vptr store must come from the constructor, and the
 * zero must be the literal (a named extern float, or a C struct init, schedules the lfs differently). */

struct Ts4RefCounted88089E2C {
    unsigned short mem_size_and_flags;
    short ref_count;
    Ts4RefCounted88089E2C() : ref_count(1) {}
    virtual ~Ts4RefCounted88089E2C();
};

struct Ts4WheelBrakeArray {
    void *data;
    int size;
    unsigned int capacity_and_flags;
    Ts4WheelBrakeArray() : data(0), size(0), capacity_and_flags(0x80000000) {}
};

struct Ts4VehicleDefaultBrake : Ts4RefCounted88089E2C {
    Ts4WheelBrakeArray wheel_braking; /* +0x08 */
    float wheels_min_time_to_block;   /* +0x14 */
    Ts4VehicleDefaultBrake();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
};

/* Swing_DLL.xex 0x884C1520 */
Ts4VehicleDefaultBrake::Ts4VehicleDefaultBrake()
{
    wheels_min_time_to_block = 0.0f;
}
