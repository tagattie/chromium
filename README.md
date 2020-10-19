# freebsd-chromium

This repository contains the FreeBSD Chromium port. [Google will no longer accept FreeBSD/OpenBSD
patches](https://groups.google.com/a/chromium.org/d/msg/chromium-dev/b57hDs8yE4g/5tXefZ74AQAJ),
so we use this repository to manage our local changes.  It was cloned from
[gliaskos/freebsd-chromium](https://github.com/gliaskos/freebsd-chromium).

See
[here](https://bugs.freebsd.org/bugzilla/buglist.cgi?quicksearch=www%2Fchromium)
for a list of all known bugs.

When submitting changes, please adhere to a few guidelines, which comply with
upstream Chromium guidelines.  This hopefully make it easier to upstream our
changes if they are ever accepted again and it should make our work useful for
other projects like OpenBSD.

* GN: Use "is\_bsd", not "is\_freebsd" or some other identifier.

* C++ files: \_bsd.cc, not \_freebsd.cc and \_openbsd.cc. The implementation
can be divided inside like Chromium developers divide Linux/Android/ChromeOS
in one .cc file.

* C++ code: generally OS\_BSD, in some cases OS\_SOMEBSD when it is really
necessary. Never use \_\_FreeBSD\_\_, if OS\_\* is not defined then there is
a reason for this. In such cases, read BUILD.gn for that target and find out
how to do it correctly.
