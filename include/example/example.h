#include <torch/script.h>

class Example {
 public:
  void run();

 private:
  torch::jit::Module model_;
};
