# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = /opt/clion-2018.2.3/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /opt/clion-2018.2.3/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ashish/Documents/Codes/Sem5_Graphics/5thSEM_Graphics

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ashish/Documents/Codes/Sem5_Graphics/5thSEM_Graphics/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ICTC.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ICTC.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ICTC.dir/flags.make

CMakeFiles/ICTC.dir/glad.c.o: CMakeFiles/ICTC.dir/flags.make
CMakeFiles/ICTC.dir/glad.c.o: ../glad.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ashish/Documents/Codes/Sem5_Graphics/5thSEM_Graphics/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/ICTC.dir/glad.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ICTC.dir/glad.c.o   -c /home/ashish/Documents/Codes/Sem5_Graphics/5thSEM_Graphics/glad.c

CMakeFiles/ICTC.dir/glad.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ICTC.dir/glad.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ashish/Documents/Codes/Sem5_Graphics/5thSEM_Graphics/glad.c > CMakeFiles/ICTC.dir/glad.c.i

CMakeFiles/ICTC.dir/glad.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ICTC.dir/glad.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ashish/Documents/Codes/Sem5_Graphics/5thSEM_Graphics/glad.c -o CMakeFiles/ICTC.dir/glad.c.s

CMakeFiles/ICTC.dir/src/main.cpp.o: CMakeFiles/ICTC.dir/flags.make
CMakeFiles/ICTC.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ashish/Documents/Codes/Sem5_Graphics/5thSEM_Graphics/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/ICTC.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ICTC.dir/src/main.cpp.o -c /home/ashish/Documents/Codes/Sem5_Graphics/5thSEM_Graphics/src/main.cpp

CMakeFiles/ICTC.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ICTC.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ashish/Documents/Codes/Sem5_Graphics/5thSEM_Graphics/src/main.cpp > CMakeFiles/ICTC.dir/src/main.cpp.i

CMakeFiles/ICTC.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ICTC.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ashish/Documents/Codes/Sem5_Graphics/5thSEM_Graphics/src/main.cpp -o CMakeFiles/ICTC.dir/src/main.cpp.s

# Object files for target ICTC
ICTC_OBJECTS = \
"CMakeFiles/ICTC.dir/glad.c.o" \
"CMakeFiles/ICTC.dir/src/main.cpp.o"

# External object files for target ICTC
ICTC_EXTERNAL_OBJECTS =

ICTC: CMakeFiles/ICTC.dir/glad.c.o
ICTC: CMakeFiles/ICTC.dir/src/main.cpp.o
ICTC: CMakeFiles/ICTC.dir/build.make
ICTC: CMakeFiles/ICTC.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ashish/Documents/Codes/Sem5_Graphics/5thSEM_Graphics/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable ICTC"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ICTC.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ICTC.dir/build: ICTC

.PHONY : CMakeFiles/ICTC.dir/build

CMakeFiles/ICTC.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ICTC.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ICTC.dir/clean

CMakeFiles/ICTC.dir/depend:
	cd /home/ashish/Documents/Codes/Sem5_Graphics/5thSEM_Graphics/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ashish/Documents/Codes/Sem5_Graphics/5thSEM_Graphics /home/ashish/Documents/Codes/Sem5_Graphics/5thSEM_Graphics /home/ashish/Documents/Codes/Sem5_Graphics/5thSEM_Graphics/cmake-build-debug /home/ashish/Documents/Codes/Sem5_Graphics/5thSEM_Graphics/cmake-build-debug /home/ashish/Documents/Codes/Sem5_Graphics/5thSEM_Graphics/cmake-build-debug/CMakeFiles/ICTC.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ICTC.dir/depend

