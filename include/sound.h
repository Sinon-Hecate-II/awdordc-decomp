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

/* The sound player handle: what Sound_StartPlayer (main_0202DBAC) fills in and
 * the segment callback (Sound_NextSegment) services.  One sound playing on a
 * set of hardware channels; separate from the voice object above. */
#define SOUND_HANDLE_TYPE          0xC0  /* u8 sound kind (0 = sample, 1/2 streamed) */
#define SOUND_HANDLE_CHANNELS      0xC2  /* u8 channels the sound asks for */
#define SOUND_HANDLE_RATE          0xC4  /* u16 sample rate */
#define SOUND_HANDLE_TIMER_PERIOD  0xC6  /* u16 hardware timer period */
#define SOUND_HANDLE_FLAGS         0x110 /* u32 player flag bits */
#define SOUND_HANDLE_MAX_CHANNELS  0x124 /* u8 channel limit */
#define SOUND_HANDLE_SAMPLE_DATA   0x12C /* s32 sample data handle */
#define SOUND_HANDLE_CHANNEL_BYTES 0x130 /* s32 sample bytes per channel */
#define SOUND_HANDLE_LOOP_START    0x134 /* s32 loop start sample */
#define SOUND_HANDLE_LOOP_END      0x138 /* s32 loop end sample */
#define SOUND_HANDLE_SEGMENT_CB    0x13C /* s32 (*)(s32 mode, s32 *previous, s32 *next, s32 arg): fills the next streamed segment */
#define SOUND_HANDLE_SEGMENT_ARG   0x140 /* s32 argument to the segment callback */
#define SOUND_HANDLE_SOUND_ID      0x144 /* s32 id of the sound/sample being played */
#define SOUND_HANDLE_SEGMENT_END   0x148 /* s32 end of the current segment */
#define SOUND_HANDLE_VOLUME        0x158 /* s32 volume, 0..0x7F */
#define SOUND_HANDLE_SAMPLES_LEFT  0x160 /* s32 samples left in the current segment */
#define SOUND_HANDLE_START_CB      0x164 /* s32 (*)(void *player, s32 soundId): restart the voices for a sound */
#define SOUND_HANDLE_RELEASE_CB    0x168 /* void (*)(void *player): stop the voices */

#endif
