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
include graphics/objects/CMakeFiles/uiObjects.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include graphics/objects/CMakeFiles/uiObjects.dir/compiler_depend.make

# Include the progress variables for this target.
include graphics/objects/CMakeFiles/uiObjects.dir/progress.make

# Include the compile flags for this target's objects.
include graphics/objects/CMakeFiles/uiObjects.dir/flags.make

graphics/objects/CMakeFiles/uiObjects.dir/UiObject.cpp.o: graphics/objects/CMakeFiles/uiObjects.dir/flags.make
graphics/objects/CMakeFiles/uiObjects.dir/UiObject.cpp.o: graphics/objects/UiObject.cpp
graphics/objects/CMakeFiles/uiObjects.dir/UiObject.cpp.o: graphics/objects/CMakeFiles/uiObjects.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/thorben/Dokumente/Development/ilc/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object graphics/objects/CMakeFiles/uiObjects.dir/UiObject.cpp.o"
	cd /home/thorben/Dokumente/Development/ilc/graphics/objects && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT graphics/objects/CMakeFiles/uiObjects.dir/UiObject.cpp.o -MF CMakeFiles/uiObjects.dir/UiObject.cpp.o.d -o CMakeFiles/uiObjects.dir/UiObject.cpp.o -c /home/thorben/Dokumente/Development/ilc/graphics/objects/UiObject.cpp

graphics/objects/CMakeFiles/uiObjects.dir/UiObject.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/uiObjects.dir/UiObject.cpp.i"
	cd /home/thorben/Dokumente/Development/ilc/graphics/objects && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/thorben/Dokumente/Development/ilc/graphics/objects/UiObject.cpp > CMakeFiles/uiObjects.dir/UiObject.cpp.i

graphics/objects/CMakeFiles/uiObjects.dir/UiObject.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/uiObjects.dir/UiObject.cpp.s"
	cd /home/thorben/Dokumente/Development/ilc/graphics/objects && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/thorben/Dokumente/Development/ilc/graphics/objects/UiObject.cpp -o CMakeFiles/uiObjects.dir/UiObject.cpp.s

graphics/objects/CMakeFiles/uiObjects.dir/Text.cpp.o: graphics/objects/CMakeFiles/uiObjects.dir/flags.make
graphics/objects/CMakeFiles/uiObjects.dir/Text.cpp.o: graphics/objects/Text.cpp
graphics/objects/CMakeFiles/uiObjects.dir/Text.cpp.o: graphics/objects/CMakeFiles/uiObjects.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/thorben/Dokumente/Development/ilc/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object graphics/objects/CMakeFiles/uiObjects.dir/Text.cpp.o"
	cd /home/thorben/Dokumente/Development/ilc/graphics/objects && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT graphics/objects/CMakeFiles/uiObjects.dir/Text.cpp.o -MF CMakeFiles/uiObjects.dir/Text.cpp.o.d -o CMakeFiles/uiObjects.dir/Text.cpp.o -c /home/thorben/Dokumente/Development/ilc/graphics/objects/Text.cpp

graphics/objects/CMakeFiles/uiObjects.dir/Text.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/uiObjects.dir/Text.cpp.i"
	cd /home/thorben/Dokumente/Development/ilc/graphics/objects && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/thorben/Dokumente/Development/ilc/graphics/objects/Text.cpp > CMakeFiles/uiObjects.dir/Text.cpp.i

graphics/objects/CMakeFiles/uiObjects.dir/Text.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/uiObjects.dir/Text.cpp.s"
	cd /home/thorben/Dokumente/Development/ilc/graphics/objects && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/thorben/Dokumente/Development/ilc/graphics/objects/Text.cpp -o CMakeFiles/uiObjects.dir/Text.cpp.s

graphics/objects/CMakeFiles/uiObjects.dir/DebugView.cpp.o: graphics/objects/CMakeFiles/uiObjects.dir/flags.make
graphics/objects/CMakeFiles/uiObjects.dir/DebugView.cpp.o: graphics/objects/DebugView.cpp
graphics/objects/CMakeFiles/uiObjects.dir/DebugView.cpp.o: graphics/objects/CMakeFiles/uiObjects.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/thorben/Dokumente/Development/ilc/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object graphics/objects/CMakeFiles/uiObjects.dir/DebugView.cpp.o"
	cd /home/thorben/Dokumente/Development/ilc/graphics/objects && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT graphics/objects/CMakeFiles/uiObjects.dir/DebugView.cpp.o -MF CMakeFiles/uiObjects.dir/DebugView.cpp.o.d -o CMakeFiles/uiObjects.dir/DebugView.cpp.o -c /home/thorben/Dokumente/Development/ilc/graphics/objects/DebugView.cpp

graphics/objects/CMakeFiles/uiObjects.dir/DebugView.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/uiObjects.dir/DebugView.cpp.i"
	cd /home/thorben/Dokumente/Development/ilc/graphics/objects && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/thorben/Dokumente/Development/ilc/graphics/objects/DebugView.cpp > CMakeFiles/uiObjects.dir/DebugView.cpp.i

