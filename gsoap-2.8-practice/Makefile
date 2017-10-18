# g++ server.cpp stdsoap2.cpp soap/soapC.cpp soap/soapcalcService.cpp -I soap/ -DWITH_NONAMESPACES -o server
# g++ client.cpp  stdsoap2.cpp soap/soapC.cpp soap/soapcalcProxy.cpp -I soap/ -DWITH_NONAMESPACES -o client
ifeq ($(TYPE), server)
    INC_DIR= soap server-soap 
    SRC_DIR= soap server-soap
else
    TYPE=client
    INC_DIR= soap client-soap 
    SRC_DIR= soap client-soap
endif

ifeq ($(ARCH), arm)
PATH :=$(PATH):/opt/freescale/usr/local/gcc-4.3.3-glibc-2.8-cs2009q1-203/arm-none-linux-gnueabi/bin/
CC=/opt/freescale/usr/local/gcc-4.3.3-glibc-2.8-cs2009q1-203/arm-none-linux-gnueabi/bin/arm-none-linux-gnueabi-g++
else
CC=g++
endif
# CFLAGS=-std=c++11
CFLAGS= -DWITH_NONAMESPACES
TARGET_DIR=
SRC_SUFFIX=cpp

OBJ_DIR_NAME=.obj
OBJ_SUFFIX=o
head_dir = $(foreach i,$(INC_DIR), -I$i)
cflags = $(head_dir) $(CFLAGS) 
ldflags =  


######################################################################################

#定义一个变量，用来表示目标.o文件:
#         $1=源文文件目录;
#         $2=源文件后缀(.cpp)
#         $3=目标文件存放的目录名(如.obj)
#         $4=生成的目标文件后缀名(如.o,.arm)
define create_obj
obj_$1 = $(patsubst %.$2, $1/$3/%.$4, $(notdir $(wildcard $1/*.$2)))
endef

#定义obj生成规则模板
#         $1=源文件目录，用来拼出变量名
#         $2=源文件后缀(.cpp)
#         $3=目标文件存放的目录名(如.obj)
#         $4=生成的目标文件后缀名(如.o,.arm)
define rule_o
$$(obj_$1): $1/$3/%.$4:$1/%.$2 $(MAKEFILE_LIST)
	@mkdir -p `dirname $$@`
	@echo -e "   $$(CC)\tCompiling $$< ...."
	@$(CC) $(cflags) -Wp,-MT,$$@ -Wp,-MMD,$$@.d -c -o $$@ $$<
endef

#根据指定的SRC_DIR,调用create_obj生成obj变量
$(foreach i,$(SRC_DIR), $(eval $(call create_obj,$i,$(SRC_SUFFIX),$(OBJ_DIR_NAME),$(OBJ_SUFFIX))))
all_obj=$(foreach i,$(SRC_DIR), $(obj_$i))
SUB_MK_DIR=
.PHONY:  $(TYPE) clean $(SUB_MK_DIR)
all:$(SUB_MK_DIR) $(TYPE) 
$(TYPE):$(all_obj)
	@$(CC) -o $@ $^ $(ldflags)
	@echo "============  Making $(TYPE) OK!! ============" 
	cp $(TYPE) /mnt/hgfs/tftpboot
	@for i in $(TARGET_DIR);do if [ -d $$i ];then cp $@ $$i;fi;done
clean:
	@rm -f $(TYPE) ./*.o
	@for d in $(SRC_DIR);do rm -rf $$d/$(OBJ_DIR_NAME); done;
	@echo " Makefile clean ...."	
	@for d in $(SUB_MK_DIR);do make clean -sC $$d; done;
$(SUB_MK_DIR):
	@make -sC $@
	@echo "============  Making $@/Makefile OK!! ============" 
$(foreach i,$(SRC_DIR), $(eval $(call rule_o,$i,$(SRC_SUFFIX),$(OBJ_DIR_NAME),$(OBJ_SUFFIX))))
-include $(patsubst %.$(OBJ_SUFFIX),%.$(OBJ_SUFFIX).d,$(all_obj))
