PROJ_INCLUDE_DIR = ../include

CPPFLAGS ?= -I$(PROJ_INCLUDE_DIR)
CXXFLAGS ?= -Wall -Wextra -std=c++11 -pedantic -Werror -Wfatal-errors

EXECS = zeros

%.oo: %.cc
	@echo "  CXX   $@" && $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(TARGET_ARCH) -c $< -o $@

%: %.oo
	@echo "  LINK  $@" && $(CXX) $^ -o $@ $(TARGET_ARCH) $(LDFLAGS) $(LOADLIBES) $(LDLIBS)

define make-exec
$1: $1.oo
endef

.PHONY: default clean

default: all

all: $(EXECS)

debug: CXXFLAGS += -g
debug: $(EXECS)

$(foreach exec,$(EXECS),$(eval $(call make-exec,$(exec))))

test: all
	@echo "::TESTING::"
	@for f in $(TESTS); do (./$${f} && echo "  TEST  $$f  OK") || echo "  TEST  $$f  FAIL"; done

clean:
	$(RM) $(TESTS)
	$(RM) $(TESTS:%=%.oo)