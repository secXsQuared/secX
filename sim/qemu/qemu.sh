#!/bin/bash
qemu-system-x86_64 -bios sim/qemu/qemu_bios.bin -cdrom out/secxkrnl.iso -s -S