# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/lu.gao/clion-2019.2.1/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/lu.gao/clion-2019.2.1/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/lu.gao/Desktop/learning-algo-week-2-bfs/range-based-for-loop

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lu.gao/Desktop/learning-algo-week-2-bfs/range-based-for-loop/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/range_based_for_loop.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/range_based_for_loop.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/range_based_for_loop.dir/flags.make

CMakeFiles/range_based_for_loop.dir/main.cpp.o: CMakeFiles/range_based_for_loop.dir/flags.make
CMakeFiles/range_based_for_loop.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lu.gao/Desktop/learning-algo-week-2-bfs/range-based-for-loop/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/range_based_for_loop.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/range_based_for_loop.dir/main.cpp.o -c /home/lu.gao/Desktop/learning-algo-week-2-bfs/range-based-for-loop/main.cpp

CMakeFiles/range_based_for_loop.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/range_based_for_loop.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lu.gao/Desktop/learning-algo-week-2-bfs/range-based-for-loop/main.cpp > CMakeFiles/range_based_for_loop.dir/main.cpp.i

CMakeFiles/range_based_for_loop.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/range_based_for_loop.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lu.gao/Desktop/learning-algo-week-2-bfs/range-based-for-loop/main.cpp -o CMakeFiles/range_based_for_loop.dir/main.cpp.s

# Object files for target range_based_for_loop
range_based_for_loop_OBJECTS = \
"CMakeFiles/range_based_for_loop.dir/main.cpp.o"

# External object files for target range_based_for_loop
range_based_for_loop_EXTERNAL_OBJECTS =

range_based_for_loop: CMakeFiles/range_based_for_loop.dir/main.cpp.o
range_based_for_loop: CMakeFiles/range_based_for_loop.dir/build.make
range_based_for_loop: CMakeFiles/range_based_for_loop.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lu.gao/Desktop/learning-algo-week-2-bfs/range-based-for-loop/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable range_based_for_loop"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/range_based_for_loop.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/range_based_for_loop.dir/build: range_based_for_loop

.PHONY : CMakeFiles/range_based_for_loop.dir/build

CMakeFiles/range_based_for_loop.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/range_based_for_loop.dir/cmake_clean.cmake
.PHONY : CMakeFiles/range_based_for_loop.dir/clean

CMakeFiles/range_based_for_loop.dir/depend:
	cd /home/lu.gao/Desktop/learning-algo-week-2-bfs/range-based-for-loop/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lu.gao/Desktop/learning-algo-week-2-bfs/range-based-for-loop /home/lu.gao/Desktop/learning-algo-week-2-bfs/range-based-for-loop /home/lu.gao/Desktop/learning-algo-week-2-bfs/range-based-for-loop/cmake-build-debug /home/lu.gao/Desktop/learning-algo-week-2-bfs/range-based-for-loop/cmake-build-debug /home/lu.gao/Desktop/learning-algo-week-2-bfs/range-based-for-loop/cmake-build-debug/CMakeFiles/range_based_for_loop.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/range_based_for_loop.dir/depend

