#include "example/example.h"

#include "utils/image.h"

void Example::run() {
  cv::Mat image = cv::Mat::zeros(100, 100, CV_8UC1);
  std::vector<std::vector<int>> bboxes{{1, 2, 3, 4}};
  draw_bboxes_on_mask(image, bboxes);
}
