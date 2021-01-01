/*
 * main.cpp
 * Copyright (C) 2021 Stephan Seitz <stephan.seitz@fau.de>
 *
 * Distributed under terms of the GPLv3 license.
 */

#include "c10_c_api.h"
#include <cstdlib>
#include <iostream>

auto main(int argc, char **argv) -> int {
  const int ONE_GPU = 1;
  CUDACachingAllocator_init(ONE_GPU);
  void *allocation = CUDACachingAllocator_raw_alloc(10);
  CUDACachingAllocator_raw_delete(allocation);
  std::cout << "Yeah! It worked on GPU." << std::endl;

  void *cpuAllocation = CPUCachingAllocator_raw_alloc(10);
  ((int *)cpuAllocation)[0] = 3;
  CPUCachingAllocator_raw_delete(cpuAllocation);
  std::cout << "Yeah! It worked on CPU." << std::endl;

  return EXIT_SUCCESS;
}
