#!/bin/bash

# install rust 
curl https://sh.rustup.rs -sSf | sh

# set path
cat $HOME/.cargo/env >> ~/.bashrc
source ~/.bashrd

# change rust version
rustup default 1.35.0

# build mdbook
# fixme: make sure the mdbook version is consistent with rust version.
cargo install mdbook
