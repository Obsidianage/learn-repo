import torch

if torch.cuda.get_device_capability(0)[0] >= 7:
    print("This GPU has Tensor Cores.")
else:
    print("This GPU does not have Tensor Cores.")
print("Number of CUDA devices:", torch.cuda.device_count())
print("Device name:", torch.cuda.get_device_name(0))