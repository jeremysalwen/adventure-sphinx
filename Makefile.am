## Process this file with automake to produce Makefile.in
## Created by Anjuta

SUBDIRS = src 

adventure_sphinxdocdir = ${prefix}/doc/adventure_sphinx
adventure_sphinxdoc_DATA = \
	README\
	COPYING\
	AUTHORS\
	ChangeLog\
	INSTALL\
	NEWS


EXTRA_DIST = $(adventure_sphinxdoc_DATA)

install-data-hook:
	cp -r '$(srcdir)/adventure-festvox' '$(DESTDIR)$(pkgdatadir)/'
	
uninstall-local-hook:
	rm -rf '$(DESTDIR)$(pkgdatadir)/adventure-festvox'
# Remove doc directory on uninstall
uninstall-local:
	-rm -r $(adventure_sphinxdocdir)