graphics/objects/CMakeFiles/uiObjects.dir/DebugView.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/uiObjects.dir/DebugView.cpp.s"
	cd /home/thorben/Dokumente/Development/ilc/graphics/objects && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/thorben/Dokumente/Development/ilc/graphics/objects/DebugView.cpp -o CMakeFiles/uiObjects.dir/DebugView.cpp.s

graphics/objects/CMakeFiles/uiObjects.dir/Texture.cpp.o: graphics/objects/CMakeFiles/uiObjects.dir/flags.make
graphics/objects/CMakeFiles/uiObjects.dir/Texture.cpp.o: graphics/objects/Texture.cpp
graphics/objects/CMakeFiles/uiObjects.dir/Texture.cpp.o: graphics/objects/CMakeFiles/uiObjects.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/thorben/Dokumente/Development/ilc/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object graphics/objects/CMakeFiles/uiObjects.dir/Texture.cpp.o"
	cd /home/thorben/Dokumente/Development/ilc/graphics/objects && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT graphics/objects/CMakeFiles/uiObjects.dir/Texture.cpp.o -MF CMakeFiles/uiObjects.dir/Texture.cpp.o.d -o CMakeFiles/uiObjects.dir/Texture.cpp.o -c /home/thorben/Dokumente/Development/ilc/graphics/objects/Texture.cpp

graphics/objects/CMakeFiles/uiObjects.dir/Texture.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/uiObjects.dir/Texture.cpp.i"
	cd /home/thorben/Dokumente/Development/ilc/graphics/objects && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/thorben/Dokumente/Development/ilc/graphics/objects/Texture.cpp > CMakeFiles/uiObjects.dir/Texture.cpp.i

graphics/objects/CMakeFiles/uiObjects.dir/Texture.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/uiObjects.dir/Texture.cpp.s"
	cd /home/thorben/Dokumente/Development/ilc/graphics/objects && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/thorben/Dokumente/Development/ilc/graphics/objects/Texture.cpp -o CMakeFiles/uiObjects.dir/Texture.cpp.s

graphics/objects/CMakeFiles/uiObjects.dir/Grid.cpp.o: graphics/objects/CMakeFiles/uiObjects.dir/flags.make
graphics/objects/CMakeFiles/uiObjects.dir/Grid.cpp.o: graphics/objects/Grid.cpp
graphics/objects/CMakeFiles/uiObjects.dir/Grid.cpp.o: graphics/objects/CMakeFiles/uiObjects.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/thorben/Dokumente/Development/ilc/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object graphics/objects/CMakeFiles/uiObjects.dir/Grid.cpp.o"
	cd /home/thorben/Dokumente/Development/ilc/graphics/objects && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT graphics/objects/CMakeFiles/uiObjects.dir/Grid.cpp.o -MF CMakeFiles/uiObjects.dir/Grid.cpp.o.d -o CMakeFiles/uiObjects.dir/Grid.cpp.o -c /home/thorben/Dokumente/Development/ilc/graphics/objects/Grid.cpp

graphics/objects/CMakeFiles/uiObjects.dir/Grid.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/uiObjects.dir/Grid.cpp.i"
	cd /home/thorben/Dokumente/Development/ilc/graphics/objects && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/thorben/Dokumente/Development/ilc/graphics/objects/Grid.cpp > CMakeFiles/uiObjects.dir/Grid.cpp.i

graphics/objects/CMakeFiles/uiObjects.dir/Grid.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/uiObjects.dir/Grid.cpp.s"
	cd /home/thorben/Dokumente/Development/ilc/graphics/objects && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/thorben/Dokumente/Development/ilc/graphics/objects/Grid.cpp -o CMakeFiles/uiObjects.dir/Grid.cpp.s

graphics/objects/CMakeFiles/uiObjects.dir/GridElement.cpp.o: graphics/objects/CMakeFiles/uiObjects.dir/flags.make
graphics/objects/CMakeFiles/uiObjects.dir/GridElement.cpp.o: graphics/objects/GridElement.cpp
graphics/objects/CMakeFiles/uiObjects.dir/GridElement.cpp.o: graphics/objects/CMakeFiles/uiObjects.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/thorben/Dokumente/Development/ilc/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object graphics/objects/CMakeFiles/uiObjects.dir/GridElement.cpp.o"
	cd /home/thorben/Dokumente/Development/ilc/graphics/objects && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT graphics/objects/CMakeFiles/uiObjects.dir/GridElement.cpp.o -MF CMakeFiles/uiObjects.dir/GridElement.cpp.o.d -o CMakeFiles/uiObjects.dir/GridElement.cpp.o -c /home/thorben/Dokumente/Development/ilc/graphics/objects/GridElement.cpp

graphics/objects/CMakeFiles/uiObjects.dir/GridElement.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/uiObjects.dir/GridElement.cpp.i"
	cd /home/thorben/Dokumente/Development/ilc/graphics/objects && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/thorben/Dokumente/Development/ilc/graphics/objects/GridElement.cpp > CMakeFiles/uiObjects.dir/GridElement.cpp.i

