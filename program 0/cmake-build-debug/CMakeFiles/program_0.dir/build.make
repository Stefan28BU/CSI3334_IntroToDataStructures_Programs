# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/Stefan_Xu/Desktop/Stefan/CSI3334/program 0"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/Stefan_Xu/Desktop/Stefan/CSI3334/program 0/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/program_0.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/program_0.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/program_0.dir/flags.make

CMakeFiles/program_0.dir/TestDriver.cpp.o: CMakeFiles/program_0.dir/flags.make
CMakeFiles/program_0.dir/TestDriver.cpp.o: ../TestDriver.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/Stefan_Xu/Desktop/Stefan/CSI3334/program 0/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/program_0.dir/TestDriver.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/program_0.dir/TestDriver.cpp.o -c "/Users/Stefan_Xu/Desktop/Stefan/CSI3334/program 0/TestDriver.cpp"

CMakeFiles/program_0.dir/TestDriver.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/program_0.dir/TestDriver.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/Stefan_Xu/Desktop/Stefan/CSI3334/program 0/TestDriver.cpp" > CMakeFiles/program_0.dir/TestDriver.cpp.i

CMakeFiles/program_0.dir/TestDriver.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/program_0.dir/TestDriver.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/Stefan_Xu/Desktop/Stefan/CSI3334/program 0/TestDriver.cpp" -o CMakeFiles/program_0.dir/TestDriver.cpp.s

CMakeFiles/program_0.dir/TestDriver.cpp.o.requires:

.PHONY : CMakeFiles/program_0.dir/TestDriver.cpp.o.requires

CMakeFiles/program_0.dir/TestDriver.cpp.o.provides: CMakeFiles/program_0.dir/TestDriver.cpp.o.requires
	$(MAKE) -f CMakeFiles/program_0.dir/build.make CMakeFiles/program_0.dir/TestDriver.cpp.o.provides.build
.PHONY : CMakeFiles/program_0.dir/TestDriver.cpp.o.provides

CMakeFiles/program_0.dir/TestDriver.cpp.o.provides.build: CMakeFiles/program_0.dir/TestDriver.cpp.o


# Object files for target program_0
program_0_OBJECTS = \
"CMakeFiles/program_0.dir/TestDriver.cpp.o"

# External object files for target program_0
program_0_EXTERNAL_OBJECTS =

program_0: CMakeFiles/program_0.dir/TestDriver.cpp.o
program_0: CMakeFiles/program_0.dir/build.make
program_0: CMakeFiles/program_0.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/Stefan_Xu/Desktop/Stefan/CSI3334/program 0/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable program_0"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/program_0.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/program_0.dir/build: program_0

.PHONY : CMakeFiles/program_0.dir/build

CMakeFiles/program_0.dir/requires: CMakeFiles/program_0.dir/TestDriver.cpp.o.requires

.PHONY : CMakeFiles/program_0.dir/requires

CMakeFiles/program_0.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/program_0.dir/cmake_clean.cmake
.PHONY : CMakeFiles/program_0.dir/clean

CMakeFiles/program_0.dir/depend:
	cd "/Users/Stefan_Xu/Desktop/Stefan/CSI3334/program 0/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/Stefan_Xu/Desktop/Stefan/CSI3334/program 0" "/Users/Stefan_Xu/Desktop/Stefan/CSI3334/program 0" "/Users/Stefan_Xu/Desktop/Stefan/CSI3334/program 0/cmake-build-debug" "/Users/Stefan_Xu/Desktop/Stefan/CSI3334/program 0/cmake-build-debug" "/Users/Stefan_Xu/Desktop/Stefan/CSI3334/program 0/cmake-build-debug/CMakeFiles/program_0.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/program_0.dir/depend

