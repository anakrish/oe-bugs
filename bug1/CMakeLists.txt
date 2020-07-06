set(EDL_PATH ${CMAKE_CURRENT_SOURCE_DIR}/test.edl)
#oeedl_file(${EDL_PATH} enclave edl_enclave_src)
#oeedl_file(${EDL_PATH} host edl_host_src)

add_custom_command(
  OUTPUT test_t.c test_u.c test_args.h
  DEPENDS ${EDL_PATH}
  COMMAND
    openenclave::oeedger8r ${EDL_PATH}
    --search-path ${OE_INCLUDEDIR} --search-path
    ${OE_INCLUDEDIR}/openenclave/edl/sgx)

set(edl_include_dir ${CMAKE_CURRENT_BINARY_DIR})

add_executable(bug1_enclave 
    test_t.c
    ${PROPS_CC}
    enclave.cc
)

target_include_directories(bug1_enclave PRIVATE
    ${edl_include_dir}
)

target_link_libraries(bug1_enclave PRIVATE
    openenclave::oeenclave
    openenclave::oelibc
    openenclave::oelibcxx
)

add_executable(bug1_host
    test_u.c
    host.cc
)

target_include_directories(bug1_host PRIVATE
    ${edl_include_dir}
)

target_link_libraries(bug1_host PRIVATE
    openenclave::oehost
)
