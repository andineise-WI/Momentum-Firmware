#pragma once

#include "../legic_app_i.h"

const char* legic_rf_std_name(LegicRfStandard rf_std);
const char* legic_fs_version_name(LegicFsVersion fs_version);
const char* legic_segment_type_name(LegicSegmentType type);

bool legic_parser_find_value_field(LegicCardData* card);
bool legic_parser_parse_segments(LegicCardData* card);
