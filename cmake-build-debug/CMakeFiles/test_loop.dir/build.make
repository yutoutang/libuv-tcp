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
include CMakeFiles/test_loop.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/test_loop.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test_loop.dir/flags.make

CMakeFiles/test_loop.dir/test/test_loop.cpp.o: CMakeFiles/test_loop.dir/flags.make
CMakeFiles/test_loop.dir/test/test_loop.cpp.o: ../test/test_loop.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/txy/Desktop/C/uv_tcp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/test_loop.dir/test/test_loop.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_loop.dir/test/test_loop.cpp.o -c /Users/txy/Desktop/C/uv_tcp/test/test_loop.cpp

CMakeFiles/test_loop.dir/test/test_loop.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_loop.dir/test/test_loop.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/txy/Desktop/C/uv_tcp/test/test_loop.cpp > CMakeFiles/test_loop.dir/test/test_loop.cpp.i

CMakeFiles/test_loop.dir/test/test_loop.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_loop.dir/test/test_loop.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/txy/Desktop/C/uv_tcp/test/test_loop.cpp -o CMakeFiles/test_loop.dir/test/test_loop.cpp.s

CMakeFiles/test_loop.dir/src/Async.cpp.o: CMakeFiles/test_loop.dir/flags.make
CMakeFiles/test_loop.dir/src/Async.cpp.o: ../src/Async.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/txy/Desktop/C/uv_tcp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/test_loop.dir/src/Async.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_loop.dir/src/Async.cpp.o -c /Users/txy/Desktop/C/uv_tcp/src/Async.cpp

CMakeFiles/test_loop.dir/src/Async.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_loop.dir/src/Async.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/txy/Desktop/C/uv_tcp/src/Async.cpp > CMakeFiles/test_loop.dir/src/Async.cpp.i

CMakeFiles/test_loop.dir/src/Async.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_loop.dir/src/Async.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/txy/Desktop/C/uv_tcp/src/Async.cpp -o CMakeFiles/test_loop.dir/src/Async.cpp.s

CMakeFiles/test_loop.dir/src/EventLoop.cpp.o: CMakeFiles/test_loop.dir/flags.make
CMakeFiles/test_loop.dir/src/EventLoop.cpp.o: ../src/EventLoop.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/txy/Desktop/C/uv_tcp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/test_loop.dir/src/EventLoop.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_loop.dir/src/EventLoop.cpp.o -c /Users/txy/Desktop/C/uv_tcp/src/EventLoop.cpp

CMakeFiles/test_loop.dir/src/EventLoop.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_loop.dir/src/EventLoop.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/txy/Desktop/C/uv_tcp/src/EventLoop.cpp > CMakeFiles/test_loop.dir/src/EventLoop.cpp.i

CMakeFiles/test_loop.dir/src/EventLoop.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_loop.dir/src/EventLoop.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/txy/Desktop/C/uv_tcp/src/EventLoop.cpp -o CMakeFiles/test_loop.dir/src/EventLoop.cpp.s

CMakeFiles/test_loop.dir/src/InetAddress.cpp.o: CMakeFiles/test_loop.dir/flags.make
CMakeFiles/test_loop.dir/src/InetAddress.cpp.o: ../src/InetAddress.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/txy/Desktop/C/uv_tcp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/test_loop.dir/src/InetAddress.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_loop.dir/src/InetAddress.cpp.o -c /Users/txy/Desktop/C/uv_tcp/src/InetAddress.cpp

CMakeFiles/test_loop.dir/src/InetAddress.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_loop.dir/src/InetAddress.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/txy/Desktop/C/uv_tcp/src/InetAddress.cpp > CMakeFiles/test_loop.dir/src/InetAddress.cpp.i

CMakeFiles/test_loop.dir/src/InetAddress.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_loop.dir/src/InetAddress.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/txy/Desktop/C/uv_tcp/src/InetAddress.cpp -o CMakeFiles/test_loop.dir/src/InetAddress.cpp.s

