# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.21

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.21.4/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.21.4/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/sergey/Documents/BonchTeOfPro/Lab-4

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/sergey/Documents/BonchTeOfPro/Lab-4/build

# Include any dependencies generated for this target.
include CMakeFiles/lab4.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/lab4.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/lab4.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lab4.dir/flags.make

CMakeFiles/lab4.dir/lib/main.cpp.o: CMakeFiles/lab4.dir/flags.make
CMakeFiles/lab4.dir/lib/main.cpp.o: ../lib/main.cpp
CMakeFiles/lab4.dir/lib/main.cpp.o: CMakeFiles/lab4.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/sergey/Documents/BonchTeOfPro/Lab-4/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/lab4.dir/lib/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/lab4.dir/lib/main.cpp.o -MF CMakeFiles/lab4.dir/lib/main.cpp.o.d -o CMakeFiles/lab4.dir/lib/main.cpp.o -c /Users/sergey/Documents/BonchTeOfPro/Lab-4/lib/main.cpp

CMakeFiles/lab4.dir/lib/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab4.dir/lib/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/sergey/Documents/BonchTeOfPro/Lab-4/lib/main.cpp > CMakeFiles/lab4.dir/lib/main.cpp.i

CMakeFiles/lab4.dir/lib/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab4.dir/lib/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/sergey/Documents/BonchTeOfPro/Lab-4/lib/main.cpp -o CMakeFiles/lab4.dir/lib/main.cpp.s

CMakeFiles/lab4.dir/lib/sources/Vehicle.cpp.o: CMakeFiles/lab4.dir/flags.make
CMakeFiles/lab4.dir/lib/sources/Vehicle.cpp.o: ../lib/sources/Vehicle.cpp
CMakeFiles/lab4.dir/lib/sources/Vehicle.cpp.o: CMakeFiles/lab4.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/sergey/Documents/BonchTeOfPro/Lab-4/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/lab4.dir/lib/sources/Vehicle.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/lab4.dir/lib/sources/Vehicle.cpp.o -MF CMakeFiles/lab4.dir/lib/sources/Vehicle.cpp.o.d -o CMakeFiles/lab4.dir/lib/sources/Vehicle.cpp.o -c /Users/sergey/Documents/BonchTeOfPro/Lab-4/lib/sources/Vehicle.cpp

CMakeFiles/lab4.dir/lib/sources/Vehicle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab4.dir/lib/sources/Vehicle.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/sergey/Documents/BonchTeOfPro/Lab-4/lib/sources/Vehicle.cpp > CMakeFiles/lab4.dir/lib/sources/Vehicle.cpp.i

CMakeFiles/lab4.dir/lib/sources/Vehicle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab4.dir/lib/sources/Vehicle.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/sergey/Documents/BonchTeOfPro/Lab-4/lib/sources/Vehicle.cpp -o CMakeFiles/lab4.dir/lib/sources/Vehicle.cpp.s

CMakeFiles/lab4.dir/lib/sources/Car.cpp.o: CMakeFiles/lab4.dir/flags.make
CMakeFiles/lab4.dir/lib/sources/Car.cpp.o: ../lib/sources/Car.cpp
CMakeFiles/lab4.dir/lib/sources/Car.cpp.o: CMakeFiles/lab4.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/sergey/Documents/BonchTeOfPro/Lab-4/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/lab4.dir/lib/sources/Car.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/lab4.dir/lib/sources/Car.cpp.o -MF CMakeFiles/lab4.dir/lib/sources/Car.cpp.o.d -o CMakeFiles/lab4.dir/lib/sources/Car.cpp.o -c /Users/sergey/Documents/BonchTeOfPro/Lab-4/lib/sources/Car.cpp

CMakeFiles/lab4.dir/lib/sources/Car.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab4.dir/lib/sources/Car.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/sergey/Documents/BonchTeOfPro/Lab-4/lib/sources/Car.cpp > CMakeFiles/lab4.dir/lib/sources/Car.cpp.i

CMakeFiles/lab4.dir/lib/sources/Car.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab4.dir/lib/sources/Car.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/sergey/Documents/BonchTeOfPro/Lab-4/lib/sources/Car.cpp -o CMakeFiles/lab4.dir/lib/sources/Car.cpp.s

CMakeFiles/lab4.dir/lib/sources/Plane.cpp.o: CMakeFiles/lab4.dir/flags.make
CMakeFiles/lab4.dir/lib/sources/Plane.cpp.o: ../lib/sources/Plane.cpp
CMakeFiles/lab4.dir/lib/sources/Plane.cpp.o: CMakeFiles/lab4.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/sergey/Documents/BonchTeOfPro/Lab-4/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/lab4.dir/lib/sources/Plane.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/lab4.dir/lib/sources/Plane.cpp.o -MF CMakeFiles/lab4.dir/lib/sources/Plane.cpp.o.d -o CMakeFiles/lab4.dir/lib/sources/Plane.cpp.o -c /Users/sergey/Documents/BonchTeOfPro/Lab-4/lib/sources/Plane.cpp

CMakeFiles/lab4.dir/lib/sources/Plane.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab4.dir/lib/sources/Plane.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/sergey/Documents/BonchTeOfPro/Lab-4/lib/sources/Plane.cpp > CMakeFiles/lab4.dir/lib/sources/Plane.cpp.i

CMakeFiles/lab4.dir/lib/sources/Plane.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab4.dir/lib/sources/Plane.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/sergey/Documents/BonchTeOfPro/Lab-4/lib/sources/Plane.cpp -o CMakeFiles/lab4.dir/lib/sources/Plane.cpp.s

# Object files for target lab4
lab4_OBJECTS = \
"CMakeFiles/lab4.dir/lib/main.cpp.o" \
"CMakeFiles/lab4.dir/lib/sources/Vehicle.cpp.o" \
"CMakeFiles/lab4.dir/lib/sources/Car.cpp.o" \
"CMakeFiles/lab4.dir/lib/sources/Plane.cpp.o"

# External object files for target lab4
lab4_EXTERNAL_OBJECTS =

lab4: CMakeFiles/lab4.dir/lib/main.cpp.o
lab4: CMakeFiles/lab4.dir/lib/sources/Vehicle.cpp.o
lab4: CMakeFiles/lab4.dir/lib/sources/Car.cpp.o
lab4: CMakeFiles/lab4.dir/lib/sources/Plane.cpp.o
lab4: CMakeFiles/lab4.dir/build.make
lab4: CMakeFiles/lab4.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/sergey/Documents/BonchTeOfPro/Lab-4/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable lab4"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lab4.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lab4.dir/build: lab4
.PHONY : CMakeFiles/lab4.dir/build

CMakeFiles/lab4.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lab4.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lab4.dir/clean

CMakeFiles/lab4.dir/depend:
	cd /Users/sergey/Documents/BonchTeOfPro/Lab-4/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/sergey/Documents/BonchTeOfPro/Lab-4 /Users/sergey/Documents/BonchTeOfPro/Lab-4 /Users/sergey/Documents/BonchTeOfPro/Lab-4/build /Users/sergey/Documents/BonchTeOfPro/Lab-4/build /Users/sergey/Documents/BonchTeOfPro/Lab-4/build/CMakeFiles/lab4.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lab4.dir/depend

