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

/* The streamed-sound state (gStreamSoundState); its streamed voice object
 * (gStreamVoice) starts at +0x48. */
#define STREAM_STATE_VOICE 0x48 /* s32 first word of the streamed voice: nonzero while open */

/* Fields of the streamed sound voice (gStreamVoice). */
#define STREAM_VOICE_ACTIVE   0x00 /* s32 nonzero while a stream is open */
#define STREAM_VOICE_ENDED    0x04 /* s32 1 when the stream reached its end */
#define STREAM_VOICE_RESERVED 0x20 /* u32 channels reserved for the stream */
#define STREAM_VOICE_MASK_A   0x24 /* u32 first channel mask stopped with the stream */
#define STREAM_VOICE_MASK_B   0x28 /* u32 second channel mask stopped and cleared */
#define STREAM_VOICE_CHANNEL  0x2C /* s32 hardware channel index, -1 when none */
#define STREAM_VOICE_ENVELOPE 0x3C /* envelope state driven by the func_0202ef* helpers */
#define STREAM_VOICE_REFILL   0x4C /* s32 nonzero while a buffer is being refilled */
#define STREAM_VOICE_VOLUME   0x50 /* s32 last volume written to the hardware */

/* A loaded sound-archive file: the word at +0x18 of its header is the offset
 * from the file to the data block its entries live in. */
#define SOUND_ARCHIVE_DATA_OFFSET  0x18 /* s32 offset in the file of the archive's data block */
#define SOUND_ARCHIVE_DATA_BLOCK   0x8C /* void * the data block (from DATA_OFFSET) */
#define SOUND_ARCHIVE_TABLE_OFFSET 0x20 /* s32 offset in the file of the object table */
#define SOUND_ARCHIVE_TABLE        0x84 /* s32 * the object table (from TABLE_OFFSET) */
#define SOUND_ARCHIVE_FILE_OFFSET  0x10 /* s32 offset in the file of the object file */
#define SOUND_ARCHIVE_FILE         0x88 /* void * the object file (from FILE_OFFSET) */
#define SOUND_ARCHIVE_ENTRY_COUNT  8    /* s32 objects in the table */
#define SOUND_ARCHIVE_ENTRIES      12   /* the objects: 16 bytes each */
#define SOUND_ARCHIVE_ENTRY_SIZE   16
#define SOUND_ARCHIVE_ENTRY_OFFSET 0    /* s32 offset in the file of the object's data */
#define SOUND_ARCHIVE_ENTRY_DATA   8    /* void * the object's data (from ENTRY_OFFSET) */

/* One entry of a loaded sound archive (12 bytes): the sound it names, the bank
 * it is played with, its volume, pan, priority, and the player channel it is
 * played on. */
typedef struct SoundArchiveEntry {
    s32 soundId;  /* +0x00 sound id of the entry */
    u16 bankId;   /* +0x04 sound bank the entry is played with */
    u8  volume;   /* +0x06 volume */
    u8  pan;      /* +0x07 pan */
    u8  priority; /* +0x08 priority: a voice of higher priority replaces a lower one */
    u8  channel;  /* +0x09 player channel/slot the entry is played on */
} SoundArchiveEntry; /* 12 bytes */

/* A sound group of the sound archive: a count and that many items, each saying
 * which kind of sound resource it names and the load flags its loader gets. */
typedef struct SoundGroupItem {
    u8  type;   /* +0x00 SOUND_GROUP_* */
    u8  flags;  /* +0x01 load flags handed to the item's loader */
    u8  pad02[2];
    s32 index;  /* +0x04 id in the table of that kind (sequence, bank, ...) */
} SoundGroupItem; /* 8 bytes */

typedef struct SoundGroup {
    u32 count;               /* +0x00 number of items */
    SoundGroupItem items[1]; /* +0x04 */
} SoundGroup;

/* SoundGroupItem::type */
enum {
    SOUND_GROUP_SEQUENCE         = 0,
    SOUND_GROUP_BANK             = 1,
    SOUND_GROUP_WAVE_ARCHIVE     = 2,
    SOUND_GROUP_SEQUENCE_ARCHIVE = 3
};

/* An id field of a sound-archive record meaning "no file/entry". */
#define SOUND_FILE_NONE 0xFFFF

/* A loaded wave archive file, as LoadWaveArchiveEntry and the packed-table
 * helpers read it: the entry count, then one data pointer per entry (a value
 * below 0x02000000 is an offset from the object itself), followed by one word
 * per entry giving where that entry's bytes start in the file (the next entry's
 * word, or the file size for the last entry, is where they end). */
#define WAVE_ARCHIVE_COUNT     0x38 /* s32 number of entries */
#define WAVE_ARCHIVE_ENTRIES   0x3C /* s32[count] per-entry data pointers (then the offsets) */
#define WAVE_ARCHIVE_FILE_SIZE 0x08 /* s32 total size of the archive file */

