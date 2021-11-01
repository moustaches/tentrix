
set( HEADERS
    include/tentrix/structure.h
    include/tentrix/print.h
    include/tentrix/move.h
)

set( SOURCES
    src/structure.cpp
    src/print.cpp
    src/move.cpp
)

add_library( tentrix
   SHARED
        ${HEADERS}
        ${SOURCES}
)

set_target_properties( tentrix
    PROPERTIES
        CXX_STANDARD 20
        CXX_STANDARD_REQUIRED ON
)

target_include_directories( tentrix
    PUBLIC
        include
)
