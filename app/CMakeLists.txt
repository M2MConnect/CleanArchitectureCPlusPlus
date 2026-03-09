set_source_files_properties(qml/styles/Theme.qml PROPERTIES QT_QML_SINGLETON_TYPE TRUE)

qt_add_executable(mqa_app
    src/main.cpp
    src/CompositionRoot.cpp
)

target_include_directories(mqa_app
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(mqa_app
    PRIVATE
        mqa_presentation
        mqa_infrastructure
        Qt6::Core
        Qt6::Gui
        Qt6::Qml
        Qt6::Quick
)

qt_add_qml_module(mqa_app
    URI ModernQtArchitecture
    VERSION 1.0
    RESOURCE_PREFIX /
    QML_FILES
        qml/Main.qml
        qml/views/MachineListView.qml
        qml/components/DetailField.qml
        qml/styles/Theme.qml
)

set_target_properties(mqa_app PROPERTIES
    WIN32_EXECUTABLE TRUE
)

if (WIN32)
    get_target_property(QT_QMAKE_EXECUTABLE Qt6::qmake IMPORTED_LOCATION)
    get_filename_component(QT_BIN_DIR "${QT_QMAKE_EXECUTABLE}" DIRECTORY)
    set(WINDEPLOYQT_EXECUTABLE "${QT_BIN_DIR}/windeployqt.exe")

    add_custom_command(TARGET mqa_app POST_BUILD
        COMMAND "${WINDEPLOYQT_EXECUTABLE}"
            --qmldir "${CMAKE_CURRENT_SOURCE_DIR}/qml"
            --no-translations
            "$<TARGET_FILE:mqa_app>"
        COMMENT "Running windeployqt for mqa_app"
        VERBATIM
    )
endif()