CMakeFiles/test_loop.dir/src/ListBuffer.cpp.o: CMakeFiles/test_loop.dir/flags.make
CMakeFiles/test_loop.dir/src/ListBuffer.cpp.o: ../src/ListBuffer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/txy/Desktop/C/uv_tcp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/test_loop.dir/src/ListBuffer.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_loop.dir/src/ListBuffer.cpp.o -c /Users/txy/Desktop/C/uv_tcp/src/ListBuffer.cpp

CMakeFiles/test_loop.dir/src/ListBuffer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_loop.dir/src/ListBuffer.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/txy/Desktop/C/uv_tcp/src/ListBuffer.cpp > CMakeFiles/test_loop.dir/src/ListBuffer.cpp.i

CMakeFiles/test_loop.dir/src/ListBuffer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_loop.dir/src/ListBuffer.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/txy/Desktop/C/uv_tcp/src/ListBuffer.cpp -o CMakeFiles/test_loop.dir/src/ListBuffer.cpp.s

CMakeFiles/test_loop.dir/src/LogWriter.cpp.o: CMakeFiles/test_loop.dir/flags.make
CMakeFiles/test_loop.dir/src/LogWriter.cpp.o: ../src/LogWriter.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/txy/Desktop/C/uv_tcp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/test_loop.dir/src/LogWriter.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_loop.dir/src/LogWriter.cpp.o -c /Users/txy/Desktop/C/uv_tcp/src/LogWriter.cpp

CMakeFiles/test_loop.dir/src/LogWriter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_loop.dir/src/LogWriter.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/txy/Desktop/C/uv_tcp/src/LogWriter.cpp > CMakeFiles/test_loop.dir/src/LogWriter.cpp.i

CMakeFiles/test_loop.dir/src/LogWriter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_loop.dir/src/LogWriter.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/txy/Desktop/C/uv_tcp/src/LogWriter.cpp -o CMakeFiles/test_loop.dir/src/LogWriter.cpp.s

CMakeFiles/test_loop.dir/src/Packet.cpp.o: CMakeFiles/test_loop.dir/flags.make
CMakeFiles/test_loop.dir/src/Packet.cpp.o: ../src/Packet.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/txy/Desktop/C/uv_tcp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/test_loop.dir/src/Packet.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_loop.dir/src/Packet.cpp.o -c /Users/txy/Desktop/C/uv_tcp/src/Packet.cpp

CMakeFiles/test_loop.dir/src/Packet.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_loop.dir/src/Packet.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/txy/Desktop/C/uv_tcp/src/Packet.cpp > CMakeFiles/test_loop.dir/src/Packet.cpp.i

CMakeFiles/test_loop.dir/src/Packet.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_loop.dir/src/Packet.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/txy/Desktop/C/uv_tcp/src/Packet.cpp -o CMakeFiles/test_loop.dir/src/Packet.cpp.s

CMakeFiles/test_loop.dir/src/TcpAcceptor.cpp.o: CMakeFiles/test_loop.dir/flags.make
CMakeFiles/test_loop.dir/src/TcpAcceptor.cpp.o: ../src/TcpAcceptor.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/txy/Desktop/C/uv_tcp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/test_loop.dir/src/TcpAcceptor.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_loop.dir/src/TcpAcceptor.cpp.o -c /Users/txy/Desktop/C/uv_tcp/src/TcpAcceptor.cpp

CMakeFiles/test_loop.dir/src/TcpAcceptor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_loop.dir/src/TcpAcceptor.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/txy/Desktop/C/uv_tcp/src/TcpAcceptor.cpp > CMakeFiles/test_loop.dir/src/TcpAcceptor.cpp.i

CMakeFiles/test_loop.dir/src/TcpAcceptor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_loop.dir/src/TcpAcceptor.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/txy/Desktop/C/uv_tcp/src/TcpAcceptor.cpp -o CMakeFiles/test_loop.dir/src/TcpAcceptor.cpp.s

