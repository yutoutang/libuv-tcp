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
include CMakeFiles/EchoServer.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/EchoServer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/EchoServer.dir/flags.make

CMakeFiles/EchoServer.dir/examples/echo/server.cpp.o: CMakeFiles/EchoServer.dir/flags.make
CMakeFiles/EchoServer.dir/examples/echo/server.cpp.o: ../examples/echo/server.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/txy/Desktop/C/uv_tcp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/EchoServer.dir/examples/echo/server.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/EchoServer.dir/examples/echo/server.cpp.o -c /Users/txy/Desktop/C/uv_tcp/examples/echo/server.cpp

CMakeFiles/EchoServer.dir/examples/echo/server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/EchoServer.dir/examples/echo/server.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/txy/Desktop/C/uv_tcp/examples/echo/server.cpp > CMakeFiles/EchoServer.dir/examples/echo/server.cpp.i

CMakeFiles/EchoServer.dir/examples/echo/server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/EchoServer.dir/examples/echo/server.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/txy/Desktop/C/uv_tcp/examples/echo/server.cpp -o CMakeFiles/EchoServer.dir/examples/echo/server.cpp.s

CMakeFiles/EchoServer.dir/examples/echo/EchoServer.cpp.o: CMakeFiles/EchoServer.dir/flags.make
CMakeFiles/EchoServer.dir/examples/echo/EchoServer.cpp.o: ../examples/echo/EchoServer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/txy/Desktop/C/uv_tcp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/EchoServer.dir/examples/echo/EchoServer.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/EchoServer.dir/examples/echo/EchoServer.cpp.o -c /Users/txy/Desktop/C/uv_tcp/examples/echo/EchoServer.cpp

CMakeFiles/EchoServer.dir/examples/echo/EchoServer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/EchoServer.dir/examples/echo/EchoServer.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/txy/Desktop/C/uv_tcp/examples/echo/EchoServer.cpp > CMakeFiles/EchoServer.dir/examples/echo/EchoServer.cpp.i

CMakeFiles/EchoServer.dir/examples/echo/EchoServer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/EchoServer.dir/examples/echo/EchoServer.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/txy/Desktop/C/uv_tcp/examples/echo/EchoServer.cpp -o CMakeFiles/EchoServer.dir/examples/echo/EchoServer.cpp.s

CMakeFiles/EchoServer.dir/examples/echo/EchoClient.cpp.o: CMakeFiles/EchoServer.dir/flags.make
CMakeFiles/EchoServer.dir/examples/echo/EchoClient.cpp.o: ../examples/echo/EchoClient.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/txy/Desktop/C/uv_tcp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/EchoServer.dir/examples/echo/EchoClient.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/EchoServer.dir/examples/echo/EchoClient.cpp.o -c /Users/txy/Desktop/C/uv_tcp/examples/echo/EchoClient.cpp

CMakeFiles/EchoServer.dir/examples/echo/EchoClient.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/EchoServer.dir/examples/echo/EchoClient.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/txy/Desktop/C/uv_tcp/examples/echo/EchoClient.cpp > CMakeFiles/EchoServer.dir/examples/echo/EchoClient.cpp.i

CMakeFiles/EchoServer.dir/examples/echo/EchoClient.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/EchoServer.dir/examples/echo/EchoClient.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/txy/Desktop/C/uv_tcp/examples/echo/EchoClient.cpp -o CMakeFiles/EchoServer.dir/examples/echo/EchoClient.cpp.s

CMakeFiles/EchoServer.dir/src/Async.cpp.o: CMakeFiles/EchoServer.dir/flags.make
CMakeFiles/EchoServer.dir/src/Async.cpp.o: ../src/Async.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/txy/Desktop/C/uv_tcp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/EchoServer.dir/src/Async.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/EchoServer.dir/src/Async.cpp.o -c /Users/txy/Desktop/C/uv_tcp/src/Async.cpp

