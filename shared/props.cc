#include <openenclave/enclave.h>

// Default parameters, can be overridden during signing.
OE_SET_ENCLAVE_SGX(
    1,    /* ProductID */
    1,    /* SecurityVersion */
    true, /* AllowDebug */
    4096, /* HeapPageCount */
    2048,  /* StackPageCount */
    1);   /* TCSCount */
