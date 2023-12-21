include_directories(.)

add_library(qt_composition SHARED
        metaobjectbuilder.cpp
        qcomponentcontainer.cpp
        qcomponentfactoryinterface.cpp
        qcomponentregistry.cpp
        qexport.cpp
        qimport.cpp
        qlazy.cpp
        qpart.cpp
        qpartmetaobject.cpp
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
#        qtestcomposition.h
#        qtestcomposition.cpp
        qcomponentregistry.hpp
)

target_link_libraries(qt_composition  PUBLIC ${QT_LIBS_WITH_PREFIX})

#TODO !!!
add_compile_definitions(QTCOMPOSITION_LIBRARY)