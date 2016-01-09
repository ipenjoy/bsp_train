
EXTRA_FLAGS += -DHAVE_CONFIG_H

SRC_OBJS := sdparm.o sdparm_data.o sdparm_data_vendor.o sdparm_access.o sdparm_vpd.o sdparm_cmd.o
LIB_OBJS := sg_lib.o sg_lib_data.o sg_cmds_basic.o sg_cmds_mmc.o sg_pt_common.o sg_pt_linux.o
##################################
 #_SOURCE_PATH=${PWD}
#_SOURCE_PATH=$(notdir ${PWD})

_SRC_WITH_PATH := $(addprefix  src/,$(SRC_OBJS:%.o=%.c))
_SRC_WITH_PATH += $(addprefix  lib/,$(LIB_OBJS:%.o=%.c))

_INCLUDE_PATH   := include
_TEMP_PATH      := tmp

_SRC_TEMP_PATH := $(_TEMP_PATH)/src/
_LIB_TEMP_PATH := $(_TEMP_PATH)/lib/


TARGET := $(_TEMP_PATH)/sdparm 
OBJS := $(addprefix $(_SRC_TEMP_PATH),$(SRC_OBJS))
OBJS += $(addprefix $(_LIB_TEMP_PATH),$(LIB_OBJS))
DEPS := $(OBJS:%.o=%.d)
DEP  := $(_TEMP_PATH)/.depend
##################################
CFLAGS := -c -I$(_INCLUDE_PATH)

all:$(TARGET)	

$(TARGET): pre $(DEP) $(OBJS)
	@echo "CC $@"
	@$(CC) -o $@ $(OBJS)
	
pre:
#@echo "$(OBJS)"
	@if [ ! -d $(_TEMP_PATH) ]; then mkdir -p $(_TEMP_PATH);fi
	@if [ ! -d $(_SRC_TEMP_PATH) ]; then mkdir -p $(_SRC_TEMP_PATH);fi
	@if [ ! -d $(_LIB_TEMP_PATH) ]; then mkdir -p $(_LIB_TEMP_PATH);fi

#$(OBJS):$(_SRC_WITH_PATH)  #为什么这个规则会出错呢？
$(_TEMP_PATH)/%.o: %.c
	@echo "CC $@"
	@$(CC)  $(CFLAGS) $< -o  $@ 
	
$(DEP):$(DEPS)
	@echo "DEPS $@"
	@cat $^ >> $@

$(DEPS):$(_SRC_WITH_PATH)	
	@echo "DEP $@"
	@$(CC) -M $(CFLAGS) $< > $@

sinclude $(DEP)
	
.PHONY:all clean test
clean :
	$(RM) $(TARGET) $(_SRC_TEMP_PATH)*.o $(_SRC_TEMP_PATH)*.d $(_LIB_TEMP_PATH)*.o $(_LIB_TEMP_PATH)*.d
