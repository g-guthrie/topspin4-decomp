typedef unsigned __int64 u64;
u64 reverse_u16x4_886EB1D8(u64 x){ return ((x>>48)&0xffff)|((x>>16)&0xffff0000)|((x<<16)&0xffff00000000)|(x<<48); }
