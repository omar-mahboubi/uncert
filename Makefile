# Cross-platform Makefile with kernel-style output

# Compiler settings
CXX := x86_64-linux-gnu-
CXXFLAGS :=
CXXFLAGS_WIN := -static -static-libstdc++ -static-libgcc
SRC := uncert.cpp

# Targets
TARGET_LINUX := uncert
TARGET_WIN := uncert.exe
TARGET_ARM := uncert_arm64

# Cross compilers (edit if installed differently)
CXX_WIN := x86_64-w64-mingw32-
CXX_ARM := aarch64-linux-gnu-

# Default target
all: $(TARGET_LINUX)

# Native build
$(TARGET_LINUX): $(SRC)
	@printf "  %-8s %s\n" "CC" "$@"
	@$(CXX)g++ $(CXXFLAGS) -o $@ $(SRC)

# Windows build
win: $(SRC)
	@printf "  %-8s %s\n" "CC" "$(TARGET_WIN)"
	@$(CXX_WIN)g++ $(CXXFLAGS_WIN) -o $(TARGET_WIN) $(SRC)
	@printf "  %-8s %s\n" "STRIP" "$(TARGET_WIN)"
	@$(CXX_WIN)strip $(TARGET_WIN)

# ARM64 build
arm64: $(SRC)
	@printf "  %-8s %s\n" "CC" "$(TARGET_ARM)"
	@$(CXX_ARM)g++ $(CXXFLAGS) -o $(TARGET_ARM) $(SRC)

# Clean
clean:
	@printf "  %-8s %s\n" "CLEAN"
	@rm -f $(TARGET_LINUX) $(TARGET_WIN) $(TARGET_ARM)
