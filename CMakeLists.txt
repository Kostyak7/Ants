cmake_minimum_required(VERSION 3.22)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(ANTS LANGUAGES CXX)
message(NOTICE "Your c++ compiler: ${CMAKE_CXX_COMPILER_ID}")

# Macros for SFML
add_compile_definitions(NOMINMAX)


# Prepare target for compiling binary file ants
file(GLOB_RECURSE ANTS_SOURCES source/*.cpp)
file(GLOB_RECURSE ANTS_HEADERS source/*.h)
add_executable(ants ${ANTS_SOURCES} ${ANTS_HEADERS})

# Macros /bigobj to get rid of error C1128
if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
	target_compile_options(ants PUBLIC "/bigobj")
endif()

# Checking of the macro __FUNCTION__ and fixing it if not supported
include(CheckCXXSourceCompiles)
check_cxx_source_compiles([[
	int main(void) {
		const char str[] = __FUNCTION__" str ";
		return 0;
	}
]] FUNCTION_MACRO_SUPPORT)
if (NOT FUNCTION_MACRO_SUPPORT)
	target_compile_definitions(ants PUBLIC -D __FUNCTION__="")
endif()

target_compile_definitions(ants PUBLIC -D GLM_ENABLE_EXPERIMENTAL)

# Get rid of MIN and MAX macros of windows.h, so the definitions in the multimin_function will be valid.
target_compile_definitions(ants PUBLIC -D NOMINMAX)

# Библиотека, для отображения кнопок, чекбоксов, данных и т.п. на окне.
find_package(imgui CONFIG REQUIRED)
target_link_libraries(ants PRIVATE imgui::imgui)

# Библиотека, для удобных менеджемента окна OpenGL и обработки событий, связанных с ним.
find_package(SFML CONFIG COMPONENTS REQUIRED window graphics system)
target_link_libraries(ants PRIVATE sfml-system sfml-window sfml-graphics)

# Дополнительная библиотека для ImGUI, связывающая его с SFML
find_package(ImGui-SFML CONFIG REQUIRED)
target_link_libraries(ants PRIVATE ImGui-SFML::ImGui-SFML)

# Библиотека, определяющая набор математических функций для 2/3D графики. Совместима с OpenGL API.
find_package(glm CONFIG REQUIRED)
target_link_libraries(ants PRIVATE glm::glm)

# Библиотека для управления расширениями OpenGL. (для расширения шейдеров)
find_package(GLEW REQUIRED)
target_link_libraries(ants PRIVATE GLEW::GLEW)
