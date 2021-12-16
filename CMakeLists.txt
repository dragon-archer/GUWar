cmake_minimum_required(VERSION 3.16)

project(GUWar VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 COMPONENTS Widgets LinguistTools REQUIRED)

set(TS_FILES Language/${PROJECT_NAME}_zh_CN.ts)

set(PROJECT_SOURCES
# Source files
		Source/Main.cpp
		Source/MainWindow.cpp
		Source/Soldier.cpp
# Header files
		Include/Pch.h
		Include/MainWindow.h
		Include/Soldier.h
# Resource files
		Resource.qrc
# Translation files
		${TS_FILES}
)

qt_add_executable(${PROJECT_NAME}
	MANUAL_FINALIZATION
	${PROJECT_SOURCES}
)
qt_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})

target_include_directories(${PROJECT_NAME} PUBLIC Include)
target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Widgets)

# Disable console
# if(WIN32)
# 	if(MSVC)
# 		set_target_properties(${PROJECT_NAME} PROPERTIES
# 			WIN32_EXECUTABLE YES
# 			LINK_FLAGS "/ENTRY:mainCRTStartup"
# 		)
# 	elseif(CMAKE_COMPILER_IS_GNUCXX)
# 		SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mwindows")
# 	else()
# 		message(SEND_ERROR "You are using an unsupported Windows compiler! (Not MSVC or GCC)")
# 	endif(MSVC)
# elseif(APPLE)
# 	set_target_properties(${PROJECT_NAME} PROPERTIES
# 		MACOSX_BUNDLE YES
# 	)
# else()
# 	message(SEND_ERROR "You are on an unsupported platform! (Not Win32, Mac OS X or Unix)")
# endif(WIN32)

qt_finalize_executable(${PROJECT_NAME})
