QT -= gui

systemc_home = $$(SYSTEMC_HOME)
isEmpty(systemc_home) {
    systemc_home = /opt/systemc
}
message(Diretorio raiz de SystemC em: $${systemc_home})

systemc_target_arch = $$(SYSTEMC_TARGET_ARCH)
isEmpty(systemc_target_arch) {
    systemc_target_arch = linux64
}
message(A arquitetura alvo é: $${systemc_target_arch})

QMAKE_RPATHDIR += $${systemc_home}/lib
message(Opção do ligador QMAKE_RPATHDIR é: $${QMAKE_RPATHDIR})

LIBS += -L$${systemc_home}/lib -lsystemc

INCLUDEPATH += $${systemc_home}/include

QMAKE_CXXFLAGS += -std=c++11


CONFIG += c++11 console
CONFIG -= app_bundle

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += main.cpp \
    control_reg_id_ex.cpp \
    control_reg_ex_mem.cpp \
    control_reg_mem_wb.cpp \
    control_logic.cpp \
    test_feed_control.cpp

QMAKE_CXXFLAGS += -std=c++11

HEADERS += \
    control_reg_id_ex.h \
    control_reg_ex_mem.h \
    control_reg_mem_wb.h \
    control_logic.h \
    test_feed_control.h \
    tsys_control.h

