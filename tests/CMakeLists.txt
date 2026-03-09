add_executable(mqa_domain_tests
    domain/MachineTests.cpp
)

target_link_libraries(mqa_domain_tests
    PRIVATE
        mqa_domain
)

add_test(NAME domain_machine_tests COMMAND mqa_domain_tests)

add_executable(mqa_application_tests
    application/LoadMachinesUseCaseTests.cpp
)

target_link_libraries(mqa_application_tests
    PRIVATE
        mqa_application
)

add_test(NAME application_load_machines_tests COMMAND mqa_application_tests)
