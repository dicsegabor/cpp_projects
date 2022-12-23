#!/bin/bash -e

coredumpctl list | tail -1 | tr -s ' ' | cut -f 5 -d ' ' | coredumpctl gdb