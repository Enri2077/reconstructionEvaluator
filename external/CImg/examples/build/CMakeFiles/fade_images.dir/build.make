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
include CMakeFiles/fade_images.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/fade_images.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/fade_images.dir/flags.make

CMakeFiles/fade_images.dir/fade_images.cpp.o: CMakeFiles/fade_images.dir/flags.make
CMakeFiles/fade_images.dir/fade_images.cpp.o: ../fade_images.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/andrea/workspaceC/reconstructionEvaluator/external/CImg/examples/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/fade_images.dir/fade_images.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/fade_images.dir/fade_images.cpp.o -c /home/andrea/workspaceC/reconstructionEvaluator/external/CImg/examples/fade_images.cpp

CMakeFiles/fade_images.dir/fade_images.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/fade_images.dir/fade_images.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/andrea/workspaceC/reconstructionEvaluator/external/CImg/examples/fade_images.cpp > CMakeFiles/fade_images.dir/fade_images.cpp.i

CMakeFiles/fade_images.dir/fade_images.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/fade_images.dir/fade_images.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/andrea/workspaceC/reconstructionEvaluator/external/CImg/examples/fade_images.cpp -o CMakeFiles/fade_images.dir/fade_images.cpp.s

CMakeFiles/fade_images.dir/fade_images.cpp.o.requires:

.PHONY : CMakeFiles/fade_images.dir/fade_images.cpp.o.requires

CMakeFiles/fade_images.dir/fade_images.cpp.o.provides: CMakeFiles/fade_images.dir/fade_images.cpp.o.requires
	$(MAKE) -f CMakeFiles/fade_images.dir/build.make CMakeFiles/fade_images.dir/fade_images.cpp.o.provides.build
.PHONY : CMakeFiles/fade_images.dir/fade_images.cpp.o.provides

CMakeFiles/fade_images.dir/fade_images.cpp.o.provides.build: CMakeFiles/fade_images.dir/fade_images.cpp.o


# Object files for target fade_images
fade_images_OBJECTS = \
"CMakeFiles/fade_images.dir/fade_images.cpp.o"

# External object files for target fade_images
fade_images_EXTERNAL_OBJECTS =

../fade_images: CMakeFiles/fade_images.dir/fade_images.cpp.o
../fade_images: CMakeFiles/fade_images.dir/build.make
../fade_images: /usr/lib/x86_64-linux-gnu/libtiff.so
../fade_images: /usr/lib/x86_64-linux-gnu/libjpeg.so
../fade_images: /usr/lib/x86_64-linux-gnu/libz.so
../fade_images: /usr/lib/x86_64-linux-gnu/libpng.so
../fade_images: /usr/lib/x86_64-linux-gnu/libz.so
../fade_images: /usr/lib/x86_64-linux-gnu/libSM.so
../fade_images: /usr/lib/x86_64-linux-gnu/libICE.so
../fade_images: /usr/lib/x86_64-linux-gnu/libX11.so
../fade_images: /usr/lib/x86_64-linux-gnu/libXext.so
../fade_images: /usr/local/lib/libopencv_viz.so.3.1.0
../fade_images: /usr/local/lib/libopencv_videostab.so.3.1.0
../fade_images: /usr/local/lib/libopencv_superres.so.3.1.0
../fade_images: /usr/local/lib/libopencv_stitching.so.3.1.0
../fade_images: /usr/local/lib/libopencv_shape.so.3.1.0
../fade_images: /usr/local/lib/libopencv_photo.so.3.1.0
../fade_images: /usr/local/lib/libopencv_objdetect.so.3.1.0
../fade_images: /usr/local/lib/libopencv_calib3d.so.3.1.0
../fade_images: /usr/lib/liblapack.so
../fade_images: /usr/lib/libblas.so
../fade_images: /usr/lib/libblas.so
../fade_images: /usr/lib/x86_64-linux-gnu/libpng.so
../fade_images: /usr/lib/x86_64-linux-gnu/libSM.so
../fade_images: /usr/lib/x86_64-linux-gnu/libICE.so
../fade_images: /usr/lib/x86_64-linux-gnu/libX11.so
../fade_images: /usr/lib/x86_64-linux-gnu/libXext.so
../fade_images: /usr/lib/liblapack.so
../fade_images: /usr/lib/libblas.so
../fade_images: /usr/local/lib/libopencv_features2d.so.3.1.0
../fade_images: /usr/local/lib/libopencv_ml.so.3.1.0
../fade_images: /usr/local/lib/libopencv_highgui.so.3.1.0
../fade_images: /usr/local/lib/libopencv_videoio.so.3.1.0
../fade_images: /usr/local/lib/libopencv_imgcodecs.so.3.1.0
../fade_images: /usr/local/lib/libopencv_flann.so.3.1.0
../fade_images: /usr/local/lib/libopencv_video.so.3.1.0
../fade_images: /usr/local/lib/libopencv_imgproc.so.3.1.0
../fade_images: /usr/local/lib/libopencv_core.so.3.1.0
../fade_images: CMakeFiles/fade_images.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/andrea/workspaceC/reconstructionEvaluator/external/CImg/examples/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../fade_images"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/fade_images.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/fade_images.dir/build: ../fade_images

.PHONY : CMakeFiles/fade_images.dir/build

CMakeFiles/fade_images.dir/requires: CMakeFiles/fade_images.dir/fade_images.cpp.o.requires

.PHONY : CMakeFiles/fade_images.dir/requires

CMakeFiles/fade_images.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/fade_images.dir/cmake_clean.cmake
.PHONY : CMakeFiles/fade_images.dir/clean

CMakeFiles/fade_images.dir/depend:
	cd /home/andrea/workspaceC/reconstructionEvaluator/external/CImg/examples/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/andrea/workspaceC/reconstructionEvaluator/external/CImg/examples /home/andrea/workspaceC/reconstructionEvaluator/external/CImg/examples /home/andrea/workspaceC/reconstructionEvaluator/external/CImg/examples/build /home/andrea/workspaceC/reconstructionEvaluator/external/CImg/examples/build /home/andrea/workspaceC/reconstructionEvaluator/external/CImg/examples/build/CMakeFiles/fade_images.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/fade_images.dir/depend
