cmake_minimum_required(VERSION 3.26)
project(trabalho_crip C)

set(CMAKE_C_STANDARD 23)

add_executable(trabalho_crip main.c
        domain/cryp/keyword.c
        domain/cryp/keyword.h
        domain/shared/file.c
        domain/shared/file.h
        domain/shared/path.c
        domain/shared/path.h
)
