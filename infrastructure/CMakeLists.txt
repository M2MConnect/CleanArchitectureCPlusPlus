add_library(mqa_infrastructure STATIC
    src/repositories/InMemoryMachineRepository.cpp
    src/logging/ConsoleLogger.cpp
)

add_library(ModernQtArchitecture::infrastructure ALIAS mqa_infrastructure)

target_include_directories(mqa_infrastructure
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(mqa_infrastructure
    PUBLIC
        mqa_application
        mqa_domain
)

target_compile_features(mqa_infrastructure PUBLIC cxx_std_20)
