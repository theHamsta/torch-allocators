#pragma once

#include <driver_types.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif
void *CUDACachingAllocator_raw_alloc(size_t nbytes);
void *CUDACachingAllocator_raw_alloc_with_stream(size_t nbytes, cudaStream_t stream);
void CUDACachingAllocator_raw_delete(void *ptr);
void CUDACachingAllocator_init(int device_count);
void CUDACachingAllocator_setMemoryFraction(double fraction, int device);
void CUDACachingAllocator_emptyCache();
void CUDACachingAllocator_cacheInfo(int dev_id, size_t *cachedAndFree, size_t *largestBlock);
void *CUDACachingAllocator_getBaseAllocation(void *ptr, size_t *size);
void CUDACachingAllocator_resetAccumulatedStats(int device);
void CUDACachingAllocator_resetPeakStats(int device);

// This is mainly calling memalign
void *CPUAllocator_raw_alloc(size_t nbytes);
void CPUAllocator_raw_delete(void *ptr);

void *THCCachingHostAllocator_raw_alloc(size_t nbytes);
void THCCachingHostAllocator_raw_delete(void *ptr);
void THCCachingHostAllocator_emptyCache(void);

#ifdef __cplusplus
}
#endif
