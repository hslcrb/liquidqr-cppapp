cmake_minimum_required(VERSION 3.16)

project(LiquidQR VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)

add_executable(appLiquidQR
    src/main.cpp
    src/qrcodegen.cpp
    src/QRGenerator.cpp
    src/MainWindow.cpp
    src/LiquidBackground.cpp
)

target_link_libraries(appLiquidQR PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
)
