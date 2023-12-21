include_directories(.)

add_library(qt_composition STATIC
        metaobjectbuilder.cpp
        qcomponentcontainer.cpp
        qcomponentfactoryinterface.cpp
        qcomponentregistry.cpp
        qexport.cpp
        qimport.cpp
        qlazy.cpp
        qpart.cpp
        qpartmetaobject.cpp
        qtestcomposition.cpp
        QtComposition_global.h
        metaobjectbuilder.h
        qcomponentcontainer.h
        qcomponentfactoryinterface.h
        qcomponentregistry.h
        qexport.h
        qimport.h
        qlazy.h
        qlazy.hpp
        qpart.h
        qpartmetaobject.h
        qtestcomposition.h
)

target_link_libraries(qt_composition  PUBLIC ${QT_LIBS_WITH_PREFIX})

#TODO !!!
add_compile_definitions(QTCOMPOSITION_LIBRARY)