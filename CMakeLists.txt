cmake_minimum_required(VERSION 3.5)

project(OptionPricer VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

set(PROJECT_SOURCES
        main.cpp
        maininterface.cpp
        maininterface.h
        maininterface.ui

        utilities/randombase.cpp
        utilities/randombase.h
        utilities/parkmiller.cpp
        utilities/parkmiller.h
        utilities/wrapper.h
        utilities/statistics.h
        utilities/statisticsmean.cpp
        utilities/statisticsmean.h
        utilities/convergencetable.cpp
        utilities/convergencetable.h
        utilities/parameters.cpp
        utilities/parameters.h
        utilities/evolution.cpp
        utilities/evolution.h
        utilities/processwrapper.cpp
        utilities/processwrapper.h
        utilities/process.cpp
        utilities/process.h
        utilities/antithetic.cpp
        utilities/antithetic.h
        utilities/exoticengine.cpp
        utilities/exoticengine.h
        utilities/exoticbsengine.cpp
        utilities/exoticbsengine.h

        payoff/payoff.cpp
        payoff/payoff.h
        payoff/payoffwrapper.cpp
        payoff/payoffwrapper.h
        payoff/vanillaoption.cpp
        payoff/vanillaoption.h
        payoff/pathdependent.cpp
        payoff/pathdependent.h
        payoff/pathdependentasian.cpp
        payoff/pathdependentasian.h
        payoff/payoffgeometricasian.cpp
        payoff/payoffgeometricasian.h
        payoff/payoffarithmeticasian.cpp
        payoff/payoffarithmeticasian.h
        payoff/payoffconstructible.h
        payoff/payoffregistration.cpp
        payoff/payofffactory.cpp
        payoff/payofffactory.h
        payoff/treeproduct.h
        payoff/treeproduct.cpp
        payoff/treeamerican.h
        payoff/treeamerican.cpp
        payoff/binomialtree.h
        payoff/binomialtree.cpp

        algorithm/montecarlossimulator.cpp
        algorithm/montecarlossimulator.h
        algorithm/pathdependentmcsimulator.cpp
        algorithm/pathdependentmcsimulator.h
        algorithm/treesimulator.cpp
        algorithm/treesimulator.h

        gbmmontecarlos.cpp
        gbmmontecarlos.h
        gbmmontecarlos.ui

        pathdependentmc.cpp
        pathdependentmc.h
        pathdependentmc.ui

        americanoptionform.cpp
        americanoptionform.h
        americanoptionform.ui
    )

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(OptionPricer
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET OptionPricer APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(OptionPricer SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(OptionPricer
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(OptionPricer PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(OptionPricer PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(OptionPricer)
endif()
