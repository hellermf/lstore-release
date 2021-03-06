cmake_minimum_required(VERSION 2.8)

if(POLICY CMP0048)
	cmake_policy(SET CMP0048 OLD)
endif()

# Name this project
set(LSTORE_PROJECT_NAME "ibp")
project(${LSTORE_PROJECT_NAME} C CXX)

# Include modules 
if(NOT USE_SUPERBUILD)
    set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
endif()
include(CheckIncludeFile)

# Detect compiler flags.
# No-op for ibp

# Find additional dependencies.
if(NOT USE_SUPERBUILD)
    find_package(ToolBox REQUIRED)
    find_package(GOP REQUIRED)
    include_directories(${TOOLBOX_INCLUDE_DIR} ${GOP_INCLUDE_DIR})
    list(APPEND LIBS ${TOOLBOX_LIBRARY} ${GOP_LIBRARY})
endif()
set(LSTORE_LIBS ${APR_LIBRARY}
                    toolbox
                    gop
    )
set(LSTORE_INCLUDE_SYSTEM ${APR_INCLUDE_DIR})
set(LSTORE_INCLUDE_PUBLIC ${toolbox_INCLUDE_DIR}
                    ${gop_INCLUDE_DIR})


# Additional Compiler flags.
# No-op for ibp

# common objects
set(LSTORE_PROJECT_OBJS
    ibp_config.c ibp_errno.c ibp_misc.c ibp_op.c ibp_sync.c ibp_types.c
    io_wrapper.c iovec_sync.c 
)

set(LSTORE_PROJECT_INCLUDES
    ibp_ClientLib.h ibp_errno.h ibp.h ibp_misc.h ibp_nfu.h ibp_op.h ibp_os.h
    ibp_protocol.h ibp_types.h iovec_sync.h io_wrapper.h
)

set(LSTORE_PROJECT_EXECUTABLES 
    ibp_perf ibp_test ibp_copyperf ibp_tool ibp_find_drive
)

# Common functionality is stored here

if(NOT USE_SUPERBUILD)
    include(LStoreCommon)
else()
    include(LStoreFunctions)
    lstore_project_common(ibp)
endif()
