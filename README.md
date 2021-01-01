# c10_c_api

A C-api wrapper around pytorch's c10 library. Currently only wraps `CUDACachingAllocator`.


```
mkdir -p release
cd release && cmake -DCMAKE_BUILD_TYPE=Release -G Ninja -DCMAKE_CXX_FLAGS=-fcolor-diagnostics -DCMAKE_C_FLAGS=-fcolor-diagnostics ..
cmake --build . -- -j8
sudo ninja install
```

Replace ninja by make if you don't use ninja (also remove `-G Ninja`).

## License

Since this is only a build wrapper around c10, it has the same license terms as pytorch/c10
