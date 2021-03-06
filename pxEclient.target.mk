# This file is generated by gyp; do not edit.

TOOLSET := target
TARGET := pxEclient
DEFS_Default := 

# Flags passed to all source files.
CFLAGS_Default := 

# Flags passed to only C files.
CFLAGS_C_Default := 

# Flags passed to only C++ files.
CFLAGS_CC_Default := 

INCS_Default := 

OBJS := $(obj).target/$(TARGET)/src/main.o \
	$(obj).target/$(TARGET)/src/option.o \
	$(obj).target/$(TARGET)/src/packet.o \
	$(obj).target/$(TARGET)/src/auth.o

# Add to the list of files we specially track dependencies for.
all_deps += $(OBJS)

# CFLAGS et al overrides must be target-local.
# See "Target-specific Variable Values" in the GNU Make manual.
$(OBJS): TOOLSET := $(TOOLSET)
$(OBJS): GYP_CFLAGS := $(DEFS_$(BUILDTYPE)) $(INCS_$(BUILDTYPE)) $(CFLAGS_$(BUILDTYPE)) $(CFLAGS_C_$(BUILDTYPE))
$(OBJS): GYP_CXXFLAGS := $(DEFS_$(BUILDTYPE)) $(INCS_$(BUILDTYPE)) $(CFLAGS_$(BUILDTYPE)) $(CFLAGS_CC_$(BUILDTYPE))

# Suffix rules, putting all outputs into $(obj).

$(obj).$(TOOLSET)/$(TARGET)/%.o: $(srcdir)/%.cc FORCE_DO_CMD
	@$(call do_cmd,cxx,1)

# Try building from generated source, too.

$(obj).$(TOOLSET)/$(TARGET)/%.o: $(obj).$(TOOLSET)/%.cc FORCE_DO_CMD
	@$(call do_cmd,cxx,1)

$(obj).$(TOOLSET)/$(TARGET)/%.o: $(obj)/%.cc FORCE_DO_CMD
	@$(call do_cmd,cxx,1)

# End of this set of suffix rules
### Rules for final target.
LDFLAGS_Default := 

LIBS := 

$(builddir)/pxEclient: GYP_LDFLAGS := $(LDFLAGS_$(BUILDTYPE))
$(builddir)/pxEclient: LIBS := $(LIBS)
$(builddir)/pxEclient: LD_INPUTS := $(OBJS)
$(builddir)/pxEclient: TOOLSET := $(TOOLSET)
$(builddir)/pxEclient: $(OBJS) FORCE_DO_CMD
	$(call do_cmd,link)

all_deps += $(builddir)/pxEclient
# Add target alias
.PHONY: pxEclient
pxEclient: $(builddir)/pxEclient

# Add executable to "all" target.
.PHONY: all
all: $(builddir)/pxEclient

