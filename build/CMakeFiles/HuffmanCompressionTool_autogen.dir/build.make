# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.31

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
CMAKE_COMMAND = "D:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "D:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\HuffmanCompressionTool

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\HuffmanCompressionTool\build

# Utility rule file for HuffmanCompressionTool_autogen.

# Include any custom commands dependencies for this target.
include CMakeFiles/HuffmanCompressionTool_autogen.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/HuffmanCompressionTool_autogen.dir/progress.make

CMakeFiles/HuffmanCompressionTool_autogen: HuffmanCompressionTool_autogen/timestamp

HuffmanCompressionTool_autogen/timestamp: D:/qt/6.5.3/mingw_64/./bin/moc.exe
HuffmanCompressionTool_autogen/timestamp: CMakeFiles/HuffmanCompressionTool_autogen.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=D:\HuffmanCompressionTool\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC for target HuffmanCompressionTool"
	"D:\Program Files\CMake\bin\cmake.exe" -E cmake_autogen D:/HuffmanCompressionTool/build/CMakeFiles/HuffmanCompressionTool_autogen.dir/AutogenInfo.json ""
	"D:\Program Files\CMake\bin\cmake.exe" -E touch D:/HuffmanCompressionTool/build/HuffmanCompressionTool_autogen/timestamp

CMakeFiles/HuffmanCompressionTool_autogen.dir/codegen:
.PHONY : CMakeFiles/HuffmanCompressionTool_autogen.dir/codegen

HuffmanCompressionTool_autogen: CMakeFiles/HuffmanCompressionTool_autogen
HuffmanCompressionTool_autogen: HuffmanCompressionTool_autogen/timestamp
HuffmanCompressionTool_autogen: CMakeFiles/HuffmanCompressionTool_autogen.dir/build.make
.PHONY : HuffmanCompressionTool_autogen

# Rule to build all files generated by this target.
CMakeFiles/HuffmanCompressionTool_autogen.dir/build: HuffmanCompressionTool_autogen
.PHONY : CMakeFiles/HuffmanCompressionTool_autogen.dir/build

CMakeFiles/HuffmanCompressionTool_autogen.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\HuffmanCompressionTool_autogen.dir\cmake_clean.cmake
.PHONY : CMakeFiles/HuffmanCompressionTool_autogen.dir/clean

CMakeFiles/HuffmanCompressionTool_autogen.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\HuffmanCompressionTool D:\HuffmanCompressionTool D:\HuffmanCompressionTool\build D:\HuffmanCompressionTool\build D:\HuffmanCompressionTool\build\CMakeFiles\HuffmanCompressionTool_autogen.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/HuffmanCompressionTool_autogen.dir/depend

