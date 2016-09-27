//#include <offload.h>

void xeonphi_force_init(void) {
  #pragma offload target(mic)
  {}
}

/*int xeonphi_num_devices(void) {
  return _Offload_number_of_devices();
}*/
