cmake_minimum_required(VERSION 3.22.1) # current version when making this project
project(passwordManager) # naming project

enable_language(ASM_NASM) # enabling asm for the use of ror and rol

add_library(
    passwordHeadersAndImps
    passwordManager.h
    passwordManagerImp.cpp
)
# this library is for the password header and implication

add_library(
    linkedListsHeadersAndImps
    linkedListsImp.cpp 
    linkedLists.h
)
# this library is for the linked lists header and implication

add_executable(passwordManager main.cpp encrypt.asm)
#adding it on

target_link_libraries(passwordManager PRIVATE passwordHeadersAndImps)
target_link_libraries(passwordManager PRIVATE linkedListsHeadersAndImps)
#adding libraries
