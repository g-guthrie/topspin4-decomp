struct Child { virtual void Release(int flags) = 0; };
extern "C" char lbl_880F22A4[];
struct Self { void *vt; Child *kids[2]; int mc; };
extern "C" void ts4_release_children_886ED508(Self *s){ int i; Child **p; s->mc = 0; s->vt = lbl_880F22A4; for (p = s->kids, i = 2; i != 0; i--, p++) if (*p) (*p)->Release(1); }