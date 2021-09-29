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

endif()

SET(LIBRARY_OUTPUT_PATH  ${PROJECT_SOURCE_DIR}\\build)
SET(BRARY_IDC_PATH ${LIBRARY_OUTPUT_PATH}\\Release\\${PROJECT_NAME})

SET(PROJECT_DEFIN ${PROJECT_SOURCE_DIR}/Axctive/Axctive.def)
aux_source_directory(${PROJECT_SOURCE_DIR}/Axctive AxList)

find_package(Qt5 COMPONENTS Core AxServer REQUIRED)

add_library(${PROJECT_NAME} SHARED
    main.cpp
    ${AxList}
    ${PROJECT_DEFIN}
)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD

    COMMAND idc ${BRARY_IDC_PATH}.dll -idl ${BRARY_IDC_PATH}.idl -version 1.0
    COMMAND midl ${BRARY_IDC_PATH}.idl /tlb ${BRARY_IDC_PATH}.tlb
    COMMAND idc ${BRARY_IDC_PATH}.dll -tlb ${BRARY_IDC_PATH}.tlb
    COMMENT "Generating and embedding type library"
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    Qt5::AxServer
    Qt5::Core
)
