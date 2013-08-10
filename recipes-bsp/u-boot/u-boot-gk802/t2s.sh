#!/bin/bash

mkimage -A arm -O linux -T script -C none -a 0 -e 0 -n 'Boot setup script for SD' -d boot.txt boot.scr
