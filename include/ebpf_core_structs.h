// Copyright (c) Microsoft Corporation
// SPDX-License-Identifier: MIT

// This file contains eBPF definitions common to eBPF core libraries as well as
// the eBPF API library.

#pragma once

#include <sal.h>
#include <stdint.h>
#include "ebpf_structs.h"

#define EBPF_MAX_PIN_PATH_LENGTH 256

/**
 * @brief eBPF Map Information
 */
typedef struct _ebpf_map_info
{
    ebpf_map_definition_in_memory_t definition;
    _Field_z_ char* pin_path;
} ebpf_map_info_t;
