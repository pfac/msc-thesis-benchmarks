BUILD_DIR ?= build
BUILD_DIR_MAKEFILE ?= Makefile.build
BUILD_TYPE ?= default

benchmarks: zeros lt-zeros

zeros: $(BUILD_TYPE)
	@for benchmark in malloc-memset calloc arma-zeros mat-zeros mat-loop mat-loop-omp; \
	do \
		$(BUILD_DIR)/$(BUILD_TYPE)/bin/$@-$${benchmark}; \
	done;

lt-zeros: $(BUILD_TYPE)
	@for benchmark in mat-loop-omp; \
	do \
		$(BUILD_DIR)/$(BUILD_TYPE)/bin/$@-$${benchmark}; \
	done;

$(BUILD_TYPE): $(BUILD_DIR) $(BUILD_DIR)/Makefile
	cd $(BUILD_DIR); $_ cmake-$@

$(BUILD_DIR):
	mkdir -p $@

$(BUILD_DIR)/Makefile: $(BUILD_DIR_MAKEFILE)
	cp $< $@


clean:
	$(RM) -r $(BUILD_DIR)
