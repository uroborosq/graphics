cmake_minimum_required(VERSION 3.23)
project(horoshoeditor)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

IF (WIN32)
    set(CMAKE_PREFIX_PATH "C:\\Users\\UroborosQ\\AppData\\Local\\6.4.0\\msvc2019_64\\lib\\cmake")
    # сюда загнать путь к libdeflate.h
    include_directories("C:/windagovno/libdeflate")
    add_library(libdeflate SHARED IMPORTED)
    # сюда загнать путь к libdeflate.dll
    set_property(TARGET libdeflate PROPERTY IMPORTED_LOCATION "C:/windagovno/libdeflate/libdeflate.a")
    # сюда загнать путь к libdeflate.dll.a
    set_property(TARGET libdeflate PROPERTY IMPORTED_IMPLIB "C:/windagovno/libdeflate/libdeflate.dll.a")
ENDIF ()

find_package(Qt6 REQUIRED COMPONENTS Widgets)
find_package(Qt6 REQUIRED COMPONENTS Gui)

if (UNIX)
    find_package(libdeflate)
ENDIF ()


qt_standard_project_setup()
include_directories(include/colorchannels)
include_directories(include/colorspaces/)
include_directories(include/qimagewidget/)
include_directories(include/qinterface/)
include_directories(include/file/)
include_directories(include/colorspaces)
include_directories(include/colorchannels)
include_directories(include/pixels)
include_directories(include/gamma)
include_directories(include/dithering)
include_directories(include/line)
include_directories(include/gradient)
include_directories(include/interpolations)
include_directories(include/filtration)
include_directories(include/qinterface/filtrationwindows)

include_directories()

add_executable(
        horoshoeditor src/app/main.cpp
        include/file/Pnm.h src/file/Pnm.cpp
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
        include/colorspaces/sRGBColorSpace.h src/colorspaces/sRGBColorSpace.cpp
        include/qinterface/QChangeColorspaceWindow.h src/qinterface/QChangeColorspaceWindow.cpp
        include/pixels/Pixels.h src/pixels/Pixels.cpp
        include/pixels/ColorSpaceEnum.h src/pixels/ColorSpaceEnum.cpp
        include/pixels/ColorChannelEnum.h
        include/qinterface/QAssignGammaWindow.h src/qinterface/QAssignGammaWindow.cpp
        include/qinterface/QConvertGammaWindow.h src/qinterface/QConvertGammaWindow.cpp
        include/gamma/GammaCorrection.h src/gamma/GammaCorrection.cpp include/dithering/AbstractDithering.h
        include/dithering/Ordered8x8Dithering.h src/dithering/Ordered8x8Dithering.cpp
        include/dithering/AbstractDithering.h
        include/dithering/AtkinsonDithering.h src/dithering/AtkinsonDithering.cpp
        include/dithering/BordersController.h src/dithering/BordersController.cpp
        include/dithering/DitheringMethodFactory.h src/dithering/DitheringMethodFactory.cpp
        include/dithering/FloydSteinbergDithering.h src/dithering/FloydSteinbergDithering.cpp
        include/dithering/NearestColor.h src/dithering/NearestColor.cpp
        include/dithering/RandomDithering.h src/dithering/RandomDithering.cpp
        include/dithering/DitheringEnum.h
        include/gamma/GammaCorrection.h src/gamma/GammaCorrection.cpp
        include/line/DrawColoredLine.h src/line/DrawColoredLine.cpp
        include/gradient/Gradient.h src/gradient/Gradient.cpp
        include/qinterface/QLineParametersSelectionWindow.h src/qinterface/QLineParametersSelectionWindow.cpp
        include/qinterface/QDrawLineWindow.h src/qinterface/QDrawLineWindow.cpp
        include/qinterface/QGradientGenerationWindow.h src/qinterface/QGradientGenerationWindow.cpp
        include/qinterface/QDitheringParametersWindow.h src/qinterface/QDitheringParametersWindow.cpp
        include/qinterface/QChooseImageDialog.h src/qinterface/QChooseImageDialog.cpp
        include/file/AbstractFile.h
        include/file/Png.h src/file/Png.cpp
        include/file/FileImageInfo.h
        include/file/FileFormatType.h include/file/PngFilters.h src/file/PngFilters.cpp include/file/FileOpenDecider.h src/file/FileOpenDecider.cpp include/file/FileFormat.h src/file/Pnm.cpp
        include/interpolations/AbstractInterpolation.h
        include/interpolations/NearestNeighbourInterpolation.h src/interpolations/NearestNeighbourInterpolation.cpp
        include/interpolations/BilinearInterpolation.h src/interpolations/BilinearInterpolation.cpp
        include/interpolations/LanczosInterpolation.h src/interpolations/LanczosInterpolation.cpp
        include/interpolations/BCSplinesInterpolation.h src/interpolations/BCSplinesInterpolation.cpp
        include/qinterface/QImageScalingWindow.h src/qinterface/QImageScalingWindow.cpp
        include/interpolations/InterpolationEnum.h
        include/qinterface/QBCSplineWindow.h src/qinterface/QBCSplineWindow.cpp
        include/interpolations/InterpolatinFabricMethod.h src/interpolations/InterpolationFabricMethod.cpp

        include/filtration/AbstractFiltering.h
        include/filtration/ThresholdFiltering.h src/filtration/ThresholdFiltering.cpp
        include/filtration/OtsuThresholdFiltering.h src/filtration/OtsuThresholdFiltering.cpp
        include/filtration/MedianFiltering.h src/filtration/MedianFiltering.cpp
        include/filtration/GaussianFiltering.h src/filtration/GaussianFiltering.cpp
        include/filtration/BoxBlurFiltering.h src/filtration/BoxBlurFiltering.cpp
        include/filtration/SobelFiltering.h src/filtration/SobelFiltering.cpp
        include/filtration/CASFiltering.h src/filtration/CASFiltering.cpp
        include/filtration/FiltrationEnum.h
        include/qinterface/filtrationwindows/QTresholdFiltrationWindow.h src/qinterface/filtrationwindows/QTresholdFiltrationWindow.cpp
        include/qinterface/filtrationwindows/QMedianFiltrationWindow.h src/qinterface/filtrationwindows/QMedianFiltrationWindow.cpp
        include/qinterface/filtrationwindows/QGaussianFiltrationWindow.h src/qinterface/filtrationwindows/QGaussianFiltrationWindow.cpp
        include/qinterface/filtrationwindows/QLinearAveragingFiltrationWindow.h src/qinterface/filtrationwindows/QLinearAveragingFiltrationWindow.cpp
        include/qinterface/filtrationwindows/QContrastAdaptiveSharpeningFiltrationWindow.h src/qinterface/filtrationwindows/QContrastAdaptiveSharpeningFiltrationWindow.cpp include/filtration/FiltrationFabricMethod.h src/filtration/FiltrationFabricMethod.cpp include/filtration/FilterConfiguration.h)

target_link_libraries(horoshoeditor PRIVATE Qt6::Widgets)
target_link_libraries(horoshoeditor PRIVATE Qt6::Gui)

if (UNIX)
    target_link_libraries(horoshoeditor PRIVATE libdeflate::libdeflate_shared)
endif ()
if (WIN32)
    target_link_libraries(horoshoeditor PRIVATE libdeflate)
endif ()

set_target_properties(horoshoeditor PROPERTIES
        WIN32_EXECUTABLE ON
        MACOSX_BUNDLE ON
        )