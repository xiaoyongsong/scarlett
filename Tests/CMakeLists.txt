IF(${WIN32})
add_subdirectory(Windows)
ENDIF(${WIN32})


add_executable(Test_Math Test_Math.cpp)
add_test(NAME Test_Math COMMAND Test_Math)

add_executable(Test_GMemoryMananger Test_GMemoryMananger.cpp)
target_link_libraries(Test_GMemoryMananger Scarlett)
add_test(NAME Test_GMemoryMananger COMMAND Test_GMemoryMananger)

