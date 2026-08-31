typedef unsigned char u8;
typedef unsigned int u32;

typedef struct Ts4Service {
    u8 reserved[0x48];
    void *component;
} Ts4Service;

extern Ts4Service *ts4_find_service(u32 service_id);
