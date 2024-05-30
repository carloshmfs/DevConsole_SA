cmake_minimum_required(VERSION 3.26.3)

project(GameConsoleSA VERSION 1.0
                       LANGUAGES CXX)

# Enable the export of compile commands
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Project setup standards
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 23)

# Project target setup
file(GLOB SOURCES
    "src/*.cpp"
    "src/*.h"
)
add_library(${CMAKE_PROJECT_NAME} SHARED ${SOURCES})

set_target_properties(${CMAKE_PROJECT_NAME} 
    PROPERTIES
    SUFFIX ".asi"
    RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin"
)

# Link with plugin_sdk
if(DEFINED ENV{PLUGIN_SDK_DIR})
    set(PLUGIN_SDK_DIR $ENV{PLUGIN_SDK_DIR})
    target_include_directories(
        ${CMAKE_PROJECT_NAME} PRIVATE
        "${PLUGIN_SDK_DIR}/shared"
        "${PLUGIN_SDK_DIR}/shared/game"
        "${PLUGIN_SDK_DIR}/plugin_SA"
        "${PLUGIN_SDK_DIR}/plugin_SA/game_SA"
    )
    target_link_directories(${CMAKE_PROJECT_NAME} PRIVATE "${PLUGIN_SDK_DIR}/output/lib")
    target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE "plugin_d.lib")
else()
    message(FATAL_ERROR "PLUGIN_SDK_DIR not defined in your enviroment")
endif()

# Important preprocessor definitions
target_compile_definitions(${CMAKE_PROJECT_NAME} PRIVATE
    _CRT_SECURE_NO_WARNINGS
    _CRT_NON_CONFORMING_SWPRINTFS
    _USE_MATH_DEFINES
    _SILENCE_CXX17_CODECVT_HEADER_DEPRECATION_WARNING
    NDEBUG
    GTASA
    PLUGIN_SGV_10US
    RW
)

# Install rotine
if(DEFINED ENV{GTA_SA_DIR})
    set(INSTALL_DIR $ENV{GTA_SA_DIR}/scripts)
else()
    message(FATAL_ERROR "GTA_SA_DIR not defined in your enviroment")
endif()

install(TARGETS ${CMAKE_PROJECT_NAME}
    RUNTIME DESTINATION ${INSTALL_DIR}
)
