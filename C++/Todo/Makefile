CXX = g++
CXXFLAGS = -Wall -Wextra -g
LDFLAGS =

 
BUILD_DIR = build

SRC = src/main.cpp src/todoUtil.cpp
OBJS = $(SRC:src/%.cpp=$(BUILD_DIR)/%.o)  

TARGET = todoApp.exe
$(info SRC=$(SRC))
$(info OBJS=$(OBJS))

.PHONY: all clean run

all: $(TARGET)

$(TARGET): $(OBJS)
	@echo "Linking... $@"
	@if not exist $(BUILD_DIR) mkdir $(BUILD_DIR)
	$(CXX) $(LDFLAGS) -o $@ $(OBJS)

$(BUILD_DIR)/%.o: src/%.cpp
	@echo "Compiling... $<"
	@if not exist $(BUILD_DIR) mkdir $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: $(TARGET)
	@echo "Running $(TARGET)..."
	$(TARGET)                   

clean:
	@if exist $(TARGET) del $(TARGET)
	@if exist $(BUILD_DIR) rmdir /s /q $(BUILD_DIR)