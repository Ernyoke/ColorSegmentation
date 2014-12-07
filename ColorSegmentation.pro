#-------------------------------------------------
#
# Project created by QtCreator 2014-11-30T23:16:35
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ColorSegmentation
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    image.cpp \
    center.cpp \
    webcam.cpp \
    progressdialog.cpp

HEADERS  += mainwindow.h \
    image.h \
    center.h \
    webcam.h \
    progressdialog.h

FORMS    += mainwindow.ui \
    progressdialog.ui

INCLUDEPATH += D:\\CPrograms\\opencv\\mybuild\\install\\include


 LIBS += D:\\CPrograms\\opencv\\mybuild\\lib\\libopencv_core249.dll.a
 LIBS += D:\\CPrograms\\opencv\\mybuild\\lib\\libopencv_features2d_pch_dephelp.a
 LIBS += D:\\CPrograms\\opencv\\mybuild\\lib\\libopencv_features2d249.dll.a
 LIBS += D:\\CPrograms\\opencv\\mybuild\\lib\\libopencv_flann_pch_dephelp.a
 LIBS += D:\\CPrograms\\opencv\\mybuild\\lib\\libopencv_flann249.dll.a
 LIBS += D:\\CPrograms\\opencv\\mybuild\\lib\\libopencv_gpu_pch_dephelp.a
 LIBS += D:\\CPrograms\\opencv\\mybuild\\lib\\libopencv_gpu249.dll.a
 LIBS += D:\\CPrograms\\opencv\\mybuild\\lib\\libopencv_haartraining_engine.a
 LIBS += D:\\CPrograms\\opencv\\mybuild\\lib\\libopencv_highgui_pch_dephelp.a
 LIBS += D:\\CPrograms\\opencv\\mybuild\\lib\\libopencv_highgui249.dll.a
 LIBS += D:\\CPrograms\\opencv\\mybuild\\lib\\libopencv_imgproc_pch_dephelp.a
 LIBS += D:\\CPrograms\\opencv\\mybuild\\lib\\libopencv_imgproc249.dll.a
 LIBS += D:\\CPrograms\\opencv\\mybuild\\lib\\libopencv_legacy_pch_dephelp.a
 LIBS += D:\\CPrograms\\opencv\\mybuild\\lib\\libopencv_legacy249.dll.a
 LIBS += D:\\CPrograms\\opencv\\mybuild\\lib\\libopencv_ml_pch_dephelp.a
 LIBS += D:\\CPrograms\\opencv\\mybuild\\lib\\libopencv_ml249.dll.a
 LIBS += D:\\CPrograms\\opencv\\mybuild\\lib\\libopencv_nonfree_pch_dephelp.a
 LIBS += D:\\CPrograms\\opencv\\mybuild\\lib\\libopencv_nonfree249.dll.a
 LIBS += D:\\CPrograms\\opencv\\mybuild\\lib\\libopencv_objdetect_pch_dephelp.a
 LIBS += D:\\CPrograms\\opencv\\mybuild\\lib\\libopencv_objdetect249.dll.a
 LIBS += D:\\CPrograms\\opencv\\mybuild\\lib\\libopencv_ocl_pch_dephelp.a
 LIBS += D:\\CPrograms\\opencv\\mybuild\\lib\\libopencv_ocl249.dll.a
 LIBS += D:\\CPrograms\\opencv\\mybuild\\lib\\libopencv_perf_calib3d_pch_dephelp.a
 LIBS += D:\\CPrograms\\opencv\\mybuild\\lib\\libopencv_perf_core_pch_dephelp.a
 LIBS += D:\\CPrograms\\opencv\\mybuild\\lib\\libopencv_perf_features2d_pch_dephelp.a
 LIBS += D:\\CPrograms\\opencv\\mybuild\\lib\\libopencv_perf_gpu_pch_dephelp.a
 LIBS += D:\\CPrograms\\opencv\\mybuild\\lib\\libopencv_perf_highgui_pch_dephelp.a
 LIBS += D:\\CPrograms\\opencv\\mybuild\\lib\\libopencv_perf_imgproc_pch_dephelp.a
 LIBS += D:\\CPrograms\\opencv\\mybuild\\lib\\libopencv_perf_nonfree_pch_dephelp.a
 LIBS += D:\\CPrograms\\opencv\\mybuild\\lib\\libopencv_perf_objdetect_pch_dephelp.a
 LIBS += D:\\CPrograms\\opencv\\mybuild\\lib\\libopencv_perf_ocl_pch_dephelp.a
 LIBS += D:\\CPrograms\\opencv\\mybuild\\lib\\libopencv_perf_photo_pch_dephelp.a
 LIBS += D:\\CPrograms\\opencv\\mybuild\\lib\\libopencv_perf_stitching_pch_dephelp.a
 LIBS += D:\\CPrograms\\opencv\\mybuild\\lib\\libopencv_perf_superres_pch_dephelp.a
 LIBS += D:\\CPrograms\\opencv\\mybuild\\lib\\libopencv_perf_video_pch_dephelp.a
 LIBS += D:\\CPrograms\\opencv\\mybuild\\lib\\libopencv_photo_pch_dephelp.a
 LIBS += D:\\CPrograms\\opencv\\mybuild\\lib\\libopencv_photo249.dll.a
 LIBS += D:\\CPrograms\\opencv\\mybuild\\lib\\libopencv_stitching_pch_dephelp.a
 LIBS += D:\\CPrograms\\opencv\\mybuild\\lib\\libopencv_stitching249.dll.a
 LIBS += D:\\CPrograms\\opencv\\mybuild\\lib\\libopencv_superres_pch_dephelp.a
 LIBS += D:\\CPrograms\\opencv\\mybuild\\lib\\libopencv_superres249.dll.a
 LIBS += D:\\CPrograms\\opencv\\mybuild\\lib\\libopencv_test_calib3d_pch_dephelp.a
 LIBS += D:\\CPrograms\\opencv\\mybuild\\lib\\libopencv_test_contrib_pch_dephelp.a
 LIBS += D:\\CPrograms\\opencv\\mybuild\\lib\\libopencv_test_core_pch_dephelp.a
 LIBS += D:\\CPrograms\\opencv\\mybuild\\lib\\libopencv_test_features2d_pch_dephelp.a
 LIBS += D:\\CPrograms\\opencv\\mybuild\\lib\\libopencv_test_flann_pch_dephelp.a
 LIBS += D:\\CPrograms\\opencv\\mybuild\\lib\\libopencv_test_gpu_pch_dephelp.a
 LIBS += D:\\CPrograms\\opencv\\mybuild\\lib\\libopencv_test_highgui_pch_dephelp.a
 LIBS += D:\\CPrograms\\opencv\\mybuild\\lib\\libopencv_test_imgproc_pch_dephelp.a
 LIBS += D:\\CPrograms\\opencv\\mybuild\\lib\\libopencv_test_legacy_pch_dephelp.a
 LIBS += D:\\CPrograms\\opencv\\mybuild\\lib\\libopencv_test_ml_pch_dephelp.a
 LIBS += D:\\CPrograms\\opencv\\mybuild\\lib\\libopencv_test_nonfree_pch_dephelp.a
 LIBS += D:\\CPrograms\\opencv\\mybuild\\lib\\libopencv_test_objdetect_pch_dephelp.a
 LIBS += D:\\CPrograms\\opencv\\mybuild\\lib\\libopencv_test_ocl_pch_dephelp.a
 LIBS += D:\\CPrograms\\opencv\\mybuild\\lib\\libopencv_test_photo_pch_dephelp.a
 LIBS += D:\\CPrograms\\opencv\\mybuild\\lib\\libopencv_test_stitching_pch_dephelp.a
 LIBS += D:\\CPrograms\\opencv\\mybuild\\lib\\libopencv_test_superres_pch_dephelp.a
 LIBS += D:\\CPrograms\\opencv\\mybuild\\lib\\libopencv_test_video_pch_dephelp.a
 LIBS += D:\\CPrograms\\opencv\\mybuild\\lib\\libopencv_ts_pch_dephelp.a
 LIBS += D:\\CPrograms\\opencv\\mybuild\\lib\\libopencv_ts249.a
 LIBS += D:\\CPrograms\\opencv\\mybuild\\lib\\libopencv_video_pch_dephelp.a
 LIBS += D:\\CPrograms\\opencv\\mybuild\\lib\\libopencv_video249.dll.a
 LIBS += D:\\CPrograms\\opencv\\mybuild\\lib\\libopencv_videostab_pch_dephelp.a
 LIBS += D:\\CPrograms\\opencv\\mybuild\\lib\\libopencv_videostab249.dll.a
 LIBS += D:\\CPrograms\\opencv\\mybuild\\lib\\libopencv_calib3d_pch_dephelp.a
 LIBS += D:\\CPrograms\\opencv\\mybuild\\lib\\libopencv_calib3d249.dll.a
 LIBS += D:\\CPrograms\\opencv\\mybuild\\lib\\libopencv_contrib_pch_dephelp.a
 LIBS += D:\\CPrograms\\opencv\\mybuild\\lib\\libopencv_contrib249.dll.a
 LIBS += D:\\CPrograms\\opencv\\mybuild\\lib\\libopencv_core_pch_dephelp.a
