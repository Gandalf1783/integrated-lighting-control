# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/thorben/Dokumente/Development/ilc

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/thorben/Dokumente/Development/ilc

# Include any dependencies generated for this target.
include graphics/CMakeFiles/ui.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include graphics/CMakeFiles/ui.dir/compiler_depend.make

# Include the progress variables for this target.
include graphics/CMakeFiles/ui.dir/progress.make

# Include the compile flags for this target's objects.
include graphics/CMakeFiles/ui.dir/flags.make

graphics/CMakeFiles/ui.dir/UI.cpp.o: graphics/CMakeFiles/ui.dir/flags.make
graphics/CMakeFiles/ui.dir/UI.cpp.o: graphics/UI.cpp
graphics/CMakeFiles/ui.dir/UI.cpp.o: graphics/CMakeFiles/ui.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/thorben/Dokumente/Development/ilc/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object graphics/CMakeFiles/ui.dir/UI.cpp.o"
	cd /home/thorben/Dokumente/Development/ilc/graphics && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT graphics/CMakeFiles/ui.dir/UI.cpp.o -MF CMakeFiles/ui.dir/UI.cpp.o.d -o CMakeFiles/ui.dir/UI.cpp.o -c /home/thorben/Dokumente/Development/ilc/graphics/UI.cpp

graphics/CMakeFiles/ui.dir/UI.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/ui.dir/UI.cpp.i"
	cd /home/thorben/Dokumente/Development/ilc/graphics && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/thorben/Dokumente/Development/ilc/graphics/UI.cpp > CMakeFiles/ui.dir/UI.cpp.i

graphics/CMakeFiles/ui.dir/UI.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/ui.dir/UI.cpp.s"
	cd /home/thorben/Dokumente/Development/ilc/graphics && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/thorben/Dokumente/Development/ilc/graphics/UI.cpp -o CMakeFiles/ui.dir/UI.cpp.s

graphics/CMakeFiles/ui.dir/Display.cpp.o: graphics/CMakeFiles/ui.dir/flags.make
graphics/CMakeFiles/ui.dir/Display.cpp.o: graphics/Display.cpp
graphics/CMakeFiles/ui.dir/Display.cpp.o: graphics/CMakeFiles/ui.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/thorben/Dokumente/Development/ilc/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object graphics/CMakeFiles/ui.dir/Display.cpp.o"
	cd /home/thorben/Dokumente/Development/ilc/graphics && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT graphics/CMakeFiles/ui.dir/Display.cpp.o -MF CMakeFiles/ui.dir/Display.cpp.o.d -o CMakeFiles/ui.dir/Display.cpp.o -c /home/thorben/Dokumente/Development/ilc/graphics/Display.cpp

graphics/CMakeFiles/ui.dir/Display.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/ui.dir/Display.cpp.i"
	cd /home/thorben/Dokumente/Development/ilc/graphics && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/thorben/Dokumente/Development/ilc/graphics/Display.cpp > CMakeFiles/ui.dir/Display.cpp.i

graphics/CMakeFiles/ui.dir/Display.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/ui.dir/Display.cpp.s"
	cd /home/thorben/Dokumente/Development/ilc/graphics && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/thorben/Dokumente/Development/ilc/graphics/Display.cpp -o CMakeFiles/ui.dir/Display.cpp.s

# Object files for target ui
ui_OBJECTS = \
"CMakeFiles/ui.dir/UI.cpp.o" \
"CMakeFiles/ui.dir/Display.cpp.o"

# External object files for target ui
ui_EXTERNAL_OBJECTS =

lib/libui.a: graphics/CMakeFiles/ui.dir/UI.cpp.o
lib/libui.a: graphics/CMakeFiles/ui.dir/Display.cpp.o
lib/libui.a: graphics/CMakeFiles/ui.dir/build.make
lib/libui.a: graphics/CMakeFiles/ui.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/thorben/Dokumente/Development/ilc/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library ../lib/libui.a"
	cd /home/thorben/Dokumente/Development/ilc/graphics && $(CMAKE_COMMAND) -P CMakeFiles/ui.dir/cmake_clean_target.cmake
	cd /home/thorben/Dokumente/Development/ilc/graphics && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ui.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
graphics/CMakeFiles/ui.dir/build: lib/libui.a
.PHONY : graphics/CMakeFiles/ui.dir/build

graphics/CMakeFiles/ui.dir/clean:
	cd /home/thorben/Dokumente/Development/ilc/graphics && $(CMAKE_COMMAND) -P CMakeFiles/ui.dir/cmake_clean.cmake
.PHONY : graphics/CMakeFiles/ui.dir/clean

graphics/CMakeFiles/ui.dir/depend:
	cd /home/thorben/Dokumente/Development/ilc && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/thorben/Dokumente/Development/ilc /home/thorben/Dokumente/Development/ilc/graphics /home/thorben/Dokumente/Development/ilc /home/thorben/Dokumente/Development/ilc/graphics /home/thorben/Dokumente/Development/ilc/graphics/CMakeFiles/ui.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : graphics/CMakeFiles/ui.dir/depend

