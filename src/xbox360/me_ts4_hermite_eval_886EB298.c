extern float lbl_8814B45C;
extern float g_ts4_script_constants[];
typedef struct Hermite { float p0, p1, m0, m1; } Hermite;
float hermite_eval_886EB298(float t, const Hermite *h){
 float t2 = t * t; float t3 = t2 * t;
 float a = h->p0*lbl_8814B45C - h->p1*lbl_8814B45C + h->m1 + h->m0;
 float b = h->p1*g_ts4_script_constants[0x4c/4] - h->p0*g_ts4_script_constants[0x4c/4] - h->m0*lbl_8814B45C - h->m1;
 return a*t3 + b*t2 + h->m0*t + h->p0; }