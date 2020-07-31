include(${CMAKE_CURRENT_SOURCE_DIR}/../cmake/Dependencies.cmake)
message("OpenCV_INCLUDE_DIRS: ${OpenCV_INCLUDE_DIRS}")
message("TORCH_INCLUDE_DIRS: ${TORCH_INCLUDE_DIRS}")

add_subdirectory(utils)

file(GLOB EXAMPLE_SRCS *.cc)
add_library(example SHARED ${EXAMPLE_SRCS})
target_include_directories(
  example
  PUBLIC "$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>"
  PUBLIC "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR};${OpenCV_INCLUDE_DIRS}>"
)
target_link_libraries(example PRIVATE ${utils})

install(
  TARGETS example
  EXPORT Example
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib)

install(
  DIRECTORY ${PROJECT_SOURCE_DIR}/include/
  DESTINATION include
  FILES_MATCHING
  PATTERN "*.h")
