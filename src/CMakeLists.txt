add_definitions(-DDIMENSION=16000)

macro(add_exec EXEC_NAME)
	add_executable(${EXEC_NAME} ${EXEC_NAME})
	target_link_libraries(${EXEC_NAME} ${RT_LIBRARY})
endmacro()

add_exec(zeros-calloc)
add_exec(zeros-malloc-memset)
add_exec(zeros-arma-zeros)
add_exec(zeros-mat-zeros)
add_exec(zeros-mat-loop)

if (OPENMP_FOUND)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
	add_exec(zeros-mat-loop-omp)
endif ()
