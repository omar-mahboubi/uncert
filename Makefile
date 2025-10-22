# Cross-platform Makefile with kernel-style output

# Compiler settings
CXX := x86_64-linux-gnu-
CXXFLAGS :=
BUILDDIR_LIN := build/linux
BUILDDIR_WIN := build/win
BUILDDIR_ARM := build/aarch64
CXXFLAGS_WIN := -static -static-libstdc++ -static-libgcc
SRC := main.cpp terminal.cpp calc.cpp methods.cpp

# Targets
TARGET_LINUX := uncert
TARGET_WIN := uncert.exe
TARGET_ARM := uncert_arm64

OBJ_L := $(SRC:%.cpp=$(BUILDDIR_LIN)/%.o)
$(BUILDDIR_LIN)/%.o: %.cpp | $(BUILDDIR_LIN)
	@printf "  %-8s %s\n" "CC" "$<"
	@$(CXX)g++ $(CXXFLAGS) -c $< -o $@

OBJ_W := $(SRC:%.cpp=$(BUILDDIR_WIN)/%.o)
$(BUILDDIR_WIN)/%.o: %.cpp | $(BUILDDIR_WIN)
	@printf "  %-8s %s\n" "CC" "$<"
	@$(CXX_WIN)g++ $(CXXFLAGS_WIN) -c $< -o $@

OBJ_A := $(SRC:%.cpp=$(BUILDDIR_ARM)/%.o)
$(BUILDDIR_ARM)/%.o: %.cpp | $(BUILDDIR_ARM)
	@printf "  %-8s %s\n" "CC" "$<"
	@$(CXX_ARM)g++ $(CXXFLAGS) -c $< -o $@

# Cross compilers (edit if installed differently)
CXX_WIN := x86_64-w64-mingw32-
CXX_ARM := aarch64-linux-gnu-

# Default target
all: linux win arm64

# Native build
linux: $(OBJ_L) | build
	@printf "  %-8s %s\n" "LD" "$(TARGET_LINUX)"
	@$(CXX)g++ $(CXXFLAGS) -o $(BUILDDIR_LIN)/$(TARGET_LINUX) $(OBJ_L)

# Windows build
win: $(OBJ_W) | build
	@printf "  %-8s %s\n" "LD" "$(TARGET_WIN)"
	@$(CXX_WIN)g++ $(CXXFLAGS_WIN) -o $(BUILDDIR_WIN)/$(TARGET_WIN) $(OBJ)
	@printf "  %-8s %s\n" "STRIP" "$(TARGET_WIN)"
	@$(CXX_WIN)strip $(BUILDDIR_WIN)/$(TARGET_WIN)

# ARM64 build
arm64: $(OBJ_A) | build
	@printf "  %-8s %s\n" "LD" "$(TARGET_ARM)"
	@$(CXX_ARM)g++ $(CXXFLAGS) -o $(BUILDDIR_ARM)/$(TARGET_ARM) $(OBJ_A)

# Clean
clean:
	@printf "  %-8s %s\n" "CLEAN"
	@rm -rf $(BUILDDIR_LIN)/
	@rm -rf $(BUILDDIR_WIN)/
	@rm -rf $(BUILDDIR_ARM)/

# Build
build:
	mkdir -p $(BUILDDIR_LIN)
	mkdir -p $(BUILDDIR_WIN)
	mkdir -p $(BUILDDIR_ARM)
