cmake_minimum_required(VERSION 3.7)
project(MailManager)

set(CMAKE_CXX_STANDARD 14)


add_subdirectory(test)

set(SOURCE_FILES src/main.cpp src/MailManager.cpp src/MailManager.h src/email.cpp src/email.h src/Arbol.h src/nodoArbol.h src/Lista.h src/nodo.h src/nodoArbol.cpp src/Arbol.cpp src/HashEntry.h src/HashMap.h src/nodoKT.h)
add_executable(MailManager ${SOURCE_FILES} src/nodoKT.h)