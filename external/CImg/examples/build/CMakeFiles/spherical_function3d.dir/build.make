# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/andrea/workspaceC/reconstructionEvaluator/external/CImg/examples

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/andrea/workspaceC/reconstructionEvaluator/external/CImg/examples/build

# Include any dependencies generated for this target.
include CMakeFiles/spherical_function3d.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/spherical_function3d.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/spherical_function3d.dir/flags.make

CMakeFiles/spherical_function3d.dir/spherical_function3d.cpp.o: CMakeFiles/spherical_function3d.dir/flags.make
CMakeFiles/spherical_function3d.dir/spherical_function3d.cpp.o: ../spherical_function3d.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/andrea/workspaceC/reconstructionEvaluator/external/CImg/examples/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/spherical_function3d.dir/spherical_function3d.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/spherical_function3d.dir/spherical_function3d.cpp.o -c /home/andrea/workspaceC/reconstructionEvaluator/external/CImg/examples/spherical_function3d.cpp

CMakeFiles/spherical_function3d.dir/spherical_function3d.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/spherical_function3d.dir/spherical_function3d.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/andrea/workspaceC/reconstructionEvaluator/external/CImg/examples/spherical_function3d.cpp > CMakeFiles/spherical_function3d.dir/spherical_function3d.cpp.i

CMakeFiles/spherical_function3d.dir/spherical_function3d.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/spherical_function3d.dir/spherical_function3d.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/andrea/workspaceC/reconstructionEvaluator/external/CImg/examples/spherical_function3d.cpp -o CMakeFiles/spherical_function3d.dir/spherical_function3d.cpp.s

CMakeFiles/spherical_function3d.dir/spherical_function3d.cpp.o.requires:

.PHONY : CMakeFiles/spherical_function3d.dir/spherical_function3d.cpp.o.requires

CMakeFiles/spherical_function3d.dir/spherical_function3d.cpp.o.provides: CMakeFiles/spherical_function3d.dir/spherical_function3d.cpp.o.requires
	$(MAKE) -f CMakeFiles/spherical_function3d.dir/build.make CMakeFiles/spherical_function3d.dir/spherical_function3d.cpp.o.provides.build
.PHONY : CMakeFiles/spherical_function3d.dir/spherical_function3d.cpp.o.provides

CMakeFiles/spherical_function3d.dir/spherical_function3d.cpp.o.provides.build: CMakeFiles/spherical_function3d.dir/spherical_function3d.cpp.o


# Object files for target spherical_function3d
spherical_function3d_OBJECTS = \
"CMakeFiles/spherical_function3d.dir/spherical_function3d.cpp.o"

# External object files for target spherical_function3d
spherical_function3d_EXTERNAL_OBJECTS =

../spherical_function3d: CMakeFiles/spherical_function3d.dir/spherical_function3d.cpp.o
../spherical_function3d: CMakeFiles/spherical_function3d.dir/build.make
../spherical_function3d: /usr/lib/x86_64-linux-gnu/libtiff.so
../spherical_function3d: /usr/lib/x86_64-linux-gnu/libjpeg.so
../spherical_function3d: /usr/lib/x86_64-linux-gnu/libz.so
../spherical_function3d: /usr/lib/x86_64-linux-gnu/libpng.so
../spherical_function3d: /usr/lib/x86_64-linux-gnu/libz.so
../spherical_function3d: /usr/lib/x86_64-linux-gnu/libSM.so
../spherical_function3d: /usr/lib/x86_64-linux-gnu/libICE.so
../spherical_function3d: /usr/lib/x86_64-linux-gnu/libX11.so
../spherical_function3d: /usr/lib/x86_64-linux-gnu/libXext.so
../spherical_function3d: /usr/local/lib/libopencv_viz.so.3.1.0
../spherical_function3d: /usr/local/lib/libopencv_videostab.so.3.1.0
../spherical_function3d: /usr/local/lib/libopencv_superres.so.3.1.0
../spherical_function3d: /usr/local/lib/libopencv_stitching.so.3.1.0
../spherical_function3d: /usr/local/lib/libopencv_shape.so.3.1.0
../spherical_function3d: /usr/local/lib/libopencv_photo.so.3.1.0
../spherical_function3d: /usr/local/lib/libopencv_objdetect.so.3.1.0
../spherical_function3d: /usr/local/lib/libopencv_calib3d.so.3.1.0
../spherical_function3d: /usr/lib/liblapack.so
../spherical_function3d: /usr/lib/libblas.so
../spherical_function3d: /usr/lib/libblas.so
../spherical_function3d: /usr/lib/x86_64-linux-gnu/libpng.so
../spherical_function3d: /usr/lib/x86_64-linux-gnu/libSM.so
../spherical_function3d: /usr/lib/x86_64-linux-gnu/libICE.so
../spherical_function3d: /usr/lib/x86_64-linux-gnu/libX11.so
../spherical_function3d: /usr/lib/x86_64-linux-gnu/libXext.so
../spherical_function3d: /usr/lib/liblapack.so
../spherical_function3d: /usr/lib/libblas.so
../spherical_function3d: /usr/local/lib/libopencv_features2d.so.3.1.0
../spherical_function3d: /usr/local/lib/libopencv_ml.so.3.1.0
../spherical_function3d: /usr/local/lib/libopencv_highgui.so.3.1.0
../spherical_function3d: /usr/local/lib/libopencv_videoio.so.3.1.0
../spherical_function3d: /usr/local/lib/libopencv_imgcodecs.so.3.1.0
../spherical_function3d: /usr/local/lib/libopencv_flann.so.3.1.0
../spherical_function3d: /usr/local/lib/libopencv_video.so.3.1.0
../spherical_function3d: /usr/local/lib/libopencv_imgproc.so.3.1.0
../spherical_function3d: /usr/local/lib/libopencv_core.so.3.1.0
../spherical_function3d: CMakeFiles/spherical_function3d.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/andrea/workspaceC/reconstructionEvaluator/external/CImg/examples/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../spherical_function3d"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/spherical_function3d.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/spherical_function3d.dir/build: ../spherical_function3d

.PHONY : CMakeFiles/spherical_function3d.dir/build

CMakeFiles/spherical_function3d.dir/requires: CMakeFiles/spherical_function3d.dir/spherical_function3d.cpp.o.requires

.PHONY : CMakeFiles/spherical_function3d.dir/requires

CMakeFiles/spherical_function3d.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/spherical_function3d.dir/cmake_clean.cmake
.PHONY : CMakeFiles/spherical_function3d.dir/clean

CMakeFiles/spherical_function3d.dir/depend:
	cd /home/andrea/workspaceC/reconstructionEvaluator/external/CImg/examples/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/andrea/workspaceC/reconstructionEvaluator/external/CImg/examples /home/andrea/workspaceC/reconstructionEvaluator/external/CImg/examples /home/andrea/workspaceC/reconstructionEvaluator/external/CImg/examples/build /home/andrea/workspaceC/reconstructionEvaluator/external/CImg/examples/build /home/andrea/workspaceC/reconstructionEvaluator/external/CImg/examples/build/CMakeFiles/spherical_function3d.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/spherical_function3d.dir/depend

