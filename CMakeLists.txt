cmake_minimum_required(VERSION 3.17)
project(a89_IsabelaMocanu915_PetShelter)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_PREFIX_PATH "C:/Qt/5.12.5/mingw73_64/lib/cmake")
set(QT_VERSION 5)
set(REQUIRED_LIBS Core Gui Widgets)
set(REQUIRED_LIBS_QUALIFIED Qt5::Core Qt5::Gui Qt5::Widgets)

include_directories(.)

find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)

add_executable(a89_IsabelaMocanu915_PetShelter
        dog.cpp
        dog.h
        exceptions.h
        GUI.cpp
        GUI.h
        GUIAdmin.cpp
        GUIAdmin.h
        GUIcsvORhtml.cpp
        GUIcsvORhtml.h
        GUIUser.cpp
        GUIUser.h
        main.cpp
        repo.cpp
        repo.h
        ui.cpp
        ui.h
        validators.cpp
        validators.h)

target_link_libraries(${PROJECT_NAME} ${REQUIRED_LIBS_QUALIFIED})
