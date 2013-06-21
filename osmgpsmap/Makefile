all: installed

GIT_DIR = build/osm-gps-map-git
GIT_URL = https://github.com/muhrix/osm-gps-map.git
GIT_REVISION = fuerte_precise
include $(shell rospack find mk)/git_checkout.mk

installed: $(GIT_DIR)
	cd $(GIT_DIR) && ./autogen.sh
	cd $(GIT_DIR) && make
	mkdir -p $(CURDIR)/lib
	cp -r $(CURDIR)/$(GIT_DIR)/src/.libs/* $(CURDIR)/lib/
	mkdir -p $(CURDIR)/include
	cp -r $(CURDIR)/$(GIT_DIR)/src/*.h $(CURDIR)/include/
	touch installed

clean:
		-rm -rf $(SOURCE_DIR) installed
wipe: clean
		-rm -rf build include lib
