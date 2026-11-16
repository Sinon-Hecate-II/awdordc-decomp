#include "common.h"

s32 func_0209cd4c(void *sprite);
s32 func_0209cd5c(void *sprite);
s32 func_0209cd64(void *sprite);
s32 func_0209cd6c(void *sprite);
s32 func_0209cd80(void *sprite);
s32 func_0209cda8(void *sprite);
s32 func_0209cdd0(void *sprite);
s32 func_0209cdf0(void *sprite);
s32 func_0209ce14(void *sprite);
s32 func_0209ce50(void *sprite);
s32 func_0209ce90(void *sprite);
s32 func_0209cecc(void *sprite);
s32 func_0209cf0c(void *sprite);
s32 func_0209cf2c(void *sprite);
s32 func_0209cf60(void *sprite);
s32 func_0209cf8c(void *sprite);
s32 func_0209cfb8(void *sprite);
s32 func_0209cfe4(void *sprite);
s32 func_0209d020(void *sprite);
s32 func_0209d3c8(void *sprite);
s32 func_0209d05c(void *sprite);
s32 func_0209d074(void *sprite);
s32 func_0209d0c0(void *sprite);
s32 func_0209d10c(void *sprite);
s32 func_0209d148(void *sprite);
s32 func_0209d1d4(void *sprite);
s32 func_0209d204(void *sprite);
s32 func_0209d224(void *sprite);
s32 func_0209d2b0(void *sprite);
s32 func_0209d33c(void *sprite);
s32 func_0209d3dc(void *sprite);
s32 func_0209d44c(void *sprite);
s32 func_0209d4bc(void *sprite);
s32 func_0209d52c(void *sprite);
s32 func_0209d59c(void *sprite);
s32 func_0209d60c(void *sprite);
s32 func_0209d67c(void *sprite);
s32 func_0209d6a4(void *sprite);
s32 func_0209d6cc(void *sprite);
s32 func_0209d6fc(void *sprite);
s32 func_0209d728(void *sprite);
s32 func_0209d750(void *sprite);
s32 func_0209d790(void *sprite);
s32 func_0209d7d8(void *sprite);
s32 func_0209d858(void *sprite);
s32 func_0209d8b8(void *sprite);
s32 func_0209d91c(void *sprite);
s32 func_0209d97c(void *sprite);
s32 func_0209d9dc(void *sprite);
s32 func_0209da3c(void *sprite);
s32 func_0209da68(void *sprite);

/* The sprite-state opcode indexes this table. Keep it between the ITCM routines. */
#pragma define_section ITCM_TEXT_DATA ".text" abs32 RWX
#pragma section ITCM_TEXT_DATA begin
s32 (*gSpriteStateHandlers[])(void *) = {
    func_0209cd4c,
    func_0209cd4c,
    func_0209cd5c,
    func_0209cd64,
    func_0209cd6c,
    func_0209cd80,
    func_0209cda8,
    func_0209cdd0,
    func_0209cdf0,
    func_0209ce14,
    func_0209ce50,
    func_0209ce90,
    func_0209cecc,
    func_0209cf0c,
    func_0209cf2c,
    func_0209cf60,
    func_0209cf8c,
    func_0209cfb8,
    func_0209cfe4,
    func_0209d020,
    func_0209d3c8,
    func_0209d05c,
    func_0209d074,
    func_0209d0c0,
    func_0209d10c,
    func_0209d148,
    func_0209d1d4,
    func_0209d204,
    func_0209d224,
    func_0209d2b0,
    func_0209d33c,
    func_0209d3c8,
    func_0209d3dc,
    func_0209d44c,
    func_0209d4bc,
    func_0209d52c,
    func_0209d59c,
    func_0209d60c,
    func_0209d67c,
    func_0209d6a4,
    func_0209d6cc,
    func_0209d6fc,
    func_0209d728,
    func_0209d750,
    func_0209d790,
    func_0209d7d8,
    func_0209d858,
    func_0209d8b8,
    func_0209d91c,
    func_0209d97c,
    func_0209d9dc,
    func_0209da3c,
    func_0209da68,
};
#pragma section ITCM_TEXT_DATA end
