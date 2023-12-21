cmake_minimum_required(VERSION 3.8)

include(FetchContent)

project(qt-composition)


set(CMAKE_CXX_STANDARD 14)
set(CMAKE_PREFIX_PATH "C:/Qt/5.15.15/msvc2019_64/lib/cmake")

set(QT_LIBS Core)

find_package(Qt5 COMPONENTS ${QT_LIBS} REQUIRED)
set(QT_LIBS_WITH_PREFIX)
foreach(lib ${QT_LIBS})
    list(APPEND QT_LIBS_WITH_PREFIX "Qt::${lib}")
endforeach()

if (WIN32)
    set(QT_COMPOSITION_BIN_OUTPUT ${PROJECT_BINARY_DIR}/bin)
    message("QT_COMPOSITION_BIN_OUTPUT: ${QT_COMPOSITION_BIN_OUTPUT}")
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${QT_COMPOSITION_BIN_OUTPUT})
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${QT_COMPOSITION_BIN_OUTPUT})
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${QT_COMPOSITION_BIN_OUTPUT})
    set(CMAKE_DEBUG_POSTFIX "")
endif()

add_subdirectory(Tests)
add_subdirectory(QtComposition)