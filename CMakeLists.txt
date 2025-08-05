cmake_minimum_required(VERSION 3.31)
project(aeds_lib C)

set(CMAKE_C_STANDARD 11)

add_compile_options(-finput-charset=UTF-8 -fexec-charset=UTF-8)

add_executable(aeds_lib_simples
        "src/listas/simples/main.c"
        "src/listas/simples/listas.h"
        "src/listas/simples/listas.c"
)

add_executable(aeds_lib_duplamente
        "src/listas/duplamenteEncadeada/main.c"
        "src/listas/duplamenteEncadeada/listasduplas.h"
        "src/listas/duplamenteEncadeada/listasduplas.c"
)

add_executable(aeds_lib_pilhas
    "src/pilhas/main.c"
    "src/pilhas/pilhas.h"
    "src/pilhas/pilhas.c"
)

add_executable(aeds_lib_filas
    "src/filas/main.c"
    "src/filas/filas.h"
    "src/filas/filas.c"
)

add_executable(aeds_lib_arvores
    "src/arvores/main.c"
    "src/arvores/arvore.h"
    "src/arvores/arvore.c"
)