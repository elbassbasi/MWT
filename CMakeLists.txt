cmake_minimum_required(VERSION 3.0)

project(mwt VERSION 0.1)

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
	set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/libs)
	set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
	set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
endif()

#build mwt
	set(mwt_src )
	set(mwt_inc include)
	set(mwt_lib )
	set(mwt_def MWTBUILD)
if (WIN32)
	set(mwt_lib gdiplus usp10 uxtheme oleaut32 gdi32 ole32 uuid msimg32 opengl32 Imm32 comctl32)
	add_subdirectory(win32)
	ENABLE_LANGUAGE(RC)
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
	add_subdirectory(gtk)
endif()

if (UNIX AND APPLE)
    find_package(OpenGL REQUIRED)
    find_library(COCOA_LIBRARY Cocoa)
    
	set(mwt_inc ${mwt_inc} ${OPENGL_INCLUDE_DIRS})
	set(mwt_lib ${mwt_lib} ${COCOA_LIBRARY} ${OPENGL_LIBRARIES})
	add_subdirectory(osx)
endif()
	add_subdirectory(common)
#	add_subdirectory(custom)

#build mwt
if(mwt)
    add_library(mwt SHARED ${mwt_src})
    target_include_directories(mwt PRIVATE ${mwt_inc})
	target_compile_definitions(mwt PRIVATE ${mwt_def})
    target_link_libraries(mwt ${mwt_lib})
endif()

#build mwtp
#	set(mwtp_src )
#	add_subdirectory(mwtp)
#	add_library(mwtp SHARED ${mwt_src} ${mwtp_src})
#    target_include_directories(mwtp PRIVATE ${mwt_inc})
#	target_compile_definitions(mwtp PRIVATE -DMWTPBUILD ${mwt_def})
#	target_link_libraries(mwtp ${mwt_lib})

#build tests
if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
#	find_package(OpenGL REQUIRED)
#	set(src_mwttest )
#	add_subdirectory(tests)
	
#	add_executable(mwttest ${src_mwttest})
#	target_include_directories(mwttest PRIVATE include ${OPENGL_INCLUDE_DIRS})
#	target_link_libraries(mwttest mwtp ${OPENGL_LIBRARIES})

#	add_custom_target(mwttest-copy-files ALL
#    	COMMAND ${CMAKE_COMMAND} -E copy_directory
#    	${CMAKE_CURRENT_SOURCE_DIR}/tests/images
#   	${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/images
#    )
endif()
