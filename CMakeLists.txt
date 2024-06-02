cmake_minimum_required(VERSION 3.26)

# Указываем имя проекта и версию
project(Calc VERSION 1.0)

set(CMAKE_CXX_STANDART 23)
set(CMAKE_CXX_STANDARD_REQUIRED true)

find_package(wxWidgets REQUIRED COMPONENTS net core base)

# Указываем пути к заголовочным файлам и исходникам
include_directories(include)
include(${wxWidgets_USE_FILE})


# Добавляем исполняемый файл
add_executable(${PROJECT_NAME}
        src/main.cpp
        src/equation.cpp
        src/solver.cpp
        src/mainframe.cpp
)

# Устанавливаем флаги компиляции и линковки
target_compile_options(${PROJECT_NAME} PRIVATE -std=c++17)
target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})
