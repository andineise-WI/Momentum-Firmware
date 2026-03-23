#pragma once

#include <furi.h>
#include <gui/gui.h>
#include <gui/view_dispatcher.h>
#include <gui/scene_manager.h>
#include <gui/modules/submenu.h>
#include <gui/modules/popup.h>
#include <gui/modules/loading.h>
#include <gui/modules/widget.h>
#include <gui/modules/text_box.h>
#include <gui/modules/dialog_ex.h>
#include <gui/modules/byte_input.h>
#include <notification/notification_messages.h>
#include <dialogs/dialogs.h>
#include <storage/storage.h>
#include <flipper_format/flipper_format.h>

#include <nfc/nfc.h>
#include <nfc/nfc_scanner.h>
#include <nfc/nfc_poller.h>

#include "scenes/legic_scene.h"

#define LEGIC_APP_FOLDER    EXT_PATH("nfc/legic")
#define LEGIC_APP_EXTENSION ".legic"
#define LEGIC_APP_FILE_TYPE "Flipper LEGIC dump"

#define LEGIC_UID_MAX_LEN   10
#define LEGIC_MAX_SEGMENTS  127
#define LEGIC_MAX_DUMP_SIZE 1024

typedef enum {
    LegicViewMenu,
    LegicViewPopup,
    LegicViewLoading,
    LegicViewWidget,
    LegicViewTextBox,
    LegicViewDialogEx,
    LegicViewByteInput,
} LegicView;

typedef enum {
    LegicCustomEventScanResult,
    LegicCustomEventReadDone,
    LegicCustomEventReadFail,
    LegicCustomEventWriteDone,
    LegicCustomEventWriteFail,
    LegicCustomEventWorkerExit,
    LegicCustomEventTextInput,
} LegicCustomEvent;

typedef enum {
    LegicRfStdLegic = 0x10,
    LegicRfStdIso15693 = 0x20,
    LegicRfStdInsideContactless = 0x21,
    LegicRfStdIso14443A = 0x30,
} LegicRfStandard;

typedef enum {
    LegicFsVersionPrimeMim = 0x00,
    LegicFsVersionPrimeImS = 0x11,
    LegicFsVersionAdvant = 0x20,
} LegicFsVersion;

typedef enum {
    LegicSegTypeAny = 0x00,
    LegicSegTypeGAM = 0x01,
    LegicSegTypeSAM = 0x02,
    LegicSegTypeIAM = 0x03,
    LegicSegTypeXAM1 = 0x04,
    LegicSegTypeData = 0x40,
} LegicSegmentType;

typedef struct {
    uint8_t segment_num;
    LegicSegmentType type;
    uint8_t function_level;
    uint8_t org_level;
    uint16_t data_size;
    uint8_t data[256];
    bool readable;
    bool writable;
} LegicSegment;

typedef struct {
    uint8_t uid[LEGIC_UID_MAX_LEN];
    uint8_t uid_len;
    LegicRfStandard rf_std;
    LegicFsVersion fs_version;
    NfcProtocol nfc_protocol;

    uint8_t segment_count;
    LegicSegment segments[LEGIC_MAX_SEGMENTS];

    uint8_t raw_data[LEGIC_MAX_DUMP_SIZE];
    uint16_t raw_data_len;

    bool has_value_field;
    int32_t balance;
} LegicCardData;

typedef struct {
    Gui* gui;
    ViewDispatcher* view_dispatcher;
    SceneManager* scene_manager;
    NotificationApp* notifications;
    DialogsApp* dialogs;
    Storage* storage;

    Submenu* submenu;
    Popup* popup;
    Loading* loading;
    Widget* widget;
    TextBox* text_box;
    DialogEx* dialog_ex;
    ByteInput* byte_input;

    FuriString* text_box_store;
    FuriString* file_path;
    FuriString* file_name;

    Nfc* nfc;
    NfcScanner* scanner;
    NfcPoller* poller;

    LegicCardData card_data;
    bool card_loaded;
    bool scan_active;
} LegicApp;

LegicApp* legic_app_alloc(void);
void legic_app_free(LegicApp* app);
