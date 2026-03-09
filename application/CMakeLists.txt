add_library(mqa_application STATIC
    src/LoadMachinesUseCase.cpp
)

add_library(ModernQtArchitecture::application ALIAS mqa_application)

target_include_directories(mqa_application
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(mqa_application
    PUBLIC
        mqa_domain
)

target_compile_features(mqa_application PUBLIC cxx_std_20)
