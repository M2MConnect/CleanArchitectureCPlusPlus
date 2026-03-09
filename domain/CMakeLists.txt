add_library(mqa_domain STATIC
    src/Machine.cpp
)

add_library(ModernQtArchitecture::domain ALIAS mqa_domain)

target_include_directories(mqa_domain
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_compile_features(mqa_domain PUBLIC cxx_std_20)
