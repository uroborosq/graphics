cmake_minimum_required(VERSION 3.23)
project(horoshoeditor)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)
find_package(Qt6 REQUIRED COMPONENTS Gui)
qt_standard_project_setup()
include_directories(include/qimagewidget/)
add_executable(horoshoeditor src/app/main.cpp include/qimagewidget/QImageWidget.h src/qimagewidget/QImageWidget.cpp)
target_link_libraries(horoshoeditor PRIVATE Qt6::Widgets)
target_link_libraries(horoshoeditor PRIVATE Qt6::Gui)

set_target_properties(horoshoeditor PROPERTIES
        WIN32_EXECUTABLE ON
        MACOSX_BUNDLE ON
        )