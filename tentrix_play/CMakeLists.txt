
add_executable(tentrix_play
    main.cpp
)

set_target_properties(tentrix_play
    PROPERTIES
        CXX_STANDARD 20
        CXX_STANDARD_REQUIRED ON
)
target_link_libraries(tentrix_play
    tentrix
)
