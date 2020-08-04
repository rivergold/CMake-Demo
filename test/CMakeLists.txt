cmake_minimum_required(VERSION 3.1)

# OpenCV
find_package(
  OpenCV REQUIRED PATHS
  /home/rivergold/software/lib/opencv/opencv-3.4.6/build/install
  NO_DEFAULT_PATH)
message("OPENCV_LIBS ${OpenCV_LIBS}")
# Torch
find_package(Torch REQUIRED PATHS ${PROJECT_SOURCE_DIR}}/../thirdparty/libtorch
             NO_DEFAULT_PATH)
# Example
find_package(Example REQUIRED PATHS ${PROJECT_SOURCE_DIR}/../build/install)

add_executable(test test.cc)
target_include_directories(test PUBLIC ${EXAMPLE_INCLUDE_DIRS})
target_link_libraries(test PUBLIC ${EXAMPLE_LIBRARIES} ${OpenCV_LIBS}
                                  ${TORCH_LIBRARIES})
