// Copyright (c) Microsoft Corporation
// SPDX-License-Identifier: MIT

#include "bpf_helpers.h"

SEC("maps")
struct bpf_map map = {sizeof(struct bpf_map), BPF_MAP_TYPE_PROG_ARRAY, sizeof(uint32_t), sizeof(uint32_t), 1};

SEC("maps") struct bpf_map canary = {sizeof(struct bpf_map), BPF_MAP_TYPE_ARRAY, sizeof(uint32_t), sizeof(uint32_t), 1};

SEC("xdp_prog") int caller(struct xdp_md* ctx)
{
    uint32_t key = 0;
    uint32_t* value;

    // This should fail since the index is past the end of the array.
    long error = bpf_tail_call(ctx, &map, 1);

    value = bpf_map_lookup_elem(&canary, &key);
    if (value) {
        *value = 1;
    }

    return (int)error;
}

SEC("xdp_prog/0") int callee(struct xdp_md* ctx) { return 42; }
