BUILD_DIR ?= build
BUILD_DIR_MAKEFILE ?= Makefile.build
BUILD_TYPE ?= default



$(BUILD_TYPE): $(BUILD_DIR) $(BUILD_DIR)/Makefile
	cd $(BUILD_DIR); $_ cmake-$@

$(BUILD_DIR):
	mkdir -p $@

$(BUILD_DIR)/Makefile: $(BUILD_DIR_MAKEFILE)
	cp $< $@



clean:
	$(RM) -r $(BUILD_DIR)
