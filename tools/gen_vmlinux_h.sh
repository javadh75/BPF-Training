#/bin/sh

mkdir -p $(dirname "$0")/../vmlinux
$(dirname "$0")/bpftool btf dump file ${1:-/sys/kernel/btf/vmlinux} format c > $(dirname "$0")/../vmlinux/vmlinux.h
