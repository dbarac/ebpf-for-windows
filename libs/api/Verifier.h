// Copyright (c) Microsoft Corporation
// SPDX-License-Identifier: MIT

#pragma once

#include "api_internal.h"
#include "config.hpp"
#include "ebpf_program_types.h"
#include "ebpf_result.h"
#include "platform.hpp"
typedef int (*map_create_fp)(
    uint32_t map_type, uint32_t key_size, uint32_t value_size, uint32_t max_entries, ebpf_verifier_options_t options);

ebpf_result_t
load_byte_code(
    _In_z_ const char* filename,
    _In_opt_z_ const char* sectionname,
    _In_ ebpf_verifier_options_t* verifier_options,
    _Inout_ std::vector<ebpf_program_t*>& programs,
    _Inout_ std::vector<ebpf_map_t*>& maps,
    _Outptr_result_maybenull_z_ const char** error_message) noexcept;

ebpf_result_t
get_program_type_info(const ebpf_program_info_t** info);
