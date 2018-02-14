ARCHS = armv7 arm64
TARGET = iphone:clang:10.3:10.0

include $(THEOS)/makefiles/common.mk

TWEAK_NAME = timerSeconds
timerSeconds_FILES = Tweak.xm

include $(THEOS_MAKE_PATH)/tweak.mk

after-install::
	install.exec "killall -9 SpringBoard"
