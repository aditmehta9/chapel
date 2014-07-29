/*
 * Copyright 2004-2014 Cray Inc.
 * Other additional copyright holders may be indicated within.
 * 
 * The entirety of this work is licensed under the Apache License,
 * Version 2.0 (the "License"); you may not use this file except
 * in compliance with the License.
 * 
 * You may obtain a copy of the License at
 * 
 *     http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

// chplcgfns.h
//
// Declarations for variables and prototypes for functions which are
// generated by the chapel compiler.
// This header makes those symbols available to client code in the runtime.
//
// TODO: Arguably, since it contains both function and variable declarations,
//  it should be renamed as chplcgdecl.h (or so).
//
#ifndef _CHPL_GEN_INTERFACE_H_
#define _CHPL_GEN_INTERFACE_H_

#include <stdlib.h>
#include "chpltypes.h"

/* This header file is for routines that are in the generated code */

/* defined in chpl__header.h: */

extern const char* chpl_compileCommand;
extern const char* chpl_compileVersion;
extern const char* CHPL_HOST_PLATFORM;
extern const char* CHPL_TARGET_PLATFORM;
extern const char* CHPL_HOST_COMPILER;
extern const char* CHPL_TARGET_COMPILER;
extern const char* CHPL_THREADS;
extern const char* CHPL_COMM;

/* defined in main.c */
extern char* chpl_executionCommand;

/* generated */
extern chpl_fn_p chpl_ftable[];

void chpl__init_preInit(int64_t _ln, c_string _fn);
void chpl__init_PrintModuleInitOrder(int64_t _ln, c_string _fn);
void chpl__init_ChapelStandard(int64_t _ln, c_string _fn);

/* used for entry point: */
extern int64_t chpl_gen_main(chpl_main_argument* const _arg);

/* used for config vars: */
extern void CreateConfigVarTable(void);

/* used by copy collection: */

//extern size_t cid2size(chpl__class_id cid);
//extern size_t* cid2offsets(chpl__class_id cid);

/* These are defined in _type_structure.c if
   --gen-communicated-structures is true and are used by a
   communication layer to query types of communicated buffers */
extern chplType chpl_getFieldType(int typeNum, int fieldNum);
extern size_t chpl_getFieldOffset(int typeNum, int fieldNum);
extern size_t chpl_getFieldSize(int typeNum);
extern const int chpl_max_fields_per_type;

#endif
