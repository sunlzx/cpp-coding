TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += /home/sunny/jdk1.6.0_29/include \n
    /home/sunny/jdk1.6.0_29/include/linux


SOURCES += main.c \
    jni_jnitest.c \
    sample1.c


HEADERS += \
    jni_jnitest.h \
    sample1.h


# gcc -fPIC -D_REENTRANT -I/home/sunny/jdk1.6.0_29/include -I/home/sunny/jdk1.6.0_29/include/linux -c jni_jnitest.c
# gcc -shared jni_jnitest.o -o libjni_jnitest.so
