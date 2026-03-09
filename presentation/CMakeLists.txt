add_library(mqa_presentation STATIC
    include/presentation/models/MachineListModel.hpp
    include/presentation/viewmodels/MachineListViewModel.hpp
    src/models/MachineListModel.cpp
    src/viewmodels/MachineListViewModel.cpp
)

add_library(ModernQtArchitecture::presentation ALIAS mqa_presentation)

target_include_directories(mqa_presentation
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(mqa_presentation
    PUBLIC
        mqa_application
        Qt6::Core
)

set_target_properties(mqa_presentation PROPERTIES
    AUTOMOC ON
)

target_compile_features(mqa_presentation PUBLIC cxx_std_20)
