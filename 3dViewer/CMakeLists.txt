cmake_minimum_required(VERSION 3.5)

project(3dViewer VERSION 0.1 LANGUAGES CXX C)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_PREFIX_PATH "/Users/kirillsmagin/Qt/6.4.2/macos/lib/cmake")

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
find_package(Qt6 REQUIRED COMPONENTS OpenGLWidgets)
find_package(Qt6 REQUIRED COMPONENTS QuickWidgets)
find_package(Qt6 REQUIRED COMPONENTS Quick3D)


set(PROJECT_SOURCES
        main.cpp
        modelview.h
        modelview.cpp
        saveload.cpp
        saveload.h
        modeiinstance.cpp
        modeiinstance.h
        gradienttex.cpp
        gradienttex.h
        gifcreator.cpp
        gifcreator.h
        gif.h
        ../parser_.h
        ../parser_.c
        ../vertex_.h
        ../affine_transfomation_.c
        ../affine_transfomation_.h
        ../Dynamic_Array_.h
        ../Dynamic_Array_.c
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(3dViewer
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET 3dViewer APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(3dViewer SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(3dViewer
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(3dViewer PRIVATE Qt6::QuickWidgets)
target_link_libraries(3dViewer PRIVATE Qt6::OpenGLWidgets)
target_link_libraries(3dViewer PRIVATE Qt6::Gui)
target_link_libraries(3dViewer PRIVATE Qt6::Quick3D)

qt_add_qml_module(3dViewer
    URI Example
    VERSION 1.0
    QML_FILES
        main.qml
    NO_RESOURCE_TARGET_PATH
)

set_target_properties(3dViewer PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS 3dViewer
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(3dViewer)
endif()
