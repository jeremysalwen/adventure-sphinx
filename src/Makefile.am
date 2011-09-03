## Process this file with automake to produce Makefile.in

## Created by Anjuta

AM_CPPFLAGS = \
	-DPACKAGE_LOCALE_DIR=\""$(prefix)/$(DATADIRNAME)/locale"\" \
	-DPACKAGE_SRC_DIR=\""$(srcdir)"\" \
	-DPACKAGE_DATA_DIR=\""$(pkgdatadir)"\"  \
	 $(ADVENTURE_SPHINX_CFLAGS)\
	 $(ESTOOLS_CPPFLAGS)\
	 $(FESTIVAL_CPPFLAGS)\
	-DMODELDIR=\"`pkg-config --variable=modeldir pocketsphinx`\"


AM_CFLAGS =\
	 -Wall\
	 -g
	 
AM_CXXFLAGS =\
	 -Wall\
	 -g\
	 -lFestival\
	 -lestools\
	 -lestbase\
	 -leststring
	 
noinst_PROGRAMS =	setup 

noinst_LIBRARIES = libmain.a

libmain_a_SOURCES = main.cxx\
	io.cxx            \
	vocab.cxx          \
	save.cxx           
	
libmain_a_CPPFLAGS = \
	-DPACKAGE_LOCALE_DIR=\""$(prefix)/$(DATADIRNAME)/locale"\" \
	-DPACKAGE_SRC_DIR=\""$(srcdir)"\" \
	-DPACKAGE_DATA_DIR=\""$(pkgdatadir)"\"  \
	 $(ESTOOLS_CPPFLAGS)\
	 $(FESTIVAL_CPPFLAGS)\
	-DMODELDIR=\"`pkg-config --variable=modeldir pocketsphinx`\"

bin_PROGRAMS = \
	adventure_sphinx


setup_SOURCES = \
	setup.c
	
setup_LDFLAGS =

adventure_sphinx_SOURCES = \
	crc.cxx            \
	done.cxx            \
	init.cxx            \
	subr.cxx            \
	wizard.cxx            \
	parser.c            \
	asr_input.cxx            \
	festival_driver.cxx        

nodist_adventure_sphinx_SOURCES = data.c

CLEANFILES = data.c

adventure_sphinx_LDFLAGS = 

adventure_sphinx_LDADD =  libmain_a-io.o  libmain_a-vocab.o\
		 	libmain_a-save.o\
		 	libmain_a-main.o\
		 	$(ADVENTURE_SPHINX_LIBS)\
		 	$(ESTOOLS_LIBS)\
		 	$(FESTIVAL_LIBS)

data.c: $(srcdir)/glorkz setup$(EXEEXT)
	./setup$(EXEEXT) $(srcdir)/glorkz >$@

grammardir = $(pkgdatadir)/grammars


dist_grammar_DATA = gram.jsgf\
	yesno.jsgf
	


