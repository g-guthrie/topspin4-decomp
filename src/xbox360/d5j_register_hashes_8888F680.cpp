/* Swing_DLL.xex 0x8888F680-0x8888FD40, executable version 0.0.0.3. */
#ifdef _MSC_VER
#define TS4_FI __forceinline
#else
#define TS4_FI inline
#endif

typedef unsigned int u32;
struct Ts4RegSub { char pad[0x4C]; };
extern "C" void fn_8815F510(Ts4RegSub *dst, const Ts4RegSub *src);
struct Ts4RegElem {
    u32 a;
    char b;
    char pad5[3];
    Ts4RegSub sub;
};
struct Ts4RegVec {
    Ts4RegElem *first;
    Ts4RegElem *last;
    Ts4RegElem *end;
    TS4_FI Ts4RegElem *copy(Ts4RegElem *f, Ts4RegElem *l, Ts4RegElem *d)
    {
        int n;
        for (n = l - f; 0 < n; --n, ++f, ++d) {
            d->a = f->a;
            d->b = f->b;
            fn_8815F510(&d->sub, &f->sub);
        }
        return d;
    }
    TS4_FI Ts4RegElem *erase(Ts4RegElem *f, Ts4RegElem *l)
    {
        Ts4RegElem *p = copy(l, last, f);
        last = p;
        return f;
    }
    TS4_FI void clear() { erase(first, last); }
};
struct Ts4RegOwner {
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
    virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7();
    virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
    virtual void s12();
    virtual void add_hash(u32 *h);
    char pad[0x28 - 4];
    int f28; int f2c; int f30; int f34; int f38; int f3c;
    char pad40[0x65 - 0x40]; char f65; char pad66[6]; int f6c;
    char pad70[0xBC - 0x70]; Ts4RegVec vec;
};
extern "C" {
void fn_88639600(Ts4RegOwner *o);
void fn_8815F510(Ts4RegSub *dst, const Ts4RegSub *src);
void ts4_register_hashes_8888F680(Ts4RegOwner *o)
{
    u32 h0, h1, h2, h3, h4, h5, h6, h7, h8, h9, h10, h11, h12, h13, h14, h15, h16, h17, h18, h19, h20, h21, h22, h23, h24, h25, h26, h27, h28, h29, h30, h31, h32, h33, h34, h35, h36, h37, h38, h39, h40, h41, h42, h43;
    h0 = 0x741A3EDCu;
    o->add_hash(&h0);
    h1 = 0x31D0E4Au;
    o->add_hash(&h1);
    h2 = 0x9A145FF0u;
    o->add_hash(&h2);
    h3 = 0xED136F66u;
    o->add_hash(&h3);
    h4 = 0x4ECD7183u;
    o->add_hash(&h4);
    h5 = 0x39CA4115u;
    o->add_hash(&h5);
    h6 = 0xA0C310AFu;
    o->add_hash(&h6);
    h7 = 0xD7C42039u;
    o->add_hash(&h7);
    h8 = 0x1A86111Fu;
    o->add_hash(&h8);
    h9 = 0x6D812189u;
    o->add_hash(&h9);
    h10 = 0xF4887033u;
    o->add_hash(&h10);
    h11 = 0x838F40A5u;
    o->add_hash(&h11);
    h12 = 0x84A3ED71u;
    o->add_hash(&h12);
    h13 = 0xBB2A1286u;
    o->add_hash(&h13);
    h14 = 0x80CB558Bu;
    o->add_hash(&h14);
    h15 = 0xCE712E50u;
    o->add_hash(&h15);
    h16 = 0xFE32DF8Du;
    o->add_hash(&h16);
    h17 = 0x6B44FE2u;
    o->add_hash(&h17);
    h18 = 0x7A655119u;
    o->add_hash(&h18);
    h19 = 0x5A7776A5u;
    o->add_hash(&h19);
    h20 = 0x2BCDE484u;
    o->add_hash(&h20);
    h21 = 0x413C598Eu;
    o->add_hash(&h21);
    h22 = 0xE382EBFAu;
    o->add_hash(&h22);
    h23 = 0x18C05278u;
    o->add_hash(&h23);
    h24 = 0xE914B04Du;
    o->add_hash(&h24);
    h25 = 0x9E1380DBu;
    o->add_hash(&h25);
    h26 = 0x71AD161u;
    o->add_hash(&h26);
    h27 = 0x701DE1F7u;
    o->add_hash(&h27);
    h28 = 0xFF34215Fu;
    o->add_hash(&h28);
    h29 = 0x883311C9u;
    o->add_hash(&h29);
    h30 = 0x113A4073u;
    o->add_hash(&h30);
    h31 = 0x663D70E5u;
    o->add_hash(&h31);
    h32 = 0x91FC0268u;
    o->add_hash(&h32);
    h33 = 0x8F553D2u;
    o->add_hash(&h33);
    h34 = 0x66E95205u;
    o->add_hash(&h34);
    h35 = 0xE196F6E7u;
    o->add_hash(&h35);
    h36 = 0x9691C671u;
    o->add_hash(&h36);
    h37 = 0xF9897CBu;
    o->add_hash(&h37);
    h38 = 0x789FA75Du;
    o->add_hash(&h38);
    h39 = 0xE820BACCu;
    o->add_hash(&h39);
    h40 = 0x9EA22899u;
    o->add_hash(&h40);
    h41 = 0xE9A5180Fu;
    o->add_hash(&h41);
    h42 = 0x70AC49B5u;
    o->add_hash(&h42);
    h43 = 0x7AB7923u;
    o->add_hash(&h43);
    {
        o->f65 = 0;
        o->f6c = 0;
        o->f3c = 0;
        o->f38 = 0;
        o->f34 = 0;
        o->f30 = 0;
        o->f28 = 0;
        o->vec.clear();
        o->f2c = 0;
    }
    fn_88639600(o);
}
}