CMakeFiles/EchoServer.dir/src/Async.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/EchoServer.dir/src/Async.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/txy/Desktop/C/uv_tcp/src/Async.cpp > CMakeFiles/EchoServer.dir/src/Async.cpp.i

CMakeFiles/EchoServer.dir/src/Async.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/EchoServer.dir/src/Async.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/txy/Desktop/C/uv_tcp/src/Async.cpp -o CMakeFiles/EchoServer.dir/src/Async.cpp.s

CMakeFiles/EchoServer.dir/src/EventLoop.cpp.o: CMakeFiles/EchoServer.dir/flags.make
CMakeFiles/EchoServer.dir/src/EventLoop.cpp.o: ../src/EventLoop.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/txy/Desktop/C/uv_tcp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/EchoServer.dir/src/EventLoop.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/EchoServer.dir/src/EventLoop.cpp.o -c /Users/txy/Desktop/C/uv_tcp/src/EventLoop.cpp

CMakeFiles/EchoServer.dir/src/EventLoop.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/EchoServer.dir/src/EventLoop.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/txy/Desktop/C/uv_tcp/src/EventLoop.cpp > CMakeFiles/EchoServer.dir/src/EventLoop.cpp.i

CMakeFiles/EchoServer.dir/src/EventLoop.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/EchoServer.dir/src/EventLoop.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/txy/Desktop/C/uv_tcp/src/EventLoop.cpp -o CMakeFiles/EchoServer.dir/src/EventLoop.cpp.s

CMakeFiles/EchoServer.dir/src/InetAddress.cpp.o: CMakeFiles/EchoServer.dir/flags.make
CMakeFiles/EchoServer.dir/src/InetAddress.cpp.o: ../src/InetAddress.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/txy/Desktop/C/uv_tcp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/EchoServer.dir/src/InetAddress.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/EchoServer.dir/src/InetAddress.cpp.o -c /Users/txy/Desktop/C/uv_tcp/src/InetAddress.cpp

CMakeFiles/EchoServer.dir/src/InetAddress.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/EchoServer.dir/src/InetAddress.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/txy/Desktop/C/uv_tcp/src/InetAddress.cpp > CMakeFiles/EchoServer.dir/src/InetAddress.cpp.i

CMakeFiles/EchoServer.dir/src/InetAddress.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/EchoServer.dir/src/InetAddress.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/txy/Desktop/C/uv_tcp/src/InetAddress.cpp -o CMakeFiles/EchoServer.dir/src/InetAddress.cpp.s

CMakeFiles/EchoServer.dir/src/ListBuffer.cpp.o: CMakeFiles/EchoServer.dir/flags.make
CMakeFiles/EchoServer.dir/src/ListBuffer.cpp.o: ../src/ListBuffer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/txy/Desktop/C/uv_tcp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/EchoServer.dir/src/ListBuffer.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/EchoServer.dir/src/ListBuffer.cpp.o -c /Users/txy/Desktop/C/uv_tcp/src/ListBuffer.cpp

CMakeFiles/EchoServer.dir/src/ListBuffer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/EchoServer.dir/src/ListBuffer.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/txy/Desktop/C/uv_tcp/src/ListBuffer.cpp > CMakeFiles/EchoServer.dir/src/ListBuffer.cpp.i

CMakeFiles/EchoServer.dir/src/ListBuffer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/EchoServer.dir/src/ListBuffer.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/txy/Desktop/C/uv_tcp/src/ListBuffer.cpp -o CMakeFiles/EchoServer.dir/src/ListBuffer.cpp.s

CMakeFiles/EchoServer.dir/src/LogWriter.cpp.o: CMakeFiles/EchoServer.dir/flags.make
CMakeFiles/EchoServer.dir/src/LogWriter.cpp.o: ../src/LogWriter.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/txy/Desktop/C/uv_tcp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/EchoServer.dir/src/LogWriter.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/EchoServer.dir/src/LogWriter.cpp.o -c /Users/txy/Desktop/C/uv_tcp/src/LogWriter.cpp

