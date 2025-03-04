// Copyright (c) Microsoft Corporation
// // SPDX-License-Identifier: MIT
#pragma once

// This file is needed since bpf.h includes it.
// It should be thought of as platform/bpf.h not Linux per se.

#include "ebpf_program_types.h"
#include "ebpf_api.h"
#define LIBBPF_API
#include "libbpf_common.h"
#undef LIBBPF_DEPRECATED
#define LIBBPF_DEPRECATED(x)

typedef uint8_t __u8;
typedef uint32_t __u32;
typedef uint64_t __u64;
typedef uint32_t pid_t;

enum bpf_prog_type
{
    BPF_PROG_TYPE_UNKNOWN,
    BPF_PROG_TYPE_XDP,
    BPF_PROG_TYPE_BIND, // TODO(#333): replace with cross-platform program type
};

enum bpf_attach_type
{
    BPF_ATTACH_TYPE_UNKNOWN,
    BPF_ATTACH_TYPE_XDP,
};

enum bpf_func_id
{
    BPF_FUNC_ID_UNKNOWN
};

enum bpf_stats_type
{
    BPF_STATS_TYPE_UNKNOWN
};

struct bpf_prog_info
{
    int data;
};
