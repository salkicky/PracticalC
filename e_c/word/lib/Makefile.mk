all:
	make -i -f util/Makefile.mk all
	make -i -f dict/Makefile.mk all

clean:
	make -i -f util/Makefile.mk clean
	make -i -f dict/Makefile.mk clean
