cmake_minimum_required(VERSION 3.0.0)
project(rpclib_benchmark)

set(CMAKE_CXX_COMPILER clang++)

macro(remove_cxx_flag flag)
    string(REPLACE "${flag}" "" CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE}")
endmacro()

option(USE_O2 "Use -O2 instead of the default -O3" OFF)

if (NOT CMAKE_BUILD_TYPE STREQUAL "Release")
    message(WARNING "Not building in release mode!")
else()
    if (USE_O2)
        remove_cxx_flag("-O3")
        set(CMAKE_CXX_FLAGS_RELEASE "-O2 ${CMAKE_CXX_FLAGS_RELEASE}")
    endif()
    message(STATUS "Release flags: ${CMAKE_CXX_FLAGS_RELEASE}")
endif()


set(CMAKE_EXPORT_COMPILE_COMMANDS "ON") # for YCM

# if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/build/conanbuildinfo.cmake) #Clion, with conanbuildinfo.cmake in build folder
#    include(${CMAKE_CURRENT_SOURCE_DIR}/build/conanbuildinfo.cmake)
# else()
#    include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake) # Not CLion
# endif()

# conan_basic_setup()

set(THREADS_PREFER_PTHREAD_FLAG ON)

find_package(ZLIB REQUIRED)
message(STATUS "Using ZLIB ${ZLIB_VERSION}")
find_package(Threads REQUIRED)
message(STATUS "Using Threads ${Threads_VERSION}")
find_package(CapnProto CONFIG REQUIRED)
message(STATUS "Using CapnProto ${CapnProto_VERSION}")
find_package(benchmark REQUIRED)
message(STATUS "Using benchmark ${benchmark_VERSION}")
find_package(rpclib REQUIRED)
message(STATUS "Using rpclib ${rpclib_VERSION}")


# Find Protobuf installation
# Looks for protobuf-config.cmake file installed by Protobuf's cmake installation.

##########################################
# set(protobuf_MODULE_COMPATIBLE TRUE)
# find_package(Protobuf REQUIRED)
# message(STATUS "Using Protobuf ${Protobuf_VERSION}")
# set(_PROTOBUF_LIBPROTOBUF protobuf::libprotobuf)

# find_package(gRPC REQUIRED)
# message(STATUS "Using gRPC ${gRPC_VERSION}")
# set(_GRPC_GRPCPP_UNSECURE gRPC::grpc++_unsecure)
##########################################


add_executable(rpclib_benchmark
    src/target_code.cc
    src/benchmark.cc
    src/capnp/capnp_service.capnp.c++
    src/thrift/thrift_service_constants.cpp
    src/thrift/thrift_service_types.cpp
    src/thrift/ThriftServiceBenchmark.cpp
    src/thrift/struct_helpers.cc
    # src/grpc/grpc_service.pb.cc
    # src/grpc/grpc_service.grpc.pb.cc
    # src/grpc/struct_helpers.cc
    src/rpclib/struct_helpers.cc
    src/capnp/struct_helpers.cc
    )

# target_link_libraries(rpclib_benchmark ${CONAN_LIBS})
target_link_libraries(rpclib_benchmark PRIVATE 
    CapnProto::capnp
    CapnProto::capnp-rpc)

target_link_libraries(rpclib_benchmark PUBLIC
    /usr/local/lib/libthrift.a
    Threads::Threads
    benchmark::benchmark
    rpclib::rpc
    ${ZLIB_LIBRARIES}
    # ${_PROTOBUF_LIBPROTOBUF}
    # ${_GRPC_GRPCPP_UNSECURE}
    )
set_target_properties(
        rpclib_benchmark
        PROPERTIES
        CXX_STANDARD 14)
# target_compile_definitions(rpclib_benchmark PUBLIC ${CONAN_DEFINES})

target_include_directories(rpclib_benchmark PUBLIC include)
target_include_directories(rpclib_benchmark PUBLIC include/thrift)
target_include_directories(rpclib_benchmark PUBLIC include/capnp)
# target_include_directories(rpclib_benchmark PUBLIC include/grpc)

add_custom_command(TARGET rpclib_benchmark POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E
                   copy ${CMAKE_BINARY_DIR}/compile_commands.json ${CMAKE_BINARY_DIR}/../compile_commands.json)

