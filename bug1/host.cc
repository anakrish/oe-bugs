#include <iostream>
#include <exception>
#include "enclave_error.h"
#include "test_u.h"

int main(int argc, char* argv[]) {
  char* enclave_path = argv[1];
  uint32_t enclave_flags = OE_ENCLAVE_FLAG_DEBUG;

  bool simulate = false;
  if (simulate) {
    enclave_flags |= OE_ENCLAVE_FLAG_SIMULATE;
  }

  std::cout << "Creating enclave" << std::endl;
  oe_enclave_t* enclave;
  oe_check(oe_create_test_enclave(
            enclave_path, OE_ENCLAVE_TYPE_SGX, enclave_flags, NULL, 0, &enclave));
  std::cout << "Enclave created" << std::endl;

  int status = 0;
  oe_check(test(enclave, &status));
  std::cout << "Done" << std::endl;
}