CMakeFiles/test_loop.dir/src/TcpClient.cpp.o: CMakeFiles/test_loop.dir/flags.make
CMakeFiles/test_loop.dir/src/TcpClient.cpp.o: ../src/TcpClient.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/txy/Desktop/C/uv_tcp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/test_loop.dir/src/TcpClient.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_loop.dir/src/TcpClient.cpp.o -c /Users/txy/Desktop/C/uv_tcp/src/TcpClient.cpp

CMakeFiles/test_loop.dir/src/TcpClient.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_loop.dir/src/TcpClient.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/txy/Desktop/C/uv_tcp/src/TcpClient.cpp > CMakeFiles/test_loop.dir/src/TcpClient.cpp.i

CMakeFiles/test_loop.dir/src/TcpClient.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_loop.dir/src/TcpClient.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/txy/Desktop/C/uv_tcp/src/TcpClient.cpp -o CMakeFiles/test_loop.dir/src/TcpClient.cpp.s

CMakeFiles/test_loop.dir/src/TcpConnection.cpp.o: CMakeFiles/test_loop.dir/flags.make
CMakeFiles/test_loop.dir/src/TcpConnection.cpp.o: ../src/TcpConnection.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/txy/Desktop/C/uv_tcp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/test_loop.dir/src/TcpConnection.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_loop.dir/src/TcpConnection.cpp.o -c /Users/txy/Desktop/C/uv_tcp/src/TcpConnection.cpp

CMakeFiles/test_loop.dir/src/TcpConnection.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_loop.dir/src/TcpConnection.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/txy/Desktop/C/uv_tcp/src/TcpConnection.cpp > CMakeFiles/test_loop.dir/src/TcpConnection.cpp.i

CMakeFiles/test_loop.dir/src/TcpConnection.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_loop.dir/src/TcpConnection.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/txy/Desktop/C/uv_tcp/src/TcpConnection.cpp -o CMakeFiles/test_loop.dir/src/TcpConnection.cpp.s

CMakeFiles/test_loop.dir/src/TcpServer.cpp.o: CMakeFiles/test_loop.dir/flags.make
CMakeFiles/test_loop.dir/src/TcpServer.cpp.o: ../src/TcpServer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/txy/Desktop/C/uv_tcp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/test_loop.dir/src/TcpServer.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_loop.dir/src/TcpServer.cpp.o -c /Users/txy/Desktop/C/uv_tcp/src/TcpServer.cpp

CMakeFiles/test_loop.dir/src/TcpServer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_loop.dir/src/TcpServer.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/txy/Desktop/C/uv_tcp/src/TcpServer.cpp > CMakeFiles/test_loop.dir/src/TcpServer.cpp.i

CMakeFiles/test_loop.dir/src/TcpServer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_loop.dir/src/TcpServer.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/txy/Desktop/C/uv_tcp/src/TcpServer.cpp -o CMakeFiles/test_loop.dir/src/TcpServer.cpp.s

CMakeFiles/test_loop.dir/src/Timer.cpp.o: CMakeFiles/test_loop.dir/flags.make
CMakeFiles/test_loop.dir/src/Timer.cpp.o: ../src/Timer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/txy/Desktop/C/uv_tcp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/test_loop.dir/src/Timer.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_loop.dir/src/Timer.cpp.o -c /Users/txy/Desktop/C/uv_tcp/src/Timer.cpp

CMakeFiles/test_loop.dir/src/Timer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_loop.dir/src/Timer.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/txy/Desktop/C/uv_tcp/src/Timer.cpp > CMakeFiles/test_loop.dir/src/Timer.cpp.i

CMakeFiles/test_loop.dir/src/Timer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_loop.dir/src/Timer.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/txy/Desktop/C/uv_tcp/src/Timer.cpp -o CMakeFiles/test_loop.dir/src/Timer.cpp.s

