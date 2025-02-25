# Makefile:

Сборщик Makefile находится в папке makefile

Чтобы выбрать **float**:

```
make
./sum
```

Чтобы выбрать **double**:

```
make TYPE=double
./sum
```

# CMakeLists:

Сборщик сmake находится в папке cmake

Для **float**:

```
mkdir build
cd build
cmake .. -DUSE_DOUBLE=OFF
make
./sum
```

Для **double**:

```
mkdir build
cd build
cmake .. -DUSE_DOUBLE=ON
make
./sum
```

