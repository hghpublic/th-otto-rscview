#!/bin/sh

TMP="$1"
OUT="$2"

./autogen.sh --enable-warnings
make
make DESTDIR="$TMP" install
VERSION=$(grep PACKAGE_VERSION config.h | sed -e 's/^.*\"\(.*\)\".*/\1/')

(
mkdir -p "${OUT}"
cd "${TMP}"
tar cvfj "${OUT}/${PROJECT}-${VERSION}-linux.tar.bz2" .
tar cvfJ "${OUT}/${PROJECT}-${VERSION}-linux.tar.xz" .
)
