CXX = g++
CXXFLAGS = -Wall -g -Iinclude

TARGET = nlpTool

SRC_DIR = src
BUILD_DIR = build

SRCS = $(shell find $(SRC_DIR) -type f -name "*.cpp" )

OBJS = $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRCS))

OBJ_DIRS := $(sort $(dir $(OBJS)))

all: $(TARGET)
	make -C lapos-0.1.2/

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^



$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIRS)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(OBJ_DIRS):
	mkdir -p $@

clean:
	make clean -C lapos-0.1.2/
	rm -rf $(BUILD_DIR) $(TARGET)

.PHONY: clean	
