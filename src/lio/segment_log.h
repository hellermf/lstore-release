/*
Advanced Computing Center for Research and Education Proprietary License
Version 1.0 (April 2006)

Copyright (c) 2006, Advanced Computing Center for Research and Education,
 Vanderbilt University, All rights reserved.

This Work is the sole and exclusive property of the Advanced Computing Center
for Research and Education department at Vanderbilt University.  No right to
disclose or otherwise disseminate any of the information contained herein is
granted by virtue of your possession of this software except in accordance with
the terms and conditions of a separate License Agreement entered into with
Vanderbilt University.

THE AUTHOR OR COPYRIGHT HOLDERS PROVIDES THE "WORK" ON AN "AS IS" BASIS,
WITHOUT WARRANTY OF ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT
LIMITED TO THE WARRANTIES OF MERCHANTABILITY, TITLE, FITNESS FOR A PARTICULAR
PURPOSE, AND NON-INFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

Vanderbilt University
Advanced Computing Center for Research and Education
230 Appleton Place
Nashville, TN 37203
http://www.accre.vanderbilt.edu
*/

//***********************************************************************
// Log structured segment support
//***********************************************************************

#include "opque.h"

#ifndef _SEGMENT_LOG_H_
#define _SEGMENT_LOG_H_

#ifdef __cplusplus
extern "C" {
#endif

#define SEGMENT_TYPE_LOG "log"

segment_t *segment_log_load(void *arg, ex_id_t id, exnode_exchange_t *ex);
segment_t *segment_log_create(void *arg);
segment_t *slog_make(service_manager_t *sm, segment_t *table, segment_t *data, segment_t *base);  //** Makes a new log segment using

//redundant---op_generic_t *slog_compact(segment_t *seg);  //** Compatcts the table/data log and optionally destroy's the old
op_generic_t *slog_merge_with_base(segment_t *seg, data_attr_t *da, ex_off_t bufsize, char *buffer, int truncate_old_log, int timeout);  //** Merges the current log with the base
//segment_clone -- Does a recursive merge_with_base by performing a deep copy
//int slog_get_segments(segment_t *seg, segment_t **table, segment_t **data, segment_t **base);
//int slog_set_segments(segment_t *seg, segment_t *table, segment_t *data, segment_t *base);

#ifdef __cplusplus
}
#endif

#endif

