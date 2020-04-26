#!/usr/bin/env bash

# fail if a check fails
set -e

for i in st4*.in; do
	echo "$i"
	./checker-st4 < "$i"
done
