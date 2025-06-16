file(GLOB_RECURSE MY_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/Source/*.cpp")

if (MSVC)
    add_compile_options(/arch:AVX2)
endif()

add_executable(Game)

target_sources(Game PRIVATE ${MY_SOURCES})

if (MSVC)
    target_compile_definitions(Game PUBLIC _CRT_SECURE_NO_WARNINGS)
endif()

target_include_directories(Game PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/Include/")

target_link_libraries(Game PRIVATE Engine)
