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
    mem_data.cpp \
    tb_mem_data.cpp

QMAKE_CXXFLAGS += -std=c++11

HEADERS += \
    mem_data.h \
    tb_mem_data.h \
    tsys_mem_data.h

