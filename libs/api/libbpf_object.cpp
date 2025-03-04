// Copyright (c) Microsoft Corporation
// SPDX-License-Identifier: MIT

#include "api_internal.h"
#pragma warning(push)
#pragma warning(disable : 4200)
#include "libbpf.h"
#pragma warning(pop)
#include "libbpf_internal.h"

// This file implements APIs in LibBPF's libbpf.h and is based on code in external/libbpf/src/libbpf.c
// used under the BSD-2-Clause license, so the coding style tries to match the libbpf.c style to
// minimize diffs until libbpf becomes cross-platform capable.  This is a temporary workaround for
// issue #351 until we can compile and use libbpf.c directly.

const char*
bpf_object__name(const struct bpf_object* object)
{
    return object->file_name;
}

int
bpf_object__pin(struct bpf_object* obj, const char* path)
{
    int err;

    err = bpf_object__pin_maps(obj, path);
    if (err)
        return libbpf_err(err);

    err = bpf_object__pin_programs(obj, path);
    if (err) {
        bpf_object__unpin_maps(obj, path);
        return libbpf_err(err);
    }

    return 0;
}

void
bpf_object__close(struct bpf_object* object)
{
    ebpf_object_close(object);
}

struct bpf_program*
bpf_object__find_program_by_name(const struct bpf_object* obj, const char* name)
{
    struct bpf_program* prog;

    bpf_object__for_each_program(prog, obj)
    {
        if (!strcmp(prog->program_name, name))
            return prog;
    }
    errno = ENOENT;
    return nullptr;
}
