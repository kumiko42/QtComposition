include_directories(.)

add_executable(qt_composition_test
        main.cpp
)

add_dependencies(qt_composition_test qt_composition)

target_link_libraries(qt_composition_test qt_composition)