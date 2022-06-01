include(CompileOptions)
include(Conan)

find_package(fmt)
find_package(tomlplusplus REQUIRED)

add_library(lipm-toml toml.cpp)
add_library(lipm::toml ALIAS lipm-toml)
target_compile_definitions(lipm-toml PRIVATE TOML_IMPLEMENTATION)
target_link_libraries(lipm-toml PUBLIC lipm::include tomlplusplus::tomlplusplus)
target_compile_features(lipm-toml PUBLIC cxx_std_20)

add_executable(main "main.cpp")
target_link_libraries(main PRIVATE fmt::fmt lipm::toml)
target_compile_features(main PRIVATE cxx_std_20)
target_compile_options(main PRIVATE ${warnings} ${wae})
