#!/bin/bash

# install rust 
curl https://sh.rustup.rs -sSf | sh

# set path
cat $HOME/.cargo/env >> ~/.bashrc
source ~/.bashrd

# change rust version
rustup default 1.35.0

# build mdbook
cargo install mdbook