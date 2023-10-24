# CMakeList.txt : CMake project for LightSync, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.26.4)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("LightSync")

# Add source to this project's executable.
#add_executable (LightSync "LightSync.cpp" "LightSync.h")
set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

include_directories(${INCLUDE_DIR})

file(
	GLOB_RECURSE PROJECT_FILES
	${INCLUDE_DIR}/*.h
	${SOURCE_DIR}/*.cpp
)

add_executable(LightSync)
add_library(LightSyncLib STATIC ${PROJECT_FILES})

target_sources(LightSync PRIVATE ${PROJECT_FILES})
#target_sources(LightSyncLib PRIVATE ${PROJECT_FILES})

target_include_directories(LightSync PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(LightSync PRIVATE LightSyncLib)


#if (CMAKE_VERSION VERSION_GREATER 3.12)
#  set_property(TARGET LightSync PROPERTY CXX_STANDARD 20)
#endif()

# TODO: Add tests and install targets if needed.
