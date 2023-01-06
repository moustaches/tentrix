

include(GoogleTest)
find_package(GTest CONFIG REQUIRED)


add_executable( tentrix_tests
    move_tools.cpp
    move_queen.cpp
    move_knight.cpp
)

set_target_properties(tentrix_tests
    PROPERTIES
        CXX_STANDARD 20
        CXX_STANDARD_REQUIRED ON
)

target_link_libraries(tentrix_tests
	PRIVATE
		tentrix
		GTest::gtest_main
)

gtest_discover_tests(tentrix_tests)

