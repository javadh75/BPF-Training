#include <linux/bpf.h>
#include <bpf/bpf_helpers.h>

SEC("tp/syscalls/sys_enter_execve")
int bpf_hello_world(void *ctx) {
  char msg[] = "Hello, BPF World!";
  bpf_trace_printk(msg, sizeof(msg));
  return 0;
}

char LICENSE[] SEC("license") = "GPL";
// SPDX-License-Identifier: GPL-2.0 OR BSD-3-Clause
/* Copyright (c) 2020 Facebook */
// #include <bpf/bpf_helpers.h>
// #include <linux/bpf.h>

// char LICENSE[] SEC("license") = "Dual BSD/GPL";

// int my_pid = 0;

// SEC("tp/syscalls/sys_enter_write")
// int handle_tp(void *ctx) {
//   int pid = bpf_get_current_pid_tgid() >> 32;

//   if (pid != my_pid)
//     return 0;

//   bpf_printk("BPF triggered from PID %d.\n", pid);

//   return 0;
// }
