cmake_minimum_required(VERSION 3.18)

project(funQ2C LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(MSVC)
    add_compile_options(
        $<$<CONFIG:>:/MT> #---------|
        $<$<CONFIG:Debug>:/MTd> #---|-- Statically link the runtime libraries
        $<$<CONFIG:Release>:/MT> #--|
    )
    set(Qt5_DIR E:\\qt5_static\\lib\\cmake\\Qt5)
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SAFESEH:NO")
    set(CMAKE_SHARED_LINKER_FLAGS_RELEASE "${CMAKE_SHARED_LINKR_FLAGS} /SAFESEH:NO")
	include_directories(${PROJECT_SOURCE_DIR}\\functionQ\\thrid_party\\ffmpeg\\include)
	link_directories(${PROJECT_SOURCE_DIR}\\functionQ\\thrid_party\\ffmpeg\\lib)

endif()

find_package(Qt5 COMPONENTS Core AxServer Network REQUIRED)

SET(LIBRARY_OUTPUT_PATH  ${PROJECT_SOURCE_DIR}\\build)

SET(BRARY_IDC_PATH ${LIBRARY_OUTPUT_PATH}\\Release\\${PROJECT_NAME})

aux_source_directory(${PROJECT_SOURCE_DIR}/functionQ/scrcpy DeviceList)
aux_source_directory(${PROJECT_SOURCE_DIR}/functionQ/scrcpy/decoder DecoderList)
aux_source_directory(${PROJECT_SOURCE_DIR}/functionQ/scrcpy/controller ControllerList)

add_library(${PROJECT_NAME} SHARED
    main.cpp
    funDevice.h
    funDevice.cpp
    funQ2C.h
    funQ2C.cpp
    funQ2C.def
    ${DeviceList}
    ${DecoderList}
    ${ControllerList}
)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD

    COMMAND idc ${BRARY_IDC_PATH}.dll -idl ${BRARY_IDC_PATH}.idl -version 1.0
    COMMAND midl ${BRARY_IDC_PATH}.idl /nologo /tlb ${BRARY_IDC_PATH}.tlb
    COMMAND idc ${BRARY_IDC_PATH}.dll -tlb ${BRARY_IDC_PATH}.tlb
    COMMENT "Generating and embedding type library"
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    Qt5::AxServer
    Qt5::Core
    Qt5::Network
    avcodec
    avformat
    avutil
    swscale 
)
