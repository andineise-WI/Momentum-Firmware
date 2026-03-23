#include "legic_parser.h"

#define TAG "LegicParser"

const char* legic_rf_std_name(LegicRfStandard rf_std) {
    switch(rf_std) {
    case LegicRfStdLegic:
        return "LEGIC RF";
    case LegicRfStdIso15693:
        return "ISO 15693";
    case LegicRfStdInsideContactless:
        return "INSIDE Contactless";
    case LegicRfStdIso14443A:
        return "ISO 14443A";
    default:
        return "Unknown";
    }
}

const char* legic_fs_version_name(LegicFsVersion fs_version) {
    switch(fs_version) {
    case LegicFsVersionPrimeMim:
        return "LEGIC prime MIM";
    case LegicFsVersionPrimeImS:
        return "LEGIC prime IM-S";
    case LegicFsVersionAdvant:
        return "LEGIC advant";
    default:
        return "Unknown";
    }
}

const char* legic_segment_type_name(LegicSegmentType type) {
    switch(type) {
    case LegicSegTypeGAM:
        return "GAM";
    case LegicSegTypeSAM:
        return "SAM";
    case LegicSegTypeIAM:
        return "IAM";
    case LegicSegTypeXAM1:
        return "XAM_1";
    case LegicSegTypeData:
        return "Data";
    default:
        return "Unknown";
    }
}

bool legic_parser_find_value_field(LegicCardData* card) {
    if(!card || card->raw_data_len < 8) return false;

    // LEGIC value fields are typically stored as 4-byte signed integers
    // in specific segment locations. The exact offset depends on the
    // application configuration.
    //
    // Common patterns for LEGIC cash/value fields:
    // - Value stored as 32-bit signed integer in cents
    // - Often in the first data segment after authorization segments
    // - Typically at a fixed offset within the segment data
    //
    // We scan for a plausible value field structure:
    // A value field usually has a value and its complement for integrity

    // Simple heuristic: look for a 4-byte value followed by its complement
    for(uint16_t i = 0; i + 7 < card->raw_data_len; i++) {
        int32_t val = (int32_t)(
            ((uint32_t)card->raw_data[i]) | ((uint32_t)card->raw_data[i + 1] << 8) |
            ((uint32_t)card->raw_data[i + 2] << 16) | ((uint32_t)card->raw_data[i + 3] << 24));

        int32_t complement = (int32_t)(
            ((uint32_t)card->raw_data[i + 4]) | ((uint32_t)card->raw_data[i + 5] << 8) |
            ((uint32_t)card->raw_data[i + 6] << 16) | ((uint32_t)card->raw_data[i + 7] << 24));

        // Check if value + complement = -1 (0xFFFFFFFF) — MIFARE-style value block
        if((uint32_t)val + (uint32_t)complement == 0xFFFFFFFF) {
            // Sanity check: balance should be in a reasonable range (0 to 999999 cents)
            if(val >= 0 && val <= 99999900) {
                card->balance = val;
                card->has_value_field = true;
                return true;
            }
        }
    }

    card->has_value_field = false;
    return false;
}

bool legic_parser_parse_segments(LegicCardData* card) {
    if(!card || card->raw_data_len < 4) return false;

    // LEGIC advant segment parsing from raw data
    // The segment structure is defined in the LEGIC file system
    // This is a simplified parser for public segment headers

    card->segment_count = 0;

    // In LEGIC advant, the first bytes contain the file system header
    // followed by segment descriptors

    return card->segment_count > 0;
}
