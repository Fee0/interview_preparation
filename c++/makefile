SUBDIRS = linked_lists

all:
	$(foreach dir, $(SUBDIRS), $(MAKE) -C $(dir);)
clean:
	$(foreach dir, $(SUBDIRS), cd $(dir) && $(MAKE) clean;)