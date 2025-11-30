cmake_minimum_required(VERSION 3.31)
project(untitled6 C)

set(CMAKE_C_STANDARD 11)

# Create separate executables
add_executable(fork_program "Fork(asc-desc).c")
add_executable(orphan_program "OrphanProcess.c")
add_executable(zombie_program "ZombieProcess.c")
add_executable(fcfs_program "FCFS.c")
add_executable(srtf_program "SRTF.c")
add_executable(IPC_program "IPC_2Pipes.c")
add_executable(Banker_program "Bankers_Algo.c")
add_executable(fifo_program "FIFO_Page_Replacement.c")
add_executable(lru_program "LRU_Page_Replacement.c")
add_executable(semaphore_program "Semaphore.c")