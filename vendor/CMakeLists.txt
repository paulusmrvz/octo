
find_package(Vulkan REQUIRED)

set(CMAKE_GLFW_DIR glfw)
set(GLFW_INCLUDE ${CMAKE_GLFW_DIR}/include)
set(GLFW_LIB glfw)
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory(${CMAKE_GLFW_DIR})

set(CMAKE_GLM_DIR glm)
set(GLM_INCLUDE ${CMAKE_GLM_DIR}/glm)
set(GLM_LIB glm)
add_subdirectory(${CMAKE_GLM_DIR})

set(CMAKE_IMGUI_DIR imgui)
set(IMGUI_INCLUDE
    ${CMAKE_IMGUI_DIR}
    ${CMAKE_IMGUI_DIR}/backends
)
set(IMGUI_LIB imgui)
add_library(${IMGUI_LIB} STATIC
    ${CMAKE_IMGUI_DIR}/backends/imgui_impl_glfw.cpp 
    ${CMAKE_IMGUI_DIR}/backends/imgui_impl_vulkan.cpp 
    ${CMAKE_IMGUI_DIR}/imgui.cpp 
    ${CMAKE_IMGUI_DIR}/imgui_draw.cpp 
    ${CMAKE_IMGUI_DIR}/imgui_demo.cpp 
    ${CMAKE_IMGUI_DIR}/imgui_tables.cpp 
    ${CMAKE_IMGUI_DIR}/imgui_widgets.cpp
)
target_include_directories(${IMGUI_LIB} PRIVATE ${IMGUI_INCLUDE} ${GLFW_INCLUDE} ${CMAKE_GLFW_DIR}/deps)
target_link_libraries(${IMGUI_LIB} PRIVATE ${GLFW_LIB} Vulkan::Vulkan)

set(CMAKE_SPDLOG_DIR spdlog)
set(SPDLOG_INCLUDE ${CMAKE_SPDLOG_DIR}/include)
set(SPDLOG_LIB spdlog)
add_subdirectory(${CMAKE_SPDLOG_DIR})

set(CMAKE_STB_DIR stb)
set(STB_INCLUDE ${CMAKE_STB_DIR})
set(STB_LIB stb)
add_library(${STB_LIB} INTERFACE)
target_include_directories(${STB_LIB} INTERFACE ${STB_INCLUDE})

set(CMAKE_LOADER_DIR tinyobjloader)
set(LOADER_INCLUDE ${CMAKE_LOADER_DIR})
set(LOADER_LIB tinyobjloader)
add_subdirectory(${CMAKE_LOADER_DIR})