TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    std_algorithms/std_rotate.cpp \
    std_algorithms/std_stable_partition.cpp \
    std_algorithms/std_for_each.cpp \
    idioms/sean_parent_polymorphism.cpp \
    std_algorithms/std_replace_copy.cpp \
    std_algorithms/std_unique_copy.cpp \
    std_algorithms/std_sort.cpp

HEADERS += \
    utils.hpp \
    idioms/sean_parent_polymorphism.hpp \
    std_algorithms/std_for_each.hpp \
    std_algorithms/std_rotate.hpp \
    std_algorithms/std_stable_partition.hpp \
    std_algorithms/std_replace_copy.h \
    std_algorithms/std_unique_copy.h \
    std_algorithms/std_sort.h
