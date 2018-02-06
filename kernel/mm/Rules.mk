include $(MK)/prologue.mk

SRC_$(d) := pmm.c

SRC_$(d) := $(addprefix $(d)/, $(SRC_$(d)))

OBJ_$(d) := $(SRC_$(d):.c=.o)

$(OBJ_$(d)): %.o: %.c
	$(COMP)

# append all OBJECTS to clean
OBJ := $(OBJ) $(OBJ_$(d))

include $(MK)/epilogue.mk