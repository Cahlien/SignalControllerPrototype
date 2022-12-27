cmake_minimum_required(VERSION 3.14)

project(SignalControllerPrototype LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Concurrent)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Concurrent)

set(SOURCE_FILES)
list(APPEND SOURCE_FILES
    main.cpp
    channels.h
    abstract_signal_controller.h
    abstract_signal_controller.cpp
    singleton_signal_controller.h
    singleton_signal_controller.cpp
    i_signal_receiver.h
    i_signal_receiver.cpp
    receiver.h
    receiver.cpp
    multi_receiver.h
    multi_receiver.cpp
    abstract_signal_content.h
    abstract_signal_content.cpp
)

add_executable(SignalControllerPrototype
  ${SOURCE_FILES}
)
target_link_libraries(SignalControllerPrototype Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Concurrent)

install(TARGETS SignalControllerPrototype
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
