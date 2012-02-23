#compile main.cpp save.cpp and sonymon.cpp into object files:
TARGET = Sonymon
OBJS = source/main.o source/saveIcon.h source/savePic1.h source/sonymon.o

#To build for custom firmware:
BUILD_PRX = 1
PSP_FW_VERSION=371

#set CFLAGS to -G0 (do not set to -G4 or -G2)
CFLAGS = -G2 -Wall -O2 -g
CXXFLAGS = $(CFLAGS) -fno-exceptions -fno-rtti
ASFLAGS = $(CFLAGS)
LIBDIR =
LDFLAGS =

#linked libraries
STDLIBS= -losl -lpng -lz \
         -lpsphprm -lpspsdk -lpspctrl -lpspumd -lpsprtc -lpsppower -lpspgu -lpspgum  -lpspaudiolib -lpspaudio -lpsphttp -lpspssl -lpspwlan \
         -lpspnet_adhocmatching -lpspnet_adhoc -lpspnet_adhocctl -lm -ljpeg
LIBS=$(STDLIBS) $(MYLIBS)

#OUTPUT FILE: EBOOT.PBP
#EBOOT TITLE: Sonymon
#EBOOT ICON:  ICON0.png
#EBOOT PIC1:  PIC1.png
#EBOOT ATR3:  SND0.at3
EXTRA_TARGETS = EBOOT.PBP
PSP_EBOOT_TITLE = Sonymon v0.3
PSP_EBOOT_ICON = resource/ICON0.png
PSP_EBOOT_PIC1 = resource/PIC1.png
PSP_EBOOT_SND0 = resource/SND0.at3

#locate build.mak
PSPSDK=$(shell psp-config --pspsdk-path)
include $(PSPSDK)/lib/build.mak

#build icon for save files
source/saveIcon.h : resource/saveICON0.png
	bin2c resource/saveICON0.png source/saveIcon.h icon0

#build pic1 for save files
source/savePic1.h : resource/savePIC1.png
	bin2c resource/savePIC1.png source/savePic1.h pic1
	
#V@ughn
	
	
