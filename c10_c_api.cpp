#include "c10/cuda/CUDACachingAllocator.h"
#include "c10_c_api.h"

using namespace c10::cuda;

extern "C" {
C10_CUDA_API void *CUDACachingAllocator_raw_alloc(size_t nbytes) {
  return CUDACachingAllocator::raw_alloc(nbytes);
}
C10_CUDA_API void *
CUDACachingAllocator_raw_alloc_with_stream(size_t nbytes, cudaStream_t stream) {
  return CUDACachingAllocator::raw_alloc_with_stream(nbytes, stream);
}
C10_CUDA_API void CUDACachingAllocator_raw_delete(void *ptr) {
  CUDACachingAllocator::raw_delete(ptr);
};

// typedef void Allocator;
// C10_CUDA_API Allocator *CUDACachingAllocator_get() {
// return (void *)CUDACachingAllocator::get();
//};
//C10_CUDA_API void CUDACachingAllocator_allocate(size_t n) {
  //CUDACachingAllocator::get()->allocate(n).get();
//};
C10_CUDA_API void CUDACachingAllocator_init(int device_count) {
  CUDACachingAllocator::init(device_count);
};
C10_CUDA_API void CUDACachingAllocator_setMemoryFraction(double fraction,
                                                         int device) {
  CUDACachingAllocator::setMemoryFraction(fraction, device);
};
C10_CUDA_API void CUDACachingAllocator_emptyCache() {
  CUDACachingAllocator::emptyCache();
};
C10_CUDA_API void CUDACachingAllocator_cacheInfo(int dev_id,
                                                 size_t *cachedAndFree,
                                                 size_t *largestBlock) {
  CUDACachingAllocator::cacheInfo(dev_id, cachedAndFree, largestBlock);
};
C10_CUDA_API void *CUDACachingAllocator_getBaseAllocation(void *ptr,
                                                          size_t *size) {
  return CUDACachingAllocator::getBaseAllocation(ptr, size);
};
// C10_CUDA_API void CUDACachingAllocator_recordStream(const DataPtr *dataPtr,
// CUDAStream stream) {
// CUDACachingAllocator::recordStream(*dataPtr, stream);
//};
// C10_CUDA_API DeviceStats CUDACachingAllocator_getDeviceStats(int device) {};
C10_CUDA_API void CUDACachingAllocator_resetAccumulatedStats(int device) {
  CUDACachingAllocator::resetAccumulatedStats(device);
};
C10_CUDA_API void CUDACachingAllocator_resetPeakStats(int device) {
  CUDACachingAllocator::resetPeakStats(device);
}
}
