/* Swing_DLL.xex 0x883E4838: memory-usage report of a 0x14-byte FMOD event-system node (FMOD Ex 4.32
 * event range; vtable 0x880396B0 slot 23). Adds its own 0x14 bytes to the tracker through
 * fn_8832EDB0(tracker, 1, 2, size), then asks the child at +8 (if any) to report through its virtual
 * slot 6 and passes a non-zero result code up; 0 = ok.
 * Matches only as a member function reading the child through the implicit `this` twice: the second
 * read becomes the `clrrwi r3,r11,0` copy. As an extern "C" function the copy needs a 64-bit field
 * (ld/cmpldi, 2 off). */

extern "C" void fn_8832EDB0(void *tracker, int a, int b, int size);

struct Ts4FmodMemReporter {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual int report_memory(void *tracker);
};

struct Ts4FmodChildNode {
    void *vtable;
    int field_04;
    Ts4FmodMemReporter *child; /* +0x08 */
    int field_0c;
    int field_10;
    int report_memory(void *tracker);
};

/* Swing_DLL.xex 0x883E4838 (vtable slot only, no direct callers) */
int Ts4FmodChildNode::report_memory(void *tracker)
{
    fn_8832EDB0(tracker, 1, 2, sizeof(Ts4FmodChildNode));
    if (child) {
        int r = child->report_memory(tracker);
        if (r)
            return r;
    }
    return 0;
}
