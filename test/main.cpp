/*
 * main.cpp
 * Copyright (C) 2021 Stephan Seitz <stephan.seitz@fau.de>
 *
 * Distributed under terms of the GPLv3 license.
 */

#include "c10_c_api.h"
#include <cstdlib>
#include <iostream>

auto main() -> int {
  const int ONE_GPU = 1;
  CUDACachingAllocator_init(ONE_GPU);
  void *allocation = CUDACachingAllocator_raw_alloc(10);
  CUDACachingAllocator_raw_delete(allocation);
  std::cout << "Yeah! It worked on GPU." << std::endl;

  void *cpuAllocation = CPUAllocator_raw_alloc(10);
  ((int *)cpuAllocation)[0] = 3;
  CPUAllocator_raw_delete(cpuAllocation);
  std::cout << "Yeah! It worked on CPU." << std::endl;

  void *hostAllocation = THCCachingHostAllocator_raw_alloc(10);
  ((int *)hostAllocation)[0] = 3;
  THCCachingHostAllocator_raw_delete(hostAllocation);
  std::cout << "Yeah! It worked with CUDA host allocation." << std::endl;

  return EXIT_SUCCESS;
}
