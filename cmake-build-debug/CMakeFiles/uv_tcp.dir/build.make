# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/txy/Desktop/C/uv_tcp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/txy/Desktop/C/uv_tcp/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/uv_tcp.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/uv_tcp.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/uv_tcp.dir/flags.make

CMakeFiles/uv_tcp.dir/main.cpp.o: CMakeFiles/uv_tcp.dir/flags.make
CMakeFiles/uv_tcp.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/txy/Desktop/C/uv_tcp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/uv_tcp.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/uv_tcp.dir/main.cpp.o -c /Users/txy/Desktop/C/uv_tcp/main.cpp

CMakeFiles/uv_tcp.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/uv_tcp.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/txy/Desktop/C/uv_tcp/main.cpp > CMakeFiles/uv_tcp.dir/main.cpp.i

CMakeFiles/uv_tcp.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/uv_tcp.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/txy/Desktop/C/uv_tcp/main.cpp -o CMakeFiles/uv_tcp.dir/main.cpp.s

# Object files for target uv_tcp
uv_tcp_OBJECTS = \
"CMakeFiles/uv_tcp.dir/main.cpp.o"

# External object files for target uv_tcp
uv_tcp_EXTERNAL_OBJECTS =

uv_tcp: CMakeFiles/uv_tcp.dir/main.cpp.o
uv_tcp: CMakeFiles/uv_tcp.dir/build.make
uv_tcp: CMakeFiles/uv_tcp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/txy/Desktop/C/uv_tcp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable uv_tcp"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/uv_tcp.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/uv_tcp.dir/build: uv_tcp

.PHONY : CMakeFiles/uv_tcp.dir/build

CMakeFiles/uv_tcp.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/uv_tcp.dir/cmake_clean.cmake
.PHONY : CMakeFiles/uv_tcp.dir/clean

CMakeFiles/uv_tcp.dir/depend:
	cd /Users/txy/Desktop/C/uv_tcp/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/txy/Desktop/C/uv_tcp /Users/txy/Desktop/C/uv_tcp /Users/txy/Desktop/C/uv_tcp/cmake-build-debug /Users/txy/Desktop/C/uv_tcp/cmake-build-debug /Users/txy/Desktop/C/uv_tcp/cmake-build-debug/CMakeFiles/uv_tcp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/uv_tcp.dir/depend
