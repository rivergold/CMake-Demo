#include "utils/torch_utils.h"

void create_tensor() {
  torch::Tensor x = torch::zeros({1, 2, 5, 5});
  std::cout << x << std::endl;
}
