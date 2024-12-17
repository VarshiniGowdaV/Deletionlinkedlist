cmake_minimum_required(VERSION 3.16)

project(deletionusinglinkedlist LANGUAGES C)

add_executable(deletionusinglinkedlist main.c)

include(GNUInstallDirs)
install(TARGETS deletionusinglinkedlist
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
