TARGET_EXEC := main

# The build paths
BUILD_DIR := ./build
SRC_DIRS := ./src
INC_DIRS := ./inc


# The source files
SRCS := $(shell find $(SRC_DIRS) -name '*.c')

# The object files
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)

# Add a prefix to INC_DIRS. So moduleA would become -ImoduleA. GCC understands this -I flag
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

# The -MMD and -MP flags together generate Makefiles for us!
# These files will have .d instead of .o as the output.
CPPFLAGS := $(INC_FLAGS) -MMD -MP

# The compiler flags for GCC
CFLAGS := -Wall -Wpedantic -Werror


# The final build step.
$(BUILD_DIR)/$(TARGET_EXEC): $(OBJS)
	$(CXX) $(OBJS) -o $@ $(LDFLAGS)

# Build step for C source
$(BUILD_DIR)/%.c.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@


.PHONY: clean
clean:
	rm -r $(BUILD_DIR)
