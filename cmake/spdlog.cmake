#add_subdirectory(${CMAKE_SOURCE_DIR}/vendor/spdlog)

set(SPDLOG_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/vendor/spdlog/include)

set(SPDLOG_LIBRARIES ${GLFW_LIBRARIES} ${CMAKE_SOURCE_DIR}/vendor/spdlog/build/libspdlog.a)