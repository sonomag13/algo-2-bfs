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
CMAKE_SOURCE_DIR = /home/lu.gao/Desktop/learning-algo-week-2-bfs/clone-graph

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lu.gao/Desktop/learning-algo-week-2-bfs/clone-graph/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/clone_graph.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/clone_graph.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/clone_graph.dir/flags.make

CMakeFiles/clone_graph.dir/main.cpp.o: CMakeFiles/clone_graph.dir/flags.make
CMakeFiles/clone_graph.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lu.gao/Desktop/learning-algo-week-2-bfs/clone-graph/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/clone_graph.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/clone_graph.dir/main.cpp.o -c /home/lu.gao/Desktop/learning-algo-week-2-bfs/clone-graph/main.cpp

CMakeFiles/clone_graph.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/clone_graph.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lu.gao/Desktop/learning-algo-week-2-bfs/clone-graph/main.cpp > CMakeFiles/clone_graph.dir/main.cpp.i

CMakeFiles/clone_graph.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/clone_graph.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lu.gao/Desktop/learning-algo-week-2-bfs/clone-graph/main.cpp -o CMakeFiles/clone_graph.dir/main.cpp.s

CMakeFiles/clone_graph.dir/CloneGraph.cpp.o: CMakeFiles/clone_graph.dir/flags.make
CMakeFiles/clone_graph.dir/CloneGraph.cpp.o: ../CloneGraph.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lu.gao/Desktop/learning-algo-week-2-bfs/clone-graph/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/clone_graph.dir/CloneGraph.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/clone_graph.dir/CloneGraph.cpp.o -c /home/lu.gao/Desktop/learning-algo-week-2-bfs/clone-graph/CloneGraph.cpp

CMakeFiles/clone_graph.dir/CloneGraph.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/clone_graph.dir/CloneGraph.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lu.gao/Desktop/learning-algo-week-2-bfs/clone-graph/CloneGraph.cpp > CMakeFiles/clone_graph.dir/CloneGraph.cpp.i

CMakeFiles/clone_graph.dir/CloneGraph.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/clone_graph.dir/CloneGraph.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lu.gao/Desktop/learning-algo-week-2-bfs/clone-graph/CloneGraph.cpp -o CMakeFiles/clone_graph.dir/CloneGraph.cpp.s

# Object files for target clone_graph
clone_graph_OBJECTS = \
"CMakeFiles/clone_graph.dir/main.cpp.o" \
"CMakeFiles/clone_graph.dir/CloneGraph.cpp.o"

# External object files for target clone_graph
clone_graph_EXTERNAL_OBJECTS =

clone_graph: CMakeFiles/clone_graph.dir/main.cpp.o
clone_graph: CMakeFiles/clone_graph.dir/CloneGraph.cpp.o
clone_graph: CMakeFiles/clone_graph.dir/build.make
clone_graph: CMakeFiles/clone_graph.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lu.gao/Desktop/learning-algo-week-2-bfs/clone-graph/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable clone_graph"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/clone_graph.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/clone_graph.dir/build: clone_graph

.PHONY : CMakeFiles/clone_graph.dir/build

CMakeFiles/clone_graph.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/clone_graph.dir/cmake_clean.cmake
.PHONY : CMakeFiles/clone_graph.dir/clean

CMakeFiles/clone_graph.dir/depend:
	cd /home/lu.gao/Desktop/learning-algo-week-2-bfs/clone-graph/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lu.gao/Desktop/learning-algo-week-2-bfs/clone-graph /home/lu.gao/Desktop/learning-algo-week-2-bfs/clone-graph /home/lu.gao/Desktop/learning-algo-week-2-bfs/clone-graph/cmake-build-debug /home/lu.gao/Desktop/learning-algo-week-2-bfs/clone-graph/cmake-build-debug /home/lu.gao/Desktop/learning-algo-week-2-bfs/clone-graph/cmake-build-debug/CMakeFiles/clone_graph.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/clone_graph.dir/depend

