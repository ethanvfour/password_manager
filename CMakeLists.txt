cmake_minimum_required(VERSION 3.22.1) # current version when making this project
project(passwordManager) # naming project

enable_language(ASM_NASM) # enabling asm for the use of ror and rol

# adding directories for the include files
include_directories(${CMAKE_SOURCE_DIR})


add_library(
    passwordHeadersAndImps
    passwordManager.h
    passwordManagerImp.cpp
)
# this library is for the password header and implication

add_library(
    linkedListsHeadersAndImps
    linkedLists.h
    linkedListsImp.cpp
)
# this library is for the linked lists header and implication

add_library(
    coolFunctionsWhoa
    coolFunctions.h 
    coolFunctionsImp.cpp 
)
# just some cool functions

add_executable(passwordManager main.cpp encrypt.asm)
#adding it on

target_link_libraries(passwordManager PRIVATE passwordHeadersAndImps)
target_link_libraries(passwordManager PRIVATE linkedListsHeadersAndImps)
target_link_libraries(passwordManager PRIVATE coolFunctionsWhoa)

#adding libraries
