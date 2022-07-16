#ifndef FIR_H_
#define FIR_H_

#include <stdint.h>

#define FIR_FILTER_LENGTH 16

typedef struct fir_filter_t {
  float buf[FIR_FILTER_LENGTH];   // buffer array
  float out;                      // output value
  uint32_t idx;                   // buffer index (struct padded)
} fir_filter_t;

void fir_init(fir_filter_t *fir);
float fir_update(fir_filter_t *fir, float input);

#endif // FIR_H_