# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/coriande/Desktop/3d_viewer/C8_3DViewer_v1.0-1/src/3d_viewer_my

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/coriande/Desktop/3d_viewer/C8_3DViewer_v1.0-1/src/build-3d_viewer_my-Desktop_x86_darwin_generic_mach_o_64bit-Debug

# Utility rule file for 3d_viewer_my_autogen.

# Include any custom commands dependencies for this target.
include CMakeFiles/3d_viewer_my_autogen.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/3d_viewer_my_autogen.dir/progress.make

CMakeFiles/3d_viewer_my_autogen:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/coriande/Desktop/3d_viewer/C8_3DViewer_v1.0-1/src/build-3d_viewer_my-Desktop_x86_darwin_generic_mach_o_64bit-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target 3d_viewer_my"
	/usr/local/bin/cmake -E cmake_autogen /Users/coriande/Desktop/3d_viewer/C8_3DViewer_v1.0-1/src/build-3d_viewer_my-Desktop_x86_darwin_generic_mach_o_64bit-Debug/CMakeFiles/3d_viewer_my_autogen.dir/AutogenInfo.json Debug

3d_viewer_my_autogen: CMakeFiles/3d_viewer_my_autogen
3d_viewer_my_autogen: CMakeFiles/3d_viewer_my_autogen.dir/build.make
.PHONY : 3d_viewer_my_autogen

# Rule to build all files generated by this target.
CMakeFiles/3d_viewer_my_autogen.dir/build: 3d_viewer_my_autogen
.PHONY : CMakeFiles/3d_viewer_my_autogen.dir/build

CMakeFiles/3d_viewer_my_autogen.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/3d_viewer_my_autogen.dir/cmake_clean.cmake
.PHONY : CMakeFiles/3d_viewer_my_autogen.dir/clean

CMakeFiles/3d_viewer_my_autogen.dir/depend:
	cd /Users/coriande/Desktop/3d_viewer/C8_3DViewer_v1.0-1/src/build-3d_viewer_my-Desktop_x86_darwin_generic_mach_o_64bit-Debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/coriande/Desktop/3d_viewer/C8_3DViewer_v1.0-1/src/3d_viewer_my /Users/coriande/Desktop/3d_viewer/C8_3DViewer_v1.0-1/src/3d_viewer_my /Users/coriande/Desktop/3d_viewer/C8_3DViewer_v1.0-1/src/build-3d_viewer_my-Desktop_x86_darwin_generic_mach_o_64bit-Debug /Users/coriande/Desktop/3d_viewer/C8_3DViewer_v1.0-1/src/build-3d_viewer_my-Desktop_x86_darwin_generic_mach_o_64bit-Debug /Users/coriande/Desktop/3d_viewer/C8_3DViewer_v1.0-1/src/build-3d_viewer_my-Desktop_x86_darwin_generic_mach_o_64bit-Debug/CMakeFiles/3d_viewer_my_autogen.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/3d_viewer_my_autogen.dir/depend

