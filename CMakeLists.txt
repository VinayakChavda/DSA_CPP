cmake_minimum_required(VERSION 3.28)
project(CPP_Codes)

set(CMAKE_CXX_STANDARD 17)

add_executable(CPP_Codes main.cpp
        selection_sort.cpp
        check_sorted_rotated.cpp
        remove_duplicate.cpp
        rotate_left_by_k.cpp
        move_zeros.cpp
        union_two_sorted_array.cpp
        missing_number.cpp
        max_consecutive_ones.cpp
        max_subarray_with_sum_k.cpp
        two_sum.cpp
        sort_colors.cpp
        majority_element.cpp
)
