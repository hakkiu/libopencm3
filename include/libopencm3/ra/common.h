
#define REG_MODE(bit, mode)		((mode) << bit)
#define REG_MODE_MASK(size, bit)		((((1 << (size)) - 1)) << (bit))