# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.10

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2018.1.2\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2018.1.2\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\Desktop\TestAVC

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Desktop\TestAVC\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/TestAVC.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/TestAVC.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TestAVC.dir/flags.make

CMakeFiles/TestAVC.dir/main.cpp.obj: CMakeFiles/TestAVC.dir/flags.make
CMakeFiles/TestAVC.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Desktop\TestAVC\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/TestAVC.dir/main.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-7~1.0-P\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\TestAVC.dir\main.cpp.obj -c D:\Desktop\TestAVC\main.cpp

CMakeFiles/TestAVC.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TestAVC.dir/main.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-7~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Desktop\TestAVC\main.cpp > CMakeFiles\TestAVC.dir\main.cpp.i

CMakeFiles/TestAVC.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TestAVC.dir/main.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-7~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Desktop\TestAVC\main.cpp -o CMakeFiles\TestAVC.dir\main.cpp.s

CMakeFiles/TestAVC.dir/main.cpp.obj.requires:

.PHONY : CMakeFiles/TestAVC.dir/main.cpp.obj.requires

CMakeFiles/TestAVC.dir/main.cpp.obj.provides: CMakeFiles/TestAVC.dir/main.cpp.obj.requires
	$(MAKE) -f CMakeFiles\TestAVC.dir\build.make CMakeFiles/TestAVC.dir/main.cpp.obj.provides.build
.PHONY : CMakeFiles/TestAVC.dir/main.cpp.obj.provides

CMakeFiles/TestAVC.dir/main.cpp.obj.provides.build: CMakeFiles/TestAVC.dir/main.cpp.obj


# Object files for target TestAVC
TestAVC_OBJECTS = \
"CMakeFiles/TestAVC.dir/main.cpp.obj"

# External object files for target TestAVC
TestAVC_EXTERNAL_OBJECTS =

TestAVC.exe: CMakeFiles/TestAVC.dir/main.cpp.obj
TestAVC.exe: CMakeFiles/TestAVC.dir/build.make
TestAVC.exe: CMakeFiles/TestAVC.dir/linklibs.rsp
TestAVC.exe: CMakeFiles/TestAVC.dir/objects1.rsp
TestAVC.exe: CMakeFiles/TestAVC.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\Desktop\TestAVC\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable TestAVC.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\TestAVC.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TestAVC.dir/build: TestAVC.exe

.PHONY : CMakeFiles/TestAVC.dir/build

CMakeFiles/TestAVC.dir/requires: CMakeFiles/TestAVC.dir/main.cpp.obj.requires

.PHONY : CMakeFiles/TestAVC.dir/requires

CMakeFiles/TestAVC.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\TestAVC.dir\cmake_clean.cmake
.PHONY : CMakeFiles/TestAVC.dir/clean

CMakeFiles/TestAVC.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Desktop\TestAVC D:\Desktop\TestAVC D:\Desktop\TestAVC\cmake-build-debug D:\Desktop\TestAVC\cmake-build-debug D:\Desktop\TestAVC\cmake-build-debug\CMakeFiles\TestAVC.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/TestAVC.dir/depend
