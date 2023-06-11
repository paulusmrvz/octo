set(SRC_FILES
    main.cpp
    tools/duration.h
    tools/log.cpp
    tools/log.h
    core/window.cpp
    core/window.h
    core/device.cpp
    core/device.h
)

add_executable(${PROJECT_NAME} ${SRC_FILES})

set(INCLUDE_LIBS ../vendor)

target_include_directories(${PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${INCLUDE_LIBS}/glfw/include
    ${INCLUDE_LIBS}/glm
    ${INCLUDE_LIBS}/imgui
    ${INCLUDE_LIBS}/imgui/backends
    ${INCLUDE_LIBS}/spdlog/include
    ${INCLUDE_LIBS}/stb
    ${INCLUDE_LIBS}/tinyobjloader
)

find_package(Vulkan REQUIRED)

target_link_libraries(${PROJECT_NAME} PRIVATE
    Vulkan::Vulkan
    glfw
    glm
    imgui
    spdlog
    stb
    tinyobjloader
)

set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED ON
)

#target_precompile_headers(${PROJECT_NAME} PUBLIC
#   
#)