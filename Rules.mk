include $(MK)/prologue.mk

#OBJ var holds all object files

dir	:= $(d)/hal
include	$(dir)/Rules.mk
dir	:= $(d)/kernel
include	$(dir)/Rules.mk
dir := $(d)/lib
include $(dir)/Rules.mk

TGT := 

include $(MK)/epilogue.mk