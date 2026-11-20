/* Swing_DLL.xex 0x8899D8C8-0x8899D910, executable version 0.0.0.3. */
struct S{char p[0xac];char*r;};
int ts4_first_free_slot_8899D8C8(struct S*s,int i){char*b=s->r;int n=*(int*)(b+4);int j;for(j=i;j<n;++j){if(*(unsigned char*)(b+*(int*)b+j*0xd8+0xc0)==0)return j;}return -1;}
