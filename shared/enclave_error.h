#pragma once

#include <iostream>
#include <openenclave/host.h>

void oe_check(oe_result_t result) {
  if (result != OE_OK) {
    std::cerr << oe_result_str(result) << std::endl;
    abort();
  }
}