CMakeFiles/EchoServer.dir/src/LogWriter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/EchoServer.dir/src/LogWriter.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/txy/Desktop/C/uv_tcp/src/LogWriter.cpp > CMakeFiles/EchoServer.dir/src/LogWriter.cpp.i

CMakeFiles/EchoServer.dir/src/LogWriter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/EchoServer.dir/src/LogWriter.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/txy/Desktop/C/uv_tcp/src/LogWriter.cpp -o CMakeFiles/EchoServer.dir/src/LogWriter.cpp.s

CMakeFiles/EchoServer.dir/src/Packet.cpp.o: CMakeFiles/EchoServer.dir/flags.make
CMakeFiles/EchoServer.dir/src/Packet.cpp.o: ../src/Packet.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/txy/Desktop/C/uv_tcp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/EchoServer.dir/src/Packet.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/EchoServer.dir/src/Packet.cpp.o -c /Users/txy/Desktop/C/uv_tcp/src/Packet.cpp

CMakeFiles/EchoServer.dir/src/Packet.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/EchoServer.dir/src/Packet.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/txy/Desktop/C/uv_tcp/src/Packet.cpp > CMakeFiles/EchoServer.dir/src/Packet.cpp.i

CMakeFiles/EchoServer.dir/src/Packet.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/EchoServer.dir/src/Packet.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/txy/Desktop/C/uv_tcp/src/Packet.cpp -o CMakeFiles/EchoServer.dir/src/Packet.cpp.s

CMakeFiles/EchoServer.dir/src/TcpAcceptor.cpp.o: CMakeFiles/EchoServer.dir/flags.make
CMakeFiles/EchoServer.dir/src/TcpAcceptor.cpp.o: ../src/TcpAcceptor.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/txy/Desktop/C/uv_tcp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/EchoServer.dir/src/TcpAcceptor.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/EchoServer.dir/src/TcpAcceptor.cpp.o -c /Users/txy/Desktop/C/uv_tcp/src/TcpAcceptor.cpp

CMakeFiles/EchoServer.dir/src/TcpAcceptor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/EchoServer.dir/src/TcpAcceptor.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/txy/Desktop/C/uv_tcp/src/TcpAcceptor.cpp > CMakeFiles/EchoServer.dir/src/TcpAcceptor.cpp.i

CMakeFiles/EchoServer.dir/src/TcpAcceptor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/EchoServer.dir/src/TcpAcceptor.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/txy/Desktop/C/uv_tcp/src/TcpAcceptor.cpp -o CMakeFiles/EchoServer.dir/src/TcpAcceptor.cpp.s

CMakeFiles/EchoServer.dir/src/TcpClient.cpp.o: CMakeFiles/EchoServer.dir/flags.make
CMakeFiles/EchoServer.dir/src/TcpClient.cpp.o: ../src/TcpClient.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/txy/Desktop/C/uv_tcp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/EchoServer.dir/src/TcpClient.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/EchoServer.dir/src/TcpClient.cpp.o -c /Users/txy/Desktop/C/uv_tcp/src/TcpClient.cpp

CMakeFiles/EchoServer.dir/src/TcpClient.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/EchoServer.dir/src/TcpClient.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/txy/Desktop/C/uv_tcp/src/TcpClient.cpp > CMakeFiles/EchoServer.dir/src/TcpClient.cpp.i

CMakeFiles/EchoServer.dir/src/TcpClient.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/EchoServer.dir/src/TcpClient.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/txy/Desktop/C/uv_tcp/src/TcpClient.cpp -o CMakeFiles/EchoServer.dir/src/TcpClient.cpp.s

