#pragma once

#include "../legic_app_i.h"

typedef enum {
    LegicWorkerEventReadDone,
    LegicWorkerEventWriteDone,
    LegicWorkerEventFail,
} LegicWorkerEvent;

typedef void (*LegicWorkerCallback)(LegicWorkerEvent event, void* context);

void legic_worker_start_read(LegicApp* app, LegicWorkerCallback callback, void* context);
void legic_worker_start_write(LegicApp* app, LegicWorkerCallback callback, void* context);
void legic_worker_stop(LegicApp* app);
