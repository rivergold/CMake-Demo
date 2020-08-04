file(GLOB EXAMPLE_SRCS *.cc utils/*.cc)

add_library(example SHARED ${EXAMPLE_SRCS})
target_include_directories(
  example
  PUBLIC
    "$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include;${CMAKE_CURRENT_SOURCE_DIR}/../;${OpenCV_INCLUDE_DIRS};${TORCH_INCLUDE_DIRS}>"
)
target_link_libraries(example PUBLIC ${OpenCV_LIBS} ${TORCH_LIBRARIES})

# @rivergold: Install and export target
install(
  TARGETS example
  EXPORT Example # EXPORT is used in generating ExampleConfig.cmake
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib)

# @rivergold: Install header into include
install(
  DIRECTORY ${CMAKE_CURRENT_LIST_DIR}
  DESTINATION include
  FILES_MATCHING
  PATTERN "*.h")

set(EXAMPLE_INCLUDE_DIRS ${CMAKE_INSTALL_PREFIX}/include)
set(EXAMPLE_LIB_DIRS ${CMAKE_INSTALL_PREFIX}/lib)

include(CMakePackageConfigHelpers)
configure_package_config_file(
  ${PROJECT_SOURCE_DIR}/cmake/ExampleConfig.cmake.in
  "${CMAKE_CURRENT_BINARY_DIR}/ExampleConfig.cmake"
  INSTALL_DESTINATION share/Example
  PATH_VARS EXAMPLE_INCLUDE_DIRS EXAMPLE_LIB_DIRS)

write_basic_package_version_file(
  "${CMAKE_CURRENT_BINARY_DIR}/ExampleConfigVersion.cmake"
  VERSION "1.0"
  COMPATIBILITY AnyNewerVersion)

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/ExampleConfig.cmake
        DESTINATION share/Example)