graphics/objects/CMakeFiles/uiObjects.dir/GridElement.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/uiObjects.dir/GridElement.cpp.s"
	cd /home/thorben/Dokumente/Development/ilc/graphics/objects && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/thorben/Dokumente/Development/ilc/graphics/objects/GridElement.cpp -o CMakeFiles/uiObjects.dir/GridElement.cpp.s

graphics/objects/CMakeFiles/uiObjects.dir/Textbox.cpp.o: graphics/objects/CMakeFiles/uiObjects.dir/flags.make
graphics/objects/CMakeFiles/uiObjects.dir/Textbox.cpp.o: graphics/objects/Textbox.cpp
graphics/objects/CMakeFiles/uiObjects.dir/Textbox.cpp.o: graphics/objects/CMakeFiles/uiObjects.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/thorben/Dokumente/Development/ilc/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object graphics/objects/CMakeFiles/uiObjects.dir/Textbox.cpp.o"
	cd /home/thorben/Dokumente/Development/ilc/graphics/objects && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT graphics/objects/CMakeFiles/uiObjects.dir/Textbox.cpp.o -MF CMakeFiles/uiObjects.dir/Textbox.cpp.o.d -o CMakeFiles/uiObjects.dir/Textbox.cpp.o -c /home/thorben/Dokumente/Development/ilc/graphics/objects/Textbox.cpp

graphics/objects/CMakeFiles/uiObjects.dir/Textbox.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/uiObjects.dir/Textbox.cpp.i"
	cd /home/thorben/Dokumente/Development/ilc/graphics/objects && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/thorben/Dokumente/Development/ilc/graphics/objects/Textbox.cpp > CMakeFiles/uiObjects.dir/Textbox.cpp.i

graphics/objects/CMakeFiles/uiObjects.dir/Textbox.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/uiObjects.dir/Textbox.cpp.s"
	cd /home/thorben/Dokumente/Development/ilc/graphics/objects && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/thorben/Dokumente/Development/ilc/graphics/objects/Textbox.cpp -o CMakeFiles/uiObjects.dir/Textbox.cpp.s

# Object files for target uiObjects
uiObjects_OBJECTS = \
"CMakeFiles/uiObjects.dir/UiObject.cpp.o" \
"CMakeFiles/uiObjects.dir/Text.cpp.o" \
"CMakeFiles/uiObjects.dir/DebugView.cpp.o" \
"CMakeFiles/uiObjects.dir/Texture.cpp.o" \
"CMakeFiles/uiObjects.dir/Grid.cpp.o" \
"CMakeFiles/uiObjects.dir/GridElement.cpp.o" \
"CMakeFiles/uiObjects.dir/Textbox.cpp.o"

# External object files for target uiObjects
uiObjects_EXTERNAL_OBJECTS =

lib/libuiObjects.a: graphics/objects/CMakeFiles/uiObjects.dir/UiObject.cpp.o
lib/libuiObjects.a: graphics/objects/CMakeFiles/uiObjects.dir/Text.cpp.o
lib/libuiObjects.a: graphics/objects/CMakeFiles/uiObjects.dir/DebugView.cpp.o
lib/libuiObjects.a: graphics/objects/CMakeFiles/uiObjects.dir/Texture.cpp.o
lib/libuiObjects.a: graphics/objects/CMakeFiles/uiObjects.dir/Grid.cpp.o
lib/libuiObjects.a: graphics/objects/CMakeFiles/uiObjects.dir/GridElement.cpp.o
lib/libuiObjects.a: graphics/objects/CMakeFiles/uiObjects.dir/Textbox.cpp.o
lib/libuiObjects.a: graphics/objects/CMakeFiles/uiObjects.dir/build.make
lib/libuiObjects.a: graphics/objects/CMakeFiles/uiObjects.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/thorben/Dokumente/Development/ilc/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX static library ../../lib/libuiObjects.a"
	cd /home/thorben/Dokumente/Development/ilc/graphics/objects && $(CMAKE_COMMAND) -P CMakeFiles/uiObjects.dir/cmake_clean_target.cmake
	cd /home/thorben/Dokumente/Development/ilc/graphics/objects && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/uiObjects.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
graphics/objects/CMakeFiles/uiObjects.dir/build: lib/libuiObjects.a
.PHONY : graphics/objects/CMakeFiles/uiObjects.dir/build

graphics/objects/CMakeFiles/uiObjects.dir/clean:
	cd /home/thorben/Dokumente/Development/ilc/graphics/objects && $(CMAKE_COMMAND) -P CMakeFiles/uiObjects.dir/cmake_clean.cmake
.PHONY : graphics/objects/CMakeFiles/uiObjects.dir/clean

graphics/objects/CMakeFiles/uiObjects.dir/depend:
	cd /home/thorben/Dokumente/Development/ilc && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/thorben/Dokumente/Development/ilc /home/thorben/Dokumente/Development/ilc/graphics/objects /home/thorben/Dokumente/Development/ilc /home/thorben/Dokumente/Development/ilc/graphics/objects /home/thorben/Dokumente/Development/ilc/graphics/objects/CMakeFiles/uiObjects.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : graphics/objects/CMakeFiles/uiObjects.dir/depend
