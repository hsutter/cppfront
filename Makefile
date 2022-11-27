all:
	$(MAKE) -C source all

check:
	$(MAKE) -C regression-tests check
	$(MAKE) -C passthrough-tests check

clean:
	$(MAKE) -C source clean
	$(MAKE) -C regression-tests clean
	$(MAKE) -C passthrough-tests clean
