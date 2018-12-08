#include <torch/torch.h>

// Define a new Module.
struct Net : torch::nn::Module {
  Net() {
    // Construct and register two Linear submodules.
    fc1 = register_module("fc1", torch::nn::Linear(8, 64));
    fc2 = register_module("fc2", torch::nn::Linear(64, 1));
  }

  // Implement the Net's algorithm.
  torch::Tensor forward(torch::Tensor x) {
    // Use one of many tensor manipulation functions.
    x = torch::relu(fc1->forward(x));
    x = torch::dropout(x, /*p=*/0.5);
    x = torch::sigmoid(fc2->forward(x));
    return x;
  }

  // Use one of many "standard library" modules.
  torch::nn::Linear fc1{nullptr}, fc2{nullptr};
};

// Create a new Net.
Net net;

// Create a multi-threaded data loader for the MNIST dataset.
auto data_loader =
  torch::data::data_loader(torch::data::datasets::MNIST("./data"));

// Instantiate an SGD optimization algorithm to update our Net's parameters.
torch::optim::SGD optimizer(net.parameters(), /*lr=*/0.1);

for (size_t epoch = 1; epoch <= 10; ++epoch) {
  size_t batch_index = 0;
  // Iterate the data loader to yield batches from the dataset.
  for (auto batch : data_loader) {
    // Reset gradients.
    optimizer.zero_grad();
    // Execute the model on the input data.
    auto prediction = model.forward(batch.data);
    // Compute a loss value to judge the prediction of our model.
    auto loss = torch::binary_cross_entropy(prediction, batch.label);
    // Compute gradients of the loss w.r.t. the parameters of our model.
    loss.backward();
    // Update the parameters based on the calculated gradients.
    optimizer.step();

    if (batch_index++ % 10 == 0) {
      std::cout << "Epoch: " << epoch << " | Batch: " << batch_index
                << " | Loss: " << loss << std::endl;
      // Serialize your model periodically as a checkpoint.
      torch::save(net, "net.pt");
    }
  }
