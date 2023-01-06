
add_executable(tentrix_sandbox
    main.cpp
    header.h
)

set_target_properties(tentrix_sandbox
    PROPERTIES
        CXX_STANDARD 20
        CXX_STANDARD_REQUIRED ON
)
target_link_libraries(tentrix_sandbox
    tentrix
)
