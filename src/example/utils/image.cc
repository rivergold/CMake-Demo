#include "example/utils/image.h"

void draw_bboxes_on_mask(cv::Mat mask,
                         const std::vector<std::vector<int>> &bboxes) {
  for (auto bbox : bboxes) {
    mask(cv::Rect(bbox[0], bbox[1], bbox[2] - bbox[0], bbox[3] - bbox[1]))
        .setTo(1);
  }
}
