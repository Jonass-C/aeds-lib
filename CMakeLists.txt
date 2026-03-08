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

add_executable(casamento_padroes
        "src/casamento_padroes/forca_bruta.c"
        "src/casamento_padroes/rabin_karp.c"
        "src/casamento_padroes/kmp.c"
        "src/casamento_padroes/boyer_moore.c"
        "src/casamento_padroes/boyer_moore_horspool.c"
        "src/casamento_padroes/boyer_moore_horspool_sunday.c"
        "src/casamento_padroes/casamento_padroes.h"
        "src/casamento_padroes/main.c"
)

add_executable(ordenacao
        "src/ordenacao/sort.h"
        "src/ordenacao/bubble_sort.c"
        "src/ordenacao/bucket_sort.c"
        "src/ordenacao/comb_sort.c"
        "src/ordenacao/counting_sort.c"
        "src/ordenacao/gnome_sort.c"
        "src/ordenacao/heap_sort.c"
        "src/ordenacao/insertion_sort.c"
        "src/ordenacao/merge_sort.c"
        "src/ordenacao/quick_sort.c"
        "src/ordenacao/select_sort.c"
        "src/ordenacao/shell_sort.c"
        "src/ordenacao/main.c"
)