cmake_minimum_required(VERSION 2.8)
project( Canny_Edge_Detector )
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )
add_executable( Canny_Edge_Detector edge.cpp )
target_link_libraries( Canny_Edge_Detector ${OpenCV_LIBS} )
