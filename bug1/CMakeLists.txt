set(EDL_PATH ${CMAKE_CURRENT_SOURCE_DIR}/test.edl)
oeedl_file(${EDL_PATH} enclave edl_enclave_src)
oeedl_file(${EDL_PATH} host edl_host_src)

set(edl_include_dir ${CMAKE_CURRENT_BINARY_DIR})

add_executable(bug1_enclave 
    ${edl_enclave_src}
    ${PROPS_CC}
    enclave.cc
)

target_include_directories(bug1_enclave PRIVATE
    ${edl_include_dir}
)

target_link_libraries(bug1_enclave PRIVATE
    openenclave::oeenclave
    openenclave::oelibcxx
)

add_executable(bug1_host
    ${edl_host_src}
    host.cc
)

target_include_directories(bug1_host PRIVATE
    ${edl_include_dir}
)

target_link_libraries(bug1_host PRIVATE
    openenclave::oehostapp
)
