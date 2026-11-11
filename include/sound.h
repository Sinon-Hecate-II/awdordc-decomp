/* The sound player/voice object (player slots and gStreamSoundPlayer): one
 * voice spread over up to 32 hardware channels, played in fixed segments. */
#ifndef SOUND_H
#define SOUND_H

#define SOUND_PLAYER_PLAY_MODE      0x20 /* s32 hardware play mode (0 = normal, 1 = half size) */
#define SOUND_PLAYER_FLAGS          0x24 /* u32 bit 0: voice is playing */
#define SOUND_PLAYER_NOTE_BYTES     0x28 /* s32 sample bytes per note/channel */
#define SOUND_PLAYER_SEGMENTS       0x2C /* s32 segments the samples are split into */
#define SOUND_PLAYER_SEGMENT_CB     0x30 /* void (*)(s32 mode, s32 notes, s32 *offsets, s32 size, s32 arg, s32 arg2) */
#define SOUND_PLAYER_CB_ARG         0x34 /* s32 argument passed to the segment callback */
#define SOUND_PLAYER_CURRENT_SEGMENT 0x38 /* s32 segment being played */
#define SOUND_PLAYER_CHANNEL        0x3C /* s32 hardware channel wire number */
#define SOUND_PLAYER_HW_CHANNEL     0x40 /* s32 allocated hardware channel index */
#define SOUND_PLAYER_CHANNEL_MASK   0x44 /* u32 mask of the hardware channels in use */
#define SOUND_PLAYER_NOTE_COUNT     0x48 /* s32 number of notes/channels */
#define SOUND_PLAYER_NOTES          0x4C /* u8[] note/channel id list */

#define SOUND_PLAYER_FLAG_PLAYING   0x0001 /* SOUND_PLAYER_FLAGS bit: voice is playing */
#define SOUND_PLAY_MODE_HALF        1      /* play mode that uses half the note bytes */

#endif
