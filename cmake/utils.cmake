set(LIB_NAME NGL)

macro(import_targets type)
    if(NOT EXISTS "${CMAKE_CURRENT_LIST_DIR}/${LIB_NAME}-${type}-targets.cmake")
        set(${CMAKE_FIND_PACKAGE_NAME}_NOT_FOUND_MESSAGE
            "${LIB_NAME} ${type} libraries were requested but not found")
        set(${CMAKE_FIND_PACKAGE_NAME}_FOUND OFF)
        return()
    endif()

    include("${CMAKE_CURRENT_LIST_DIR}/${LIB_NAME}-${type}-targets.cmake")
endmacro()

if(NOT TARGET ${LIB_NAME}::${LIB_NAME})
    set(type "")

    if(DEFINED ${LIB_NAME}_SHARED_LIBS)
        if(${LIB_NAME}_SHARED_LIBS)
            set(type "shared")
        else()
            set(type "static")
        endif()
    elseif(BUILD_SHARED_LIBS AND
           EXISTS "${CMAKE_CURRENT_LIST_DIR}/${LIB_NAME}-shared-targets.cmake")
        set(type "shared")
    elseif(EXISTS "${CMAKE_CURRENT_LIST_DIR}/${LIB_NAME}-static-targets.cmake")
        set(type "static")
    else()
        set(type "shared")
    endif()

    import_targets(${type})
    check_required_components(${LIB_NAME})
    message("-- Found ${type} ${LIB_NAME} (version ${${CMAKE_FIND_PACKAGE_NAME}_VERSION})")
endif()