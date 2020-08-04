#pragma once

#include <opencv2/opencv.hpp>

void draw_bboxes_on_mask(cv::Mat mask,
                         const std::vector<std::vector<int>> &bboxes);
