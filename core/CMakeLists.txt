set(LIB_NAME camerus_core)

find_package(OpenCV REQUIRED)

#file(GLOB LIB_SOURCES "src/*.cpp")

add_library(${LIB_NAME}
    src/concatenation.cpp
    src/video_creator.cpp
    src/filters.cpp
    src/contours.cpp
    src/video_reader.cpp
)

target_include_directories(${LIB_NAME} PUBLIC include)

target_link_libraries(${LIB_NAME} ${OpenCV_LIBS})