CMakeFiles/EchoServer.dir/src/TcpConnection.cpp.o: CMakeFiles/EchoServer.dir/flags.make
CMakeFiles/EchoServer.dir/src/TcpConnection.cpp.o: ../src/TcpConnection.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/txy/Desktop/C/uv_tcp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/EchoServer.dir/src/TcpConnection.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/EchoServer.dir/src/TcpConnection.cpp.o -c /Users/txy/Desktop/C/uv_tcp/src/TcpConnection.cpp

CMakeFiles/EchoServer.dir/src/TcpConnection.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/EchoServer.dir/src/TcpConnection.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/txy/Desktop/C/uv_tcp/src/TcpConnection.cpp > CMakeFiles/EchoServer.dir/src/TcpConnection.cpp.i

CMakeFiles/EchoServer.dir/src/TcpConnection.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/EchoServer.dir/src/TcpConnection.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/txy/Desktop/C/uv_tcp/src/TcpConnection.cpp -o CMakeFiles/EchoServer.dir/src/TcpConnection.cpp.s

CMakeFiles/EchoServer.dir/src/TcpServer.cpp.o: CMakeFiles/EchoServer.dir/flags.make
CMakeFiles/EchoServer.dir/src/TcpServer.cpp.o: ../src/TcpServer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/txy/Desktop/C/uv_tcp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/EchoServer.dir/src/TcpServer.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/EchoServer.dir/src/TcpServer.cpp.o -c /Users/txy/Desktop/C/uv_tcp/src/TcpServer.cpp

CMakeFiles/EchoServer.dir/src/TcpServer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/EchoServer.dir/src/TcpServer.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/txy/Desktop/C/uv_tcp/src/TcpServer.cpp > CMakeFiles/EchoServer.dir/src/TcpServer.cpp.i

CMakeFiles/EchoServer.dir/src/TcpServer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/EchoServer.dir/src/TcpServer.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/txy/Desktop/C/uv_tcp/src/TcpServer.cpp -o CMakeFiles/EchoServer.dir/src/TcpServer.cpp.s

CMakeFiles/EchoServer.dir/src/Timer.cpp.o: CMakeFiles/EchoServer.dir/flags.make
CMakeFiles/EchoServer.dir/src/Timer.cpp.o: ../src/Timer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/txy/Desktop/C/uv_tcp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object CMakeFiles/EchoServer.dir/src/Timer.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/EchoServer.dir/src/Timer.cpp.o -c /Users/txy/Desktop/C/uv_tcp/src/Timer.cpp

CMakeFiles/EchoServer.dir/src/Timer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/EchoServer.dir/src/Timer.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/txy/Desktop/C/uv_tcp/src/Timer.cpp > CMakeFiles/EchoServer.dir/src/Timer.cpp.i

CMakeFiles/EchoServer.dir/src/Timer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/EchoServer.dir/src/Timer.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/txy/Desktop/C/uv_tcp/src/Timer.cpp -o CMakeFiles/EchoServer.dir/src/Timer.cpp.s

CMakeFiles/EchoServer.dir/src/http/HttpCommon.cpp.o: CMakeFiles/EchoServer.dir/flags.make
CMakeFiles/EchoServer.dir/src/http/HttpCommon.cpp.o: ../src/http/HttpCommon.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/txy/Desktop/C/uv_tcp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building CXX object CMakeFiles/EchoServer.dir/src/http/HttpCommon.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/EchoServer.dir/src/http/HttpCommon.cpp.o -c /Users/txy/Desktop/C/uv_tcp/src/http/HttpCommon.cpp

CMakeFiles/EchoServer.dir/src/http/HttpCommon.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/EchoServer.dir/src/http/HttpCommon.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/txy/Desktop/C/uv_tcp/src/http/HttpCommon.cpp > CMakeFiles/EchoServer.dir/src/http/HttpCommon.cpp.i

