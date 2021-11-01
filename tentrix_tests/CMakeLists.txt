
enable_testing()

include(GoogleTest)

find_package(GTest CONFIG REQUIRED)

add_executable( tentrix_tests
    main.cpp
)

set_target_properties(tentrix_tests
    PROPERTIES
        CXX_STANDARD 20
        CXX_STANDARD_REQUIRED ON
)

target_link_libraries(tentrix_tests
    tentrix
    GTest::gmock
    GTest::gtest
    GTest::gmock_main
    GTest::gtest_main
)

gtest_discover_tests(tentrix_tests)

