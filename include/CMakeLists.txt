add_library(lipm-include INTERFACE)
add_library(lipm::include ALIAS lipm-include)
target_include_directories(lipm-include INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}")
target_compile_definitions(lipm-include INTERFACE TOML_HEADER_ONLY=0)
