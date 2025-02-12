#Makefile:

По умолчанию выбран **float**:

```make\n./sum```

Result --> Sum:4.89582e-11

Чтобы выбрать **double**:

```make TYPE=double\n./sum```

Result --> Sum:-0.0277862

#CMakeLists:

Для **float**:

```mkdir build\ncd build\ncmake .. -DUSE_DOUBLE=OFFmake\n./sum```

Result --> Sum:6.27585e-10

Для **double**:

```mkdir build\ncd build\ncmake .. -DUSE_DOUBLE=ONmake\n./sum```

Result --> Sum:-0.0277862
