#!/bin/bash

find . -type f -exec bash -c "[ ! -s \"{}\" ] && rm \"{}\"" \;
