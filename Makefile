SUBDIRS += \
	Render

ifneq (, $(shell which ccache))
  export PRE_CXX=ccache
endif

include Makefile.subdir


all: subdirs

.PHONY: test
UNAME_S := $(shell uname -s)