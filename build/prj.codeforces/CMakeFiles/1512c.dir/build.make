# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.31

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
CMAKE_COMMAND = /Applications/CMake.app/Contents/bin/cmake

# The command to remove a file.
RM = /Applications/CMake.app/Contents/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/maksimkuznetsov/Documents/misis2024f-24-01-kuznetsov-m-a-1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/maksimkuznetsov/Documents/misis2024f-24-01-kuznetsov-m-a-1/build

# Include any dependencies generated for this target.
include prj.codeforces/CMakeFiles/1512c.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include prj.codeforces/CMakeFiles/1512c.dir/compiler_depend.make

# Include the progress variables for this target.
include prj.codeforces/CMakeFiles/1512c.dir/progress.make

# Include the compile flags for this target's objects.
include prj.codeforces/CMakeFiles/1512c.dir/flags.make

prj.codeforces/CMakeFiles/1512c.dir/codegen:
.PHONY : prj.codeforces/CMakeFiles/1512c.dir/codegen

prj.codeforces/CMakeFiles/1512c.dir/1512c.cpp.o: prj.codeforces/CMakeFiles/1512c.dir/flags.make
prj.codeforces/CMakeFiles/1512c.dir/1512c.cpp.o: /Users/maksimkuznetsov/Documents/misis2024f-24-01-kuznetsov-m-a-1/prj.codeforces/1512c.cpp
prj.codeforces/CMakeFiles/1512c.dir/1512c.cpp.o: prj.codeforces/CMakeFiles/1512c.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/maksimkuznetsov/Documents/misis2024f-24-01-kuznetsov-m-a-1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object prj.codeforces/CMakeFiles/1512c.dir/1512c.cpp.o"
	cd /Users/maksimkuznetsov/Documents/misis2024f-24-01-kuznetsov-m-a-1/build/prj.codeforces && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT prj.codeforces/CMakeFiles/1512c.dir/1512c.cpp.o -MF CMakeFiles/1512c.dir/1512c.cpp.o.d -o CMakeFiles/1512c.dir/1512c.cpp.o -c /Users/maksimkuznetsov/Documents/misis2024f-24-01-kuznetsov-m-a-1/prj.codeforces/1512c.cpp

prj.codeforces/CMakeFiles/1512c.dir/1512c.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/1512c.dir/1512c.cpp.i"
	cd /Users/maksimkuznetsov/Documents/misis2024f-24-01-kuznetsov-m-a-1/build/prj.codeforces && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/maksimkuznetsov/Documents/misis2024f-24-01-kuznetsov-m-a-1/prj.codeforces/1512c.cpp > CMakeFiles/1512c.dir/1512c.cpp.i

prj.codeforces/CMakeFiles/1512c.dir/1512c.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/1512c.dir/1512c.cpp.s"
	cd /Users/maksimkuznetsov/Documents/misis2024f-24-01-kuznetsov-m-a-1/build/prj.codeforces && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/maksimkuznetsov/Documents/misis2024f-24-01-kuznetsov-m-a-1/prj.codeforces/1512c.cpp -o CMakeFiles/1512c.dir/1512c.cpp.s

# Object files for target 1512c
1512c_OBJECTS = \
"CMakeFiles/1512c.dir/1512c.cpp.o"

# External object files for target 1512c
1512c_EXTERNAL_OBJECTS =

/Users/maksimkuznetsov/Documents/misis2024f-24-01-kuznetsov-m-a-1/bin/1512c: prj.codeforces/CMakeFiles/1512c.dir/1512c.cpp.o
/Users/maksimkuznetsov/Documents/misis2024f-24-01-kuznetsov-m-a-1/bin/1512c: prj.codeforces/CMakeFiles/1512c.dir/build.make
/Users/maksimkuznetsov/Documents/misis2024f-24-01-kuznetsov-m-a-1/bin/1512c: prj.codeforces/CMakeFiles/1512c.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/maksimkuznetsov/Documents/misis2024f-24-01-kuznetsov-m-a-1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable /Users/maksimkuznetsov/Documents/misis2024f-24-01-kuznetsov-m-a-1/bin/1512c"
	cd /Users/maksimkuznetsov/Documents/misis2024f-24-01-kuznetsov-m-a-1/build/prj.codeforces && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/1512c.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
prj.codeforces/CMakeFiles/1512c.dir/build: /Users/maksimkuznetsov/Documents/misis2024f-24-01-kuznetsov-m-a-1/bin/1512c
.PHONY : prj.codeforces/CMakeFiles/1512c.dir/build

prj.codeforces/CMakeFiles/1512c.dir/clean:
	cd /Users/maksimkuznetsov/Documents/misis2024f-24-01-kuznetsov-m-a-1/build/prj.codeforces && $(CMAKE_COMMAND) -P CMakeFiles/1512c.dir/cmake_clean.cmake
.PHONY : prj.codeforces/CMakeFiles/1512c.dir/clean

prj.codeforces/CMakeFiles/1512c.dir/depend:
	cd /Users/maksimkuznetsov/Documents/misis2024f-24-01-kuznetsov-m-a-1/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/maksimkuznetsov/Documents/misis2024f-24-01-kuznetsov-m-a-1 /Users/maksimkuznetsov/Documents/misis2024f-24-01-kuznetsov-m-a-1/prj.codeforces /Users/maksimkuznetsov/Documents/misis2024f-24-01-kuznetsov-m-a-1/build /Users/maksimkuznetsov/Documents/misis2024f-24-01-kuznetsov-m-a-1/build/prj.codeforces /Users/maksimkuznetsov/Documents/misis2024f-24-01-kuznetsov-m-a-1/build/prj.codeforces/CMakeFiles/1512c.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : prj.codeforces/CMakeFiles/1512c.dir/depend

