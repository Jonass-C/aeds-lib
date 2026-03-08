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
        "src/listas/duplamente_encadeada/main.c"
        "src/listas/duplamente_encadeada/listas_duplas.h"
        "src/listas/duplamente_encadeada/listas_duplas.c"
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

add_executable(arvores_percursos
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

add_executable(tabela_hash
        "src/tabela_hash/tabela_hash.c"
        "src/tabela_hash/tabela_hash.h"
        "src/tabela_hash/main.c"
)

#add_executable(forca_bruta "forçaBruta.c" "benchmark/benchmark.c")
#add_executable(rabin_karp "rabinKarp.c" "benchmark/benchmark.c")
#add_executable(kmp "kmp.c" "benchmark/benchmark.c")
#add_executable(boyer_moore "boyer-moore/bm.c" "benchmark/benchmark.c")
#add_executable(boyer_moore_horspool "boyer-moore/bmh.c" "benchmark/benchmark.c")
#add_executable(boyer_moore_horspool_sunday "boyer-moore/bmhs.c" "benchmark/benchmark.c")



