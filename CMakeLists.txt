cmake_minimum_required(VERSION 3.31)
project(aeds_lib C)

set(CMAKE_C_STANDARD 11)

add_compile_options(-finput-charset=UTF-8 -fexec-charset=UTF-8)

add_executable(listas_simples
        "src/listas/simples/main.c"
        "src/listas/simples/listas.h"
        "src/listas/simples/listas.c"
)

add_executable(listas_duplas
        "src/listas/duplamenteEncadeada/main.c"
        "src/listas/duplamenteEncadeada/listasduplas.h"
        "src/listas/duplamenteEncadeada/listasduplas.c"
)

add_executable(pilhas
    "src/pilhas/main.c"
    "src/pilhas/pilhas.h"
    "src/pilhas/pilhas.c"
)

add_executable(filas
    "src/filas/main.c"
    "src/filas/filas.h"
    "src/filas/filas.c"
)

add_executable(pesquisa_sequencial
        "src/pesquisa/sequencial/main.c"
        "src/pesquisa/pesquisa.h"
        "src/pesquisa/sequencial/sequencial.c"
)

add_executable(pesquisa_binaria
        "src/pesquisa/binaria/main.c"
        "src/pesquisa/pesquisa.h"
        "src/pesquisa/binaria/binaria.c"
)

add_executable(arvores
    "src/arvores/percursos/main.c"
    "src/arvores/percursos/arvore.h"
    "src/arvores/percursos/arvore.c"
)

add_executable(arvores_abb
        "src/arvores/abb/main.c"
        "src/arvores/abb/abb.h"
        "src/arvores/abb/abb.c"
)

add_executable(arvores_avl
        "src/arvores/avl/main.c"
        "src/arvores/avl/avl.h"
        "src/arvores/avl/avl.c"
)





