cmake_minimum_required(VERSION 3.23)
project(horoshoeditor)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

IF (WIN32)
    set(CMAKE_PREFIX_PATH "C:\\Program Files\\Qt6\\6.4.0\\msvc2019_64\\lib\\cmake")
ENDIF()

find_package(Qt6 REQUIRED COMPONENTS Widgets)
find_package(Qt6 REQUIRED COMPONENTS Gui)
qt_standard_project_setup()
include_directories(include/colorchannels)
include_directories(include/colorspaces/)
include_directories(include/qimagewidget/)
include_directories(include/qinterface/)
include_directories(include/pnm/)
include_directories(include/colorspaces)
include_directories(include/colorchannels)
add_executable(horoshoeditor src/app/main.cpp
        include/pnm/Pnm.h src/pnm/Pnm.cpp
        include/qimagewidget/QImageWidget.h src/qimagewidget/QImageWidget.cpp
        include/qinterface/QOpenPictureWindow.h src/qinterface/QOpenPictureWindow.cpp
        include/qinterface/QMain.h src/qinterface/QMain.cpp
        include/qinterface/QSavePictureWindow.h src/qinterface/QSavePictureWindow.cpp
        include/colorchannels/selectcolorchannel.h src/colorchannels/selectcolorchannel.cpp
        include/colorspaces/CMYColorSpace.h src/colorspaces/CMYColorSpace.cpp
        include/colorspaces/HSLColorSpace.h src/colorspaces/HSLColorSpace.cpp
        include/colorspaces/HSVColorSpace.h src/colorspaces/HSVColorSpace.cpp
        include/colorspaces/YCbCr_601ColorSpace.h src/colorspaces/YCbCr_601ColorSpace.cpp
        include/colorspaces/YCbCr_709ColorSpace.h src/colorspaces/YCbCr_709ColorSpace.cpp
        include/colorspaces/YCoCgColorSpace.h src/colorspaces/YCoCgColorSpace.cpp
        include/qinterface/QChangeColorspaceWindow.h src/qinterface/QChangeColorspaceWindow.cpp)
target_link_libraries(horoshoeditor PRIVATE Qt6::Widgets)
target_link_libraries(horoshoeditor PRIVATE Qt6::Gui)

set_target_properties(horoshoeditor PROPERTIES
        WIN32_EXECUTABLE ON
        MACOSX_BUNDLE ON
        )