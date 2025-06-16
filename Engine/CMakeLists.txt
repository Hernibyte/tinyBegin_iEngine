add_library(Engine)

file(GLOB_RECURSE MY_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/Source/*.cpp")
file(GLOB_RECURSE MY_INCLUDES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/Include/*.hpp")

target_sources(Engine 
    PUBLIC 
        FILE_SET engine_headers
        TYPE HEADERS
        BASE_DIRS ./Include
        FILES ${MY_INCLUDES}
    PRIVATE
        ${MY_SOURCES}
)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)
set(GLFW_SHARED_LIBS OFF CACHE BOOL "" FORCE)

add_subdirectory(ThirdParty/glfw)
add_subdirectory(ThirdParty/glad)

target_compile_definitions(Engine PUBLIC GLFW_INCLUDE_NONE=1)

target_link_libraries(Engine PRIVATE glfw glad)
