# 开启MOC和UIC
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# 配置
set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} C:/Qt/6.2.2/mingw_64 C:/MinGW-Library)
set(CMAKE_CXX_STANDARD 17)

# 查找包
find_package(Qt6 REQUIRED COMPONENTS Widgets)
find_package(SDL2 REQUIRED)
find_package(spdlog REQUIRED)

# 包含目录
include_directories(
        third-party/rapidjson
        core
        ${Qt6Widgets_INCLUDE_DIRS}
        ${SDL2_INCLUDE_DIRS}
        ${SPDLOG_INCLUDE_DIRS}
)

set(
        QtDriver
        driver/mainwindow.h driver/mainwindow.cpp)

set(
        Core
        ${CMAKE_CURRENT_SOURCE_DIR}/core/config.cpp
)

add_subdirectory(test)

set(SOURCES ${QtDriver} ${Core} main.cpp)

add_executable(pgnes ${SOURCES})

target_link_libraries(
        pgnes
        ${Qt6Widgets_LIBRARIES}
        ${SPDLOG_LIBRARIES}
        ${SDL2_LIBRARIES})

#[[
find_package(Qt6 REQUIRED COMPONENTS Widgets OpenGL OpenGLWidgets ${QtHelpModule})
find_package(SDL2 REQUIRED)

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/src/
        ${SDL2_INCLUDE_DIRS})
include_directories(${Qt6Widgets_INCLUDE_DIRS} ${Qt6Help_INCLUDE_DIRS} ${Qt6OpenGLWidgets_INCLUDE_DIRS})

set(QtDriver
        ${CMAKE_CURRENT_SOURCE_DIR}/src/driver/application.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/driver/mainwindow.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/driver/window_view.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/driver/window_view_opengl.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/driver/window_view_sdl.cpp)

set(Core
        ${CMAKE_CURRENT_SOURCE_DIR}/src/core/nes.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/core/config.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)
]]