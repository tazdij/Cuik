#pragma once
#include <common.h>
#include <arena.h>

#include <ext/stb_ds.h>
#include <front/parser.h>

#include "tb.h"

extern TokenStream ir_gen_tokens;
extern TB_Module* mod;
extern _Atomic int sema_error_count;

// stage 1 is forward declarations
void gen_ir_stage1(TopLevel tl, size_t i);

// stage 2 is definitions
void gen_ir_stage2(TopLevel tl, size_t i);
