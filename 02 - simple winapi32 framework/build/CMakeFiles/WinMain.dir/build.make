# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.23

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\Lukasz Tenerowicz\Desktop\DirectX\02 - simple winapi32 framework"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\Lukasz Tenerowicz\Desktop\DirectX\02 - simple winapi32 framework\build"

# Include any dependencies generated for this target.
include CMakeFiles/WinMain.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/WinMain.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/WinMain.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/WinMain.dir/flags.make

CMakeFiles/WinMain.dir/src/WinMain.cpp.obj: CMakeFiles/WinMain.dir/flags.make
CMakeFiles/WinMain.dir/src/WinMain.cpp.obj: CMakeFiles/WinMain.dir/includes_CXX.rsp
CMakeFiles/WinMain.dir/src/WinMain.cpp.obj: ../src/WinMain.cpp
CMakeFiles/WinMain.dir/src/WinMain.cpp.obj: CMakeFiles/WinMain.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Lukasz Tenerowicz\Desktop\DirectX\02 - simple winapi32 framework\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/WinMain.dir/src/WinMain.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\X86_64~2.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/WinMain.dir/src/WinMain.cpp.obj -MF CMakeFiles\WinMain.dir\src\WinMain.cpp.obj.d -o CMakeFiles\WinMain.dir\src\WinMain.cpp.obj -c "C:\Users\Lukasz Tenerowicz\Desktop\DirectX\02 - simple winapi32 framework\src\WinMain.cpp"

CMakeFiles/WinMain.dir/src/WinMain.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WinMain.dir/src/WinMain.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\X86_64~2.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Lukasz Tenerowicz\Desktop\DirectX\02 - simple winapi32 framework\src\WinMain.cpp" > CMakeFiles\WinMain.dir\src\WinMain.cpp.i

CMakeFiles/WinMain.dir/src/WinMain.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WinMain.dir/src/WinMain.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\X86_64~2.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Lukasz Tenerowicz\Desktop\DirectX\02 - simple winapi32 framework\src\WinMain.cpp" -o CMakeFiles\WinMain.dir\src\WinMain.cpp.s

# Object files for target WinMain
WinMain_OBJECTS = \
"CMakeFiles/WinMain.dir/src/WinMain.cpp.obj"

# External object files for target WinMain
WinMain_EXTERNAL_OBJECTS =

../bin/WinMain.exe: CMakeFiles/WinMain.dir/src/WinMain.cpp.obj
../bin/WinMain.exe: CMakeFiles/WinMain.dir/build.make
../bin/WinMain.exe: CMakeFiles/WinMain.dir/linklibs.rsp
../bin/WinMain.exe: CMakeFiles/WinMain.dir/objects1.rsp
../bin/WinMain.exe: CMakeFiles/WinMain.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\Lukasz Tenerowicz\Desktop\DirectX\02 - simple winapi32 framework\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ..\bin\WinMain.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\WinMain.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/WinMain.dir/build: ../bin/WinMain.exe
.PHONY : CMakeFiles/WinMain.dir/build

CMakeFiles/WinMain.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\WinMain.dir\cmake_clean.cmake
.PHONY : CMakeFiles/WinMain.dir/clean

CMakeFiles/WinMain.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\Lukasz Tenerowicz\Desktop\DirectX\02 - simple winapi32 framework" "C:\Users\Lukasz Tenerowicz\Desktop\DirectX\02 - simple winapi32 framework" "C:\Users\Lukasz Tenerowicz\Desktop\DirectX\02 - simple winapi32 framework\build" "C:\Users\Lukasz Tenerowicz\Desktop\DirectX\02 - simple winapi32 framework\build" "C:\Users\Lukasz Tenerowicz\Desktop\DirectX\02 - simple winapi32 framework\build\CMakeFiles\WinMain.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/WinMain.dir/depend

