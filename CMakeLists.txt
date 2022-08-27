#>>Cmake Generals
cmake_minimum_required(VERSION 3.10)
get_filename_component(ProjectId ${CMAKE_CURRENT_LIST_DIR} NAME)
string(REPLACE " " "_" ProjectId ${ProjectId})
project(${ProjectId}
         VERSION 1.0
         LANGUAGES CXX)

######################################
#   GRPC and PROTOBUF Parts
######################################
include(cmake/common.cmake)
# Proto file
file(GLOB PROTOBUF_DEFINITION_FILES "${PROJECT_SOURCE_DIR}/data/*.proto")
#get_target_property(grpc_cpp_plugin_location gRPC::grpc_cpp_plugin LOCATION)
set(PROTOBUF_INPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/data")
set(PROTOBUF_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/Models/")
foreach(file ${PROTOBUF_DEFINITION_FILES})
    set(PROTOBUF_ARGUMENTS "protoc --proto_path=\"${PROTOBUF_INPUT_DIRECTORY}\" \
        --grpc_out=\"${PROTOBUF_OUTPUT_DIRECTORY}\" --cpp_out=\"${PROTOBUF_OUTPUT_DIRECTORY}\" \
        --plugin=protoc-gen-grpc=\"${_GRPC_CPP_PLUGIN_EXECUTABLE}\" \"${file}\"")
    exec_program(${PROTOBUF_ARGUMENTS}
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
    RESULT_VARIABLE PROTOBUF_RESULT
    OUTPUT_VARIABLE PROTOBUF_OUTPUT_VARIABLE)
     message("${PROTOBUF_RESULT}" )
     message("${PROTOBUF_OUTPUT_VARIABLE}")
endforeach()
file(GLOB PROTOBUF_MODELS_INCLUDES "Models/*.pb.cc" "Models/*.hpp")
get_filename_component(PROTOBUF_MODELS_INCLUDES_PATH "${PROTOBUF_MODELS_INCLUDES}" PATH)
set( GRPC_TRACE "all")
set( GRPC_VERBOSITY "DEBUG")
######################################
#   Projecy sub dirs
######################################
add_subdirectory(grpc-test-server)
add_subdirectory(grpc-test-client)
