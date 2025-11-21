# Makefile pour CMake et OpenMP

BUILD_DIR = out
TARGET = ProjetCryptoAvancee

# Options CMake par défaut
CMAKE_OPTS = -DCMAKE_BUILD_TYPE=Release

.PHONY: all openmp no-openmp build clean rebuild

all: build

openmp:
	cmake -S . -B $(BUILD_DIR) $(CMAKE_OPTS) -DUSE_OPENMP=ON

no-openmp:
	cmake -S . -B $(BUILD_DIR) $(CMAKE_OPTS) -DUSE_OPENMP=OFF

build:
	cmake --build $(BUILD_DIR) --target $(TARGET)

clean:
	rm -rf $(BUILD_DIR)

rebuild: clean openmp build

