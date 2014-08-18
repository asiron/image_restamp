cmake_minimum_required(VERSION 2.8.3)
project(image_restamp)

set(CMAKE_CXX_FLAGS "-std=c++0x ${CMAKE_CXX_FLAGS}")

set(ROS_CXX_DEPENDENCIES
  image_transport
  roscpp
  sensor_msgs
)

find_package(catkin REQUIRED COMPONENTS
  ${ROS_CXX_DEPENDENCIES}
)

#find Boost
find_package(Boost REQUIRED COMPONENTS signals)

include_directories(include ${catkin_INCLUDE_DIRS} ${Boost_INCLUDE_DIRS})
link_directories(${catkin_LIBRARY_DIRS})

catkin_package(
   CATKIN_DEPENDS ${ROS_CXX_DEPENDENCIES}
)

#create target image_restamp_node
add_executable(image_restamp_node src/image_restamp_node.cpp)
target_link_libraries(image_restamp_node ${catkin_LIBRARIES})
add_dependencies(image_restamp_node ${catkin_EXPORTED_TARGETS})

#install nao_waypoint
install(TARGETS
  image_restamp_node
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)
