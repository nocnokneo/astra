set (_projname "calibrate")

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")

find_package(SFML COMPONENTS graphics window system)
find_package(OpenCV REQUIRED core imgproc highgui calib3d)

#maps relwithdebinfo to release, so don't include debug version of opencv
set_target_properties(${OpenCV_LIBS} PROPERTIES MAP_IMPORTED_CONFIG_RELWITHDEBINFO RELEASE)
set_target_properties(${OpenCV_LIBS} PROPERTIES MAP_IMPORTED_CONFIG_MINSIZEREL RELEASE)

set (${_projname}_SOURCES
  ${SAMPLE_COMMON_DIR}/lit_depth_visualizer.hpp
  ${SAMPLE_COMMON_DIR}/key_handler.h
  main.cpp
  )

add_executable(${_projname} ${${_projname}_SOURCES})

set_target_properties(${_projname} PROPERTIES FOLDER "${SAMPLE_DIR_FOLDER}tools")

include_directories(${_projname}
  ${SFML_INCLUDE_DIR}
  ${ASTRA_INCLUDE_DIR}
  ${SAMPLE_COMMON_DIR}
  ${OpenCV_INCLUDE_DIRS})

target_link_libraries(${_projname} ${ASTRA_LIBRARIES} ${SFML_LIBRARIES} ${OpenCV_LIBS})

set_debug_working_dir(${_projname} "$(TargetDir)")

add_astra_sdk_dependency(${_projname})

install_sample(${_projname})
