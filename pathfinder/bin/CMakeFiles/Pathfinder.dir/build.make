# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.24

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/dicsegabor/dev/own_projects/c++/learning_projects/pathfinder/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dicsegabor/dev/own_projects/c++/learning_projects/pathfinder/bin

# Include any dependencies generated for this target.
include CMakeFiles/Pathfinder.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Pathfinder.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Pathfinder.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Pathfinder.dir/flags.make

CMakeFiles/Pathfinder.dir/main.cpp.o: CMakeFiles/Pathfinder.dir/flags.make
CMakeFiles/Pathfinder.dir/main.cpp.o: /home/dicsegabor/dev/own_projects/c++/learning_projects/pathfinder/src/main.cpp
CMakeFiles/Pathfinder.dir/main.cpp.o: CMakeFiles/Pathfinder.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dicsegabor/dev/own_projects/c++/learning_projects/pathfinder/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Pathfinder.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Pathfinder.dir/main.cpp.o -MF CMakeFiles/Pathfinder.dir/main.cpp.o.d -o CMakeFiles/Pathfinder.dir/main.cpp.o -c /home/dicsegabor/dev/own_projects/c++/learning_projects/pathfinder/src/main.cpp

CMakeFiles/Pathfinder.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Pathfinder.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dicsegabor/dev/own_projects/c++/learning_projects/pathfinder/src/main.cpp > CMakeFiles/Pathfinder.dir/main.cpp.i

CMakeFiles/Pathfinder.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Pathfinder.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dicsegabor/dev/own_projects/c++/learning_projects/pathfinder/src/main.cpp -o CMakeFiles/Pathfinder.dir/main.cpp.s

CMakeFiles/Pathfinder.dir/graph.cpp.o: CMakeFiles/Pathfinder.dir/flags.make
CMakeFiles/Pathfinder.dir/graph.cpp.o: /home/dicsegabor/dev/own_projects/c++/learning_projects/pathfinder/src/graph.cpp
CMakeFiles/Pathfinder.dir/graph.cpp.o: CMakeFiles/Pathfinder.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dicsegabor/dev/own_projects/c++/learning_projects/pathfinder/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Pathfinder.dir/graph.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Pathfinder.dir/graph.cpp.o -MF CMakeFiles/Pathfinder.dir/graph.cpp.o.d -o CMakeFiles/Pathfinder.dir/graph.cpp.o -c /home/dicsegabor/dev/own_projects/c++/learning_projects/pathfinder/src/graph.cpp

CMakeFiles/Pathfinder.dir/graph.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Pathfinder.dir/graph.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dicsegabor/dev/own_projects/c++/learning_projects/pathfinder/src/graph.cpp > CMakeFiles/Pathfinder.dir/graph.cpp.i

CMakeFiles/Pathfinder.dir/graph.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Pathfinder.dir/graph.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dicsegabor/dev/own_projects/c++/learning_projects/pathfinder/src/graph.cpp -o CMakeFiles/Pathfinder.dir/graph.cpp.s

CMakeFiles/Pathfinder.dir/bfs.cpp.o: CMakeFiles/Pathfinder.dir/flags.make
CMakeFiles/Pathfinder.dir/bfs.cpp.o: /home/dicsegabor/dev/own_projects/c++/learning_projects/pathfinder/src/bfs.cpp
CMakeFiles/Pathfinder.dir/bfs.cpp.o: CMakeFiles/Pathfinder.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dicsegabor/dev/own_projects/c++/learning_projects/pathfinder/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Pathfinder.dir/bfs.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Pathfinder.dir/bfs.cpp.o -MF CMakeFiles/Pathfinder.dir/bfs.cpp.o.d -o CMakeFiles/Pathfinder.dir/bfs.cpp.o -c /home/dicsegabor/dev/own_projects/c++/learning_projects/pathfinder/src/bfs.cpp

CMakeFiles/Pathfinder.dir/bfs.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Pathfinder.dir/bfs.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dicsegabor/dev/own_projects/c++/learning_projects/pathfinder/src/bfs.cpp > CMakeFiles/Pathfinder.dir/bfs.cpp.i

CMakeFiles/Pathfinder.dir/bfs.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Pathfinder.dir/bfs.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dicsegabor/dev/own_projects/c++/learning_projects/pathfinder/src/bfs.cpp -o CMakeFiles/Pathfinder.dir/bfs.cpp.s

# Object files for target Pathfinder
Pathfinder_OBJECTS = \
"CMakeFiles/Pathfinder.dir/main.cpp.o" \
"CMakeFiles/Pathfinder.dir/graph.cpp.o" \
"CMakeFiles/Pathfinder.dir/bfs.cpp.o"

# External object files for target Pathfinder
Pathfinder_EXTERNAL_OBJECTS =

Pathfinder: CMakeFiles/Pathfinder.dir/main.cpp.o
Pathfinder: CMakeFiles/Pathfinder.dir/graph.cpp.o
Pathfinder: CMakeFiles/Pathfinder.dir/bfs.cpp.o
Pathfinder: CMakeFiles/Pathfinder.dir/build.make
Pathfinder: CMakeFiles/Pathfinder.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/dicsegabor/dev/own_projects/c++/learning_projects/pathfinder/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable Pathfinder"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Pathfinder.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Pathfinder.dir/build: Pathfinder
.PHONY : CMakeFiles/Pathfinder.dir/build

CMakeFiles/Pathfinder.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Pathfinder.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Pathfinder.dir/clean

CMakeFiles/Pathfinder.dir/depend:
	cd /home/dicsegabor/dev/own_projects/c++/learning_projects/pathfinder/bin && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dicsegabor/dev/own_projects/c++/learning_projects/pathfinder/src /home/dicsegabor/dev/own_projects/c++/learning_projects/pathfinder/src /home/dicsegabor/dev/own_projects/c++/learning_projects/pathfinder/bin /home/dicsegabor/dev/own_projects/c++/learning_projects/pathfinder/bin /home/dicsegabor/dev/own_projects/c++/learning_projects/pathfinder/bin/CMakeFiles/Pathfinder.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Pathfinder.dir/depend

