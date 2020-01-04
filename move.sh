#!/bin/bash

# build
mdbook build

rm -rf docs
mkdir docs

cp -r ./book/* ./docs