CMakeFiles/EchoServer.dir/src/http/HttpCommon.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/EchoServer.dir/src/http/HttpCommon.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/txy/Desktop/C/uv_tcp/src/http/HttpCommon.cpp -o CMakeFiles/EchoServer.dir/src/http/HttpCommon.cpp.s

CMakeFiles/EchoServer.dir/src/http/HttpServer.cpp.o: CMakeFiles/EchoServer.dir/flags.make
CMakeFiles/EchoServer.dir/src/http/HttpServer.cpp.o: ../src/http/HttpServer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/txy/Desktop/C/uv_tcp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Building CXX object CMakeFiles/EchoServer.dir/src/http/HttpServer.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/EchoServer.dir/src/http/HttpServer.cpp.o -c /Users/txy/Desktop/C/uv_tcp/src/http/HttpServer.cpp

CMakeFiles/EchoServer.dir/src/http/HttpServer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/EchoServer.dir/src/http/HttpServer.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/txy/Desktop/C/uv_tcp/src/http/HttpServer.cpp > CMakeFiles/EchoServer.dir/src/http/HttpServer.cpp.i

CMakeFiles/EchoServer.dir/src/http/HttpServer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/EchoServer.dir/src/http/HttpServer.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/txy/Desktop/C/uv_tcp/src/http/HttpServer.cpp -o CMakeFiles/EchoServer.dir/src/http/HttpServer.cpp.s

CMakeFiles/EchoServer.dir/src/http/Request.cpp.o: CMakeFiles/EchoServer.dir/flags.make
CMakeFiles/EchoServer.dir/src/http/Request.cpp.o: ../src/http/Request.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/txy/Desktop/C/uv_tcp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_17) "Building CXX object CMakeFiles/EchoServer.dir/src/http/Request.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/EchoServer.dir/src/http/Request.cpp.o -c /Users/txy/Desktop/C/uv_tcp/src/http/Request.cpp

CMakeFiles/EchoServer.dir/src/http/Request.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/EchoServer.dir/src/http/Request.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/txy/Desktop/C/uv_tcp/src/http/Request.cpp > CMakeFiles/EchoServer.dir/src/http/Request.cpp.i

CMakeFiles/EchoServer.dir/src/http/Request.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/EchoServer.dir/src/http/Request.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/txy/Desktop/C/uv_tcp/src/http/Request.cpp -o CMakeFiles/EchoServer.dir/src/http/Request.cpp.s

CMakeFiles/EchoServer.dir/src/http/Response.cpp.o: CMakeFiles/EchoServer.dir/flags.make
CMakeFiles/EchoServer.dir/src/http/Response.cpp.o: ../src/http/Response.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/txy/Desktop/C/uv_tcp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_18) "Building CXX object CMakeFiles/EchoServer.dir/src/http/Response.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/EchoServer.dir/src/http/Response.cpp.o -c /Users/txy/Desktop/C/uv_tcp/src/http/Response.cpp

CMakeFiles/EchoServer.dir/src/http/Response.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/EchoServer.dir/src/http/Response.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/txy/Desktop/C/uv_tcp/src/http/Response.cpp > CMakeFiles/EchoServer.dir/src/http/Response.cpp.i

CMakeFiles/EchoServer.dir/src/http/Response.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/EchoServer.dir/src/http/Response.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/txy/Desktop/C/uv_tcp/src/http/Response.cpp -o CMakeFiles/EchoServer.dir/src/http/Response.cpp.s

