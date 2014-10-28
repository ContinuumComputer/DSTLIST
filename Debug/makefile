################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
PHONEY_DEPLOY_OUTPUT += \
deploy \


# All Target
all: DSTLIST.txe

# Tool invocations
DSTLIST.txe: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: C Linker (TNS/E)'
	c99 -Wsystype=guardian -Wcall_shared -Wsaveabend -Weld="-unres_symbols Ignore" -o "DSTLIST.txe" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

deploy: DSTLIST.txe
	@echo 'Invoking: Deploy Tool'
	java -jar "C:/eclipse/plugins/com.hp.nsdee_4.0.0/Tools/Deploy.jar" -dir=\$$WORK1.EXTERNO -r=DSTLIST -q=guardian -code=800 -mode=bin -p= -t= -h= -u= -f="DSTLIST.txe"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(PHONEY_DEPLOY_OUTPUT)$(EXECUTABLES) DSTLIST.txe
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
