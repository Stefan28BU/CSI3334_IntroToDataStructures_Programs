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
CMAKE_SOURCE_DIR = /Users/Stefan_Xu/Desktop/Stefan/CSI3334/pj5

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/Stefan_Xu/Desktop/Stefan/CSI3334/pj5/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/pj5.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/pj5.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/pj5.dir/flags.make

CMakeFiles/pj5.dir/main.cpp.o: CMakeFiles/pj5.dir/flags.make
CMakeFiles/pj5.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Stefan_Xu/Desktop/Stefan/CSI3334/pj5/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/pj5.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pj5.dir/main.cpp.o -c /Users/Stefan_Xu/Desktop/Stefan/CSI3334/pj5/main.cpp

CMakeFiles/pj5.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pj5.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/Stefan_Xu/Desktop/Stefan/CSI3334/pj5/main.cpp > CMakeFiles/pj5.dir/main.cpp.i

CMakeFiles/pj5.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pj5.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/Stefan_Xu/Desktop/Stefan/CSI3334/pj5/main.cpp -o CMakeFiles/pj5.dir/main.cpp.s

CMakeFiles/pj5.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/pj5.dir/main.cpp.o.requires

CMakeFiles/pj5.dir/main.cpp.o.provides: CMakeFiles/pj5.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/pj5.dir/build.make CMakeFiles/pj5.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/pj5.dir/main.cpp.o.provides

CMakeFiles/pj5.dir/main.cpp.o.provides.build: CMakeFiles/pj5.dir/main.cpp.o


# Object files for target pj5
pj5_OBJECTS = \
"CMakeFiles/pj5.dir/main.cpp.o"

# External object files for target pj5
pj5_EXTERNAL_OBJECTS =

pj5: CMakeFiles/pj5.dir/main.cpp.o
pj5: CMakeFiles/pj5.dir/build.make
pj5: CMakeFiles/pj5.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/Stefan_Xu/Desktop/Stefan/CSI3334/pj5/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable pj5"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pj5.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/pj5.dir/build: pj5

.PHONY : CMakeFiles/pj5.dir/build

CMakeFiles/pj5.dir/requires: CMakeFiles/pj5.dir/main.cpp.o.requires

.PHONY : CMakeFiles/pj5.dir/requires

CMakeFiles/pj5.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/pj5.dir/cmake_clean.cmake
.PHONY : CMakeFiles/pj5.dir/clean

CMakeFiles/pj5.dir/depend:
	cd /Users/Stefan_Xu/Desktop/Stefan/CSI3334/pj5/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/Stefan_Xu/Desktop/Stefan/CSI3334/pj5 /Users/Stefan_Xu/Desktop/Stefan/CSI3334/pj5 /Users/Stefan_Xu/Desktop/Stefan/CSI3334/pj5/cmake-build-debug /Users/Stefan_Xu/Desktop/Stefan/CSI3334/pj5/cmake-build-debug /Users/Stefan_Xu/Desktop/Stefan/CSI3334/pj5/cmake-build-debug/CMakeFiles/pj5.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/pj5.dir/depend
