cmake_minimum_required(VERSION 3.8)
project(my_cpp_pkg)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

#Inclui diretório de cabeçalhops
include_directories(include)

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

#Aciciona o executável
add_executable(cpp_node src/my_first_node.cpp)

#Vincula as dependências de um target (executável ou biblioteca) as bibliotecas e pacotes ROS2 que ele utiliza
ament_target_dependencies(cpp_node rclcpp std_msgs)


#Instala o executável
install(TARGETS
  cpp_node
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
