cmake_minimum_required(VERSION 3.5)
project(ProjetCryptoAvancee)

set(CMAKE_C_STANDARD 11)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

# === Trouver CUnit ===
find_path(CUNIT_INCLUDE_DIR CUnit/Basic.h
        PATHS /usr/local/include /opt/homebrew/include
)
find_library(CUNIT_LIBRARY cunit
        PATHS /usr/local/lib /opt/homebrew/lib
)
if(NOT CUNIT_INCLUDE_DIR OR NOT CUNIT_LIBRARY)
    message(FATAL_ERROR "CUnit not found. Please install it with Homebrew.")
endif()
message(STATUS "Found CUnit: ${CUNIT_INCLUDE_DIR}, ${CUNIT_LIBRARY}")

# === Fichiers ===
set(MDBR_COMPILATION_FLAGS -Wall -Wextra)
set(MDBR_COMPILATION_DEFINITION -D_CRT_SECURE_NO_WARNINGS -DNOMINMAX)

set(MDBR_HEADERS
        "./src/ISD.h"
        "./src/MDPC.h"
        "./src/Matrice.h"
        "./src/Polynome.h"
        "./src/AES_GCM.h"
        "./src/utils/Logger.h"
        "./src/VectorTuple.h"
        "./src/utils/utils.h"
        "src/UnitTests/MatriceTest.h"
        "src/UnitTests/PolynomeTest.h"
        "src/UnitTests/VectorTupleTest.h"
        "./src/UnitTests/IsdTest.h"


)
set(MDBR_SOURCES
        "./src/ISD.c"
        "./src/MDPC.c"
        "./src/main.c"
        "./src/Matrice.c"
        "./src/Polynome.c"
        "./src/AES_GCM.c"
        "./src/VectorTuple.c"
        "./src/utils/utils.c"
        "src/UnitTests/MatriceTest.c"
        "src/UnitTests/PolynomeTest.c"
        "src/UnitTests/VectorTupleTest.c"
        "./src/UnitTests/IsdTest.c"

)

# === D'abord définir la cible ===
add_executable(${PROJECT_NAME} ${MDBR_SOURCES} ${MDBR_HEADERS})

target_include_directories(${PROJECT_NAME} PRIVATE
        SYSTEM
        ${CUNIT_INCLUDE_DIR}
        include/
)

# === Ensuite configurer la cible ===
target_compile_features(${PROJECT_NAME} PRIVATE c_std_11)
target_compile_options(${PROJECT_NAME} PRIVATE ${MDBR_COMPILATION_FLAGS})
target_compile_definitions(${PROJECT_NAME} PRIVATE ${MDBR_COMPILATION_DEFINITION})

find_package(OpenSSL REQUIRED)

target_include_directories(${PROJECT_NAME} PRIVATE SYSTEM "include/" ${MDBR_EXTERN_INCLUDES} ${CUNIT_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} PRIVATE ${MDBR_EXTERN_LIBRARIES} ${CUNIT_LIBRARY} OpenSSL::Crypto)
