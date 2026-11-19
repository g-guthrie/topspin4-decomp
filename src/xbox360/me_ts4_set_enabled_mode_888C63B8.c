typedef struct { char pad[0x139]; unsigned char disabled; char pad2[0x12]; int *mode; } Ts4ModeOwner;
/* Sets the disabled flag from enable, and writes mode 1 (enabled) or 2 (disabled). */
void ts4_set_enabled_mode_888C63B8(Ts4ModeOwner *o, unsigned char enable)
{ o->disabled = !enable; if (enable) *o->mode = 1; else *o->mode = 2; }