/* One record of the packed entry table a sound bank shares with the animation
 * system; the packed-table iterator reads it.  A type-1 record copies five u16
 * values at +0x02, of which the wave archive loader uses the first two: the
 * entry index in the archive and the archive slot it belongs to. */
typedef struct PackedBankEntry {
    u8  type;       /* +0x00 entry type: 1..5, 16 or 17 */
    u8  filler_01;
    u16 waveEntry;  /* +0x02 wave archive entry index */
    u16 waveSlot;   /* +0x04 wave archive slot (0..3) */
    u16 unk_06;
    u16 unk_08;
    u16 unk_0A;
} PackedBankEntry;

/* The sound driver's own voice pool and channel tables (separate from the
 * sound player object above).
 *
 * A linked list is a 12-byte header; every node carries a {prev, next} pair at
 * a fixed offset from the node's start (ListInit/ListAppend/ListRemove take
 * the header and compute the links from that offset). */
#define SOUND_LIST_COUNT       0x08 /* u16 nodes in the list */
#define SOUND_LIST_NODE_OFFSET 0x0A /* u16 offset of the links inside a node */

/* One voice of gVoicePool (16 voices, 0x44 bytes each).  gActiveVoices and
 * gFreeVoices both link the voices at SOUND_VOICE_LINKS; a playing voice is
 * also linked into its channel's list at SOUND_CHANNEL_VOICE_LINKS. */
#define SOUND_VOICE_SIZE     0x44
#define SOUND_VOICE_LINKS    0x14 /* the {prev, next} pair of the voice lists */
#define SOUND_VOICE_STATE    0x2C /* u8 0 = free, 1 = keyed on, 2 = playing */
#define SOUND_VOICE_CHANNEL  0x3C /* u8 hardware channel the voice plays on */
#define SOUND_VOICE_COUNT    16

/* One channel of gSoundChannels (32 channels, 0x24 bytes each): the voices and
 * the sequences playing through it, its voice limit and its volume. */
#define SOUND_CHANNEL_SIZE        0x24
#define SOUND_CHANNEL_VOICE_LIST  0x00 /* list of voices, links at voice+0xC */
#define SOUND_CHANNEL_VOICE_LINKS 0x0C
#define SOUND_CHANNEL_SEQ_LIST    0x0C /* list of sequences, links at their +0 */
#define SOUND_CHANNEL_VOICE_LIMIT 0x18 /* u32 voices the channel accepts */
#define SOUND_CHANNEL_UNK_1C      0x1C /* u32 cleared at start-up */
#define SOUND_CHANNEL_VOLUME      0x20 /* u8 volume, 0..SOUND_VOLUME_MAX */
#define SOUND_CHANNEL_COUNT       32

#define SOUND_VOLUME_MAX 0x7F /* full volume, in the 0..0x7F range */

/* Per-hardware-channel state (gSoundChannelSampleState), two s32 words per channel,
 * indexed by the note id the player lists at SOUND_PLAYER_NOTES: the sample
 * address the channel's current segment starts at and the timer period it is
 * played with.  The sound player fills it when a voice starts and reads it back
 * for every segment. */
#define SOUND_CHANNEL_STATE_STRIDE  8 /* bytes per channel: SOUND_CHANNEL_SAMPLE_ADDR + one word */
#define SOUND_CHANNEL_SAMPLE_ADDR   0 /* s32 address of the channel's current sample */
#define SOUND_CHANNEL_TIMER_PERIOD  4 /* s32 timer period the channel plays at */

/* The game's sound wrapper state (gSoundState): the SDK sound player it keeps
 * running, the heap that player lives in, and the sound ids already started this
 * frame (a sound effect plays at most once per frame). */
#define SOUND_STATE_ENABLED      0x00 /* u8 nonzero once the sound system is up */
#define SOUND_STATE_READY        0x04 /* u8 nonzero once the sound player can be addressed */
#define SOUND_STATE_PLAYER       0x10 /* void *SDK sound player */
#define SOUND_STATE_HEAP         0x14 /* s32 sound heap block */
#define SOUND_STATE_PLAYED_COUNT 0x18 /* s32 sound ids started this frame */
#define SOUND_STATE_FRAME        0x1C /* s32 gFrameCounter the count belongs to */
#define SOUND_PLAYED_MAX         8    /* sound ids remembered per frame (gSoundFrameIds) */
#define SOUND_SLOT_COUNT         4    /* sound effect slots (gSoundSlotHandles) */

/* Menu sounds handed to PlaySoundEffect. */
#define SOUND_MENU_MOVE    0x10010 /* the cursor moved to the other option */
#define SOUND_MENU_CONFIRM 0x1000D /* the highlighted option was accepted */
#define SOUND_MENU_CANCEL  0x1000F /* the choice was cancelled */

#endif
