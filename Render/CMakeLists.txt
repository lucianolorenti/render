file(GLOB SOURCES "*.cpp")
 
add_executable(Render ${SOURCES})
find_package(SFML 2.5.1 COMPONENTS audio graphics window system REQUIRED)

target_link_libraries(Render
        PUBLIC
        sfml-graphics sfml-audio sfml-window sfml-system )