# Object files for target EchoServer
EchoServer_OBJECTS = \
"CMakeFiles/EchoServer.dir/examples/echo/server.cpp.o" \
"CMakeFiles/EchoServer.dir/examples/echo/EchoServer.cpp.o" \
"CMakeFiles/EchoServer.dir/examples/echo/EchoClient.cpp.o" \
"CMakeFiles/EchoServer.dir/src/Async.cpp.o" \
"CMakeFiles/EchoServer.dir/src/EventLoop.cpp.o" \
"CMakeFiles/EchoServer.dir/src/InetAddress.cpp.o" \
"CMakeFiles/EchoServer.dir/src/ListBuffer.cpp.o" \
"CMakeFiles/EchoServer.dir/src/LogWriter.cpp.o" \
"CMakeFiles/EchoServer.dir/src/Packet.cpp.o" \
"CMakeFiles/EchoServer.dir/src/TcpAcceptor.cpp.o" \
"CMakeFiles/EchoServer.dir/src/TcpClient.cpp.o" \
"CMakeFiles/EchoServer.dir/src/TcpConnection.cpp.o" \
"CMakeFiles/EchoServer.dir/src/TcpServer.cpp.o" \
"CMakeFiles/EchoServer.dir/src/Timer.cpp.o" \
"CMakeFiles/EchoServer.dir/src/http/HttpCommon.cpp.o" \
"CMakeFiles/EchoServer.dir/src/http/HttpServer.cpp.o" \
"CMakeFiles/EchoServer.dir/src/http/Request.cpp.o" \
"CMakeFiles/EchoServer.dir/src/http/Response.cpp.o"

# External object files for target EchoServer
EchoServer_EXTERNAL_OBJECTS =

EchoServer: CMakeFiles/EchoServer.dir/examples/echo/server.cpp.o
EchoServer: CMakeFiles/EchoServer.dir/examples/echo/EchoServer.cpp.o
EchoServer: CMakeFiles/EchoServer.dir/examples/echo/EchoClient.cpp.o
EchoServer: CMakeFiles/EchoServer.dir/src/Async.cpp.o
EchoServer: CMakeFiles/EchoServer.dir/src/EventLoop.cpp.o
EchoServer: CMakeFiles/EchoServer.dir/src/InetAddress.cpp.o
EchoServer: CMakeFiles/EchoServer.dir/src/ListBuffer.cpp.o
EchoServer: CMakeFiles/EchoServer.dir/src/LogWriter.cpp.o
EchoServer: CMakeFiles/EchoServer.dir/src/Packet.cpp.o
EchoServer: CMakeFiles/EchoServer.dir/src/TcpAcceptor.cpp.o
EchoServer: CMakeFiles/EchoServer.dir/src/TcpClient.cpp.o
EchoServer: CMakeFiles/EchoServer.dir/src/TcpConnection.cpp.o
EchoServer: CMakeFiles/EchoServer.dir/src/TcpServer.cpp.o
EchoServer: CMakeFiles/EchoServer.dir/src/Timer.cpp.o
EchoServer: CMakeFiles/EchoServer.dir/src/http/HttpCommon.cpp.o
EchoServer: CMakeFiles/EchoServer.dir/src/http/HttpServer.cpp.o
EchoServer: CMakeFiles/EchoServer.dir/src/http/Request.cpp.o
EchoServer: CMakeFiles/EchoServer.dir/src/http/Response.cpp.o
EchoServer: CMakeFiles/EchoServer.dir/build.make
EchoServer: CMakeFiles/EchoServer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/txy/Desktop/C/uv_tcp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_19) "Linking CXX executable EchoServer"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/EchoServer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/EchoServer.dir/build: EchoServer

.PHONY : CMakeFiles/EchoServer.dir/build

CMakeFiles/EchoServer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/EchoServer.dir/cmake_clean.cmake
.PHONY : CMakeFiles/EchoServer.dir/clean

CMakeFiles/EchoServer.dir/depend:
	cd /Users/txy/Desktop/C/uv_tcp/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/txy/Desktop/C/uv_tcp /Users/txy/Desktop/C/uv_tcp /Users/txy/Desktop/C/uv_tcp/cmake-build-debug /Users/txy/Desktop/C/uv_tcp/cmake-build-debug /Users/txy/Desktop/C/uv_tcp/cmake-build-debug/CMakeFiles/EchoServer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/EchoServer.dir/depend

