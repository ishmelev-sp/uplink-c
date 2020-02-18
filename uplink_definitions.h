// Copyright (C) 2020 Storj Labs, Inc.
// See LICENSE for copying information.

#pragma once

#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Access   { long _handle; } Access;
typedef struct Project  { long _handle; } Project;
typedef struct Download { long _handle; } Download;
typedef struct Upload   { long _handle; } Upload;

typedef struct Config {
    char *user_agent;
    bool skip_whitelist;
    int32_t dial_timeout_milliseconds;
} Config;

typedef struct Bucket {
    char *name;
} Bucket;

typedef struct ObjectInfo {
    int64_t created;
    int64_t expires;
} ObjectInfo;

typedef struct StandardMetadata {
    int64_t content_length;
    char *content_type;
    char *etag;

    int64_t  file_created;
    int64_t  file_modified;
    uint32_t file_permissions;
} StandardMetadata;

typedef struct CustomMetadata {
} CustomMetadata;

typedef struct Object {
    char *key;
    ObjectInfo info;
    StandardMetadata standard;
    CustomMetadata custom;
} Object;

typedef struct Objects { long _handle; } Objects;
typedef struct ObjectsOptions { 
    char *prefix;
    char *cursor;
    bool recursive;

    bool info;
    bool standard;
    bool custom;
} ObjectsOptions;

typedef struct Buckets { long _handle; } Buckets;
typedef struct BucketsOptions { 
    char *cursor;
} BucketsOptions;
