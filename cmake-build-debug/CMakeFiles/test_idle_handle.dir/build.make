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
include CMakeFiles/test_idle_handle.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/test_idle_handle.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test_idle_handle.dir/flags.make

CMakeFiles/test_idle_handle.dir/test/test_idle_handle.cpp.o: CMakeFiles/test_idle_handle.dir/flags.make
CMakeFiles/test_idle_handle.dir/test/test_idle_handle.cpp.o: ../test/test_idle_handle.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/txy/Desktop/C/uv_tcp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/test_idle_handle.dir/test/test_idle_handle.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_idle_handle.dir/test/test_idle_handle.cpp.o -c /Users/txy/Desktop/C/uv_tcp/test/test_idle_handle.cpp

CMakeFiles/test_idle_handle.dir/test/test_idle_handle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_idle_handle.dir/test/test_idle_handle.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/txy/Desktop/C/uv_tcp/test/test_idle_handle.cpp > CMakeFiles/test_idle_handle.dir/test/test_idle_handle.cpp.i

CMakeFiles/test_idle_handle.dir/test/test_idle_handle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_idle_handle.dir/test/test_idle_handle.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/txy/Desktop/C/uv_tcp/test/test_idle_handle.cpp -o CMakeFiles/test_idle_handle.dir/test/test_idle_handle.cpp.s

# Object files for target test_idle_handle
test_idle_handle_OBJECTS = \
"CMakeFiles/test_idle_handle.dir/test/test_idle_handle.cpp.o"

# External object files for target test_idle_handle
test_idle_handle_EXTERNAL_OBJECTS =

test_idle_handle: CMakeFiles/test_idle_handle.dir/test/test_idle_handle.cpp.o
test_idle_handle: CMakeFiles/test_idle_handle.dir/build.make
test_idle_handle: CMakeFiles/test_idle_handle.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/txy/Desktop/C/uv_tcp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable test_idle_handle"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_idle_handle.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test_idle_handle.dir/build: test_idle_handle

.PHONY : CMakeFiles/test_idle_handle.dir/build

CMakeFiles/test_idle_handle.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test_idle_handle.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test_idle_handle.dir/clean

CMakeFiles/test_idle_handle.dir/depend:
	cd /Users/txy/Desktop/C/uv_tcp/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/txy/Desktop/C/uv_tcp /Users/txy/Desktop/C/uv_tcp /Users/txy/Desktop/C/uv_tcp/cmake-build-debug /Users/txy/Desktop/C/uv_tcp/cmake-build-debug /Users/txy/Desktop/C/uv_tcp/cmake-build-debug/CMakeFiles/test_idle_handle.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/test_idle_handle.dir/depend

