# Tweak OE 

The call to `oe_abort` must be commented out in `libc/syscalls.c`:
https://github.com/openenclave/openenclave/blob/923d14af1625723304e304fc8cb5f22d882abc66/libc/syscalls.c#L51-L56
```c
    if (clk_id != CLOCK_REALTIME)
    {
        /* Only supporting CLOCK_REALTIME */
        // oe_assert("clock_gettime(): panic" == NULL);  <---- comment out this line.
        goto done;
    }
```

# Build

```sh
mkdir build
cd build
cmake ..
make
```

# Run

## Bug1

```sh
cd build
bug1/bug1_host bug1/bug1_enclave
```
