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
CMAKE_SOURCE_DIR = /Users/maksimkuznetsov/Documents/misis2024f-24-01-kuznetsov-m-a

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/maksimkuznetsov/Documents/misis2024f-24-01-kuznetsov-m-a/build

# Include any dependencies generated for this target.
include prj.codeforces/CMakeFiles/0978a.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include prj.codeforces/CMakeFiles/0978a.dir/compiler_depend.make

# Include the progress variables for this target.
include prj.codeforces/CMakeFiles/0978a.dir/progress.make

# Include the compile flags for this target's objects.
include prj.codeforces/CMakeFiles/0978a.dir/flags.make

prj.codeforces/CMakeFiles/0978a.dir/codegen:
.PHONY : prj.codeforces/CMakeFiles/0978a.dir/codegen

prj.codeforces/CMakeFiles/0978a.dir/0978a.cpp.o: prj.codeforces/CMakeFiles/0978a.dir/flags.make
prj.codeforces/CMakeFiles/0978a.dir/0978a.cpp.o: /Users/maksimkuznetsov/Documents/misis2024f-24-01-kuznetsov-m-a/prj.codeforces/0978a.cpp
prj.codeforces/CMakeFiles/0978a.dir/0978a.cpp.o: prj.codeforces/CMakeFiles/0978a.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/maksimkuznetsov/Documents/misis2024f-24-01-kuznetsov-m-a/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object prj.codeforces/CMakeFiles/0978a.dir/0978a.cpp.o"
	cd /Users/maksimkuznetsov/Documents/misis2024f-24-01-kuznetsov-m-a/build/prj.codeforces && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT prj.codeforces/CMakeFiles/0978a.dir/0978a.cpp.o -MF CMakeFiles/0978a.dir/0978a.cpp.o.d -o CMakeFiles/0978a.dir/0978a.cpp.o -c /Users/maksimkuznetsov/Documents/misis2024f-24-01-kuznetsov-m-a/prj.codeforces/0978a.cpp

prj.codeforces/CMakeFiles/0978a.dir/0978a.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/0978a.dir/0978a.cpp.i"
	cd /Users/maksimkuznetsov/Documents/misis2024f-24-01-kuznetsov-m-a/build/prj.codeforces && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/maksimkuznetsov/Documents/misis2024f-24-01-kuznetsov-m-a/prj.codeforces/0978a.cpp > CMakeFiles/0978a.dir/0978a.cpp.i

prj.codeforces/CMakeFiles/0978a.dir/0978a.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/0978a.dir/0978a.cpp.s"
	cd /Users/maksimkuznetsov/Documents/misis2024f-24-01-kuznetsov-m-a/build/prj.codeforces && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/maksimkuznetsov/Documents/misis2024f-24-01-kuznetsov-m-a/prj.codeforces/0978a.cpp -o CMakeFiles/0978a.dir/0978a.cpp.s

# Object files for target 0978a
0978a_OBJECTS = \
"CMakeFiles/0978a.dir/0978a.cpp.o"

# External object files for target 0978a
0978a_EXTERNAL_OBJECTS =

/Users/maksimkuznetsov/Documents/misis2024f-24-01-kuznetsov-m-a/bin/0978a: prj.codeforces/CMakeFiles/0978a.dir/0978a.cpp.o
/Users/maksimkuznetsov/Documents/misis2024f-24-01-kuznetsov-m-a/bin/0978a: prj.codeforces/CMakeFiles/0978a.dir/build.make
/Users/maksimkuznetsov/Documents/misis2024f-24-01-kuznetsov-m-a/bin/0978a: prj.codeforces/CMakeFiles/0978a.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/maksimkuznetsov/Documents/misis2024f-24-01-kuznetsov-m-a/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable /Users/maksimkuznetsov/Documents/misis2024f-24-01-kuznetsov-m-a/bin/0978a"
	cd /Users/maksimkuznetsov/Documents/misis2024f-24-01-kuznetsov-m-a/build/prj.codeforces && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/0978a.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
prj.codeforces/CMakeFiles/0978a.dir/build: /Users/maksimkuznetsov/Documents/misis2024f-24-01-kuznetsov-m-a/bin/0978a
.PHONY : prj.codeforces/CMakeFiles/0978a.dir/build

prj.codeforces/CMakeFiles/0978a.dir/clean:
	cd /Users/maksimkuznetsov/Documents/misis2024f-24-01-kuznetsov-m-a/build/prj.codeforces && $(CMAKE_COMMAND) -P CMakeFiles/0978a.dir/cmake_clean.cmake
.PHONY : prj.codeforces/CMakeFiles/0978a.dir/clean

prj.codeforces/CMakeFiles/0978a.dir/depend:
	cd /Users/maksimkuznetsov/Documents/misis2024f-24-01-kuznetsov-m-a/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/maksimkuznetsov/Documents/misis2024f-24-01-kuznetsov-m-a /Users/maksimkuznetsov/Documents/misis2024f-24-01-kuznetsov-m-a/prj.codeforces /Users/maksimkuznetsov/Documents/misis2024f-24-01-kuznetsov-m-a/build /Users/maksimkuznetsov/Documents/misis2024f-24-01-kuznetsov-m-a/build/prj.codeforces /Users/maksimkuznetsov/Documents/misis2024f-24-01-kuznetsov-m-a/build/prj.codeforces/CMakeFiles/0978a.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : prj.codeforces/CMakeFiles/0978a.dir/depend