CMakeFiles/test_loop.dir/src/http/HttpCommon.cpp.o: CMakeFiles/test_loop.dir/flags.make
CMakeFiles/test_loop.dir/src/http/HttpCommon.cpp.o: ../src/http/HttpCommon.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/txy/Desktop/C/uv_tcp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/test_loop.dir/src/http/HttpCommon.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_loop.dir/src/http/HttpCommon.cpp.o -c /Users/txy/Desktop/C/uv_tcp/src/http/HttpCommon.cpp

CMakeFiles/test_loop.dir/src/http/HttpCommon.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_loop.dir/src/http/HttpCommon.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/txy/Desktop/C/uv_tcp/src/http/HttpCommon.cpp > CMakeFiles/test_loop.dir/src/http/HttpCommon.cpp.i

CMakeFiles/test_loop.dir/src/http/HttpCommon.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_loop.dir/src/http/HttpCommon.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/txy/Desktop/C/uv_tcp/src/http/HttpCommon.cpp -o CMakeFiles/test_loop.dir/src/http/HttpCommon.cpp.s

CMakeFiles/test_loop.dir/src/http/HttpServer.cpp.o: CMakeFiles/test_loop.dir/flags.make
CMakeFiles/test_loop.dir/src/http/HttpServer.cpp.o: ../src/http/HttpServer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/txy/Desktop/C/uv_tcp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object CMakeFiles/test_loop.dir/src/http/HttpServer.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_loop.dir/src/http/HttpServer.cpp.o -c /Users/txy/Desktop/C/uv_tcp/src/http/HttpServer.cpp

CMakeFiles/test_loop.dir/src/http/HttpServer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_loop.dir/src/http/HttpServer.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/txy/Desktop/C/uv_tcp/src/http/HttpServer.cpp > CMakeFiles/test_loop.dir/src/http/HttpServer.cpp.i

CMakeFiles/test_loop.dir/src/http/HttpServer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_loop.dir/src/http/HttpServer.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/txy/Desktop/C/uv_tcp/src/http/HttpServer.cpp -o CMakeFiles/test_loop.dir/src/http/HttpServer.cpp.s

CMakeFiles/test_loop.dir/src/http/Request.cpp.o: CMakeFiles/test_loop.dir/flags.make
CMakeFiles/test_loop.dir/src/http/Request.cpp.o: ../src/http/Request.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/txy/Desktop/C/uv_tcp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building CXX object CMakeFiles/test_loop.dir/src/http/Request.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_loop.dir/src/http/Request.cpp.o -c /Users/txy/Desktop/C/uv_tcp/src/http/Request.cpp

CMakeFiles/test_loop.dir/src/http/Request.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_loop.dir/src/http/Request.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/txy/Desktop/C/uv_tcp/src/http/Request.cpp > CMakeFiles/test_loop.dir/src/http/Request.cpp.i

CMakeFiles/test_loop.dir/src/http/Request.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_loop.dir/src/http/Request.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/txy/Desktop/C/uv_tcp/src/http/Request.cpp -o CMakeFiles/test_loop.dir/src/http/Request.cpp.s

CMakeFiles/test_loop.dir/src/http/Response.cpp.o: CMakeFiles/test_loop.dir/flags.make
CMakeFiles/test_loop.dir/src/http/Response.cpp.o: ../src/http/Response.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/txy/Desktop/C/uv_tcp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Building CXX object CMakeFiles/test_loop.dir/src/http/Response.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_loop.dir/src/http/Response.cpp.o -c /Users/txy/Desktop/C/uv_tcp/src/http/Response.cpp

CMakeFiles/test_loop.dir/src/http/Response.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_loop.dir/src/http/Response.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/txy/Desktop/C/uv_tcp/src/http/Response.cpp > CMakeFiles/test_loop.dir/src/http/Response.cpp.i

