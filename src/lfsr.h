#include <tuple>

typedef uint32_t lfsr_poly_t;
typedef uint32_t lfsr_state_t;

struct lfsr_t {
    lfsr_poly_t poly;
    lfsr_state_t state;

    lfsr_t(lfsr_poly_t poly, lfsr_state_t state = 1);
};


static inline int popcnt(uint32_t x)
{
    int c;
    for (c = 0; x != 0; x >>= 1)
        if (x & 1)
            c++;
    return c;
}

static inline uint32_t reverse32(uint32_t v) {
    uint32_t rtn = 0;
    for(int i = 0;i < 32;i++) {
        rtn = rtn << 1;
        rtn |= v & 1;
        v = v >> 1;
    }
    return rtn;
}


uint32_t lfsr_period(lfsr_poly_t p);
uint32_t lfsr_find(lfsr_poly_t p, lfsr_state_t start, lfsr_state_t end);

void print_binary(uint32_t v);
lfsr_poly_t lsfr_mirror_poly(lfsr_poly_t poly);
lfsr_state_t lsfr_iterate(lfsr_state_t state, lfsr_poly_t poly, uint32_t cnt = 1);
lfsr_t lsfr_iterate(lfsr_t lsfr, uint32_t cnt = 1);