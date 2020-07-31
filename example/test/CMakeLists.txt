set(EXAMPLE_DIR
    /home/rivergold/Documents/RiverGold/rivergold-project/CMake-Demo/example/build/install
)
find_package(OpenCV REQUIRED PATHS
             /home/rivergold/software/lib/opencv/opencv-3.4.6/build/install)
message("OPENCV_LIBS ${OpenCV_LIBS}")
find_package(
  Torch
  REQUIRED
  PATHS
  /home/rivergold/Documents/RiverGold/rivergold-project/CMake-Demo/example/thirdparty/libtorch
)

add_executable(test test.cc)
target_include_directories(test PUBLIC ${EXAMPLE_DIR}/include)
target_link_libraries(
  test PUBLIC ${EXAMPLE_DIR}/lib/libexample.so ${EXAMPLE_DIR}/lib/libutils.so
              ${OpenCV_LIBS} ${TORCH_LIBRARIES})