CMakeFiles/test_loop.dir/src/http/Response.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_loop.dir/src/http/Response.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/txy/Desktop/C/uv_tcp/src/http/Response.cpp -o CMakeFiles/test_loop.dir/src/http/Response.cpp.s

# Object files for target test_loop
test_loop_OBJECTS = \
"CMakeFiles/test_loop.dir/test/test_loop.cpp.o" \
"CMakeFiles/test_loop.dir/src/Async.cpp.o" \
"CMakeFiles/test_loop.dir/src/EventLoop.cpp.o" \
"CMakeFiles/test_loop.dir/src/InetAddress.cpp.o" \
"CMakeFiles/test_loop.dir/src/ListBuffer.cpp.o" \
"CMakeFiles/test_loop.dir/src/LogWriter.cpp.o" \
"CMakeFiles/test_loop.dir/src/Packet.cpp.o" \
"CMakeFiles/test_loop.dir/src/TcpAcceptor.cpp.o" \
"CMakeFiles/test_loop.dir/src/TcpClient.cpp.o" \
"CMakeFiles/test_loop.dir/src/TcpConnection.cpp.o" \
"CMakeFiles/test_loop.dir/src/TcpServer.cpp.o" \
"CMakeFiles/test_loop.dir/src/Timer.cpp.o" \
"CMakeFiles/test_loop.dir/src/http/HttpCommon.cpp.o" \
"CMakeFiles/test_loop.dir/src/http/HttpServer.cpp.o" \
"CMakeFiles/test_loop.dir/src/http/Request.cpp.o" \
"CMakeFiles/test_loop.dir/src/http/Response.cpp.o"

# External object files for target test_loop
test_loop_EXTERNAL_OBJECTS =

test_loop: CMakeFiles/test_loop.dir/test/test_loop.cpp.o
test_loop: CMakeFiles/test_loop.dir/src/Async.cpp.o
test_loop: CMakeFiles/test_loop.dir/src/EventLoop.cpp.o
test_loop: CMakeFiles/test_loop.dir/src/InetAddress.cpp.o
test_loop: CMakeFiles/test_loop.dir/src/ListBuffer.cpp.o
test_loop: CMakeFiles/test_loop.dir/src/LogWriter.cpp.o
test_loop: CMakeFiles/test_loop.dir/src/Packet.cpp.o
test_loop: CMakeFiles/test_loop.dir/src/TcpAcceptor.cpp.o
test_loop: CMakeFiles/test_loop.dir/src/TcpClient.cpp.o
test_loop: CMakeFiles/test_loop.dir/src/TcpConnection.cpp.o
test_loop: CMakeFiles/test_loop.dir/src/TcpServer.cpp.o
test_loop: CMakeFiles/test_loop.dir/src/Timer.cpp.o
test_loop: CMakeFiles/test_loop.dir/src/http/HttpCommon.cpp.o
test_loop: CMakeFiles/test_loop.dir/src/http/HttpServer.cpp.o
test_loop: CMakeFiles/test_loop.dir/src/http/Request.cpp.o
test_loop: CMakeFiles/test_loop.dir/src/http/Response.cpp.o
test_loop: CMakeFiles/test_loop.dir/build.make
test_loop: CMakeFiles/test_loop.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/txy/Desktop/C/uv_tcp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_17) "Linking CXX executable test_loop"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_loop.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test_loop.dir/build: test_loop

.PHONY : CMakeFiles/test_loop.dir/build

CMakeFiles/test_loop.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test_loop.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test_loop.dir/clean

CMakeFiles/test_loop.dir/depend:
	cd /Users/txy/Desktop/C/uv_tcp/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/txy/Desktop/C/uv_tcp /Users/txy/Desktop/C/uv_tcp /Users/txy/Desktop/C/uv_tcp/cmake-build-debug /Users/txy/Desktop/C/uv_tcp/cmake-build-debug /Users/txy/Desktop/C/uv_tcp/cmake-build-debug/CMakeFiles/test_loop.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/test_loop.dir/depend
