/* Swing_DLL.xex 0x88609470-0x886094B8, executable version 0.0.0.3. */
struct S{char p[0x30];int*a;int n;};
int ts4_contains_value_88609470(int x,struct S*s){int r=0;int i=0;int n=s->n;if(n<=0)return r;do{if(s->a[i]==x){r=1;break;}++i;}while(i<n);return r;}
