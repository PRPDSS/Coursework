cmake_minimum_required(VERSION 3.10)

# Указываем имя проекта и версию
project(Calc VERSION 1.0)

# # Устанавливаем стандарт C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_COMPILER "/usr/bin/clang")


# Получаем флаги компиляции и линковки для WxWidgets
execute_process(
    COMMAND wx-config --cxxflags
    OUTPUT_VARIABLE wxWidgets_CXX_FLAGS
    OUTPUT_STRIP_TRAILING_WHITESPACE
)
execute_process(
    COMMAND wx-config --libs
    OUTPUT_VARIABLE wxWidgets_LINK_FLAGS
    OUTPUT_STRIP_TRAILING_WHITESPACE
)
execute_process(
    COMMAND wx-config --prefix
    OUTPUT_VARIABLE wxWidgets_PREFIX
    OUTPUT_STRIP_TRAILING_WHITESPACE
)

# Указываем пути к заголовочным файлам и исходникам
include_directories(include ${wxWidgets_PREFIX}/include/wx-3.2 ${wxWidgets_PREFIX}/lib)

# Добавляем исполняемый файл
add_executable(${PROJECT_NAME}
    src/main.cpp
    src/equation.cpp
    src/solver.cpp
)

# Устанавливаем флаги компиляции и линковки
target_compile_options(${PROJECT_NAME} PRIVATE ${wxWidgets_CXX_FLAGS})
target_link_libraries(${PROJECT_NAME} ${wxWidgets_LINK_FLAGS})

# Добавляем флаги линковки для macOS
if(APPLE)
    target_compile_options(${PROJECT_NAME} PRIVATE -arch arm64)
    target_link_options(${PROJECT_NAME} PRIVATE -arch arm64)
    target_link_libraries(${PROJECT_NAME} "-framework CoreFoundation")
endif()
