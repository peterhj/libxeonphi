#include <offload.h>

#include <stdint.h>
#include <stdlib.h>
#include <string.h>

void xeonphi_force_init(void) {
  #pragma offload target(mic)
  {}
}

int xeonphi_num_devices(void) {
  return _Offload_number_of_devices();
}

void xeonphi_malloc(uint8_t *hptr, size_t sz, int dev_idx) {
  #pragma offload target(mic:dev_idx) \
          nocopy(hptr:length(0) alloc_if(0) free_if(0))
  {
    hptr = (uint8_t *)malloc(sz);
  }
}

void xeonphi_free(uint8_t *hptr, int dev_idx) {
  #pragma offload target(mic:dev_idx) \
          nocopy(hptr:length(0) alloc_if(0) free_if(0))
  {
    free((void *)hptr);
  }
}

void xeonphi_copy_up(const uint8_t *hptr, size_t sz, int dev_idx) {
  #pragma offload_transfer target(mic:dev_idx) \
          in(hptr:length(sz) alloc_if(0) free_if(0))
  {}
}

void xeonphi_copy_down(uint8_t *hptr, size_t sz, int dev_idx) {
  #pragma offload_transfer target(mic:dev_idx) \
          out(hptr:length(sz) alloc_if(0) free_if(0))
  {}
}

void xeonphi_memset(uint8_t *hptr, size_t sz, int dev_idx, uint8_t val) {
  #pragma offload target(mic:dev_idx) \
          nocopy(hptr:length(sz) alloc_if(0) free_if(0))
  {
    memset(hptr, sz, val);
  }
}
