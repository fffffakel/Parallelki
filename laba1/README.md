#Makefile:
По умолчанию выбран **float**:
```make```
```./sum```
Result --> Sum:4.89582e-11

Чтобы выбрать **double**:
```make TYPE=double```
```./sum```
Result --> Sum:-0.0277862

#CMakeLists:
Для **float**:
```mkdir build```
```cd build```
```cmake .. -DUSE_DOUBLE=OFF```
```make```
```./sum```
Result --> Sum:6.27585e-10

Для **double**:
 ```mkdir build```
```cd build```
```cmake .. -DUSE_DOUBLE=ON```
```make```
```./sum```
Result --> Sum:-0.0277862
