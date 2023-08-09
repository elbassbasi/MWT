cmake_minimum_required(VERSION 3.0)

project(mwt VERSION 0.1)

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
	set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/libs)
	set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
	set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
endif()

	set(COMMOM_DIR src/common)
	set(common_src 
		${COMMOM_DIR}/core/resource.c 
		${COMMOM_DIR}/core/app.c
		${COMMOM_DIR}/core/toolkit.c
		${COMMOM_DIR}/core/utf8.c
		${COMMOM_DIR}/widgets/widget.c
	)
    
    set(platform_src )

	set(mwt_inc include)
	set(mwt_lib )
	set(mwt_def MWTBUILD)
if (WIN32)
	set(mwt_lib ${mwt_lib} gdiplus usp10 uxtheme oleaut32 gdi32 ole32 uuid msimg32 opengl32 Imm32 comctl32)
	ENABLE_LANGUAGE(RC)
    set(WIN32_DIR src/win32)
    set(win32_src 
		${WIN32_DIR}/widgets/container.c
		${WIN32_DIR}/widgets/frame.c
		${WIN32_DIR}/widgets/menu.c 
		${WIN32_DIR}/widgets/toolkit.c 
		${WIN32_DIR}/widgets/tooltip.c
		${WIN32_DIR}/widgets/widget.c
		${WIN32_DIR}/widgets/widget_msg.c
	)
    set(platform_src ${platform_src} ${win32_src})
endif(WIN32)

if (UNIX AND NOT APPLE)
	if (POLICY CMP0072)
    	cmake_policy(SET CMP0072 NEW)
	endif()
	FIND_PACKAGE(PkgConfig REQUIRED)
    PKG_CHECK_MODULES(GTK3 REQUIRED gtk+-3.0)
    find_package(OpenGL REQUIRED)
    
	set(mwt_inc ${mwt_inc} ${GTK3_INCLUDE_DIRS} ${OPENGL_INCLUDE_DIRS})
	set(mwt_lib ${mwt_lib} ${GTK3_LIBRARIES} ${OPENGL_LIBRARIES} pthread dl)
	set(mwt_def ${mwt_def} )
endif()

if (UNIX AND APPLE)
    find_package(OpenGL REQUIRED)
    find_library(COCOA_LIBRARY Cocoa)
    
	set(mwt_inc ${mwt_inc} ${OPENGL_INCLUDE_DIRS})
	set(mwt_lib ${mwt_lib} ${COCOA_LIBRARY} ${OPENGL_LIBRARIES})
endif()

    set(mwt_src ${common_src} ${platform_src})
    list(REMOVE_DUPLICATES mwt_src)
    add_library(mwt SHARED ${mwt_src})
    target_include_directories(mwt PRIVATE ${mwt_inc})
	target_compile_definitions(mwt PRIVATE ${mwt_def})
    target_link_libraries(mwt ${mwt_lib})

#build tests
#if(CMAKE_PROJECT_NAME STREQUAL PROJECT_sNAME)
    set(TEST_DIR tests)
	set(src_mwttest 
        ${TEST_DIR}/main/TApp.cpp
    )
	
	add_executable(mwttest ${src_mwttest})
	target_include_directories(mwttest PUBLIC ./include )
	target_link_libraries(mwttest mwt)
#endif()
